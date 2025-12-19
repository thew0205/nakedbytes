

import json
import struct
from typing import Any, List, Dict, cast


from .type_utils import get_offset_type_int, get_padding_size, get_real_type_name, get_type_from_json




primitive_types = {'bool', 'char', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64', 'float32', 'float64', 'string', 'blob'}


def is_primitive_type(type_name):
    return type_name in primitive_types

    
    
def get_offset_type_desc_int(offset_size:int, types_desc: set['TypeDesc']) -> 'TypeDesc':
    type_desc = get_type_desc_from_types_desc(get_offset_type_int(offset_size=offset_size), types_desc)
    if type_desc == None:
        raise ValueError(f"The offset type of {type_desc} is not allowed.")
    return type_desc

def get_type_desc_from_types_desc(type_name: str, types_desc: set['TypeDesc']) -> 'TypeDesc|None':
    for t in types_desc:
        if t.name == type_name:
            return t
    return None

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
        self.is_offset_type: bool = type_type in ['struct_offset', 'class', 'union'] or name in ['string', 'blob']
        
        self.size: int = 0
        self.unpadded_size = 0
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
        
    # def is_offset_type(self) -> bool:
    #     return self.type_type in ['struct_offset', 'class', 'union']
    def can_contain_member(self) -> bool:
        return self.type_type in ['struct', 'struct_offset', 'class']
     
    def add_member(self,name: str, type_type: str, is_array: bool, default_value,parent_types: List[str], offset_size: int, types_desc: set['TypeDesc'], model_def: Dict)-> None:
        if not self.can_contain_member():
            raise ValueError(f"This type must of either struct, struct_offset or class to be able to add a member but type is of {self.type_type}")
        else:
            # Pop the last pad
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
                real_type: TypeDesc = compute_add_type_desc(type_type, types_desc, model_def, offset_size=offset_size, parent_types=parent_types)
                if real_type is None:
                    raise ValueError("Type must be specified for MemberDesc")
                else: 
                    if real_type.is_offset_type or is_array:
                        mem_size = offset_size
                        mem_alignment = offset_size
                    else:
                        mem_size = real_type.size
                        mem_alignment = real_type.alignment
                    
            if real_type.type_type == 'union' and (not is_array):
                self.add_member(name= f"{name}_type", type_type=f"{type_type}_enum", is_array=False, default_value=None, parent_types=parent_types, offset_size=offset_size, types_desc=types_desc,model_def= model_def)
            self.alignment = max(mem_alignment, self.alignment)
            
            
            padding = get_padding_size(self.size, mem_alignment)
            if padding > 0:
                mem_pad = MemberDesc(f'pad{self.size}', cast(TypeDesc,get_type_desc_from_types_desc(f'pad{padding}', types_desc)), False, default_value=None,offset=self.size, size=padding, alignment=1)
                self.members.append(mem_pad)
                self.set_size(self.size + padding)
                
            member = MemberDesc(name=name,type_type=real_type, is_array=is_array, default_value=default_value, offset=self.size,size=mem_size, alignment=mem_alignment)
                
            self.members.append(member)
            self.set_size(self.size + member.size)
            self.unpadded_size = self.size
            
            padding = get_padding_size(self.size, self.alignment)
            if padding > 0:
                mem_pad = MemberDesc(f'pad{self.size}', cast(TypeDesc,get_type_desc_from_types_desc(f'pad{padding}', types_desc)), False,default_value=None, offset=self.size, size=padding, alignment=1)
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
        return f'TypeDesc(name={self.name}, size={self.size}, type={self.type_type}, alignment={self.alignment}, is_primitive={self.is_primitive}, members=\n{[str(m)  for m in members]})'
    
    @staticmethod
    def gen_primitive_type(name: str, size: int, alignment: int) -> 'TypeDesc':
        typeDesc = TypeDesc(name=name, is_primitive= True, type_type='struct')
        typeDesc.set_alignment(alignment)
        typeDesc.set_size(size)
        return typeDesc
    
    @staticmethod
    def generate_enum_type(name: str, base_type: str, enums: List, types_desc: set['TypeDesc']):
        enums = [{'name': f"{name}_{enu['name']}"} for enu in enums]
        real_base_type = get_type_desc_from_types_desc(base_type, types_desc)
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
    def gen_union_type(name: str, members: List, offset_size: int, types_desc: set['TypeDesc'], model_def: dict, parent_types: list[str]) -> 'TypeDesc':
        type_desc = TypeDesc(name=name, is_primitive= False,type_type='union')
        for mem in members:
            if mem['name'] == None:
                raise ValueError("Name of the union type member not specified.")
            real_mem_type = compute_add_type_desc(mem['name'], types_desc, model_def, offset_size=offset_size, parent_types=parent_types)
            if real_mem_type == None:
                raise ValueError("Union member type doesn't exist")
            type_desc.add_u_members(real_mem_type)
        type_desc.set_alignment(offset_size)
        type_desc.set_size(offset_size)
        return type_desc
    
    @staticmethod
    def gen_struct_type(name: str, type_type: str, members: List, offset_size: int, types_desc: set['TypeDesc'], model_def: dict, parent_types: list[str])-> 'TypeDesc':
        type_desc = TypeDesc(name=name, type_type=type_type, is_primitive=False)
        for member in members:
            type_desc.add_member(name=member['name'],type_type=get_real_type_name( member['type']), is_array=get_type_is_vector(member['type']),default_value=member.get('default_value', None),parent_types=parent_types, offset_size=offset_size, model_def=model_def, types_desc=types_desc)
        return type_desc
    
    @staticmethod
    def gen_class_type(name: str, type_type: str, members: List, offset_size: int, types_desc: set['TypeDesc'], model_def: dict, parent_types: list[str])-> 'TypeDesc':
        type_desc = TypeDesc(name=name, type_type=type_type, is_primitive=False)
        type_desc.set_size(type_desc.size + offset_size)
        for member in members:
            type_desc.add_member(name=member['name'],type_type=get_real_type_name( member['type']), is_array=get_type_is_vector(member['type']), default_value= member.get('default_value', None),parent_types=parent_types, offset_size=offset_size, model_def=model_def, types_desc=types_desc)
        return type_desc
    
    @staticmethod
    def generate_pad(size: int) -> 'TypeDesc':
        type_desc = TypeDesc(name=f'pad{size}', is_primitive= True,type_type='struct')
        type_desc.set_size(size)
        type_desc.set_alignment(1)
        return type_desc
    
    @staticmethod
    def get_primitive_types_desc(offset_size: int) -> set['TypeDesc']:
        return {
            TypeDesc.gen_primitive_type(name='bool',size= 1, alignment=1),
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
    
class MemberDesc:
    def __init__(self, name: str, type_type: TypeDesc, is_array: bool, offset: int, size: int, alignment: int, default_value) -> None:
        
        
        self.name: str = name
        self.type_desc: TypeDesc = type_type
        self.offset: int = offset
        self.is_array: bool = is_array
        self.is_offset_type: bool = is_array or type_type.is_offset_type or type_type.name in ['string', 'blob']
        self.size: int = size
        self.alignment: int = alignment
        self.default_value = self.set_default_value(default_value)
        
        
    def set_default_value(self, default_value) -> Any:
        if (self.type_desc.is_primitive or self.type_desc.type_type == 'enum') and (not self.is_array):
            if default_value == None:
                if self.type_desc.type_type == 'enum':
                    return 0
                
                elif self.type_desc.name in ['bool', 'char', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64', 'float32', 'float64']:
                    return 0
                elif self.type_desc.name in ['string', 'blob']:
                    return None
                else:
                    return None
            else:
                if self.type_desc.type_type == 'enum':
                    if isinstance(default_value, int) or isinstance(default_value, str):
                        for enu in self.type_desc.e_members:
                            if (isinstance(default_value, int) and enu.value == default_value) or (isinstance(default_value, str) and enu.name == default_value):
                                return default_value
                        else:
                            raise ValueError(f"Default value for enum type must be of int or str type but got {type(default_value)}")
                    else:
                        raise ValueError(f"Default value for enum type must be of int type but got {type(default_value)}")
                if self.type_desc.name == 'bool':
                    if isinstance(default_value, bool):
                        return default_value
                    else:
                        raise ValueError(f"Default value for bool type must be of bool type but got {type(default_value)}")
                elif self.type_desc.name == 'char':
                    if isinstance(default_value, str) and len(default_value) == 1:
                        return default_value
                    else:
                        raise ValueError(f"Default value for char type must be of str type with length 1 but got {default_value}")
                elif self.type_desc.name in ['int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']:
                    if isinstance(default_value, int):
                        return default_value
                    else:
                        raise ValueError(f"Default value for {self.type_desc.name} type must be of int type but got {type(default_value)}")
                elif self.type_desc.name in ['float32', 'float64']:
                    if isinstance(default_value, float) or isinstance(default_value, int):
                        return float(default_value)
                    else:
                        raise ValueError(f"Default value for {self.type_desc.name} type must be of float type but got {type(default_value)}")
                elif self.type_desc.name in ['string', 'blob']:
                    if isinstance(default_value, str):
                        return default_value
                    else:
                        raise ValueError(f"Default value for {self.type_desc.name} type must be of str type but got {type(default_value)}")
                else:    
                    return None
            
        else:
            return None

    def __str__(self) -> str:
        return f'MemberDesc(name={self.name}, type={'List[' if self.is_array  else ''}{self.type_desc.name}{']' if self.is_array else ''}, size={self.size}, offset={self.offset}, alignment={self.alignment}, is_array={self.is_array}, default_value={self.default_value})'
        



        


def get_type_is_vector(type_name: str) -> bool:
    first_bracket_index = type_name.find('[')
    last_bracket_index = type_name.find(']')
    if  first_bracket_index != -1 and last_bracket_index != -1:
        return type_name[0: first_bracket_index] == 'vector'
    return False


def members_contain_union_recursively(type_json: Dict, model_def: Dict, offset_size: int) -> bool:
    for mem in type_json["members"]:
        mem_type = get_real_type_name(mem['type'])
        if is_primitive_type(mem_type):
            continue
       
        type_json = get_type_from_json(mem_type, model_def)
        if type_json['type'] == 'enum':
            return False
        if type_json['type'] == 'union':
            return True
        it_has  =  members_contain_union_recursively(get_type_from_json(mem_type, model_def), model_def, offset_size)
        if it_has:
            return True
    return False

def compute_add_type_desc(type_name: str, types_desc: set['TypeDesc'], model_def: Dict, offset_size: int, parent_types: List[str]) -> TypeDesc:
    type_desc_from_types_desc = get_type_desc_from_types_desc(type_name, types_desc)
    if type_desc_from_types_desc != None:
        return type_desc_from_types_desc
    
    type_def = get_type_from_json(type_name, model_def)

    if type_def['type'] == 'enum':
        type_desc = TypeDesc.generate_enum_type(type_def['name'], type_def['base_type'], type_def['enums'], types_desc)
        types_desc.add(type_desc)
        return type_desc
    elif type_def['type'] == 'union':
        types_desc.add(TypeDesc.generate_enum_type(f"{type_def['name']}_enum", get_offset_type_int(offset_size), type_def['unions'],types_desc))
        type_desc =  TypeDesc.gen_union_type(type_def['name'],type_def['unions'],offset_size, types_desc, model_def,parent_types)
        types_desc.add(type_desc)
        return type_desc
    elif type_def['type'] in ['struct', 'struct_offset']:
        parent_types.append(type_def['name'])
        
        type_desc = TypeDesc.gen_struct_type(name=type_def['name'], type_type=type_def['type'], members=type_def['members'], offset_size=offset_size, model_def=model_def, parent_types=parent_types, types_desc=types_desc)
        
        types_desc.add(type_desc)
        parent_types.pop()
        
        return type_desc
    elif type_def['type'] == 'class':
        parent_types.append(type_def['name'])
        
        type_desc = TypeDesc.gen_class_type(name=type_def['name'], type_type=type_def['type'], members=type_def['members'], offset_size=offset_size, model_def=model_def, parent_types=parent_types, types_desc=types_desc)
        
        types_desc.add(type_desc)
        parent_types.pop()
        
        return type_desc
    else:
        raise ValueError(f"The type of this type which is {type_def['type']} is not supported")  
    

def compute_all_types_desc(types: set[str], model_def: Dict, offset_size: int, parent_types: List[str], types_desc: set[TypeDesc]):
    for type_name in types:
        if is_primitive_type(type_name):
            continue
        compute_add_type_desc(type_name = type_name, types_desc=types_desc, model_def=model_def, offset_size=offset_size, parent_types=parent_types)
    return types_desc