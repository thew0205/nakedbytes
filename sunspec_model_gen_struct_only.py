import json
import struct
from typing import List

model = {}
with open('sunspec_model.json', 'r') as f:
    model = json.load(f)
model1 = {}
with open('model_1.json', 'r') as f:
    model1 = json.load(f)
offset_size = 4 if model.get('offset_size') is None else model['offset_size']  # Size of the 'offset' type in bytes
primitive_types = {
    ('char',1,1),('int8',1,1), ('uint8',1,1), ('int16',2,2), ('uint16',2,2), ('int32',4,4), ('uint32',4,4), ( 'int64',8,8), ('uint64',8,8), ('float32',4), ('float64',8), ('string', offset_size, offset_size)}
types = {'char', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64', 'float32', 'float64', 'string'}

class StraightTypeDesc:
    def __init__(self, name: str, members: List['MemberDesc'], typeDesc: 'TypeDesc') -> None:
        self.name: str = name
        self.members : List['MemberDesc']= members
        self.typeDesc: TypeDesc = typeDesc
    def __str__(self) -> str:
        return f'StraightTypeDesc(name={self.name}, members={[str(m) for m in self.members]})'

def typeDesc_to_StraightTypeDesc(typeDesc: 'TypeDesc') -> StraightTypeDesc:
    members: List['MemberDesc'] = []
    if typeDesc.type != 'struct':
        raise ValueError('Only type of struct is allowed.')
    for mem in typeDesc.s_members:
        if mem.type.is_primitive or mem.type.type in ['enum', 'union'] or mem.is_array:
            members.append(mem)
        else:
            s_type = get_straightTypeDesc(mem.name) 
            if s_type is  None:
                ty = get_size_from_types_size_alignment(mem.type.name)
                if ty is None:
                    raise ValueError("Ty must not be None")
                s_type = typeDesc_to_StraightTypeDesc(ty)
                
            tempMembers = [MemberDesc(name=f'{mem.name}::{m.name}', type= m.type, is_array=m.is_array, offset=mem.offset + m.offset) for m in s_type.members]
            members.extend(tempMembers)
    ret_straight_type_desc = StraightTypeDesc(name= typeDesc.name, members=members, typeDesc= typeDesc)
    straightTypeDescs.append(ret_straight_type_desc)
    return ret_straight_type_desc
                
def straight_model(model: dict) -> dict:
    ret: dict = {}
    for k, v in model.items():
        if isinstance(v, list):
            ret[k] = v
        elif not isinstance(v, dict) :
            ret[k] = v
        else:
            val = straight_model(v)
            for ki, vi in val.items():
                ret[f'{k}::{ki}'] = vi
    return ret
                
            
        
class TypeDesc:
    def __init__(self, name: str,  type: str, size: int = 0,alignment: int = 1,  is_primitive: bool= False, metadata = {}, s_members: List['MemberDesc'] = [],u_members: List['TypeDesc'] = [], e_members: List =[] , basetype: 'TypeDesc|None' = None) -> None:
        self.name: str = name
        self.size: int = size
        self.alignment: int = alignment
        self.s_members: List['MemberDesc']= s_members
        self.u_members = u_members
        self.e_members = e_members
        self.is_primitive = is_primitive
        self.metadata = metadata
        self.type = type
        self.basetype = basetype
        
    
    def __str__(self) -> str:
        members = self.u_members if self.u_members != [] else self.s_members if self.s_members != [] else self.e_members
        return f'TypeDesc(name={self.name}, size={self.size}, alignment={self.alignment}, is_primitive={self.is_primitive}, metadata={self.metadata}, members=\n{[str(m)  for m in members]})'
    
    @staticmethod
    def gen_primitive_type(name: str, size: int, alignment: int):
        return TypeDesc(name=name, size= size, alignment= alignment, is_primitive= True, type='struct') 
    
    @staticmethod
    def gen_struct_type(name: str, members: List['MemberDesc'], is_primitive: bool):
        size: int = 0
        max_alignment: int = 0
        for member in members:
            size += member.size
            if max_alignment < member.alignment:
                max_alignment = member.alignment
        offset_diff = get_next_valid_offset(size, alignment=max_alignment) - size
        if offset_diff > 0:
            mem = MemberDesc(f'pad{size}', get_size_from_types_size_alignment(f'pad{offset_diff}'), False, offset=size,)
            members.append(mem)
            size += mem.size
        ret = TypeDesc(name=name, size= size, alignment= max_alignment, is_primitive= is_primitive, s_members=members, type='struct')
        for member in members:
            if member.type is None:
                member.type = ret
        return ret
    @staticmethod
    def gen_list_type(name: str, basetype: str):
        return TypeDesc(name=name, is_primitive= False, type='array')
    @staticmethod
    def gen_union_type(name: str, members: List['TypeDesc']):
        return TypeDesc(name=name, is_primitive= False,u_members= members, type='union', size= offset_size,alignment= offset_size)
    @staticmethod
    def generate_enum_type(name: str, base_type: str, enums: List):
        type = get_size_from_types_size_alignment(base_type)
        if type is None:
            raise ValueError("Enum must be of a base type of one of the defined int types")
        size = type.size
        alignment = type.alignment
        return TypeDesc(name=name, size= size, alignment= alignment, is_primitive= False, e_members=enums, type= 'enum', basetype = type)
    
    
    # @staticmethod
    # def gen_offset_type(base_type: 'str', m_type: str):
    #     return TypeDesc(name='offset', size= offset_size, alignment= offset_size, is_primitive= False, metadata= {'m_type': m_type, 'base_type': base_type})
    @staticmethod
    def generate_pad(name: str, size: int):
        return TypeDesc(name=f'pad{size}', size= size, alignment= 1, is_primitive= True,type='struct' )
    
    
    @staticmethod
    def is_type_union(type_name: str) -> bool:
        type_def = compute_type_desc(type_name)
        if type_def is not None and type_def.metadata.get('m_type', None) == 'union':
            return True
        return False
    @staticmethod
    def get_offset_type_int() -> str:
        if offset_size == 2:
            return ('uint16')
        elif offset_size == 4:
            return ('uint32')
        elif offset_size == 8:
            return ('uint64')
        else: 
            return 'uint8'
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
    types_desc.add(TypeDesc.generate_pad(f'pad{i}', i) )
    
straightTypeDescs: List['StraightTypeDesc'] = []

def get_size_from_types_size_alignment(type_name) -> TypeDesc|None:
    for t in types_desc:
        if t.name == type_name:
            return t
    return None

def get_straightTypeDesc(type_name: str) -> StraightTypeDesc|None:
    for t in straightTypeDescs:
        if t.name == type_name:
            return t
    return None

class MemberDesc:
    def __init__(self, name: str, type: TypeDesc|None, is_array: bool, offset: int = 0) -> None:
        if type is None and not is_array:
            raise ValueError("If it is not an array then it must have a type")
        self.name = name
        self.type: TypeDesc = type
        self.offset = offset
        self.is_array = is_array
        if is_array:
            self.size = offset_size
            self.alignment = offset_size
        else:
            self.size = type.size
            self.alignment = type.alignment
        
    def __str__(self) -> str:
        return f'MemberDesc(name={self.name}, type={'List[' if self.is_array  else ''}{self.type.name}{']' if self.is_array else ''}, size={self.size}, offset={self.offset}, alignment={self.alignment})'
        

def get_all_types(root_type, types):
    
    if root_type['name'] in types:
        return types
    types.add(root_type['name'])
    members = root_type.get('members', [])
    for member in members:
        if not member['type']  in types:
            member_type = get_type(member['type'])
            types.update(get_all_types(member_type, types))
        
    return types
        
        


def is_primitive_type(type_name):
    # if type_name in ['string', 'blob', 'union']:
    #     return True
    for prim_type in primitive_types:
        if prim_type[0] == type_name:
            return True
    return False

def get_type(type_name):
    for model_type in model['types']:
        if model_type['name'] == type_name:
            return model_type


    
def get_primitive_size(type_name)-> int:
    for prim_type in primitive_types:
        if prim_type[0] == type_name:
            return prim_type[1]
    return None



def get_next_valid_offset(offset: int, alignment: int) -> int:
    rem = offset % alignment
    if rem != 0:
        offset += alignment - rem
    return offset

# def get_m_type(member) -> str:
#     if member.get('is_array') is not None and member['is_array']:
#         return 'array'
#     elif TypeDesc.is_type_union(member['type']):
#         return 'union'
#     return 'struct'

def compute_type_desc(type_name) -> TypeDesc:
    
    type_def = get_type(type_name)

    if get_size_from_types_size_alignment(type_name) is not None:
        return get_size_from_types_size_alignment(type_name)

    elif type_def['type'] == 'enum':
        return TypeDesc.generate_enum_type(type_def['name'], type_def['base_type'], type_def['enums'])
    elif type_def['type'] == 'union':
        types_desc.add(TypeDesc.generate_enum_type(f"{type_def['name']}_enum", TypeDesc.get_offset_type_int(), type_def['members']))
        return TypeDesc.gen_union_type(type_def['name'],[compute_type_desc(m['name']) for m in type_def['members']])
    
    elif type_def['type'] == 'struct':
        offset: int = 0
        # max_alignment: int = 0
        members: List[MemberDesc] =[]
        for member in type_def['members']: 
            if  member['type'] == type_name:
                if  member.get('is_array', False):
                    type = None
                else: 
                    raise ValueError("If it is not an array then it must have a type")
            # elif  member.get('is_array', False) or member['type'] in ['string', 'blob']:
                 
            elif get_size_from_types_size_alignment(member['type']) is  None:
                type = compute_type_desc(member['type'])
            else:
                type = get_size_from_types_size_alignment(member['type'])
            if type is not None and type.type == 'union':
                mem = MemberDesc(f'{member['name']}_type', get_size_from_types_size_alignment(f"{member['type']}_enum"), False , offset) 
                offset_diff = get_next_valid_offset(offset, alignment=mem.alignment) - offset
                if offset_diff > 0:
                    mem_pad = MemberDesc(f'pad{offset}', get_size_from_types_size_alignment(f'pad{offset_diff}'), False, offset=offset,)
                    members.append(mem_pad)
                    offset += mem_pad.size
                
                members.append(mem)
                offset += mem.size
            mem = MemberDesc(member['name'], type, member.get('is_array', False), offset) 
            offset_diff = get_next_valid_offset(offset, alignment=mem.alignment) - offset
            if offset_diff > 0:
                mem_pad = MemberDesc(f'pad{offset}', get_size_from_types_size_alignment(f'pad{offset_diff}'), False, offset=offset,)
                members.append(mem_pad)
                offset += mem_pad.size
            
            members.append(mem)
            
            offset += mem.size
        return TypeDesc.gen_struct_type(type_name, members=members, is_primitive=False)
            
             
    
def generate_primitive_bytearray(value, type: TypeDesc) -> bytearray:
    if value == None:
        return bytearray(b'\x00' * type.size)
    elif type.name == 'char':       
        return value.encode(encoding='ascii')[0:1]
    elif type.name == 'int8':
        val = int(value)
        return bytearray(struct.pack('b', val))
    elif type.name == 'uint8':
        val = int(value)
        return bytearray(struct.pack('B', val))
    elif type.name == 'int16':
        val = int(value)
        return bytearray(struct.pack('<h', val))
    elif type.name == 'uint16':
        val = int(value)
        return bytearray(struct.pack('<H', val))
    elif type.name == 'int32':
        val = int(value)
        return bytearray(struct.pack('<i', val))
    elif type.name == 'uint32':
        val = int(value)
        return bytearray(struct.pack('<I', val))
    elif type.name == 'int64':
        val = int(value)
        return bytearray(struct.pack('<q', val))
    elif type.name == 'uint64':
        val = int(value)
        return bytearray(struct.pack('<Q', val))
    elif type.name == 'float32':
        val = float(value)
        return bytearray(struct.pack('<f', val))
    elif type.name == 'float64':
        val = float(value)
        return bytearray(struct.pack('<d', val))
    elif type.name == 'string':
        item_byte: bytearray = generate_primitive_bytearray(len(value), get_size_from_types_size_alignment(TypeDesc.get_offset_type_int()))
        item_byte.extend(value.encode(encoding='ascii'))
        item_byte.append(0x00)
        return item_byte
    elif type.name == 'offset':
        val = int(value)
        if offset_size == 2:
            return bytearray(struct.pack('<H', val))
        elif offset_size == 4:
            return bytearray(struct.pack('<I', val))
        elif offset_size == 8:
            return bytearray(struct.pack('<Q', val))
    else:
        raise ValueError(f"Unsupported primitive type: {type.name}")
def generate_union_byte(model, type: TypeDesc, member_type: str) -> bytearray:
    return generate_byte(model, get_straightTypeDesc(member_type))
    if f'{member.name}_type' in model and f'{member.name}' in model:
        byte_array[type.offset:type.offset + type.size] = generate_primitive_bytearray(len(byte_array), get_size_from_types_size_alignment(TypeDesc.get_offset_type_int()))
        item_bytes = generate_byte(model[f'{member.name}'], type)
        byte_array.extend(item_bytes)
        generate_primitive_bytearray(model[f'{member.name}_type'], get_size_from_types_size_alignment(f"{member.type.name}_enum"))
    else:
        byte_array[member.offset:member.offset + member.type.size] = b'\x00' * offset_size
    
    pass
def generate_array_byte(model, type: TypeDesc) -> bytearray:
    byte_array = bytearray(offset_size*( len(model) + 1))
    byte_array[0:offset_size] = generate_primitive_bytearray(len(model), get_size_from_types_size_alignment(TypeDesc.get_offset_type_int()))
    for i, item in enumerate(model):
        item_bytes = generate_byte(item, get_straightTypeDesc(type.name))
        byte_array_offset = offset_size + i * offset_size
        byte_array[byte_array_offset:  byte_array_offset+  offset_size]= generate_primitive_bytearray(len(byte_array) -(offset_size + offset_size * i ), get_size_from_types_size_alignment(TypeDesc.get_offset_type_int()))
        byte_array.extend(item_bytes)
        
    return byte_array
    
def generate_byte(model, str_type: StraightTypeDesc) -> bytearray:
    type = str_type.typeDesc
    
    
    if type.is_primitive:
        return generate_primitive_bytearray(model, type)
    byte_array = bytearray(type.size)
    for member in str_type.members:
        if member.name.startswith('pad'):
            byte_array[member.offset:member.offset + member.size] = b'\xa5' * member.size
        elif member.is_array:
            if model[f'{member.name}'] == None or model[f'{member.name}'] == []:
                byte_array[member.offset:member.offset + member.size] = b'\x00' * member.size
            else:
                byte_array[member.offset:member.offset + member.size] = generate_primitive_bytearray((len(byte_array) - member.offset), get_size_from_types_size_alignment(TypeDesc.get_offset_type_int()))
                item_byte =  generate_array_byte(model[f'{member.name}'], member.type)
                byte_array.extend(item_byte)   
        elif member.type.is_primitive:
            r_bytes = generate_primitive_bytearray(model[f'{member.name}'], member.type) 
            if member.type.name == 'string':
                byte_array[member.offset:member.offset + member.size] = generate_primitive_bytearray((len(byte_array) - member.offset), get_size_from_types_size_alignment(TypeDesc.get_offset_type_int()))
                byte_array.extend(r_bytes)
            else:
                byte_array[member.offset:member.offset + member.size] = r_bytes
        elif member.type.type == 'enum':
            for i, item in enumerate(member.type.e_members):
                if item['name'] == model[f'{member.name}']:
                    val = i
                    byte_array[member.offset:member.offset + member.size] =  generate_primitive_bytearray(val, member.type.basetype)
                    break
            else:
                raise ValueError(f"Enum value {item['name']}'] not found in enum {member.type.e_members}.")
        elif member.type.type == 'union':
            if f'{member.name}_type' in model and f'{member.name}' in model:
                byte_array[member.offset:member.offset + member.type.size] = generate_primitive_bytearray(len(byte_array), get_size_from_types_size_alignment(TypeDesc.get_offset_type_int()))
                byte_array.extend( generate_union_byte(model[f'{member.name}'], member.type, model[f'{member.name}_type']))
                        
            else:
                member_bytes = generate_byte(model[f'{member.name}'], member.type)
                raise ValueError("dsfghjk")
                byte_array[member.offset:member.offset + member.type.size] = member_bytes
        
        # pass
    return byte_array

def compute_all_types_desc(types):
    for type_name in types:
        size = compute_type_desc(type_name)
        types_desc.add(size)
    return types_desc
            
root_type_name = model['root_type']

root_type = get_type(root_type_name)
get_all_types(root_type, types)
print(types)
for t in (compute_all_types_desc(types)):
    print(t)
    
for t in types_desc:
    if t.type != 'struct':
        continue
    print(typeDesc_to_StraightTypeDesc(t),"\n")
    
for k,v in(straight_model(model1).items()):
    print(k, v)
bin = generate_byte(straight_model(model1), get_straightTypeDesc(root_type_name))
with open("model1.bin", 'wb') as f:
    f.write(bin)
