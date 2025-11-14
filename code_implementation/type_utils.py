


def get_padding_size(offset: int, alignment: int) -> int:
    return (alignment - (offset % alignment)) % alignment

def get_next_valid_offset(offset: int, alignment: int) -> int:
    return offset + get_padding_size(offset, alignment)

