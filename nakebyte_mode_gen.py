import json
import struct
from typing import List, Dict, cast


model = {}
with open('array_union.json', 'r') as f:
    model = json.load(f)
model1 = {}
with open('array_union_data.json', 'r') as f:
    model1 = json.load(f)
offset_size = 4 if model.get('offset_size') is None else model['offset_size']  # Size of the 'offset' type in bytes


primitive_types = {
    ('char',1,1),('int8',1,1), ('uint8',1,1), ('int16',2,2), ('uint16',2,2), ('int32',4,4), ('uint32',4,4), ( 'int64',8,8), ('uint64',8,8), ('float32',4), ('float64',8), ('string', offset_size, offset_size)}
all_types = {'char', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64', 'float32', 'float64', 'string'}
needed_types = all_types.copy()

def is_primitive_type(type_name):
    # if type_name in ['string', 'blob', 'union']:
    #     return True
    for prim_type in primitive_types:
        if prim_type[0] == type_name:
            return True
    return False

def get_padding_size(offset: int, alignment: int) -> int:
    return (alignment - (offset % alignment)) % alignment

def get_next_valid_offset(offset: int, alignment: int) -> int:
    return offset + get_padding_size(offset, alignment)

def get_type_from_json(type_name) -> Dict:
    
    for model_type in model['types']:
        if model_type['name'] == type_name:
            return model_type
    raise ValueError(f"Type name given but type definition json not found. Error in model definition.")
        
def set_all_types():
    for ty in model.get('types', []):
        all_types.add(ty['name'])
    
def set_needed_types(root_type):    
    if root_type['name'] in needed_types:
        return needed_types
    needed_types.add(root_type['name'])
    members = root_type.get('members', [])
    for member in members:
        if not member['type']  in needed_types:
            member_type = get_type_from_json(member['type'])
            #? Not needed?
            set_needed_types(member_type)
    members = root_type.get('unions', [])
    for member in members:
        if not member['name']  in needed_types:
            member_type = get_type_from_json(member['name'])
            #? Not needed?
            set_needed_types(member_type)
            # needed_types.update(set_needed_types(member_type))   
    return needed_types

class EnumMember:
    def __init__(self, name: str, value: int) -> None:
        self.name = name
        self.value = value
        
    def __str__(self):
        return f'EnumMember(name={self.name}, value={self.value})'

class TypeDesc:
    def __init__(self, name: str,  type_type: str,  is_primitive: bool= False) -> None:
        self.name: str = name
        self.type_type = type_type
        self.is_primitive = is_primitive
        
        self.size: int = 0
        self.alignment: int = 0
        self.members: List['MemberDesc']= []
        self.u_members: List['TypeDesc'] = []
        self.e_members: List['EnumMember'] = []
        
    def set_basetype(self, basetype: 'TypeDesc') -> None:
        if self.type_type != 'enum':
            raise ValueError(f"Only a type of enum can have a basetype but type is {self.type_type}")
        else:
            self.basetype: 'TypeDesc' = basetype
            
    def set_alignment(self, alignment: int) -> None:
        self.alignment = alignment
        
    def set_size(self, size: int) -> None:
        self.size = size
        
    def is_offset_type(self) -> bool:
        return self.type_type in ['struct_offset', 'class', 'union']
    def can_contain_member(self) -> bool:
        return self.type_type in ['struct', 'struct_offset', 'class']
     
    def add_member(self,name: str, type_type: str, is_array: bool)-> None:
        if not self.can_contain_member():
            raise ValueError(f"This type must of either struct, struct_offset or class to be able to add a member but type is of {self.type_type}")
        else:
            if self.members != [] and self.members[-1].name.startswith('pad'):
                self.set_size(self.size - self.members[-1].size)
                self.members.pop()
            # mem_size = 0
            # mem_alignment = 0
            if type_type in parent_types:
                if is_array:
                    mem_size = offset_size
                    mem_alignment = offset_size
                    real_type = self
                else:
                     raise ValueError(f"Possibility of Cyclic Dependency exists which include these types {parent_types}.")
            else:
                real_type: TypeDesc = compute_type_desc(type_type)
                if real_type is None:
                    raise ValueError("Type must be specified for MemberDesc")
                else: 
                    if real_type.is_offset_type():
                        mem_size = offset_size
                        mem_alignment = offset_size
                    else:
                        mem_size = real_type.size
                        mem_alignment = real_type.alignment
                    
            if real_type.type_type == 'union' and (not is_array):
                self.add_member(name= f"{name}_type", type_type=f"{type_type}_enum", is_array=False)
            self.alignment = max(mem_alignment, self.alignment)
            
            
            padding = get_padding_size(self.size, mem_alignment)
            if padding > 0:
                mem_pad = MemberDesc(f'pad{self.size}', cast(TypeDesc,get_type_desc_from_types_desc(f'pad{padding}')), False, offset=self.size, size=padding, alignment=1)
                self.members.append(mem_pad)
                self.set_size(self.size + padding)
                
            member = MemberDesc(name=name,type_type=real_type, is_array=is_array, offset=self.size,size=mem_size, alignment=mem_alignment)
                
            self.members.append(member)
            self.set_size(self.size + member.size)
            
            padding = get_padding_size(self.size, self.alignment)
            if padding > 0:
                mem_pad = MemberDesc(f'pad{self.size}', cast(TypeDesc,get_type_desc_from_types_desc(f'pad{padding}')), False, offset=self.size, size=padding, alignment=1)
                self.members.append(mem_pad)
                self.set_size(self.size + padding)
                
            
            
    def add_e_member(self, name: str, value: int|None = None):
        if self.type_type != 'enum':
            raise ValueError(f"Enum member can oly be added for type of enum but type is {self.type_type}")
        elif any(e.name == name for e in self.e_members):
            raise ValueError(f"Enum member is already contained in enum member")
        elif value != None and any(e.value == value for e in self.e_members):
            raise ValueError(f"Enum value is already contained in enum member")
        else:
            if value == None:
                if len(self.e_members) == 0:
                    value =0
                else:
                    value = self.e_members[-1].value + 1
            elif value != None:
                for e in self.e_members:
                    if value == e.value:
                        raise ValueError(f"Enum can not have duplicate elements. {e.name} and {name} have the same value of {value}")
            self.e_members.append(EnumMember(name,value ))
    # TODO
    def add_u_members(self, type_desc: 'TypeDesc'):
        if self.type_type != 'union':
            raise ValueError(f"Union member can only be added for union type but type is {self}")
        self.u_members.append(type_desc)
            
    def __str__(self) -> str:
        members = self.u_members if self.u_members != [] else self.members if self.members != [] else self.e_members
        return f'TypeDesc(name={self.name}, size={self.size}, alignment={self.alignment}, is_primitive={self.is_primitive}, members=\n{[str(m)  for m in members]})'
    
    @staticmethod
    def gen_primitive_type(name: str, size: int, alignment: int) -> 'TypeDesc':
        typeDesc = TypeDesc(name=name, is_primitive= True, type_type='struct')
        typeDesc.set_alignment(alignment)
        typeDesc.set_size(size)
        return typeDesc
    
    @staticmethod
    def generate_enum_type(name: str, base_type: str, enums: List):
        real_base_type = get_type_desc_from_types_desc(base_type)
        if real_base_type is None:
            raise ValueError("Enum must be of a base type of one of the defined int types")
        size = real_base_type.size
        alignment = real_base_type.alignment
        type_desc = TypeDesc(name=name, is_primitive= False, type_type= 'enum')
        type_desc.set_size(size)
        type_desc.set_alignment(alignment)
        type_desc.set_basetype(real_base_type)
        for e in enums:
            type_desc.add_e_member(name=e['name'], value=e.get('value', None))
        return type_desc
    
    @staticmethod
    def gen_union_type(name: str, members: List):
        type_desc = TypeDesc(name=name, is_primitive= False,type_type='union')
        for mem in members:
            if mem['name'] == None:
                raise ValueError("Name of the union type member not specified.")
            real_mem_type = get_type_desc_from_types_desc(mem['name'])
            if real_mem_type == None:
                raise ValueError("Union member type doesn't exist")
            type_desc.add_u_members(real_mem_type)
        type_desc.set_alignment(offset_size)
        type_desc.set_size(offset_size)
        return type_desc
    
    @staticmethod
    def generate_pad(size: int) -> 'TypeDesc':
        type_desc = TypeDesc(name=f'pad{size}', is_primitive= True,type_type='struct')
        type_desc.set_size(size)
        type_desc.set_alignment(1)
        return type_desc
    
            
types_desc = {
            TypeDesc.gen_primitive_type(name='char',size= 1, alignment=1),
            TypeDesc.gen_primitive_type(name='int8',size= 1, alignment=1), 
            TypeDesc.gen_primitive_type(name='uint8',size= 1, alignment=1),
            TypeDesc.gen_primitive_type(name='int16',size= 2, alignment=2), 
            TypeDesc.gen_primitive_type(name='uint16',size= 2, alignment=2),
            TypeDesc.gen_primitive_type(name='int32',size= 4, alignment=4), 
            TypeDesc.gen_primitive_type(name='uint32',size= 4, alignment=4),
            TypeDesc.gen_primitive_type(name='int64',size= 8, alignment=8), 
            TypeDesc.gen_primitive_type(name='uint64',size= 8, alignment=8),
            TypeDesc.gen_primitive_type(name='float32',size= 4, alignment=4), 
            TypeDesc.gen_primitive_type(name='float64',size= 8, alignment=8),
            TypeDesc.gen_primitive_type(name='string',size= offset_size, alignment= offset_size)         
        }  
for i in range(1, 8):
    types_desc.add(TypeDesc.generate_pad(i) )  
parent_types= []
# Todo: Add alignment here for redundancy
class MemberDesc:
    def __init__(self, name: str, type_type: TypeDesc, is_array: bool, offset: int, size: int, alignment: int) -> None:
        
        
        self.name = name
        self.type_desc: TypeDesc = type_type
        self.offset = offset
        self.is_array = is_array
        self.is_offset_type = is_array or type_type.is_offset_type() or type_type.name == 'string'
        self.size = size
        self.alignment = alignment
    
    def __str__(self) -> str:
        return f'MemberDesc(name={self.name}, type={'List[' if self.is_array  else ''}{self.type_desc.name}{']' if self.is_array else ''}, size={self.size}, offset={self.offset}, alignment={self.alignment})'
        
def get_type_desc_from_types_desc(type_name: str) -> TypeDesc|None:
    for t in types_desc:
        if t.name == type_name:
            return t
    return None

def get_offset_type_int() -> str:
    if offset_size == 1:
        return ('uint8')
    elif offset_size == 2:
        return ('uint16')
    elif offset_size == 4:
        return ('uint32')
    elif offset_size == 8:
        return ('uint64')
    else: 
        return 'uint16'
    
def get_offset_type_desc_int() -> TypeDesc:
    type_desc = get_type_desc_from_types_desc(get_offset_type_int())
    if type_desc == None:
        raise ValueError(f"The raw string type of {type_desc} is not allowed.")
    return type_desc
        
def compute_type_desc(type_name: str) -> TypeDesc:
    type_desc_from_types_desc = get_type_desc_from_types_desc(type_name)
    if type_desc_from_types_desc != None:
        return type_desc_from_types_desc
    
    type_def = get_type_from_json(type_name)

    if type_def['type'] == 'enum':
        return TypeDesc.generate_enum_type(type_def['name'], type_def['base_type'], type_def['enums'])
    elif type_def['type'] == 'union':
        types_desc.add(TypeDesc.generate_enum_type(f"{type_def['name']}_enum", get_offset_type_int(), type_def['unions']))
        return TypeDesc.gen_union_type(type_def['name'],type_def['unions'])
    elif type_def['type'] in ['struct', 'struct_offset', 'class']:
        parent_types.append(type_def['name'])
        
        type_desc = TypeDesc(name=type_def['name'], type_type=type_def['type'],is_primitive=False)
        for member in type_def['members']:
            type_desc.add_member(name=member['name'],type_type=member['type'], is_array=member.get('is_array', False))
           
        parent_types.pop()
        
        return type_desc
    else:
        raise ValueError(f"The type of this type which is {type_def['type']}is not supported")  
    
def members_contain_union_recursively(type_json: Dict) -> bool:
    for mem in type_json["members"]:
        if is_primitive_type(mem["type"]):
            continue
        type_json = get_type_from_json(mem['type'])
        if type_json['type'] == 'enum':
            return False
        if type_json['type'] == 'union':
            return True
        it_has  =  members_contain_union_recursively(get_type_from_json(mem["type"]))
        if it_has:
            return True
    return False

def compute_all_types_desc(types: set[str]):
    types_with_union: set[str] = set()
    union_types: set[str] = set()
    for type_name in types:
        if is_primitive_type(type_name):
            continue
        type_json = get_type_from_json(type_name)
        if type_json["type"] == 'union':
            union_types.add(type_name)
            continue
        if type_json["type"] != 'enum':
            if members_contain_union_recursively(type_json):
                types_with_union.add(type_name)
                continue
        type_desc = compute_type_desc(type_name)
        types_desc.add(type_desc)
    for type_name in union_types:
        type_desc = compute_type_desc(type_name)
        types_desc.add(type_desc)
    for type_name in types_with_union:
        type_desc = compute_type_desc(type_name)
        types_desc.add(type_desc)
    return types_desc


def generate_primitive_bytearray(value, type_desc: TypeDesc) -> bytearray:
    if value == None:
        # raise ValueError("Don't know what to do yet")
        return bytearray(b'\x00' * type_desc.size)
    elif type_desc.name == 'char':       
        return value.encode(encoding='ascii')[0:1]
    elif type_desc.name == 'int8':
        val = int(value)
        return bytearray(struct.pack('b', val))
    elif type_desc.name == 'uint8':
        val = int(value)
        return bytearray(struct.pack('B', val))
    elif type_desc.name == 'int16':
        val = int(value)
        return bytearray(struct.pack('<h', val))
    elif type_desc.name == 'uint16':
        val = int(value)
        return bytearray(struct.pack('<H', val))
    elif type_desc.name == 'int32':
        val = int(value)
        return bytearray(struct.pack('<i', val))
    elif type_desc.name == 'uint32':
        val = int(value)
        return bytearray(struct.pack('<I', val))
    elif type_desc.name == 'int64':
        val = int(value)
        return bytearray(struct.pack('<q', val))
    elif type_desc.name == 'uint64':
        val = int(value)
        return bytearray(struct.pack('<Q', val))
    elif type_desc.name == 'float32':
        val = float(value)
        return bytearray(struct.pack('<f', val))
    elif type_desc.name == 'float64':
        val = float(value)
        return bytearray(struct.pack('<d', val))
    elif type_desc.name == 'string':
        str_type = get_offset_type_desc_int()
        if str_type == None:
            raise ValueError(f"The raw string type of {str_type} is not allowed.")
        item_byte: bytearray = generate_primitive_bytearray(len(value), str_type)
        item_byte.extend(value.encode(encoding='ascii'))
        item_byte.append(0x00)
        return item_byte
    elif type_desc.name == 'offset':
        val = int(value)
        if offset_size == 2:
            return bytearray(struct.pack('<b', val))
        elif offset_size == 2:
            return bytearray(struct.pack('<h', val))
        elif offset_size == 4:
            return bytearray(struct.pack('<i', val))
        elif offset_size == 8:
            return bytearray(struct.pack('<q', val))
        else:
            return bytearray(struct.pack('<h', val))

    else:
        raise ValueError(f"Unsupported primitive type: {type_desc.name}")
     
def generate_array_byte(model: List, type_desc: TypeDesc) -> bytearray:
    item_count = ( len(model))
    root_array_length = offset_size
    root_array = bytearray(root_array_length)
    root_array[0:offset_size] = generate_primitive_bytearray(item_count, get_offset_type_desc_int())
    padding: int = get_padding_size(root_array_length, type_desc.alignment)
    if padding > 0:
        root_array.extend((b'\xa5' * padding))
        
    # Todo make sure it start at the alignment
    if type_desc.is_primitive:
        if type_desc.name == 'string':
            for i, item in enumerate(model):
                byte_array = bytearray(offset_size * item_count)
                
                item_bytes = generate_primitive_bytearray(item, cast(TypeDesc, get_type_desc_from_types_desc(type_desc.name)))
                byte_array_offset = offset_size + i * offset_size
                byte_array[byte_array_offset:  byte_array_offset+  offset_size]= generate_primitive_bytearray(len(byte_array) -(offset_size + offset_size * i ), get_offset_type_desc_int())
                byte_array.extend(item_bytes)
        else:
            byte_array = bytearray(type_desc.size * item_count)
            for i, item in enumerate(model):
                byte_array_offset = offset_size + i * offset_size
                
                byte_array[byte_array_offset: byte_array_offset + type_desc.size] = generate_primitive_bytearray(model[i], type_desc)
    elif not type_desc.is_offset_type():
        byte_array = bytearray(type_desc.size * item_count)
        for i, item in enumerate(model):
            item_offset = type_desc.size * i 
            for mem in type_desc.members:
                curr_offset = item_offset + mem.offset 
                if mem.name.startswith('pad'):
                    byte_array[curr_offset :curr_offset + mem.size] = b'\xa5' * mem.size
                elif not mem.is_offset_type:
                    byte_array[curr_offset :curr_offset + mem.size] = generate_byte(model[i][f'{mem.name}'], mem.type_desc)
                
                else:
                    if mem.type_desc.type_type == 'union':
                        temp_bytes = generate_byte(model[i][f'{mem.name}'], cast(TypeDesc, get_type_desc_from_types_desc(model[i][f'{mem.name}_type'])) )
                    else:
                        temp_bytes = generate_byte(model[i][f'{mem.name}'], mem.type_desc )
                    if len(temp_bytes) == 0:
                        offset1 = 0
                    else: 
                        offset1 = (len(byte_array) - curr_offset)
                    byte_array[curr_offset :curr_offset+ mem.size] = generate_primitive_bytearray(offset1, get_offset_type_desc_int())
                    byte_array.extend(temp_bytes)
    elif type_desc.type_type == 'union': 
        byte_array = bytearray(offset_size * 2  * item_count)
        for i, item in enumerate(model):
            curr_offset = offset_size * i *2
            byte_array[curr_offset: curr_offset+ offset_size ] = generate_byte(item["type"], cast(TypeDesc, get_type_desc_from_types_desc(f'{type_desc.name}_enum')) )
            item_bytes = generate_byte(item["value"], cast(TypeDesc, get_type_desc_from_types_desc(item["type"])))
            if len(item_bytes) == 0:
                value = 0
            else: 
                value = (len(byte_array) - (curr_offset+ offset_size))
            byte_array[curr_offset+ offset_size: curr_offset+ offset_size * 2] = generate_primitive_bytearray(value , get_offset_type_desc_int())
            byte_array.extend(item_bytes)
 
        
        # raise ValueError("Still deciding what to do")
    elif type_desc.is_offset_type():
        byte_array = bytearray(offset_size * item_count)
        
        for i, item in enumerate(model):    
            temp_bytes = generate_byte(model[i], type_desc)
            byte_array_offset = i * offset_size
            
            if len(temp_bytes) == 0:
                offset1 = 0
            else: 
                offset1 = (len(byte_array) - byte_array_offset)
            byte_array[byte_array_offset:  byte_array_offset+  offset_size] = generate_primitive_bytearray(offset1, get_offset_type_desc_int())
            byte_array.extend(temp_bytes)
    else:
            raise ValueError("fdghj")
    root_array.extend(byte_array)
    return root_array

     

def generate_byte(model, type_desc: TypeDesc) -> bytearray:
    root_array: bytearray = bytearray(type_desc.size)
    
    if type_desc.is_primitive:
        return generate_primitive_bytearray(model, type_desc)
    elif type_desc.type_type == 'enum':
        for i, item in enumerate(type_desc.e_members):
            if item.name == model:
                val = i
                return generate_primitive_bytearray(val, type_desc.basetype)
        else:
            raise ValueError(f"Enum value {model}'] not found in enum {type_desc.e_members}.")
    elif type_desc.type_type == 'union':
        raise ValueError("jsfdjksd")
    elif type_desc.can_contain_member():
        for mem in type_desc.members:
            if mem.name.startswith('pad'):
                root_array[mem.offset:mem.offset + mem.size] = b'\xa5' * mem.size
            elif mem.is_array:
                if model[f'{mem.name}'] == None or model[f'{mem.name}'] == []:
                    root_array[mem.offset:mem.offset + mem.size] = (b'\xa5' * mem.size)
                else:
                    root_array[mem.offset:mem.offset + mem.size] = generate_primitive_bytearray((len(root_array) - mem.offset), get_offset_type_desc_int())
                item_byte =  generate_array_byte(model[f'{mem.name}'], mem.type_desc)
                root_array.extend(item_byte)
            elif mem.type_desc.is_primitive:
                if mem.type_desc.name == 'string':
                    if model[f'{mem.name}'] == None:
                        root_array[mem.offset:mem.offset + mem.size] = b'\x00' * mem.size
                    elif isinstance(model[f'{mem.name}'], str):
                        root_array[mem.offset:mem.offset + mem.size] = root_array[mem.offset:mem.offset + mem.size] = generate_primitive_bytearray((len(root_array) - mem.offset), get_offset_type_desc_int())
                        r_bytes = generate_primitive_bytearray(model[f'{mem.name}'], mem.type_desc) 
                        root_array.extend(r_bytes)
                    else:
                        raise ValueError(f"Value of type is must be a string instead of {type(model[f'{mem.name}'])}")
                else:
                    r_bytes = generate_primitive_bytearray(model[f'{mem.name}'], mem.type_desc) 
                    root_array[mem.offset:mem.offset + mem.size] = r_bytes
                
            elif not mem.type_desc.is_offset_type():
                for s_mem in mem.type_desc.members:
                    curr_offset = mem.offset+ s_mem.offset 
                    if not s_mem.is_offset_type:
                        root_array[curr_offset :curr_offset+ s_mem.size] = generate_byte(model[f'{mem.name}'][f'{s_mem.name}'], s_mem.type_desc)
                    else:
                        if s_mem.is_array:
                            temp_bytes = generate_array_byte(model[f'{mem.name}'][f'{s_mem.name}'], s_mem.type_desc)
                        else:
                            temp_bytes = generate_byte(model[f'{mem.name}'][f'{s_mem.name}'], s_mem.type_desc)
                        if len(temp_bytes) == 0:
                            offset1 = 0
                        else: 
                            offset1 = (len(root_array) - curr_offset)
                        root_array[curr_offset :curr_offset+ s_mem.size] = generate_primitive_bytearray(offset1, get_offset_type_desc_int())
                        root_array.extend(temp_bytes)
            elif mem.type_desc.type_type == 'union':
                if f'{mem.name}_type' in model and f'{mem.name}' in model and model[f'{mem.name}'] != None:
                    root_array[mem.offset:mem.offset + mem.type_desc.size] = generate_primitive_bytearray(len(root_array) - mem.offset , get_offset_type_desc_int())
                    union_type_str = model[f'{mem.name}_type']
                    
                    union_type = get_type_desc_from_types_desc(union_type_str)
                    if union_type == None:
                        raise ValueError(f"Type specified for union {union_type_str}. Type must be of one of {mem.type_desc.u_members}")
                    root_array.extend( generate_byte(model[f'{mem.name}'],union_type) )
                            
                else:
                   root_array[mem.offset:mem.offset + mem.type_desc.size]  = generate_primitive_bytearray(0, get_offset_type_desc_int())
                    
            elif mem.type_desc.is_offset_type():
                temp_bytes = generate_byte(model[f'{mem.name}'], mem.type_desc)
                if len(temp_bytes) == 0:
                    offset1 = 0
                else: 
                    offset1 = (len(root_array) - mem.offset)
                root_array[mem.offset:mem.offset + mem.type_desc.size] = generate_primitive_bytearray(offset1, get_offset_type_desc_int())
                root_array.extend(temp_bytes)
        return root_array
    else:
            raise ValueError("fdghj")
                    
                        
        
    
    
root_type_name = model['root_type']

root_type = get_type_from_json(root_type_name)
set_all_types()
set_needed_types(root_type)
if not needed_types.issubset(all_types):
    raise ValueError("All the needed type must be a subset of all type known.")
print(needed_types)


for t in (compute_all_types_desc(needed_types)):
    print(t,"\n")
print(f"Type Desc length is {len(types_desc)}")
bin = generate_byte(model1,cast(TypeDesc, get_type_desc_from_types_desc (root_type_name)))
with open("model1.bin2", 'wb') as f:
    f.write(bin)
