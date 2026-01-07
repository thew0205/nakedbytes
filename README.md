# NakedBytes

NakedBytes is an efficient serialization specification designed for low-size binary formats while maintaining fast read performance. It is intended for use across embedded devices to large servers, particularly in resource-constrained environments like energy-sector and industrial applications.

This project provides tools for generating compact binary representations from JSON schemas, along with code generation for C++ serialization and deserialization.

## Features

- **Compact Binary Format**: Produces highly efficient serialized data with minimal overhead.
- **Schema-Driven**: Uses JSON schemas to define data structures.
- **Code Generation**: Automatically generates C++ code for serialization and deserialization.
- **Cross-Platform**: Works on embedded devices (e.g., RP2350) and general-purpose systems (e.g., Ubuntu).
- **Compatibility**: Supports forward and backward compatibility for schema evolution.
- **Performance Optimized**: Focuses on fast deserialization and low memory usage.

## Installation

### Prerequisites

- Python 3.6+
- CMake (for building C++ components)

### Setup

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/nakedbytes.git
   cd nakedbytes
   ```

2. Install Python dependencies:
   ```bash
   pip install -r requirements.txt
   ```

3. Build the project (if needed):
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

## Usage

### Command Line Tool

The main tool is `nakedbytes.py` in the `code_implementation/` directory.

#### Generate C++ Code

```bash
python code_implementation/nakedbytes.py schema.json --cpp output_dir
```

This generates C++ header files for the defined schema.

#### Serialize JSON to Binary

```bash
python code_implementation/nakedbytes.py schema.json -b data.json -o output_dir
```

This serializes the JSON data according to the schema and outputs a `.bin` file.

### Schema Format

Schemas are defined in JSON format. Example:

```json
{
  "root_type": "MyStruct",
  "version": 1,
  "offset_size": 2,
  "types": {
    "MyStruct": {
      "type": "struct",
      "fields": [
        {"name": "field1", "type": "uint32"},
        {"name": "field2", "type": "string"}
      ]
    }
  }
}
```

### C++ Integration

Include the generated header files in your C++ project and use the provided serialization/deserialization functions.

## Examples

See the `test/` directory for various examples, including:

- Simple structures
- Arrays and unions
- SunSpec model integration
- Struct offsets

Run a test example:

```bash
cd test/test_simple_example
python test_simple_example.py
```

## Research and Benchmarks

This project includes a comprehensive research paper comparing NakedBytes with FlatBuffers and Protocol Buffers. The paper evaluates performance across:

- Binary size
- Code size and static memory
- Computation time (serialization/deserialization)
- Runtime memory usage
- Compatibility features

Benchmarks were conducted on both general-purpose PCs and embedded devices (RP2350).

See `research_paper/naked_byte_research_paper.tex` for the full paper.

## Project Structure

- `code_implementation/`: Core Python implementation
- `models/`: Model definitions and utilities
- `nanopb/`: Integration with nanopb (Protocol Buffers for embedded)
- `sunspec/`: SunSpec model examples
- `test/`: Test cases and examples
- `research_paper/`: Academic paper and benchmarks
- `tflite/`: TensorFlow Lite integration
- `white_paper/`: Documentation

## Contributing

Contributions are welcome! Please:

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Add tests if applicable
5. Submit a pull request

## License

This project is licensed under the Apache License 2.0. See `models/LICENSE` for details.

## Pending Issues

- Array of unions support
- Null value handling for classes and missing values

## Contact

For questions or support, please open an issue on GitHub. 