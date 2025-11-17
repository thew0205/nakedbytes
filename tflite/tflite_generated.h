
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define OFFSET_SIZE 2



struct DimensionMetadata; 
struct DimensionMetadataOffset; 
struct TileOptions; 
struct TileOptionsOffset; 
struct EqualOptions; 
struct EqualOptionsOffset; 
struct ShapeOptions; 
struct ShapeOptionsOffset; 
struct PowOptions; 
struct PowOptionsOffset; 
struct StableHLOCompositeOptions; 
struct StableHLOCompositeOptionsOffset; 
struct BuiltinOptions2; 
struct BuiltinOptions2Offset; 
struct ArgMinOptions; 
struct ArgMinOptionsOffset; 
struct StablehloConcatenateOptions; 
struct StablehloConcatenateOptionsOffset; 
struct FakeQuantOptions; 
struct FakeQuantOptionsOffset; 
struct SparseIndexVector; 
struct SparseIndexVectorOffset; 
struct Int32Vector; 
struct Int32VectorOffset; 
struct GreaterOptions; 
struct GreaterOptionsOffset; 
struct PackOptions; 
struct PackOptionsOffset; 
struct Uint16Vector; 
struct Uint16VectorOffset; 
struct LogicalOrOptions; 
struct LogicalOrOptionsOffset; 
struct Pool2DOptions; 
struct Pool2DOptionsOffset; 
struct OneHotOptions; 
struct OneHotOptionsOffset; 
struct SVDFOptions; 
struct SVDFOptionsOffset; 
struct SplitVOptions; 
struct SplitVOptionsOffset; 
struct LogicalNotOptions; 
struct LogicalNotOptionsOffset; 
struct UnpackOptions; 
struct UnpackOptionsOffset; 
struct FloorDivOptions; 
struct FloorDivOptionsOffset; 
struct DynamicUpdateSliceOptions; 
struct DynamicUpdateSliceOptionsOffset; 
struct VariantSubType; 
struct VariantSubTypeOffset; 
struct ExpandDimsOptions; 
struct ExpandDimsOptionsOffset; 
struct SquareOptions; 
struct SquareOptionsOffset; 
struct StablehloShiftLeftOptions; 
struct FullyConnectedOptions; 
struct FullyConnectedOptionsOffset; 
struct ZerosLikeOptions; 
struct ZerosLikeOptionsOffset; 
struct ArgMaxOptions; 
struct ArgMaxOptionsOffset; 
struct FillOptions; 
struct FillOptionsOffset; 
struct StablehloBroadcastInDimOptions; 
struct StablehloBroadcastInDimOptionsOffset; 
struct StablehloCaseOptions; 
struct StablehloCaseOptionsOffset; 
struct SplitOptions; 
struct SplitOptionsOffset; 
struct BidirectionalSequenceLSTMOptions; 
struct BidirectionalSequenceLSTMOptionsOffset; 
struct BidirectionalSequenceRNNOptions; 
struct BidirectionalSequenceRNNOptionsOffset; 
struct Metadata; 
struct MetadataOffset; 
struct DensifyOptions; 
struct DensifyOptionsOffset; 
struct StablehloSliceOptions; 
struct StablehloSliceOptionsOffset; 
struct LessOptions; 
struct LessOptionsOffset; 
struct StablehloConvolutionOptions; 
struct StablehloConvolutionOptionsOffset; 
struct CumsumOptions; 
struct CumsumOptionsOffset; 
struct StablehloCustomCallOptions; 
struct StablehloCustomCallOptionsOffset; 
struct RNNOptions; 
struct RNNOptionsOffset; 
struct SoftmaxOptions; 
struct SoftmaxOptionsOffset; 
struct UnidirectionalSequenceLSTMOptions; 
struct UnidirectionalSequenceLSTMOptionsOffset; 
struct LeakyReluOptions; 
struct LeakyReluOptionsOffset; 
struct SignatureDef; 
struct SignatureDefOffset; 
struct NotEqualOptions; 
struct NotEqualOptionsOffset; 
struct Buffer; 
struct BufferOffset; 
struct TensorMap; 
struct TensorMapOffset; 
struct ScatterNdOptions; 
struct ScatterNdOptionsOffset; 
struct SelectOptions; 
struct SelectOptionsOffset; 
struct ConcatenationOptions; 
struct ConcatenationOptionsOffset; 
struct FloorModOptions; 
struct FloorModOptionsOffset; 
struct Operator; 
struct OperatorOffset; 
struct Uint8Vector; 
struct Uint8VectorOffset; 
struct LessEqualOptions; 
struct LessEqualOptionsOffset; 
struct AddOptions; 
struct AddOptionsOffset; 
struct RangeOptions; 
struct RangeOptionsOffset; 
struct Model; 
struct ModelOffset; 
struct StablehloGatherOptions; 
struct StablehloGatherOptionsOffset; 
struct BuiltinOptions; 
struct BuiltinOptionsOffset; 
struct QuantizationParameters; 
struct QuantizationParametersOffset; 
struct L2NormOptions; 
struct L2NormOptionsOffset; 
struct ConcatEmbeddingsOptions; 
struct ConcatEmbeddingsOptionsOffset; 
struct ResizeNearestNeighborOptions; 
struct ResizeNearestNeighborOptionsOffset; 
struct SquaredDifferenceOptions; 
struct SquaredDifferenceOptionsOffset; 
struct LocalResponseNormalizationOptions; 
struct LocalResponseNormalizationOptionsOffset; 
struct MirrorPadOptions; 
struct MirrorPadOptionsOffset; 
struct LSTMOptions; 
struct LSTMOptionsOffset; 
struct StablehloReduceOptions; 
struct StablehloReduceOptionsOffset; 
struct AbsOptions; 
struct AbsOptionsOffset; 
struct ReduceWindowOptions; 
struct ReduceWindowOptionsOffset; 
struct UniqueOptions; 
struct UniqueOptionsOffset; 
struct ReverseV2Options; 
struct ReverseV2OptionsOffset; 
struct ResizeBilinearOptions; 
struct ResizeBilinearOptionsOffset; 
struct AddNOptions; 
struct AddNOptionsOffset; 
struct StablehloScatterOptions; 
struct StablehloScatterOptionsOffset; 
struct GatherNdOptions; 
struct GatherNdOptionsOffset; 
struct CosOptions; 
struct CosOptionsOffset; 
struct QuantizationDetails; 
struct QuantizationDetailsOffset; 
struct WhereOptions; 
struct WhereOptionsOffset; 
struct RankOptions; 
struct RankOptionsOffset; 
struct ReverseSequenceOptions; 
struct ReverseSequenceOptionsOffset; 
struct StablehloCompareOptions; 
struct StablehloCompareOptionsOffset; 
struct MatrixDiagOptions; 
struct MatrixDiagOptionsOffset; 
struct CustomQuantization; 
struct CustomQuantizationOffset; 
struct CallOptions; 
struct CallOptionsOffset; 
struct BlockwiseQuantization; 
struct QuantizeOptions; 
struct QuantizeOptionsOffset; 
struct MatrixSetDiagOptions; 
struct MatrixSetDiagOptionsOffset; 
struct HardSwishOptions; 
struct HardSwishOptionsOffset; 
struct IfOptions; 
struct IfOptionsOffset; 
struct ReshapeOptions; 
struct ReshapeOptionsOffset; 
struct WhileOptions; 
struct WhileOptionsOffset; 
struct StablehloDotGeneralOptions; 
struct StablehloDotGeneralOptionsOffset; 
struct SkipGramOptions; 
struct SkipGramOptionsOffset; 
struct SpaceToDepthOptions; 
struct SpaceToDepthOptionsOffset; 
struct DepthToSpaceOptions; 
struct DepthToSpaceOptionsOffset; 
struct StablehloDynamicSliceOptions; 
struct StablehloDynamicSliceOptionsOffset; 
struct NonMaxSuppressionV4Options; 
struct NonMaxSuppressionV4OptionsOffset; 
struct EmbeddingLookupSparseOptions; 
struct EmbeddingLookupSparseOptionsOffset; 
struct NonMaxSuppressionV5Options; 
struct NonMaxSuppressionV5OptionsOffset; 
struct SelectV2Options; 
struct SelectV2OptionsOffset; 
struct StablehloRngBitGeneratorOptions; 
struct StablehloRngBitGeneratorOptionsOffset; 
struct SegmentSumOptions; 
struct SegmentSumOptionsOffset; 
struct BatchMatMulOptions; 
struct BatchMatMulOptionsOffset; 
struct MulOptions; 
struct MulOptionsOffset; 
struct CallOnceOptions; 
struct CallOnceOptionsOffset; 
struct StablehloPadOptions; 
struct StablehloPadOptionsOffset; 
struct StablehloIotaOptions; 
struct StablehloIotaOptionsOffset; 
struct PadOptions; 
struct PadOptionsOffset; 
struct BroadcastToOptions; 
struct BroadcastToOptionsOffset; 
struct DepthwiseConv2DOptions; 
struct DepthwiseConv2DOptionsOffset; 
struct GatherOptions; 
struct GatherOptionsOffset; 
struct StablehloReduceWindowOptions; 
struct StablehloReduceWindowOptionsOffset; 
struct Rfft2dOptions; 
struct Rfft2dOptionsOffset; 
struct BatchToSpaceNDOptions; 
struct BatchToSpaceNDOptionsOffset; 
struct Conv3DOptions; 
struct Conv3DOptionsOffset; 
struct LogicalAndOptions; 
struct LogicalAndOptionsOffset; 
struct HashtableOptions; 
struct HashtableOptionsOffset; 
struct OperatorCode; 
struct OperatorCodeOffset; 
struct Conv2DOptions; 
struct Conv2DOptionsOffset; 
struct SpaceToBatchNDOptions; 
struct SpaceToBatchNDOptionsOffset; 
struct TransposeOptions; 
struct TransposeOptionsOffset; 
struct StablehloSortOptions; 
struct StablehloSortOptionsOffset; 
struct ReducerOptions; 
struct ReducerOptionsOffset; 
struct SubOptions; 
struct SubOptionsOffset; 
struct DivOptions; 
struct DivOptionsOffset; 
struct SqueezeOptions; 
struct SqueezeOptionsOffset; 
struct HashtableFindOptions; 
struct HashtableFindOptionsOffset; 
struct StablehloWhileOptions; 
struct StablehloWhileOptionsOffset; 
struct SequenceRNNOptions; 
struct SequenceRNNOptionsOffset; 
struct StridedSliceOptions; 
struct StridedSliceOptionsOffset; 
struct HashtableImportOptions; 
struct HashtableImportOptionsOffset; 
struct UnsortedSegmentProdOptions; 
struct UnsortedSegmentProdOptionsOffset; 
struct ExpOptions; 
struct ExpOptionsOffset; 
struct StablehloTransposeOptions; 
struct StablehloTransposeOptionsOffset; 
struct HashtableSizeOptions; 
struct HashtableSizeOptionsOffset; 
struct VarHandleOptions; 
struct VarHandleOptionsOffset; 
struct ReadVariableOptions; 
struct ReadVariableOptionsOffset; 
struct DilateOptions; 
struct DilateOptionsOffset; 
struct AssignVariableOptions; 
struct AssignVariableOptionsOffset; 
struct RandomOptions; 
struct RandomOptionsOffset; 
struct BucketizeOptions; 
struct BucketizeOptionsOffset; 
struct TopKV2Options; 
struct TopKV2OptionsOffset; 
struct LogSoftmaxOptions; 
struct LogSoftmaxOptionsOffset; 
struct CastOptions; 
struct CastOptionsOffset; 
struct GeluOptions; 
struct GeluOptionsOffset; 
struct DequantizeOptions; 
struct DequantizeOptionsOffset; 
struct Tensor; 
struct TensorOffset; 
struct UnsortedSegmentMaxOptions; 
struct UnsortedSegmentMaxOptionsOffset; 
struct SubGraph; 
struct SubGraphOffset; 
struct LSHProjectionOptions; 
struct LSHProjectionOptionsOffset; 
struct MaximumMinimumOptions; 
struct MaximumMinimumOptionsOffset; 
struct UnsortedSegmentMinOptions; 
struct UnsortedSegmentMinOptionsOffset; 
struct NegOptions; 
struct NegOptionsOffset; 
struct UnsortedSegmentSumOptions; 
struct UnsortedSegmentSumOptionsOffset; 
struct PadV2Options; 
struct PadV2OptionsOffset; 
struct ATan2Options; 
struct ATan2OptionsOffset; 
struct GreaterEqualOptions; 
struct GreaterEqualOptionsOffset; 
struct SignOptions; 
struct SignOptionsOffset; 
struct SliceOptions; 
struct SliceOptionsOffset; 
struct BitcastOptions; 
struct BitcastOptionsOffset; 
struct TransposeConvOptions; 
struct TransposeConvOptionsOffset; 
struct BitwiseXorOptions; 
struct BitwiseXorOptionsOffset; 
struct SparseToDenseOptions; 
struct SparseToDenseOptionsOffset; 
struct SparsityParameters; 
struct SparsityParametersOffset; 
struct RightShiftOptions; 
struct RightShiftOptionsOffset; 



struct StringOffset
{
    unsigned char *data;
    StringOffset(unsigned char *dataPtr)
    {
        data = dataPtr;
    }

#define STRING_LENGTH_OFFSET 0
    uint16_t length()
    {
        uint16_t offset = *reinterpret_cast<uint16_t *>(data) + STRING_LENGTH_OFFSET;
        return *reinterpret_cast<uint16_t *>(data[offset]);
    }

#define STRING_VALUE_OFFSET 2
    const char *value()
    {
        uint16_t offset = *reinterpret_cast<uint16_t *>(data) + STRING_VALUE_OFFSET;
        return reinterpret_cast<const char *>(&data[offset]);
    }

    bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(&data[0]) == 0;
    }
};

template <typename T>
struct Union
{
    unsigned char *data;
    Union(unsigned char *dataPtr)
    {
        data = dataPtr;
    }

#define UNION_TYPE_OFFSET 0
    uint16_t type()
    {
        return *reinterpret_cast<uint16_t *>(&data[UNION_TYPE_OFFSET]);
    }

#define DATA_OFFSET 2
    unsigned char *raw_data()
    {
        int16_t offset = *reinterpret_cast<uint16_t *>(&data[DATA_OFFSET]) + DATA_OFFSET;

        return (&data[offset]);
    }
    
    bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(&data[DATA_OFFSET]) == 0;
    }
};

template <typename T>
struct Vector
{
    unsigned char *data;

    bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(&data[0]) == 0;
    }
    
    uint16_t size()
    {
        int16_t offset =  *reinterpret_cast<uint16_t *>(&data[0]);
        return *reinterpret_cast<uint16_t *>(&data[offset]);
    }

    T get(size_t index)
    {
        int16_t offset =  *reinterpret_cast<uint16_t *>(&data[0]) + OFFSET_SIZE + OFFSET_SIZE * index;
       

        return T(&data[offset]);
    }

    Vector(unsigned char *dataPtr)
    {
        data = dataPtr;
    }
};


enum DimensionType : int8_t {

DimensionType_DENSE,
DimensionType_SPARSE_CSR,
};

const char * DimensionType_to_string(DimensionType value){switch (value){case DimensionType_DENSE:return "DimensionType_DENSE";case DimensionType_SPARSE_CSR:return "DimensionType_SPARSE_CSR";default: return NULL;}}enum SparseIndexVector_enum : uint16_t {

SparseIndexVector_enum_Int32Vector,
SparseIndexVector_enum_Uint16Vector,
SparseIndexVector_enum_Uint8Vector,
};

const char * SparseIndexVector_enum_to_string(SparseIndexVector_enum value){switch (value){case SparseIndexVector_enum_Int32Vector:return "SparseIndexVector_enum_Int32Vector";case SparseIndexVector_enum_Uint16Vector:return "SparseIndexVector_enum_Uint16Vector";case SparseIndexVector_enum_Uint8Vector:return "SparseIndexVector_enum_Uint8Vector";default: return NULL;}}

struct DimensionMetadata {

unsigned char * data_;

DimensionMetadata(unsigned char * data) : data_(data) {}

#define DIMENSIONMETADATA_MEMBER_SIZE_OFFSET 0
#define DIMENSIONMETADATA_FORMAT_OFFSET 2
#define DIMENSIONMETADATA_PAD3_OFFSET 3
#define DIMENSIONMETADATA_DENSE_SIZE_OFFSET 4
#define DIMENSIONMETADATA_ARRAY_SEGMENTS_TYPE_OFFSET 8
#define DIMENSIONMETADATA_PAD10_OFFSET 10
#define DIMENSIONMETADATA_ARRAY_SEGMENTS_OFFSET 12
#define DIMENSIONMETADATA_ARRAY_INDICES_TYPE_OFFSET 14
#define DIMENSIONMETADATA_ARRAY_INDICES_OFFSET 16
#define DIMENSIONMETADATA_PAD18_OFFSET 18


DimensionType format() {
if(DIMENSIONMETADATA_FORMAT_OFFSET < *reinterpret_cast<uint16_t *>(&data_[DIMENSIONMETADATA_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<DimensionType*>(&data_[DIMENSIONMETADATA_FORMAT_OFFSET ]);}}

int32_t dense_size() {if(DIMENSIONMETADATA_DENSE_SIZE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[DIMENSIONMETADATA_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[DIMENSIONMETADATA_DENSE_SIZE_OFFSET ]);}}

SparseIndexVector_enum array_segments_type() {
if(DIMENSIONMETADATA_ARRAY_SEGMENTS_TYPE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[DIMENSIONMETADATA_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<SparseIndexVector_enum*>(&data_[DIMENSIONMETADATA_ARRAY_SEGMENTS_TYPE_OFFSET ]);}}

Union<SparseIndexVector> array_segments(){if(DIMENSIONMETADATA_ARRAY_SEGMENTS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[DIMENSIONMETADATA_MEMBER_SIZE_OFFSET])){const int16_t offset = DIMENSIONMETADATA_ARRAY_SEGMENTS_OFFSET - 2;return Union<SparseIndexVector>(&data_[offset]);}}

SparseIndexVector_enum array_indices_type() {
if(DIMENSIONMETADATA_ARRAY_INDICES_TYPE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[DIMENSIONMETADATA_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<SparseIndexVector_enum*>(&data_[DIMENSIONMETADATA_ARRAY_INDICES_TYPE_OFFSET ]);}}

Union<SparseIndexVector> array_indices(){if(DIMENSIONMETADATA_ARRAY_INDICES_OFFSET < *reinterpret_cast<uint16_t *>(&data_[DIMENSIONMETADATA_MEMBER_SIZE_OFFSET])){const int16_t offset = DIMENSIONMETADATA_ARRAY_INDICES_OFFSET - 2;return Union<SparseIndexVector>(&data_[offset]);}}

};



struct DimensionMetadataOffset {

unsigned char * data_;

DimensionMetadataOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

DimensionMetadata value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return DimensionMetadata(&data_[offset]);}};



struct TileOptions {

unsigned char * data_;

TileOptions(unsigned char * data) : data_(data) {}

#define TILEOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct TileOptionsOffset {

unsigned char * data_;

TileOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

TileOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return TileOptions(&data_[offset]);}};





struct EqualOptions {

unsigned char * data_;

EqualOptions(unsigned char * data) : data_(data) {}

#define EQUALOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct EqualOptionsOffset {

unsigned char * data_;

EqualOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

EqualOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return EqualOptions(&data_[offset]);}};

enum TensorType : uint8_t {

TensorType_FLOAT32,
TensorType_FLOAT16,
TensorType_INT32,
TensorType_UINT8,
TensorType_INT64,
TensorType_STRING,
TensorType_BOOL,
TensorType_INT16,
TensorType_COMPLEX64,
TensorType_INT8,
TensorType_FLOAT64,
TensorType_COMPLEX128,
TensorType_UINT64,
TensorType_RESOURCE,
TensorType_VARIANT,
TensorType_UINT32,
TensorType_UINT16,
TensorType_INT4,
TensorType_BFLOAT16,
};

const char * TensorType_to_string(TensorType value){switch (value){case TensorType_FLOAT32:return "TensorType_FLOAT32";case TensorType_FLOAT16:return "TensorType_FLOAT16";case TensorType_INT32:return "TensorType_INT32";case TensorType_UINT8:return "TensorType_UINT8";case TensorType_INT64:return "TensorType_INT64";case TensorType_STRING:return "TensorType_STRING";case TensorType_BOOL:return "TensorType_BOOL";case TensorType_INT16:return "TensorType_INT16";case TensorType_COMPLEX64:return "TensorType_COMPLEX64";case TensorType_INT8:return "TensorType_INT8";case TensorType_FLOAT64:return "TensorType_FLOAT64";case TensorType_COMPLEX128:return "TensorType_COMPLEX128";case TensorType_UINT64:return "TensorType_UINT64";case TensorType_RESOURCE:return "TensorType_RESOURCE";case TensorType_VARIANT:return "TensorType_VARIANT";case TensorType_UINT32:return "TensorType_UINT32";case TensorType_UINT16:return "TensorType_UINT16";case TensorType_INT4:return "TensorType_INT4";case TensorType_BFLOAT16:return "TensorType_BFLOAT16";default: return NULL;}}

struct ShapeOptions {

unsigned char * data_;

ShapeOptions(unsigned char * data) : data_(data) {}

#define SHAPEOPTIONS_MEMBER_SIZE_OFFSET 0
#define SHAPEOPTIONS_OUT_TYPE_OFFSET 2


TensorType out_type() {
if(SHAPEOPTIONS_OUT_TYPE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SHAPEOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<TensorType*>(&data_[SHAPEOPTIONS_OUT_TYPE_OFFSET ]);}}

};



struct ShapeOptionsOffset {

unsigned char * data_;

ShapeOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

ShapeOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return ShapeOptions(&data_[offset]);}};



struct PowOptions {

unsigned char * data_;

PowOptions(unsigned char * data) : data_(data) {}

#define POWOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct PowOptionsOffset {

unsigned char * data_;

PowOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

PowOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return PowOptions(&data_[offset]);}};

enum BuiltinOptions2_enum : uint16_t {

BuiltinOptions2_enum_StablehloConcatenateOptions,
BuiltinOptions2_enum_StablehloBroadcastInDimOptions,
BuiltinOptions2_enum_StablehloSliceOptions,
BuiltinOptions2_enum_StablehloConvolutionOptions,
BuiltinOptions2_enum_StablehloCustomCallOptions,
BuiltinOptions2_enum_StablehloReduceOptions,
BuiltinOptions2_enum_StablehloScatterOptions,
BuiltinOptions2_enum_StablehloCompareOptions,
BuiltinOptions2_enum_StablehloDynamicSliceOptions,
BuiltinOptions2_enum_StablehloPadOptions,
BuiltinOptions2_enum_StablehloIotaOptions,
BuiltinOptions2_enum_StablehloDotGeneralOptions,
BuiltinOptions2_enum_StablehloReduceWindowOptions,
BuiltinOptions2_enum_StablehloSortOptions,
BuiltinOptions2_enum_StablehloWhileOptions,
BuiltinOptions2_enum_StablehloGatherOptions,
BuiltinOptions2_enum_StablehloTransposeOptions,
BuiltinOptions2_enum_DilateOptions,
BuiltinOptions2_enum_StablehloRngBitGeneratorOptions,
BuiltinOptions2_enum_ReduceWindowOptions,
BuiltinOptions2_enum_StableHLOCompositeOptions,
BuiltinOptions2_enum_StablehloShiftLeftOptions,
BuiltinOptions2_enum_StablehloCaseOptions,
};

const char * BuiltinOptions2_enum_to_string(BuiltinOptions2_enum value){switch (value){case BuiltinOptions2_enum_StablehloConcatenateOptions:return "BuiltinOptions2_enum_StablehloConcatenateOptions";case BuiltinOptions2_enum_StablehloBroadcastInDimOptions:return "BuiltinOptions2_enum_StablehloBroadcastInDimOptions";case BuiltinOptions2_enum_StablehloSliceOptions:return "BuiltinOptions2_enum_StablehloSliceOptions";case BuiltinOptions2_enum_StablehloConvolutionOptions:return "BuiltinOptions2_enum_StablehloConvolutionOptions";case BuiltinOptions2_enum_StablehloCustomCallOptions:return "BuiltinOptions2_enum_StablehloCustomCallOptions";case BuiltinOptions2_enum_StablehloReduceOptions:return "BuiltinOptions2_enum_StablehloReduceOptions";case BuiltinOptions2_enum_StablehloScatterOptions:return "BuiltinOptions2_enum_StablehloScatterOptions";case BuiltinOptions2_enum_StablehloCompareOptions:return "BuiltinOptions2_enum_StablehloCompareOptions";case BuiltinOptions2_enum_StablehloDynamicSliceOptions:return "BuiltinOptions2_enum_StablehloDynamicSliceOptions";case BuiltinOptions2_enum_StablehloPadOptions:return "BuiltinOptions2_enum_StablehloPadOptions";case BuiltinOptions2_enum_StablehloIotaOptions:return "BuiltinOptions2_enum_StablehloIotaOptions";case BuiltinOptions2_enum_StablehloDotGeneralOptions:return "BuiltinOptions2_enum_StablehloDotGeneralOptions";case BuiltinOptions2_enum_StablehloReduceWindowOptions:return "BuiltinOptions2_enum_StablehloReduceWindowOptions";case BuiltinOptions2_enum_StablehloSortOptions:return "BuiltinOptions2_enum_StablehloSortOptions";case BuiltinOptions2_enum_StablehloWhileOptions:return "BuiltinOptions2_enum_StablehloWhileOptions";case BuiltinOptions2_enum_StablehloGatherOptions:return "BuiltinOptions2_enum_StablehloGatherOptions";case BuiltinOptions2_enum_StablehloTransposeOptions:return "BuiltinOptions2_enum_StablehloTransposeOptions";case BuiltinOptions2_enum_DilateOptions:return "BuiltinOptions2_enum_DilateOptions";case BuiltinOptions2_enum_StablehloRngBitGeneratorOptions:return "BuiltinOptions2_enum_StablehloRngBitGeneratorOptions";case BuiltinOptions2_enum_ReduceWindowOptions:return "BuiltinOptions2_enum_ReduceWindowOptions";case BuiltinOptions2_enum_StableHLOCompositeOptions:return "BuiltinOptions2_enum_StableHLOCompositeOptions";case BuiltinOptions2_enum_StablehloShiftLeftOptions:return "BuiltinOptions2_enum_StablehloShiftLeftOptions";case BuiltinOptions2_enum_StablehloCaseOptions:return "BuiltinOptions2_enum_StablehloCaseOptions";default: return NULL;}}

enum CustomOptionsFormat : int8_t {

CustomOptionsFormat_FLEXBUFFERS,
};

const char * CustomOptionsFormat_to_string(CustomOptionsFormat value){switch (value){case CustomOptionsFormat_FLEXBUFFERS:return "CustomOptionsFormat_FLEXBUFFERS";default: return NULL;}}

struct StableHLOCompositeOptions {

unsigned char * data_;

StableHLOCompositeOptions(unsigned char * data) : data_(data) {}

#define STABLEHLOCOMPOSITEOPTIONS_MEMBER_SIZE_OFFSET 0
#define STABLEHLOCOMPOSITEOPTIONS_NAME_OFFSET 2
#define STABLEHLOCOMPOSITEOPTIONS_DECOMPOSITION_SUBGRAPH_INDEX_OFFSET 4
#define STABLEHLOCOMPOSITEOPTIONS_COMPOSITE_ATTRIBUTES_OFFSET 8
#define STABLEHLOCOMPOSITEOPTIONS_COMPOSITE_ATTRIBUTES_FORMAT_OFFSET 10
#define STABLEHLOCOMPOSITEOPTIONS_PAD11_OFFSET 11
#define STABLEHLOCOMPOSITEOPTIONS_VERSION_OFFSET 12


StringOffset name(){if(STABLEHLOCOMPOSITEOPTIONS_NAME_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCOMPOSITEOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOCOMPOSITEOPTIONS_NAME_OFFSET ;return StringOffset(&data_[offset]);}}

int32_t decomposition_subgraph_index() {if(STABLEHLOCOMPOSITEOPTIONS_DECOMPOSITION_SUBGRAPH_INDEX_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCOMPOSITEOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[STABLEHLOCOMPOSITEOPTIONS_DECOMPOSITION_SUBGRAPH_INDEX_OFFSET ]);}}

Vector<uint8_t> composite_attributes(){if(STABLEHLOCOMPOSITEOPTIONS_COMPOSITE_ATTRIBUTES_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCOMPOSITEOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOCOMPOSITEOPTIONS_COMPOSITE_ATTRIBUTES_OFFSET ;return Vector<uint8_t>(&data_[offset]);}}

CustomOptionsFormat composite_attributes_format() {
if(STABLEHLOCOMPOSITEOPTIONS_COMPOSITE_ATTRIBUTES_FORMAT_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCOMPOSITEOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<CustomOptionsFormat*>(&data_[STABLEHLOCOMPOSITEOPTIONS_COMPOSITE_ATTRIBUTES_FORMAT_OFFSET ]);}}

int32_t version() {if(STABLEHLOCOMPOSITEOPTIONS_VERSION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCOMPOSITEOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[STABLEHLOCOMPOSITEOPTIONS_VERSION_OFFSET ]);}}

};



struct StableHLOCompositeOptionsOffset {

unsigned char * data_;

StableHLOCompositeOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

StableHLOCompositeOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return StableHLOCompositeOptions(&data_[offset]);}};



enum LSHProjectionType : uint8_t {

LSHProjectionType_UNKNOWN,
LSHProjectionType_SPARSE,
LSHProjectionType_DENSE,
};

const char * LSHProjectionType_to_string(LSHProjectionType value){switch (value){case LSHProjectionType_UNKNOWN:return "LSHProjectionType_UNKNOWN";case LSHProjectionType_SPARSE:return "LSHProjectionType_SPARSE";case LSHProjectionType_DENSE:return "LSHProjectionType_DENSE";default: return NULL;}}



struct ArgMinOptions {

unsigned char * data_;

ArgMinOptions(unsigned char * data) : data_(data) {}

#define ARGMINOPTIONS_MEMBER_SIZE_OFFSET 0
#define ARGMINOPTIONS_OUTPUT_TYPE_OFFSET 2


TensorType output_type() {
if(ARGMINOPTIONS_OUTPUT_TYPE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[ARGMINOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<TensorType*>(&data_[ARGMINOPTIONS_OUTPUT_TYPE_OFFSET ]);}}

};



struct ArgMinOptionsOffset {

unsigned char * data_;

ArgMinOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

ArgMinOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return ArgMinOptions(&data_[offset]);}};



struct StablehloConcatenateOptions {

unsigned char * data_;

StablehloConcatenateOptions(unsigned char * data) : data_(data) {}

#define STABLEHLOCONCATENATEOPTIONS_MEMBER_SIZE_OFFSET 0
#define STABLEHLOCONCATENATEOPTIONS_PAD2_OFFSET 2
#define STABLEHLOCONCATENATEOPTIONS_DIMENSION_OFFSET 8


int64_t dimension() {if(STABLEHLOCONCATENATEOPTIONS_DIMENSION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCONCATENATEOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int64_t*>(&data_[STABLEHLOCONCATENATEOPTIONS_DIMENSION_OFFSET ]);}}

};



struct StablehloConcatenateOptionsOffset {

unsigned char * data_;

StablehloConcatenateOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

StablehloConcatenateOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return StablehloConcatenateOptions(&data_[offset]);}};



struct FakeQuantOptions {

unsigned char * data_;

FakeQuantOptions(unsigned char * data) : data_(data) {}

#define FAKEQUANTOPTIONS_MEMBER_SIZE_OFFSET 0
#define FAKEQUANTOPTIONS_PAD2_OFFSET 2
#define FAKEQUANTOPTIONS_MIN_OFFSET 4
#define FAKEQUANTOPTIONS_MAX_OFFSET 8
#define FAKEQUANTOPTIONS_NUM_BITS_OFFSET 12
#define FAKEQUANTOPTIONS_NARROW_RANGE_OFFSET 16
#define FAKEQUANTOPTIONS_PAD17_OFFSET 17


float min() {if(FAKEQUANTOPTIONS_MIN_OFFSET < *reinterpret_cast<uint16_t *>(&data_[FAKEQUANTOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<float*>(&data_[FAKEQUANTOPTIONS_MIN_OFFSET ]);}}

float max() {if(FAKEQUANTOPTIONS_MAX_OFFSET < *reinterpret_cast<uint16_t *>(&data_[FAKEQUANTOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<float*>(&data_[FAKEQUANTOPTIONS_MAX_OFFSET ]);}}

int32_t num_bits() {if(FAKEQUANTOPTIONS_NUM_BITS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[FAKEQUANTOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[FAKEQUANTOPTIONS_NUM_BITS_OFFSET ]);}}

bool narrow_range() {if(FAKEQUANTOPTIONS_NARROW_RANGE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[FAKEQUANTOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[FAKEQUANTOPTIONS_NARROW_RANGE_OFFSET ]);}}

};



struct FakeQuantOptionsOffset {

unsigned char * data_;

FakeQuantOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

FakeQuantOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return FakeQuantOptions(&data_[offset]);}};







struct Int32Vector {

unsigned char * data_;

Int32Vector(unsigned char * data) : data_(data) {}

#define INT32VECTOR_MEMBER_SIZE_OFFSET 0
#define INT32VECTOR_ENUMS_OFFSET 2


Vector<int32_t> enums(){if(INT32VECTOR_ENUMS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[INT32VECTOR_MEMBER_SIZE_OFFSET])){const int16_t offset = INT32VECTOR_ENUMS_OFFSET ;return Vector<int32_t>(&data_[offset]);}}

};



struct Int32VectorOffset {

unsigned char * data_;

Int32VectorOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

Int32Vector value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return Int32Vector(&data_[offset]);}};



struct GreaterOptions {

unsigned char * data_;

GreaterOptions(unsigned char * data) : data_(data) {}

#define GREATEROPTIONS_MEMBER_SIZE_OFFSET 0


};



struct GreaterOptionsOffset {

unsigned char * data_;

GreaterOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

GreaterOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return GreaterOptions(&data_[offset]);}};



struct PackOptions {

unsigned char * data_;

PackOptions(unsigned char * data) : data_(data) {}

#define PACKOPTIONS_MEMBER_SIZE_OFFSET 0
#define PACKOPTIONS_PAD2_OFFSET 2
#define PACKOPTIONS_VALUES_COUNT_OFFSET 4
#define PACKOPTIONS_AXIS_OFFSET 8


int32_t values_count() {if(PACKOPTIONS_VALUES_COUNT_OFFSET < *reinterpret_cast<uint16_t *>(&data_[PACKOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[PACKOPTIONS_VALUES_COUNT_OFFSET ]);}}

int32_t axis() {if(PACKOPTIONS_AXIS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[PACKOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[PACKOPTIONS_AXIS_OFFSET ]);}}

};



struct PackOptionsOffset {

unsigned char * data_;

PackOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

PackOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return PackOptions(&data_[offset]);}};



struct Uint16Vector {

unsigned char * data_;

Uint16Vector(unsigned char * data) : data_(data) {}

#define UINT16VECTOR_MEMBER_SIZE_OFFSET 0
#define UINT16VECTOR_ENUMS_OFFSET 2


Vector<uint16_t> enums(){if(UINT16VECTOR_ENUMS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[UINT16VECTOR_MEMBER_SIZE_OFFSET])){const int16_t offset = UINT16VECTOR_ENUMS_OFFSET ;return Vector<uint16_t>(&data_[offset]);}}

};



struct Uint16VectorOffset {

unsigned char * data_;

Uint16VectorOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

Uint16Vector value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return Uint16Vector(&data_[offset]);}};



struct LogicalOrOptions {

unsigned char * data_;

LogicalOrOptions(unsigned char * data) : data_(data) {}

#define LOGICALOROPTIONS_MEMBER_SIZE_OFFSET 0


};



struct LogicalOrOptionsOffset {

unsigned char * data_;

LogicalOrOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

LogicalOrOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return LogicalOrOptions(&data_[offset]);}};

enum ActivationFunctionType : uint8_t {

ActivationFunctionType_NONE,
ActivationFunctionType_RELU,
ActivationFunctionType_RELU_N1_TO_1,
ActivationFunctionType_RELU6,
ActivationFunctionType_TANH,
ActivationFunctionType_SIGN_BIT,
};

const char * ActivationFunctionType_to_string(ActivationFunctionType value){switch (value){case ActivationFunctionType_NONE:return "ActivationFunctionType_NONE";case ActivationFunctionType_RELU:return "ActivationFunctionType_RELU";case ActivationFunctionType_RELU_N1_TO_1:return "ActivationFunctionType_RELU_N1_TO_1";case ActivationFunctionType_RELU6:return "ActivationFunctionType_RELU6";case ActivationFunctionType_TANH:return "ActivationFunctionType_TANH";case ActivationFunctionType_SIGN_BIT:return "ActivationFunctionType_SIGN_BIT";default: return NULL;}}

struct Pool2DOptions {

unsigned char * data_;

Pool2DOptions(unsigned char * data) : data_(data) {}

#define POOL2DOPTIONS_MEMBER_SIZE_OFFSET 0
#define POOL2DOPTIONS_PAD2_OFFSET 2
#define POOL2DOPTIONS_STRIDE_W_OFFSET 4
#define POOL2DOPTIONS_STRIDE_H_OFFSET 8
#define POOL2DOPTIONS_FILTER_WIDTH_OFFSET 12
#define POOL2DOPTIONS_FILTER_HEIGHT_OFFSET 16
#define POOL2DOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET 20
#define POOL2DOPTIONS_PAD21_OFFSET 21


int32_t stride_w() {if(POOL2DOPTIONS_STRIDE_W_OFFSET < *reinterpret_cast<uint16_t *>(&data_[POOL2DOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[POOL2DOPTIONS_STRIDE_W_OFFSET ]);}}

int32_t stride_h() {if(POOL2DOPTIONS_STRIDE_H_OFFSET < *reinterpret_cast<uint16_t *>(&data_[POOL2DOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[POOL2DOPTIONS_STRIDE_H_OFFSET ]);}}

int32_t filter_width() {if(POOL2DOPTIONS_FILTER_WIDTH_OFFSET < *reinterpret_cast<uint16_t *>(&data_[POOL2DOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[POOL2DOPTIONS_FILTER_WIDTH_OFFSET ]);}}

int32_t filter_height() {if(POOL2DOPTIONS_FILTER_HEIGHT_OFFSET < *reinterpret_cast<uint16_t *>(&data_[POOL2DOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[POOL2DOPTIONS_FILTER_HEIGHT_OFFSET ]);}}

ActivationFunctionType fused_activation_function() {
if(POOL2DOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[POOL2DOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<ActivationFunctionType*>(&data_[POOL2DOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET ]);}}

};



struct Pool2DOptionsOffset {

unsigned char * data_;

Pool2DOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

Pool2DOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return Pool2DOptions(&data_[offset]);}};







struct OneHotOptions {

unsigned char * data_;

OneHotOptions(unsigned char * data) : data_(data) {}

#define ONEHOTOPTIONS_MEMBER_SIZE_OFFSET 0
#define ONEHOTOPTIONS_PAD2_OFFSET 2
#define ONEHOTOPTIONS_AXIS_OFFSET 4


int32_t axis() {if(ONEHOTOPTIONS_AXIS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[ONEHOTOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[ONEHOTOPTIONS_AXIS_OFFSET ]);}}

};



struct OneHotOptionsOffset {

unsigned char * data_;

OneHotOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

OneHotOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return OneHotOptions(&data_[offset]);}};



struct SVDFOptions {

unsigned char * data_;

SVDFOptions(unsigned char * data) : data_(data) {}

#define SVDFOPTIONS_MEMBER_SIZE_OFFSET 0
#define SVDFOPTIONS_PAD2_OFFSET 2
#define SVDFOPTIONS_RANK_OFFSET 4
#define SVDFOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET 8
#define SVDFOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET 9
#define SVDFOPTIONS_PAD10_OFFSET 10


int32_t rank() {if(SVDFOPTIONS_RANK_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SVDFOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[SVDFOPTIONS_RANK_OFFSET ]);}}

ActivationFunctionType fused_activation_function() {
if(SVDFOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SVDFOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<ActivationFunctionType*>(&data_[SVDFOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET ]);}}

bool asymmetric_quantize_inputs() {if(SVDFOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SVDFOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[SVDFOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET ]);}}

};



struct SVDFOptionsOffset {

unsigned char * data_;

SVDFOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

SVDFOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return SVDFOptions(&data_[offset]);}};



struct SplitVOptions {

unsigned char * data_;

SplitVOptions(unsigned char * data) : data_(data) {}

#define SPLITVOPTIONS_MEMBER_SIZE_OFFSET 0
#define SPLITVOPTIONS_PAD2_OFFSET 2
#define SPLITVOPTIONS_NUM_SPLITS_OFFSET 4


int32_t num_splits() {if(SPLITVOPTIONS_NUM_SPLITS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SPLITVOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[SPLITVOPTIONS_NUM_SPLITS_OFFSET ]);}}

};



struct SplitVOptionsOffset {

unsigned char * data_;

SplitVOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

SplitVOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return SplitVOptions(&data_[offset]);}};



struct LogicalNotOptions {

unsigned char * data_;

LogicalNotOptions(unsigned char * data) : data_(data) {}

#define LOGICALNOTOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct LogicalNotOptionsOffset {

unsigned char * data_;

LogicalNotOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

LogicalNotOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return LogicalNotOptions(&data_[offset]);}};



struct UnpackOptions {

unsigned char * data_;

UnpackOptions(unsigned char * data) : data_(data) {}

#define UNPACKOPTIONS_MEMBER_SIZE_OFFSET 0
#define UNPACKOPTIONS_PAD2_OFFSET 2
#define UNPACKOPTIONS_NUM_OFFSET 4
#define UNPACKOPTIONS_AXIS_OFFSET 8


int32_t num() {if(UNPACKOPTIONS_NUM_OFFSET < *reinterpret_cast<uint16_t *>(&data_[UNPACKOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[UNPACKOPTIONS_NUM_OFFSET ]);}}

int32_t axis() {if(UNPACKOPTIONS_AXIS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[UNPACKOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[UNPACKOPTIONS_AXIS_OFFSET ]);}}

};



struct UnpackOptionsOffset {

unsigned char * data_;

UnpackOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

UnpackOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return UnpackOptions(&data_[offset]);}};



struct FloorDivOptions {

unsigned char * data_;

FloorDivOptions(unsigned char * data) : data_(data) {}

#define FLOORDIVOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct FloorDivOptionsOffset {

unsigned char * data_;

FloorDivOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

FloorDivOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return FloorDivOptions(&data_[offset]);}};



struct DynamicUpdateSliceOptions {

unsigned char * data_;

DynamicUpdateSliceOptions(unsigned char * data) : data_(data) {}

#define DYNAMICUPDATESLICEOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct DynamicUpdateSliceOptionsOffset {

unsigned char * data_;

DynamicUpdateSliceOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

DynamicUpdateSliceOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return DynamicUpdateSliceOptions(&data_[offset]);}};



struct VariantSubType {

unsigned char * data_;

VariantSubType(unsigned char * data) : data_(data) {}

#define VARIANTSUBTYPE_MEMBER_SIZE_OFFSET 0
#define VARIANTSUBTYPE_SHAPE_OFFSET 2
#define VARIANTSUBTYPE_TYPE_OFFSET 4
#define VARIANTSUBTYPE_HAS_RANK_OFFSET 5


Vector<int32_t> shape(){if(VARIANTSUBTYPE_SHAPE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[VARIANTSUBTYPE_MEMBER_SIZE_OFFSET])){const int16_t offset = VARIANTSUBTYPE_SHAPE_OFFSET ;return Vector<int32_t>(&data_[offset]);}}

TensorType type() {
if(VARIANTSUBTYPE_TYPE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[VARIANTSUBTYPE_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<TensorType*>(&data_[VARIANTSUBTYPE_TYPE_OFFSET ]);}}

bool has_rank() {if(VARIANTSUBTYPE_HAS_RANK_OFFSET < *reinterpret_cast<uint16_t *>(&data_[VARIANTSUBTYPE_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[VARIANTSUBTYPE_HAS_RANK_OFFSET ]);}}

};



struct VariantSubTypeOffset {

unsigned char * data_;

VariantSubTypeOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

VariantSubType value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return VariantSubType(&data_[offset]);}};



struct ExpandDimsOptions {

unsigned char * data_;

ExpandDimsOptions(unsigned char * data) : data_(data) {}

#define EXPANDDIMSOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct ExpandDimsOptionsOffset {

unsigned char * data_;

ExpandDimsOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

ExpandDimsOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return ExpandDimsOptions(&data_[offset]);}};





struct SquareOptions {

unsigned char * data_;

SquareOptions(unsigned char * data) : data_(data) {}

#define SQUAREOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct SquareOptionsOffset {

unsigned char * data_;

SquareOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

SquareOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return SquareOptions(&data_[offset]);}};



struct StablehloShiftLeftOptions {

unsigned char * data_;

StablehloShiftLeftOptions(unsigned char * data) : data_(data) {}



};





enum FullyConnectedOptionsWeightsFormat : uint8_t {

FullyConnectedOptionsWeightsFormat_DEFAULT,
FullyConnectedOptionsWeightsFormat_SHUFFLED4x16INT8,
};

const char * FullyConnectedOptionsWeightsFormat_to_string(FullyConnectedOptionsWeightsFormat value){switch (value){case FullyConnectedOptionsWeightsFormat_DEFAULT:return "FullyConnectedOptionsWeightsFormat_DEFAULT";case FullyConnectedOptionsWeightsFormat_SHUFFLED4x16INT8:return "FullyConnectedOptionsWeightsFormat_SHUFFLED4x16INT8";default: return NULL;}}

struct FullyConnectedOptions {

unsigned char * data_;

FullyConnectedOptions(unsigned char * data) : data_(data) {}

#define FULLYCONNECTEDOPTIONS_MEMBER_SIZE_OFFSET 0
#define FULLYCONNECTEDOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET 2
#define FULLYCONNECTEDOPTIONS_WEIGHTS_FORMAT_OFFSET 3
#define FULLYCONNECTEDOPTIONS_KEEP_NUM_DIMS_OFFSET 4
#define FULLYCONNECTEDOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET 5
#define FULLYCONNECTEDOPTIONS_QUANTIZED_BIAS_TYPE_OFFSET 6


ActivationFunctionType fused_activation_function() {
if(FULLYCONNECTEDOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[FULLYCONNECTEDOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<ActivationFunctionType*>(&data_[FULLYCONNECTEDOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET ]);}}

FullyConnectedOptionsWeightsFormat weights_format() {
if(FULLYCONNECTEDOPTIONS_WEIGHTS_FORMAT_OFFSET < *reinterpret_cast<uint16_t *>(&data_[FULLYCONNECTEDOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<FullyConnectedOptionsWeightsFormat*>(&data_[FULLYCONNECTEDOPTIONS_WEIGHTS_FORMAT_OFFSET ]);}}

bool keep_num_dims() {if(FULLYCONNECTEDOPTIONS_KEEP_NUM_DIMS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[FULLYCONNECTEDOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[FULLYCONNECTEDOPTIONS_KEEP_NUM_DIMS_OFFSET ]);}}

bool asymmetric_quantize_inputs() {if(FULLYCONNECTEDOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[FULLYCONNECTEDOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[FULLYCONNECTEDOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET ]);}}

TensorType quantized_bias_type() {
if(FULLYCONNECTEDOPTIONS_QUANTIZED_BIAS_TYPE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[FULLYCONNECTEDOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<TensorType*>(&data_[FULLYCONNECTEDOPTIONS_QUANTIZED_BIAS_TYPE_OFFSET ]);}}

};



struct FullyConnectedOptionsOffset {

unsigned char * data_;

FullyConnectedOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

FullyConnectedOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return FullyConnectedOptions(&data_[offset]);}};



struct ZerosLikeOptions {

unsigned char * data_;

ZerosLikeOptions(unsigned char * data) : data_(data) {}

#define ZEROSLIKEOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct ZerosLikeOptionsOffset {

unsigned char * data_;

ZerosLikeOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

ZerosLikeOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return ZerosLikeOptions(&data_[offset]);}};



struct ArgMaxOptions {

unsigned char * data_;

ArgMaxOptions(unsigned char * data) : data_(data) {}

#define ARGMAXOPTIONS_MEMBER_SIZE_OFFSET 0
#define ARGMAXOPTIONS_OUTPUT_TYPE_OFFSET 2


TensorType output_type() {
if(ARGMAXOPTIONS_OUTPUT_TYPE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[ARGMAXOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<TensorType*>(&data_[ARGMAXOPTIONS_OUTPUT_TYPE_OFFSET ]);}}

};



struct ArgMaxOptionsOffset {

unsigned char * data_;

ArgMaxOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

ArgMaxOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return ArgMaxOptions(&data_[offset]);}};



struct FillOptions {

unsigned char * data_;

FillOptions(unsigned char * data) : data_(data) {}

#define FILLOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct FillOptionsOffset {

unsigned char * data_;

FillOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

FillOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return FillOptions(&data_[offset]);}};



struct StablehloBroadcastInDimOptions {

unsigned char * data_;

StablehloBroadcastInDimOptions(unsigned char * data) : data_(data) {}

#define STABLEHLOBROADCASTINDIMOPTIONS_MEMBER_SIZE_OFFSET 0
#define STABLEHLOBROADCASTINDIMOPTIONS_BROADCAST_DIMENSIONS_OFFSET 2


Vector<int64_t> broadcast_dimensions(){if(STABLEHLOBROADCASTINDIMOPTIONS_BROADCAST_DIMENSIONS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOBROADCASTINDIMOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOBROADCASTINDIMOPTIONS_BROADCAST_DIMENSIONS_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

};



struct StablehloBroadcastInDimOptionsOffset {

unsigned char * data_;

StablehloBroadcastInDimOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

StablehloBroadcastInDimOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return StablehloBroadcastInDimOptions(&data_[offset]);}};



struct StablehloCaseOptions {

unsigned char * data_;

StablehloCaseOptions(unsigned char * data) : data_(data) {}

#define STABLEHLOCASEOPTIONS_MEMBER_SIZE_OFFSET 0
#define STABLEHLOCASEOPTIONS_BRANCH_SUBGRAPH_INDICES_OFFSET 2


Vector<int32_t> branch_subgraph_indices(){if(STABLEHLOCASEOPTIONS_BRANCH_SUBGRAPH_INDICES_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCASEOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOCASEOPTIONS_BRANCH_SUBGRAPH_INDICES_OFFSET ;return Vector<int32_t>(&data_[offset]);}}

};



struct StablehloCaseOptionsOffset {

unsigned char * data_;

StablehloCaseOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

StablehloCaseOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return StablehloCaseOptions(&data_[offset]);}};



struct SplitOptions {

unsigned char * data_;

SplitOptions(unsigned char * data) : data_(data) {}

#define SPLITOPTIONS_MEMBER_SIZE_OFFSET 0
#define SPLITOPTIONS_PAD2_OFFSET 2
#define SPLITOPTIONS_NUM_SPLITS_OFFSET 4


int32_t num_splits() {if(SPLITOPTIONS_NUM_SPLITS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SPLITOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[SPLITOPTIONS_NUM_SPLITS_OFFSET ]);}}

};



struct SplitOptionsOffset {

unsigned char * data_;

SplitOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

SplitOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return SplitOptions(&data_[offset]);}};



struct BidirectionalSequenceLSTMOptions {

unsigned char * data_;

BidirectionalSequenceLSTMOptions(unsigned char * data) : data_(data) {}

#define BIDIRECTIONALSEQUENCELSTMOPTIONS_MEMBER_SIZE_OFFSET 0
#define BIDIRECTIONALSEQUENCELSTMOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET 2
#define BIDIRECTIONALSEQUENCELSTMOPTIONS_PAD3_OFFSET 3
#define BIDIRECTIONALSEQUENCELSTMOPTIONS_CELL_CLIP_OFFSET 4
#define BIDIRECTIONALSEQUENCELSTMOPTIONS_PROJ_CLIP_OFFSET 8
#define BIDIRECTIONALSEQUENCELSTMOPTIONS_MERGE_OUTPUTS_OFFSET 12
#define BIDIRECTIONALSEQUENCELSTMOPTIONS_TIME_MAJOR_OFFSET 13
#define BIDIRECTIONALSEQUENCELSTMOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET 14
#define BIDIRECTIONALSEQUENCELSTMOPTIONS_PAD15_OFFSET 15


ActivationFunctionType fused_activation_function() {
if(BIDIRECTIONALSEQUENCELSTMOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[BIDIRECTIONALSEQUENCELSTMOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<ActivationFunctionType*>(&data_[BIDIRECTIONALSEQUENCELSTMOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET ]);}}

float cell_clip() {if(BIDIRECTIONALSEQUENCELSTMOPTIONS_CELL_CLIP_OFFSET < *reinterpret_cast<uint16_t *>(&data_[BIDIRECTIONALSEQUENCELSTMOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<float*>(&data_[BIDIRECTIONALSEQUENCELSTMOPTIONS_CELL_CLIP_OFFSET ]);}}

float proj_clip() {if(BIDIRECTIONALSEQUENCELSTMOPTIONS_PROJ_CLIP_OFFSET < *reinterpret_cast<uint16_t *>(&data_[BIDIRECTIONALSEQUENCELSTMOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<float*>(&data_[BIDIRECTIONALSEQUENCELSTMOPTIONS_PROJ_CLIP_OFFSET ]);}}

bool merge_outputs() {if(BIDIRECTIONALSEQUENCELSTMOPTIONS_MERGE_OUTPUTS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[BIDIRECTIONALSEQUENCELSTMOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[BIDIRECTIONALSEQUENCELSTMOPTIONS_MERGE_OUTPUTS_OFFSET ]);}}

bool time_major() {if(BIDIRECTIONALSEQUENCELSTMOPTIONS_TIME_MAJOR_OFFSET < *reinterpret_cast<uint16_t *>(&data_[BIDIRECTIONALSEQUENCELSTMOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[BIDIRECTIONALSEQUENCELSTMOPTIONS_TIME_MAJOR_OFFSET ]);}}

bool asymmetric_quantize_inputs() {if(BIDIRECTIONALSEQUENCELSTMOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[BIDIRECTIONALSEQUENCELSTMOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[BIDIRECTIONALSEQUENCELSTMOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET ]);}}

};



struct BidirectionalSequenceLSTMOptionsOffset {

unsigned char * data_;

BidirectionalSequenceLSTMOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

BidirectionalSequenceLSTMOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return BidirectionalSequenceLSTMOptions(&data_[offset]);}};



struct BidirectionalSequenceRNNOptions {

unsigned char * data_;

BidirectionalSequenceRNNOptions(unsigned char * data) : data_(data) {}

#define BIDIRECTIONALSEQUENCERNNOPTIONS_MEMBER_SIZE_OFFSET 0
#define BIDIRECTIONALSEQUENCERNNOPTIONS_TIME_MAJOR_OFFSET 2
#define BIDIRECTIONALSEQUENCERNNOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET 3
#define BIDIRECTIONALSEQUENCERNNOPTIONS_MERGE_OUTPUTS_OFFSET 4
#define BIDIRECTIONALSEQUENCERNNOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET 5


bool time_major() {if(BIDIRECTIONALSEQUENCERNNOPTIONS_TIME_MAJOR_OFFSET < *reinterpret_cast<uint16_t *>(&data_[BIDIRECTIONALSEQUENCERNNOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[BIDIRECTIONALSEQUENCERNNOPTIONS_TIME_MAJOR_OFFSET ]);}}

ActivationFunctionType fused_activation_function() {
if(BIDIRECTIONALSEQUENCERNNOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[BIDIRECTIONALSEQUENCERNNOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<ActivationFunctionType*>(&data_[BIDIRECTIONALSEQUENCERNNOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET ]);}}

bool merge_outputs() {if(BIDIRECTIONALSEQUENCERNNOPTIONS_MERGE_OUTPUTS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[BIDIRECTIONALSEQUENCERNNOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[BIDIRECTIONALSEQUENCERNNOPTIONS_MERGE_OUTPUTS_OFFSET ]);}}

bool asymmetric_quantize_inputs() {if(BIDIRECTIONALSEQUENCERNNOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[BIDIRECTIONALSEQUENCERNNOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[BIDIRECTIONALSEQUENCERNNOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET ]);}}

};



struct BidirectionalSequenceRNNOptionsOffset {

unsigned char * data_;

BidirectionalSequenceRNNOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

BidirectionalSequenceRNNOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return BidirectionalSequenceRNNOptions(&data_[offset]);}};



struct Metadata {

unsigned char * data_;

Metadata(unsigned char * data) : data_(data) {}

#define METADATA_MEMBER_SIZE_OFFSET 0
#define METADATA_NAME_OFFSET 2
#define METADATA_BUFFER_OFFSET 4


StringOffset name(){if(METADATA_NAME_OFFSET < *reinterpret_cast<uint16_t *>(&data_[METADATA_MEMBER_SIZE_OFFSET])){const int16_t offset = METADATA_NAME_OFFSET ;return StringOffset(&data_[offset]);}}

uint32_t buffer() {if(METADATA_BUFFER_OFFSET < *reinterpret_cast<uint16_t *>(&data_[METADATA_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<uint32_t*>(&data_[METADATA_BUFFER_OFFSET ]);}}

};



struct MetadataOffset {

unsigned char * data_;

MetadataOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

Metadata value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return Metadata(&data_[offset]);}};



struct DensifyOptions {

unsigned char * data_;

DensifyOptions(unsigned char * data) : data_(data) {}

#define DENSIFYOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct DensifyOptionsOffset {

unsigned char * data_;

DensifyOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

DensifyOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return DensifyOptions(&data_[offset]);}};



struct StablehloSliceOptions {

unsigned char * data_;

StablehloSliceOptions(unsigned char * data) : data_(data) {}

#define STABLEHLOSLICEOPTIONS_MEMBER_SIZE_OFFSET 0
#define STABLEHLOSLICEOPTIONS_START_INDICES_OFFSET 2
#define STABLEHLOSLICEOPTIONS_LIMIT_INDICES_OFFSET 4
#define STABLEHLOSLICEOPTIONS_STRIDES_OFFSET 6


Vector<int64_t> start_indices(){if(STABLEHLOSLICEOPTIONS_START_INDICES_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOSLICEOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOSLICEOPTIONS_START_INDICES_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

Vector<int64_t> limit_indices(){if(STABLEHLOSLICEOPTIONS_LIMIT_INDICES_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOSLICEOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOSLICEOPTIONS_LIMIT_INDICES_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

Vector<int64_t> strides(){if(STABLEHLOSLICEOPTIONS_STRIDES_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOSLICEOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOSLICEOPTIONS_STRIDES_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

};



struct StablehloSliceOptionsOffset {

unsigned char * data_;

StablehloSliceOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

StablehloSliceOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return StablehloSliceOptions(&data_[offset]);}};



struct LessOptions {

unsigned char * data_;

LessOptions(unsigned char * data) : data_(data) {}

#define LESSOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct LessOptionsOffset {

unsigned char * data_;

LessOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

LessOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return LessOptions(&data_[offset]);}};

enum StablehloPrecisionConfig : uint32_t {

StablehloPrecisionConfig_DEFAULT,
StablehloPrecisionConfig_HIGH,
StablehloPrecisionConfig_HIGHEST,
};

const char * StablehloPrecisionConfig_to_string(StablehloPrecisionConfig value){switch (value){case StablehloPrecisionConfig_DEFAULT:return "StablehloPrecisionConfig_DEFAULT";case StablehloPrecisionConfig_HIGH:return "StablehloPrecisionConfig_HIGH";case StablehloPrecisionConfig_HIGHEST:return "StablehloPrecisionConfig_HIGHEST";default: return NULL;}}

struct StablehloConvolutionOptions {

unsigned char * data_;

StablehloConvolutionOptions(unsigned char * data) : data_(data) {}

#define STABLEHLOCONVOLUTIONOPTIONS_MEMBER_SIZE_OFFSET 0
#define STABLEHLOCONVOLUTIONOPTIONS_WINDOW_STRIDES_OFFSET 2
#define STABLEHLOCONVOLUTIONOPTIONS_LHS_DILATION_OFFSET 4
#define STABLEHLOCONVOLUTIONOPTIONS_RHS_DILATION_OFFSET 6
#define STABLEHLOCONVOLUTIONOPTIONS_WINDOW_REVERSAL_OFFSET 8
#define STABLEHLOCONVOLUTIONOPTIONS_PAD9_OFFSET 9
#define STABLEHLOCONVOLUTIONOPTIONS_INPUT_BATCH_DIMENSION_OFFSET 16
#define STABLEHLOCONVOLUTIONOPTIONS_INPUT_FEATURE_DIMENSION_OFFSET 24
#define STABLEHLOCONVOLUTIONOPTIONS_INPUT_SPATIAL_DIMENSIONS_OFFSET 32
#define STABLEHLOCONVOLUTIONOPTIONS_PAD34_OFFSET 34
#define STABLEHLOCONVOLUTIONOPTIONS_KERNEL_INPUT_FEATURE_DIMENSION_OFFSET 40
#define STABLEHLOCONVOLUTIONOPTIONS_KERNEL_OUTPUT_FEATURE_DIMENSION_OFFSET 48
#define STABLEHLOCONVOLUTIONOPTIONS_KERNEL_SPATIAL_DIMENSIONS_OFFSET 56
#define STABLEHLOCONVOLUTIONOPTIONS_PAD58_OFFSET 58
#define STABLEHLOCONVOLUTIONOPTIONS_OUTPUT_BATCH_DIMENSION_OFFSET 64
#define STABLEHLOCONVOLUTIONOPTIONS_OUTPUT_FEATURE_DIMENSION_OFFSET 72
#define STABLEHLOCONVOLUTIONOPTIONS_OUTPUT_SPATIAL_DIMENSIONS_OFFSET 80
#define STABLEHLOCONVOLUTIONOPTIONS_PAD82_OFFSET 82
#define STABLEHLOCONVOLUTIONOPTIONS_FEATURE_GROUP_COUNT_OFFSET 88
#define STABLEHLOCONVOLUTIONOPTIONS_BATCH_GROUP_COUNT_OFFSET 96
#define STABLEHLOCONVOLUTIONOPTIONS_PRECISION_CONFIG_OFFSET 104
#define STABLEHLOCONVOLUTIONOPTIONS_PAD106_OFFSET 106


Vector<int64_t> window_strides(){if(STABLEHLOCONVOLUTIONOPTIONS_WINDOW_STRIDES_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCONVOLUTIONOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOCONVOLUTIONOPTIONS_WINDOW_STRIDES_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

Vector<int64_t> lhs_dilation(){if(STABLEHLOCONVOLUTIONOPTIONS_LHS_DILATION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCONVOLUTIONOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOCONVOLUTIONOPTIONS_LHS_DILATION_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

Vector<int64_t> rhs_dilation(){if(STABLEHLOCONVOLUTIONOPTIONS_RHS_DILATION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCONVOLUTIONOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOCONVOLUTIONOPTIONS_RHS_DILATION_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

bool window_reversal() {if(STABLEHLOCONVOLUTIONOPTIONS_WINDOW_REVERSAL_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCONVOLUTIONOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[STABLEHLOCONVOLUTIONOPTIONS_WINDOW_REVERSAL_OFFSET ]);}}

int64_t input_batch_dimension() {if(STABLEHLOCONVOLUTIONOPTIONS_INPUT_BATCH_DIMENSION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCONVOLUTIONOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int64_t*>(&data_[STABLEHLOCONVOLUTIONOPTIONS_INPUT_BATCH_DIMENSION_OFFSET ]);}}

int64_t input_feature_dimension() {if(STABLEHLOCONVOLUTIONOPTIONS_INPUT_FEATURE_DIMENSION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCONVOLUTIONOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int64_t*>(&data_[STABLEHLOCONVOLUTIONOPTIONS_INPUT_FEATURE_DIMENSION_OFFSET ]);}}

Vector<int64_t> input_spatial_dimensions(){if(STABLEHLOCONVOLUTIONOPTIONS_INPUT_SPATIAL_DIMENSIONS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCONVOLUTIONOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOCONVOLUTIONOPTIONS_INPUT_SPATIAL_DIMENSIONS_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

int64_t kernel_input_feature_dimension() {if(STABLEHLOCONVOLUTIONOPTIONS_KERNEL_INPUT_FEATURE_DIMENSION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCONVOLUTIONOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int64_t*>(&data_[STABLEHLOCONVOLUTIONOPTIONS_KERNEL_INPUT_FEATURE_DIMENSION_OFFSET ]);}}

int64_t kernel_output_feature_dimension() {if(STABLEHLOCONVOLUTIONOPTIONS_KERNEL_OUTPUT_FEATURE_DIMENSION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCONVOLUTIONOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int64_t*>(&data_[STABLEHLOCONVOLUTIONOPTIONS_KERNEL_OUTPUT_FEATURE_DIMENSION_OFFSET ]);}}

Vector<int64_t> kernel_spatial_dimensions(){if(STABLEHLOCONVOLUTIONOPTIONS_KERNEL_SPATIAL_DIMENSIONS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCONVOLUTIONOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOCONVOLUTIONOPTIONS_KERNEL_SPATIAL_DIMENSIONS_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

int64_t output_batch_dimension() {if(STABLEHLOCONVOLUTIONOPTIONS_OUTPUT_BATCH_DIMENSION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCONVOLUTIONOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int64_t*>(&data_[STABLEHLOCONVOLUTIONOPTIONS_OUTPUT_BATCH_DIMENSION_OFFSET ]);}}

int64_t output_feature_dimension() {if(STABLEHLOCONVOLUTIONOPTIONS_OUTPUT_FEATURE_DIMENSION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCONVOLUTIONOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int64_t*>(&data_[STABLEHLOCONVOLUTIONOPTIONS_OUTPUT_FEATURE_DIMENSION_OFFSET ]);}}

Vector<int64_t> output_spatial_dimensions(){if(STABLEHLOCONVOLUTIONOPTIONS_OUTPUT_SPATIAL_DIMENSIONS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCONVOLUTIONOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOCONVOLUTIONOPTIONS_OUTPUT_SPATIAL_DIMENSIONS_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

int64_t feature_group_count() {if(STABLEHLOCONVOLUTIONOPTIONS_FEATURE_GROUP_COUNT_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCONVOLUTIONOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int64_t*>(&data_[STABLEHLOCONVOLUTIONOPTIONS_FEATURE_GROUP_COUNT_OFFSET ]);}}

int64_t batch_group_count() {if(STABLEHLOCONVOLUTIONOPTIONS_BATCH_GROUP_COUNT_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCONVOLUTIONOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int64_t*>(&data_[STABLEHLOCONVOLUTIONOPTIONS_BATCH_GROUP_COUNT_OFFSET ]);}}

Vector<StablehloPrecisionConfig> precision_config(){if(STABLEHLOCONVOLUTIONOPTIONS_PRECISION_CONFIG_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCONVOLUTIONOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOCONVOLUTIONOPTIONS_PRECISION_CONFIG_OFFSET ;return Vector<StablehloPrecisionConfig>(&data_[offset]);}}

};



struct StablehloConvolutionOptionsOffset {

unsigned char * data_;

StablehloConvolutionOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

StablehloConvolutionOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return StablehloConvolutionOptions(&data_[offset]);}};



struct CumsumOptions {

unsigned char * data_;

CumsumOptions(unsigned char * data) : data_(data) {}

#define CUMSUMOPTIONS_MEMBER_SIZE_OFFSET 0
#define CUMSUMOPTIONS_EXCLUSIVE_OFFSET 2
#define CUMSUMOPTIONS_REVERSE_OFFSET 3


bool exclusive() {if(CUMSUMOPTIONS_EXCLUSIVE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[CUMSUMOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[CUMSUMOPTIONS_EXCLUSIVE_OFFSET ]);}}

bool reverse() {if(CUMSUMOPTIONS_REVERSE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[CUMSUMOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[CUMSUMOPTIONS_REVERSE_OFFSET ]);}}

};



struct CumsumOptionsOffset {

unsigned char * data_;

CumsumOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

CumsumOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return CumsumOptions(&data_[offset]);}};



struct StablehloCustomCallOptions {

unsigned char * data_;

StablehloCustomCallOptions(unsigned char * data) : data_(data) {}

#define STABLEHLOCUSTOMCALLOPTIONS_MEMBER_SIZE_OFFSET 0
#define STABLEHLOCUSTOMCALLOPTIONS_CALL_TARGET_NAME_OFFSET 2
#define STABLEHLOCUSTOMCALLOPTIONS_HAS_SIDE_EFFECT_OFFSET 4
#define STABLEHLOCUSTOMCALLOPTIONS_PAD5_OFFSET 5
#define STABLEHLOCUSTOMCALLOPTIONS_BACKEND_CONFIG_OFFSET 6
#define STABLEHLOCUSTOMCALLOPTIONS_API_VERSION_OFFSET 8
#define STABLEHLOCUSTOMCALLOPTIONS_CALLED_COMPUTATIONS_OFFSET 12
#define STABLEHLOCUSTOMCALLOPTIONS_CUSTOM_ATTRIBUTES_OFFSET 14


StringOffset call_target_name(){if(STABLEHLOCUSTOMCALLOPTIONS_CALL_TARGET_NAME_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCUSTOMCALLOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOCUSTOMCALLOPTIONS_CALL_TARGET_NAME_OFFSET ;return StringOffset(&data_[offset]);}}

bool has_side_effect() {if(STABLEHLOCUSTOMCALLOPTIONS_HAS_SIDE_EFFECT_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCUSTOMCALLOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[STABLEHLOCUSTOMCALLOPTIONS_HAS_SIDE_EFFECT_OFFSET ]);}}

StringOffset backend_config(){if(STABLEHLOCUSTOMCALLOPTIONS_BACKEND_CONFIG_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCUSTOMCALLOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOCUSTOMCALLOPTIONS_BACKEND_CONFIG_OFFSET ;return StringOffset(&data_[offset]);}}

int32_t api_version() {if(STABLEHLOCUSTOMCALLOPTIONS_API_VERSION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCUSTOMCALLOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[STABLEHLOCUSTOMCALLOPTIONS_API_VERSION_OFFSET ]);}}

Vector<int32_t> called_computations(){if(STABLEHLOCUSTOMCALLOPTIONS_CALLED_COMPUTATIONS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCUSTOMCALLOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOCUSTOMCALLOPTIONS_CALLED_COMPUTATIONS_OFFSET ;return Vector<int32_t>(&data_[offset]);}}

Vector<uint8_t> custom_attributes(){if(STABLEHLOCUSTOMCALLOPTIONS_CUSTOM_ATTRIBUTES_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCUSTOMCALLOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOCUSTOMCALLOPTIONS_CUSTOM_ATTRIBUTES_OFFSET ;return Vector<uint8_t>(&data_[offset]);}}

};



struct StablehloCustomCallOptionsOffset {

unsigned char * data_;

StablehloCustomCallOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

StablehloCustomCallOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return StablehloCustomCallOptions(&data_[offset]);}};



struct RNNOptions {

unsigned char * data_;

RNNOptions(unsigned char * data) : data_(data) {}

#define RNNOPTIONS_MEMBER_SIZE_OFFSET 0
#define RNNOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET 2
#define RNNOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET 3


ActivationFunctionType fused_activation_function() {
if(RNNOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[RNNOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<ActivationFunctionType*>(&data_[RNNOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET ]);}}

bool asymmetric_quantize_inputs() {if(RNNOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[RNNOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[RNNOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET ]);}}

};



struct RNNOptionsOffset {

unsigned char * data_;

RNNOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

RNNOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return RNNOptions(&data_[offset]);}};



struct SoftmaxOptions {

unsigned char * data_;

SoftmaxOptions(unsigned char * data) : data_(data) {}

#define SOFTMAXOPTIONS_MEMBER_SIZE_OFFSET 0
#define SOFTMAXOPTIONS_PAD2_OFFSET 2
#define SOFTMAXOPTIONS_BETA_OFFSET 4


float beta() {if(SOFTMAXOPTIONS_BETA_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SOFTMAXOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<float*>(&data_[SOFTMAXOPTIONS_BETA_OFFSET ]);}}

};



struct SoftmaxOptionsOffset {

unsigned char * data_;

SoftmaxOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

SoftmaxOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return SoftmaxOptions(&data_[offset]);}};



struct UnidirectionalSequenceLSTMOptions {

unsigned char * data_;

UnidirectionalSequenceLSTMOptions(unsigned char * data) : data_(data) {}

#define UNIDIRECTIONALSEQUENCELSTMOPTIONS_MEMBER_SIZE_OFFSET 0
#define UNIDIRECTIONALSEQUENCELSTMOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET 2
#define UNIDIRECTIONALSEQUENCELSTMOPTIONS_PAD3_OFFSET 3
#define UNIDIRECTIONALSEQUENCELSTMOPTIONS_CELL_CLIP_OFFSET 4
#define UNIDIRECTIONALSEQUENCELSTMOPTIONS_PROJ_CLIP_OFFSET 8
#define UNIDIRECTIONALSEQUENCELSTMOPTIONS_TIME_MAJOR_OFFSET 12
#define UNIDIRECTIONALSEQUENCELSTMOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET 13
#define UNIDIRECTIONALSEQUENCELSTMOPTIONS_DIAGONAL_RECURRENT_TENSORS_OFFSET 14
#define UNIDIRECTIONALSEQUENCELSTMOPTIONS_PAD15_OFFSET 15


ActivationFunctionType fused_activation_function() {
if(UNIDIRECTIONALSEQUENCELSTMOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[UNIDIRECTIONALSEQUENCELSTMOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<ActivationFunctionType*>(&data_[UNIDIRECTIONALSEQUENCELSTMOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET ]);}}

float cell_clip() {if(UNIDIRECTIONALSEQUENCELSTMOPTIONS_CELL_CLIP_OFFSET < *reinterpret_cast<uint16_t *>(&data_[UNIDIRECTIONALSEQUENCELSTMOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<float*>(&data_[UNIDIRECTIONALSEQUENCELSTMOPTIONS_CELL_CLIP_OFFSET ]);}}

float proj_clip() {if(UNIDIRECTIONALSEQUENCELSTMOPTIONS_PROJ_CLIP_OFFSET < *reinterpret_cast<uint16_t *>(&data_[UNIDIRECTIONALSEQUENCELSTMOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<float*>(&data_[UNIDIRECTIONALSEQUENCELSTMOPTIONS_PROJ_CLIP_OFFSET ]);}}

bool time_major() {if(UNIDIRECTIONALSEQUENCELSTMOPTIONS_TIME_MAJOR_OFFSET < *reinterpret_cast<uint16_t *>(&data_[UNIDIRECTIONALSEQUENCELSTMOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[UNIDIRECTIONALSEQUENCELSTMOPTIONS_TIME_MAJOR_OFFSET ]);}}

bool asymmetric_quantize_inputs() {if(UNIDIRECTIONALSEQUENCELSTMOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[UNIDIRECTIONALSEQUENCELSTMOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[UNIDIRECTIONALSEQUENCELSTMOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET ]);}}

bool diagonal_recurrent_tensors() {if(UNIDIRECTIONALSEQUENCELSTMOPTIONS_DIAGONAL_RECURRENT_TENSORS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[UNIDIRECTIONALSEQUENCELSTMOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[UNIDIRECTIONALSEQUENCELSTMOPTIONS_DIAGONAL_RECURRENT_TENSORS_OFFSET ]);}}

};



struct UnidirectionalSequenceLSTMOptionsOffset {

unsigned char * data_;

UnidirectionalSequenceLSTMOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

UnidirectionalSequenceLSTMOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return UnidirectionalSequenceLSTMOptions(&data_[offset]);}};



struct LeakyReluOptions {

unsigned char * data_;

LeakyReluOptions(unsigned char * data) : data_(data) {}

#define LEAKYRELUOPTIONS_MEMBER_SIZE_OFFSET 0
#define LEAKYRELUOPTIONS_PAD2_OFFSET 2
#define LEAKYRELUOPTIONS_ALPHA_OFFSET 4


float alpha() {if(LEAKYRELUOPTIONS_ALPHA_OFFSET < *reinterpret_cast<uint16_t *>(&data_[LEAKYRELUOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<float*>(&data_[LEAKYRELUOPTIONS_ALPHA_OFFSET ]);}}

};



struct LeakyReluOptionsOffset {

unsigned char * data_;

LeakyReluOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

LeakyReluOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return LeakyReluOptions(&data_[offset]);}};



struct TensorMap {

unsigned char * data_;

TensorMap(unsigned char * data) : data_(data) {}

#define TENSORMAP_MEMBER_SIZE_OFFSET 0
#define TENSORMAP_NAME_OFFSET 2
#define TENSORMAP_TENSOR_INDEX_OFFSET 4


StringOffset name(){if(TENSORMAP_NAME_OFFSET < *reinterpret_cast<uint16_t *>(&data_[TENSORMAP_MEMBER_SIZE_OFFSET])){const int16_t offset = TENSORMAP_NAME_OFFSET ;return StringOffset(&data_[offset]);}}

uint32_t tensor_index() {if(TENSORMAP_TENSOR_INDEX_OFFSET < *reinterpret_cast<uint16_t *>(&data_[TENSORMAP_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<uint32_t*>(&data_[TENSORMAP_TENSOR_INDEX_OFFSET ]);}}

};



struct TensorMapOffset {

unsigned char * data_;

TensorMapOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

TensorMap value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return TensorMap(&data_[offset]);}};

struct SignatureDef {

unsigned char * data_;

SignatureDef(unsigned char * data) : data_(data) {}

#define SIGNATUREDEF_MEMBER_SIZE_OFFSET 0
#define SIGNATUREDEF_INPUTS_OFFSET 2
#define SIGNATUREDEF_OUTPUTS_OFFSET 4
#define SIGNATUREDEF_SIGNATURE_KEY_OFFSET 6
#define SIGNATUREDEF_DEPRECATED_TAG_OFFSET 8
#define SIGNATUREDEF_PAD10_OFFSET 10
#define SIGNATUREDEF_SUBGRAPH_INDEX_OFFSET 12


Vector<TensorMapOffset> inputs(){if(SIGNATUREDEF_INPUTS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SIGNATUREDEF_MEMBER_SIZE_OFFSET])){const int16_t offset = SIGNATUREDEF_INPUTS_OFFSET ;return Vector<TensorMapOffset>(&data_[offset]);}}

Vector<TensorMapOffset> outputs(){if(SIGNATUREDEF_OUTPUTS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SIGNATUREDEF_MEMBER_SIZE_OFFSET])){const int16_t offset = SIGNATUREDEF_OUTPUTS_OFFSET ;return Vector<TensorMapOffset>(&data_[offset]);}}

StringOffset signature_key(){if(SIGNATUREDEF_SIGNATURE_KEY_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SIGNATUREDEF_MEMBER_SIZE_OFFSET])){const int16_t offset = SIGNATUREDEF_SIGNATURE_KEY_OFFSET ;return StringOffset(&data_[offset]);}}

StringOffset deprecated_tag(){if(SIGNATUREDEF_DEPRECATED_TAG_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SIGNATUREDEF_MEMBER_SIZE_OFFSET])){const int16_t offset = SIGNATUREDEF_DEPRECATED_TAG_OFFSET ;return StringOffset(&data_[offset]);}}

uint32_t subgraph_index() {if(SIGNATUREDEF_SUBGRAPH_INDEX_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SIGNATUREDEF_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<uint32_t*>(&data_[SIGNATUREDEF_SUBGRAPH_INDEX_OFFSET ]);}}

};



struct SignatureDefOffset {

unsigned char * data_;

SignatureDefOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

SignatureDef value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return SignatureDef(&data_[offset]);}};





struct NotEqualOptions {

unsigned char * data_;

NotEqualOptions(unsigned char * data) : data_(data) {}

#define NOTEQUALOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct NotEqualOptionsOffset {

unsigned char * data_;

NotEqualOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

NotEqualOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return NotEqualOptions(&data_[offset]);}};



struct Buffer {

unsigned char * data_;

Buffer(unsigned char * data) : data_(data) {}

#define BUFFER_MEMBER_SIZE_OFFSET 0
#define BUFFER_DATA_OFFSET 2
#define BUFFER_PAD4_OFFSET 4
#define BUFFER_OFFSET_OFFSET 8
#define BUFFER_SIZE_OFFSET 16


Vector<uint8_t> data(){if(BUFFER_DATA_OFFSET < *reinterpret_cast<uint16_t *>(&data_[BUFFER_MEMBER_SIZE_OFFSET])){const int16_t offset = BUFFER_DATA_OFFSET ;return Vector<uint8_t>(&data_[offset]);}}

uint64_t offset() {if(BUFFER_OFFSET_OFFSET < *reinterpret_cast<uint16_t *>(&data_[BUFFER_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<uint64_t*>(&data_[BUFFER_OFFSET_OFFSET ]);}}

uint64_t size() {if(BUFFER_SIZE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[BUFFER_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<uint64_t*>(&data_[BUFFER_SIZE_OFFSET ]);}}

};



struct BufferOffset {

unsigned char * data_;

BufferOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

Buffer value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return Buffer(&data_[offset]);}};





struct ScatterNdOptions {

unsigned char * data_;

ScatterNdOptions(unsigned char * data) : data_(data) {}

#define SCATTERNDOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct ScatterNdOptionsOffset {

unsigned char * data_;

ScatterNdOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

ScatterNdOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return ScatterNdOptions(&data_[offset]);}};



struct SelectOptions {

unsigned char * data_;

SelectOptions(unsigned char * data) : data_(data) {}

#define SELECTOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct SelectOptionsOffset {

unsigned char * data_;

SelectOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

SelectOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return SelectOptions(&data_[offset]);}};



struct ConcatenationOptions {

unsigned char * data_;

ConcatenationOptions(unsigned char * data) : data_(data) {}

#define CONCATENATIONOPTIONS_MEMBER_SIZE_OFFSET 0
#define CONCATENATIONOPTIONS_PAD2_OFFSET 2
#define CONCATENATIONOPTIONS_AXIS_OFFSET 4
#define CONCATENATIONOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET 8
#define CONCATENATIONOPTIONS_PAD9_OFFSET 9


int32_t axis() {if(CONCATENATIONOPTIONS_AXIS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[CONCATENATIONOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[CONCATENATIONOPTIONS_AXIS_OFFSET ]);}}

ActivationFunctionType fused_activation_function() {
if(CONCATENATIONOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[CONCATENATIONOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<ActivationFunctionType*>(&data_[CONCATENATIONOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET ]);}}

};



struct ConcatenationOptionsOffset {

unsigned char * data_;

ConcatenationOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

ConcatenationOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return ConcatenationOptions(&data_[offset]);}};



struct FloorModOptions {

unsigned char * data_;

FloorModOptions(unsigned char * data) : data_(data) {}

#define FLOORMODOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct FloorModOptionsOffset {

unsigned char * data_;

FloorModOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

FloorModOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return FloorModOptions(&data_[offset]);}};

enum BuiltinOptions_enum : uint16_t {

BuiltinOptions_enum_Conv2DOptions,
BuiltinOptions_enum_DepthwiseConv2DOptions,
BuiltinOptions_enum_ConcatEmbeddingsOptions,
BuiltinOptions_enum_LSHProjectionOptions,
BuiltinOptions_enum_Pool2DOptions,
BuiltinOptions_enum_SVDFOptions,
BuiltinOptions_enum_RNNOptions,
BuiltinOptions_enum_FullyConnectedOptions,
BuiltinOptions_enum_SoftmaxOptions,
BuiltinOptions_enum_ConcatenationOptions,
BuiltinOptions_enum_AddOptions,
BuiltinOptions_enum_L2NormOptions,
BuiltinOptions_enum_LocalResponseNormalizationOptions,
BuiltinOptions_enum_LSTMOptions,
BuiltinOptions_enum_ResizeBilinearOptions,
BuiltinOptions_enum_CallOptions,
BuiltinOptions_enum_ReshapeOptions,
BuiltinOptions_enum_SkipGramOptions,
BuiltinOptions_enum_SpaceToDepthOptions,
BuiltinOptions_enum_EmbeddingLookupSparseOptions,
BuiltinOptions_enum_MulOptions,
BuiltinOptions_enum_PadOptions,
BuiltinOptions_enum_GatherOptions,
BuiltinOptions_enum_BatchToSpaceNDOptions,
BuiltinOptions_enum_SpaceToBatchNDOptions,
BuiltinOptions_enum_TransposeOptions,
BuiltinOptions_enum_ReducerOptions,
BuiltinOptions_enum_SubOptions,
BuiltinOptions_enum_DivOptions,
BuiltinOptions_enum_SqueezeOptions,
BuiltinOptions_enum_SequenceRNNOptions,
BuiltinOptions_enum_StridedSliceOptions,
BuiltinOptions_enum_ExpOptions,
BuiltinOptions_enum_TopKV2Options,
BuiltinOptions_enum_SplitOptions,
BuiltinOptions_enum_LogSoftmaxOptions,
BuiltinOptions_enum_CastOptions,
BuiltinOptions_enum_DequantizeOptions,
BuiltinOptions_enum_MaximumMinimumOptions,
BuiltinOptions_enum_ArgMaxOptions,
BuiltinOptions_enum_LessOptions,
BuiltinOptions_enum_NegOptions,
BuiltinOptions_enum_PadV2Options,
BuiltinOptions_enum_GreaterOptions,
BuiltinOptions_enum_GreaterEqualOptions,
BuiltinOptions_enum_LessEqualOptions,
BuiltinOptions_enum_SelectOptions,
BuiltinOptions_enum_SliceOptions,
BuiltinOptions_enum_TransposeConvOptions,
BuiltinOptions_enum_SparseToDenseOptions,
BuiltinOptions_enum_TileOptions,
BuiltinOptions_enum_ExpandDimsOptions,
BuiltinOptions_enum_EqualOptions,
BuiltinOptions_enum_NotEqualOptions,
BuiltinOptions_enum_ShapeOptions,
BuiltinOptions_enum_PowOptions,
BuiltinOptions_enum_ArgMinOptions,
BuiltinOptions_enum_FakeQuantOptions,
BuiltinOptions_enum_PackOptions,
BuiltinOptions_enum_LogicalOrOptions,
BuiltinOptions_enum_OneHotOptions,
BuiltinOptions_enum_LogicalAndOptions,
BuiltinOptions_enum_LogicalNotOptions,
BuiltinOptions_enum_UnpackOptions,
BuiltinOptions_enum_FloorDivOptions,
BuiltinOptions_enum_SquareOptions,
BuiltinOptions_enum_ZerosLikeOptions,
BuiltinOptions_enum_FillOptions,
BuiltinOptions_enum_BidirectionalSequenceLSTMOptions,
BuiltinOptions_enum_BidirectionalSequenceRNNOptions,
BuiltinOptions_enum_UnidirectionalSequenceLSTMOptions,
BuiltinOptions_enum_FloorModOptions,
BuiltinOptions_enum_RangeOptions,
BuiltinOptions_enum_ResizeNearestNeighborOptions,
BuiltinOptions_enum_LeakyReluOptions,
BuiltinOptions_enum_SquaredDifferenceOptions,
BuiltinOptions_enum_MirrorPadOptions,
BuiltinOptions_enum_AbsOptions,
BuiltinOptions_enum_SplitVOptions,
BuiltinOptions_enum_UniqueOptions,
BuiltinOptions_enum_ReverseV2Options,
BuiltinOptions_enum_AddNOptions,
BuiltinOptions_enum_GatherNdOptions,
BuiltinOptions_enum_CosOptions,
BuiltinOptions_enum_WhereOptions,
BuiltinOptions_enum_RankOptions,
BuiltinOptions_enum_ReverseSequenceOptions,
BuiltinOptions_enum_MatrixDiagOptions,
BuiltinOptions_enum_QuantizeOptions,
BuiltinOptions_enum_MatrixSetDiagOptions,
BuiltinOptions_enum_HardSwishOptions,
BuiltinOptions_enum_IfOptions,
BuiltinOptions_enum_WhileOptions,
BuiltinOptions_enum_DepthToSpaceOptions,
BuiltinOptions_enum_NonMaxSuppressionV4Options,
BuiltinOptions_enum_NonMaxSuppressionV5Options,
BuiltinOptions_enum_ScatterNdOptions,
BuiltinOptions_enum_SelectV2Options,
BuiltinOptions_enum_DensifyOptions,
BuiltinOptions_enum_SegmentSumOptions,
BuiltinOptions_enum_BatchMatMulOptions,
BuiltinOptions_enum_CumsumOptions,
BuiltinOptions_enum_CallOnceOptions,
BuiltinOptions_enum_BroadcastToOptions,
BuiltinOptions_enum_Rfft2dOptions,
BuiltinOptions_enum_Conv3DOptions,
BuiltinOptions_enum_HashtableOptions,
BuiltinOptions_enum_HashtableFindOptions,
BuiltinOptions_enum_HashtableImportOptions,
BuiltinOptions_enum_HashtableSizeOptions,
BuiltinOptions_enum_VarHandleOptions,
BuiltinOptions_enum_ReadVariableOptions,
BuiltinOptions_enum_AssignVariableOptions,
BuiltinOptions_enum_RandomOptions,
BuiltinOptions_enum_BucketizeOptions,
BuiltinOptions_enum_GeluOptions,
BuiltinOptions_enum_DynamicUpdateSliceOptions,
BuiltinOptions_enum_UnsortedSegmentProdOptions,
BuiltinOptions_enum_UnsortedSegmentMaxOptions,
BuiltinOptions_enum_UnsortedSegmentMinOptions,
BuiltinOptions_enum_UnsortedSegmentSumOptions,
BuiltinOptions_enum_ATan2Options,
BuiltinOptions_enum_SignOptions,
BuiltinOptions_enum_BitcastOptions,
BuiltinOptions_enum_BitwiseXorOptions,
BuiltinOptions_enum_RightShiftOptions,
};

const char * BuiltinOptions_enum_to_string(BuiltinOptions_enum value){switch (value){case BuiltinOptions_enum_Conv2DOptions:return "BuiltinOptions_enum_Conv2DOptions";case BuiltinOptions_enum_DepthwiseConv2DOptions:return "BuiltinOptions_enum_DepthwiseConv2DOptions";case BuiltinOptions_enum_ConcatEmbeddingsOptions:return "BuiltinOptions_enum_ConcatEmbeddingsOptions";case BuiltinOptions_enum_LSHProjectionOptions:return "BuiltinOptions_enum_LSHProjectionOptions";case BuiltinOptions_enum_Pool2DOptions:return "BuiltinOptions_enum_Pool2DOptions";case BuiltinOptions_enum_SVDFOptions:return "BuiltinOptions_enum_SVDFOptions";case BuiltinOptions_enum_RNNOptions:return "BuiltinOptions_enum_RNNOptions";case BuiltinOptions_enum_FullyConnectedOptions:return "BuiltinOptions_enum_FullyConnectedOptions";case BuiltinOptions_enum_SoftmaxOptions:return "BuiltinOptions_enum_SoftmaxOptions";case BuiltinOptions_enum_ConcatenationOptions:return "BuiltinOptions_enum_ConcatenationOptions";case BuiltinOptions_enum_AddOptions:return "BuiltinOptions_enum_AddOptions";case BuiltinOptions_enum_L2NormOptions:return "BuiltinOptions_enum_L2NormOptions";case BuiltinOptions_enum_LocalResponseNormalizationOptions:return "BuiltinOptions_enum_LocalResponseNormalizationOptions";case BuiltinOptions_enum_LSTMOptions:return "BuiltinOptions_enum_LSTMOptions";case BuiltinOptions_enum_ResizeBilinearOptions:return "BuiltinOptions_enum_ResizeBilinearOptions";case BuiltinOptions_enum_CallOptions:return "BuiltinOptions_enum_CallOptions";case BuiltinOptions_enum_ReshapeOptions:return "BuiltinOptions_enum_ReshapeOptions";case BuiltinOptions_enum_SkipGramOptions:return "BuiltinOptions_enum_SkipGramOptions";case BuiltinOptions_enum_SpaceToDepthOptions:return "BuiltinOptions_enum_SpaceToDepthOptions";case BuiltinOptions_enum_EmbeddingLookupSparseOptions:return "BuiltinOptions_enum_EmbeddingLookupSparseOptions";case BuiltinOptions_enum_MulOptions:return "BuiltinOptions_enum_MulOptions";case BuiltinOptions_enum_PadOptions:return "BuiltinOptions_enum_PadOptions";case BuiltinOptions_enum_GatherOptions:return "BuiltinOptions_enum_GatherOptions";case BuiltinOptions_enum_BatchToSpaceNDOptions:return "BuiltinOptions_enum_BatchToSpaceNDOptions";case BuiltinOptions_enum_SpaceToBatchNDOptions:return "BuiltinOptions_enum_SpaceToBatchNDOptions";case BuiltinOptions_enum_TransposeOptions:return "BuiltinOptions_enum_TransposeOptions";case BuiltinOptions_enum_ReducerOptions:return "BuiltinOptions_enum_ReducerOptions";case BuiltinOptions_enum_SubOptions:return "BuiltinOptions_enum_SubOptions";case BuiltinOptions_enum_DivOptions:return "BuiltinOptions_enum_DivOptions";case BuiltinOptions_enum_SqueezeOptions:return "BuiltinOptions_enum_SqueezeOptions";case BuiltinOptions_enum_SequenceRNNOptions:return "BuiltinOptions_enum_SequenceRNNOptions";case BuiltinOptions_enum_StridedSliceOptions:return "BuiltinOptions_enum_StridedSliceOptions";case BuiltinOptions_enum_ExpOptions:return "BuiltinOptions_enum_ExpOptions";case BuiltinOptions_enum_TopKV2Options:return "BuiltinOptions_enum_TopKV2Options";case BuiltinOptions_enum_SplitOptions:return "BuiltinOptions_enum_SplitOptions";case BuiltinOptions_enum_LogSoftmaxOptions:return "BuiltinOptions_enum_LogSoftmaxOptions";case BuiltinOptions_enum_CastOptions:return "BuiltinOptions_enum_CastOptions";case BuiltinOptions_enum_DequantizeOptions:return "BuiltinOptions_enum_DequantizeOptions";case BuiltinOptions_enum_MaximumMinimumOptions:return "BuiltinOptions_enum_MaximumMinimumOptions";case BuiltinOptions_enum_ArgMaxOptions:return "BuiltinOptions_enum_ArgMaxOptions";case BuiltinOptions_enum_LessOptions:return "BuiltinOptions_enum_LessOptions";case BuiltinOptions_enum_NegOptions:return "BuiltinOptions_enum_NegOptions";case BuiltinOptions_enum_PadV2Options:return "BuiltinOptions_enum_PadV2Options";case BuiltinOptions_enum_GreaterOptions:return "BuiltinOptions_enum_GreaterOptions";case BuiltinOptions_enum_GreaterEqualOptions:return "BuiltinOptions_enum_GreaterEqualOptions";case BuiltinOptions_enum_LessEqualOptions:return "BuiltinOptions_enum_LessEqualOptions";case BuiltinOptions_enum_SelectOptions:return "BuiltinOptions_enum_SelectOptions";case BuiltinOptions_enum_SliceOptions:return "BuiltinOptions_enum_SliceOptions";case BuiltinOptions_enum_TransposeConvOptions:return "BuiltinOptions_enum_TransposeConvOptions";case BuiltinOptions_enum_SparseToDenseOptions:return "BuiltinOptions_enum_SparseToDenseOptions";case BuiltinOptions_enum_TileOptions:return "BuiltinOptions_enum_TileOptions";case BuiltinOptions_enum_ExpandDimsOptions:return "BuiltinOptions_enum_ExpandDimsOptions";case BuiltinOptions_enum_EqualOptions:return "BuiltinOptions_enum_EqualOptions";case BuiltinOptions_enum_NotEqualOptions:return "BuiltinOptions_enum_NotEqualOptions";case BuiltinOptions_enum_ShapeOptions:return "BuiltinOptions_enum_ShapeOptions";case BuiltinOptions_enum_PowOptions:return "BuiltinOptions_enum_PowOptions";case BuiltinOptions_enum_ArgMinOptions:return "BuiltinOptions_enum_ArgMinOptions";case BuiltinOptions_enum_FakeQuantOptions:return "BuiltinOptions_enum_FakeQuantOptions";case BuiltinOptions_enum_PackOptions:return "BuiltinOptions_enum_PackOptions";case BuiltinOptions_enum_LogicalOrOptions:return "BuiltinOptions_enum_LogicalOrOptions";case BuiltinOptions_enum_OneHotOptions:return "BuiltinOptions_enum_OneHotOptions";case BuiltinOptions_enum_LogicalAndOptions:return "BuiltinOptions_enum_LogicalAndOptions";case BuiltinOptions_enum_LogicalNotOptions:return "BuiltinOptions_enum_LogicalNotOptions";case BuiltinOptions_enum_UnpackOptions:return "BuiltinOptions_enum_UnpackOptions";case BuiltinOptions_enum_FloorDivOptions:return "BuiltinOptions_enum_FloorDivOptions";case BuiltinOptions_enum_SquareOptions:return "BuiltinOptions_enum_SquareOptions";case BuiltinOptions_enum_ZerosLikeOptions:return "BuiltinOptions_enum_ZerosLikeOptions";case BuiltinOptions_enum_FillOptions:return "BuiltinOptions_enum_FillOptions";case BuiltinOptions_enum_BidirectionalSequenceLSTMOptions:return "BuiltinOptions_enum_BidirectionalSequenceLSTMOptions";case BuiltinOptions_enum_BidirectionalSequenceRNNOptions:return "BuiltinOptions_enum_BidirectionalSequenceRNNOptions";case BuiltinOptions_enum_UnidirectionalSequenceLSTMOptions:return "BuiltinOptions_enum_UnidirectionalSequenceLSTMOptions";case BuiltinOptions_enum_FloorModOptions:return "BuiltinOptions_enum_FloorModOptions";case BuiltinOptions_enum_RangeOptions:return "BuiltinOptions_enum_RangeOptions";case BuiltinOptions_enum_ResizeNearestNeighborOptions:return "BuiltinOptions_enum_ResizeNearestNeighborOptions";case BuiltinOptions_enum_LeakyReluOptions:return "BuiltinOptions_enum_LeakyReluOptions";case BuiltinOptions_enum_SquaredDifferenceOptions:return "BuiltinOptions_enum_SquaredDifferenceOptions";case BuiltinOptions_enum_MirrorPadOptions:return "BuiltinOptions_enum_MirrorPadOptions";case BuiltinOptions_enum_AbsOptions:return "BuiltinOptions_enum_AbsOptions";case BuiltinOptions_enum_SplitVOptions:return "BuiltinOptions_enum_SplitVOptions";case BuiltinOptions_enum_UniqueOptions:return "BuiltinOptions_enum_UniqueOptions";case BuiltinOptions_enum_ReverseV2Options:return "BuiltinOptions_enum_ReverseV2Options";case BuiltinOptions_enum_AddNOptions:return "BuiltinOptions_enum_AddNOptions";case BuiltinOptions_enum_GatherNdOptions:return "BuiltinOptions_enum_GatherNdOptions";case BuiltinOptions_enum_CosOptions:return "BuiltinOptions_enum_CosOptions";case BuiltinOptions_enum_WhereOptions:return "BuiltinOptions_enum_WhereOptions";case BuiltinOptions_enum_RankOptions:return "BuiltinOptions_enum_RankOptions";case BuiltinOptions_enum_ReverseSequenceOptions:return "BuiltinOptions_enum_ReverseSequenceOptions";case BuiltinOptions_enum_MatrixDiagOptions:return "BuiltinOptions_enum_MatrixDiagOptions";case BuiltinOptions_enum_QuantizeOptions:return "BuiltinOptions_enum_QuantizeOptions";case BuiltinOptions_enum_MatrixSetDiagOptions:return "BuiltinOptions_enum_MatrixSetDiagOptions";case BuiltinOptions_enum_HardSwishOptions:return "BuiltinOptions_enum_HardSwishOptions";case BuiltinOptions_enum_IfOptions:return "BuiltinOptions_enum_IfOptions";case BuiltinOptions_enum_WhileOptions:return "BuiltinOptions_enum_WhileOptions";case BuiltinOptions_enum_DepthToSpaceOptions:return "BuiltinOptions_enum_DepthToSpaceOptions";case BuiltinOptions_enum_NonMaxSuppressionV4Options:return "BuiltinOptions_enum_NonMaxSuppressionV4Options";case BuiltinOptions_enum_NonMaxSuppressionV5Options:return "BuiltinOptions_enum_NonMaxSuppressionV5Options";case BuiltinOptions_enum_ScatterNdOptions:return "BuiltinOptions_enum_ScatterNdOptions";case BuiltinOptions_enum_SelectV2Options:return "BuiltinOptions_enum_SelectV2Options";case BuiltinOptions_enum_DensifyOptions:return "BuiltinOptions_enum_DensifyOptions";case BuiltinOptions_enum_SegmentSumOptions:return "BuiltinOptions_enum_SegmentSumOptions";case BuiltinOptions_enum_BatchMatMulOptions:return "BuiltinOptions_enum_BatchMatMulOptions";case BuiltinOptions_enum_CumsumOptions:return "BuiltinOptions_enum_CumsumOptions";case BuiltinOptions_enum_CallOnceOptions:return "BuiltinOptions_enum_CallOnceOptions";case BuiltinOptions_enum_BroadcastToOptions:return "BuiltinOptions_enum_BroadcastToOptions";case BuiltinOptions_enum_Rfft2dOptions:return "BuiltinOptions_enum_Rfft2dOptions";case BuiltinOptions_enum_Conv3DOptions:return "BuiltinOptions_enum_Conv3DOptions";case BuiltinOptions_enum_HashtableOptions:return "BuiltinOptions_enum_HashtableOptions";case BuiltinOptions_enum_HashtableFindOptions:return "BuiltinOptions_enum_HashtableFindOptions";case BuiltinOptions_enum_HashtableImportOptions:return "BuiltinOptions_enum_HashtableImportOptions";case BuiltinOptions_enum_HashtableSizeOptions:return "BuiltinOptions_enum_HashtableSizeOptions";case BuiltinOptions_enum_VarHandleOptions:return "BuiltinOptions_enum_VarHandleOptions";case BuiltinOptions_enum_ReadVariableOptions:return "BuiltinOptions_enum_ReadVariableOptions";case BuiltinOptions_enum_AssignVariableOptions:return "BuiltinOptions_enum_AssignVariableOptions";case BuiltinOptions_enum_RandomOptions:return "BuiltinOptions_enum_RandomOptions";case BuiltinOptions_enum_BucketizeOptions:return "BuiltinOptions_enum_BucketizeOptions";case BuiltinOptions_enum_GeluOptions:return "BuiltinOptions_enum_GeluOptions";case BuiltinOptions_enum_DynamicUpdateSliceOptions:return "BuiltinOptions_enum_DynamicUpdateSliceOptions";case BuiltinOptions_enum_UnsortedSegmentProdOptions:return "BuiltinOptions_enum_UnsortedSegmentProdOptions";case BuiltinOptions_enum_UnsortedSegmentMaxOptions:return "BuiltinOptions_enum_UnsortedSegmentMaxOptions";case BuiltinOptions_enum_UnsortedSegmentMinOptions:return "BuiltinOptions_enum_UnsortedSegmentMinOptions";case BuiltinOptions_enum_UnsortedSegmentSumOptions:return "BuiltinOptions_enum_UnsortedSegmentSumOptions";case BuiltinOptions_enum_ATan2Options:return "BuiltinOptions_enum_ATan2Options";case BuiltinOptions_enum_SignOptions:return "BuiltinOptions_enum_SignOptions";case BuiltinOptions_enum_BitcastOptions:return "BuiltinOptions_enum_BitcastOptions";case BuiltinOptions_enum_BitwiseXorOptions:return "BuiltinOptions_enum_BitwiseXorOptions";case BuiltinOptions_enum_RightShiftOptions:return "BuiltinOptions_enum_RightShiftOptions";default: return NULL;}}

struct Operator {

unsigned char * data_;

Operator(unsigned char * data) : data_(data) {}

#define OPERATOR_MEMBER_SIZE_OFFSET 0
#define OPERATOR_PAD2_OFFSET 2
#define OPERATOR_OPCODE_INDEX_OFFSET 4
#define OPERATOR_INPUTS_OFFSET 8
#define OPERATOR_OUTPUTS_OFFSET 10
#define OPERATOR_BUILTIN_OPTIONS_TYPE_OFFSET 12
#define OPERATOR_PAD14_OFFSET 14
#define OPERATOR_BUILTIN_OPTIONS_OFFSET 16
#define OPERATOR_CUSTOM_OPTIONS_OFFSET 18
#define OPERATOR_CUSTOM_OPTIONS_FORMAT_OFFSET 20
#define OPERATOR_PAD21_OFFSET 21
#define OPERATOR_MUTATING_VARIABLE_INPUTS_OFFSET 22
#define OPERATOR_INTERMEDIATES_OFFSET 24
#define OPERATOR_PAD26_OFFSET 26
#define OPERATOR_LARGE_CUSTOM_OPTIONS_OFFSET_OFFSET 32
#define OPERATOR_LARGE_CUSTOM_OPTIONS_SIZE_OFFSET 40
#define OPERATOR_BUILTIN_OPTIONS_2_TYPE_OFFSET 48
#define OPERATOR_PAD50_OFFSET 50
#define OPERATOR_BUILTIN_OPTIONS_2_OFFSET 56
#define OPERATOR_PAD58_OFFSET 58
#define OPERATOR_DEBUG_METADATA_INDEX_OFFSET 60


uint32_t opcode_index() {if(OPERATOR_OPCODE_INDEX_OFFSET < *reinterpret_cast<uint16_t *>(&data_[OPERATOR_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<uint32_t*>(&data_[OPERATOR_OPCODE_INDEX_OFFSET ]);}}

Vector<int32_t> inputs(){if(OPERATOR_INPUTS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[OPERATOR_MEMBER_SIZE_OFFSET])){const int16_t offset = OPERATOR_INPUTS_OFFSET ;return Vector<int32_t>(&data_[offset]);}}

Vector<int32_t> outputs(){if(OPERATOR_OUTPUTS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[OPERATOR_MEMBER_SIZE_OFFSET])){const int16_t offset = OPERATOR_OUTPUTS_OFFSET ;return Vector<int32_t>(&data_[offset]);}}

BuiltinOptions_enum builtin_options_type() {
if(OPERATOR_BUILTIN_OPTIONS_TYPE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[OPERATOR_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<BuiltinOptions_enum*>(&data_[OPERATOR_BUILTIN_OPTIONS_TYPE_OFFSET ]);}}

Union<BuiltinOptions> builtin_options(){if(OPERATOR_BUILTIN_OPTIONS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[OPERATOR_MEMBER_SIZE_OFFSET])){const int16_t offset = OPERATOR_BUILTIN_OPTIONS_OFFSET - 2;return Union<BuiltinOptions>(&data_[offset]);}}

Vector<uint8_t> custom_options(){if(OPERATOR_CUSTOM_OPTIONS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[OPERATOR_MEMBER_SIZE_OFFSET])){const int16_t offset = OPERATOR_CUSTOM_OPTIONS_OFFSET ;return Vector<uint8_t>(&data_[offset]);}}

CustomOptionsFormat custom_options_format() {
if(OPERATOR_CUSTOM_OPTIONS_FORMAT_OFFSET < *reinterpret_cast<uint16_t *>(&data_[OPERATOR_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<CustomOptionsFormat*>(&data_[OPERATOR_CUSTOM_OPTIONS_FORMAT_OFFSET ]);}}

Vector<bool> mutating_variable_inputs(){if(OPERATOR_MUTATING_VARIABLE_INPUTS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[OPERATOR_MEMBER_SIZE_OFFSET])){const int16_t offset = OPERATOR_MUTATING_VARIABLE_INPUTS_OFFSET ;return Vector<bool>(&data_[offset]);}}

Vector<int32_t> intermediates(){if(OPERATOR_INTERMEDIATES_OFFSET < *reinterpret_cast<uint16_t *>(&data_[OPERATOR_MEMBER_SIZE_OFFSET])){const int16_t offset = OPERATOR_INTERMEDIATES_OFFSET ;return Vector<int32_t>(&data_[offset]);}}

uint64_t large_custom_options_offset() {if(OPERATOR_LARGE_CUSTOM_OPTIONS_OFFSET_OFFSET < *reinterpret_cast<uint16_t *>(&data_[OPERATOR_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<uint64_t*>(&data_[OPERATOR_LARGE_CUSTOM_OPTIONS_OFFSET_OFFSET ]);}}

uint64_t large_custom_options_size() {if(OPERATOR_LARGE_CUSTOM_OPTIONS_SIZE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[OPERATOR_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<uint64_t*>(&data_[OPERATOR_LARGE_CUSTOM_OPTIONS_SIZE_OFFSET ]);}}

BuiltinOptions2_enum builtin_options_2_type() {
if(OPERATOR_BUILTIN_OPTIONS_2_TYPE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[OPERATOR_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<BuiltinOptions2_enum*>(&data_[OPERATOR_BUILTIN_OPTIONS_2_TYPE_OFFSET ]);}}

Union<BuiltinOptions2> builtin_options_2(){if(OPERATOR_BUILTIN_OPTIONS_2_OFFSET < *reinterpret_cast<uint16_t *>(&data_[OPERATOR_MEMBER_SIZE_OFFSET])){const int16_t offset = OPERATOR_BUILTIN_OPTIONS_2_OFFSET - 2;return Union<BuiltinOptions2>(&data_[offset]);}}

int32_t debug_metadata_index() {if(OPERATOR_DEBUG_METADATA_INDEX_OFFSET < *reinterpret_cast<uint16_t *>(&data_[OPERATOR_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[OPERATOR_DEBUG_METADATA_INDEX_OFFSET ]);}}

};



struct OperatorOffset {

unsigned char * data_;

OperatorOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

Operator value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return Operator(&data_[offset]);}};



struct Uint8Vector {

unsigned char * data_;

Uint8Vector(unsigned char * data) : data_(data) {}

#define UINT8VECTOR_MEMBER_SIZE_OFFSET 0
#define UINT8VECTOR_ENUMS_OFFSET 2


Vector<uint8_t> enums(){if(UINT8VECTOR_ENUMS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[UINT8VECTOR_MEMBER_SIZE_OFFSET])){const int16_t offset = UINT8VECTOR_ENUMS_OFFSET ;return Vector<uint8_t>(&data_[offset]);}}

};



struct Uint8VectorOffset {

unsigned char * data_;

Uint8VectorOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

Uint8Vector value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return Uint8Vector(&data_[offset]);}};



struct LessEqualOptions {

unsigned char * data_;

LessEqualOptions(unsigned char * data) : data_(data) {}

#define LESSEQUALOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct LessEqualOptionsOffset {

unsigned char * data_;

LessEqualOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

LessEqualOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return LessEqualOptions(&data_[offset]);}};



struct AddOptions {

unsigned char * data_;

AddOptions(unsigned char * data) : data_(data) {}

#define ADDOPTIONS_MEMBER_SIZE_OFFSET 0
#define ADDOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET 2
#define ADDOPTIONS_POT_SCALE_INT16_OFFSET 3


ActivationFunctionType fused_activation_function() {
if(ADDOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[ADDOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<ActivationFunctionType*>(&data_[ADDOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET ]);}}

bool pot_scale_int16() {if(ADDOPTIONS_POT_SCALE_INT16_OFFSET < *reinterpret_cast<uint16_t *>(&data_[ADDOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[ADDOPTIONS_POT_SCALE_INT16_OFFSET ]);}}

};



struct AddOptionsOffset {

unsigned char * data_;

AddOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

AddOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return AddOptions(&data_[offset]);}};





struct RangeOptions {

unsigned char * data_;

RangeOptions(unsigned char * data) : data_(data) {}

#define RANGEOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct RangeOptionsOffset {

unsigned char * data_;

RangeOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

RangeOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return RangeOptions(&data_[offset]);}};

enum BuiltinOperator : int32_t {

BuiltinOperator_ADD,
BuiltinOperator_AVERAGE_POOL_2D,
BuiltinOperator_CONCATENATION,
BuiltinOperator_CONV_2D,
BuiltinOperator_DEPTHWISE_CONV_2D,
BuiltinOperator_DEPTH_TO_SPACE,
BuiltinOperator_DEQUANTIZE,
BuiltinOperator_EMBEDDING_LOOKUP,
BuiltinOperator_FLOOR,
BuiltinOperator_FULLY_CONNECTED,
BuiltinOperator_HASHTABLE_LOOKUP,
BuiltinOperator_L2_NORMALIZATION,
BuiltinOperator_L2_POOL_2D,
BuiltinOperator_LOCAL_RESPONSE_NORMALIZATION,
BuiltinOperator_LOGISTIC,
BuiltinOperator_LSH_PROJECTION,
BuiltinOperator_LSTM,
BuiltinOperator_MAX_POOL_2D,
BuiltinOperator_MUL,
BuiltinOperator_RELU,
BuiltinOperator_RELU_N1_TO_1,
BuiltinOperator_RELU6,
BuiltinOperator_RESHAPE,
BuiltinOperator_RESIZE_BILINEAR,
BuiltinOperator_RNN,
BuiltinOperator_SOFTMAX,
BuiltinOperator_SPACE_TO_DEPTH,
BuiltinOperator_SVDF,
BuiltinOperator_TANH,
BuiltinOperator_CONCAT_EMBEDDINGS,
BuiltinOperator_SKIP_GRAM,
BuiltinOperator_CALL,
BuiltinOperator_CUSTOM,
BuiltinOperator_EMBEDDING_LOOKUP_SPARSE,
BuiltinOperator_PAD,
BuiltinOperator_UNIDIRECTIONAL_SEQUENCE_RNN,
BuiltinOperator_GATHER,
BuiltinOperator_BATCH_TO_SPACE_ND,
BuiltinOperator_SPACE_TO_BATCH_ND,
BuiltinOperator_TRANSPOSE,
BuiltinOperator_MEAN,
BuiltinOperator_SUB,
BuiltinOperator_DIV,
BuiltinOperator_SQUEEZE,
BuiltinOperator_UNIDIRECTIONAL_SEQUENCE_LSTM,
BuiltinOperator_STRIDED_SLICE,
BuiltinOperator_BIDIRECTIONAL_SEQUENCE_RNN,
BuiltinOperator_EXP,
BuiltinOperator_TOPK_V2,
BuiltinOperator_SPLIT,
BuiltinOperator_LOG_SOFTMAX,
BuiltinOperator_DELEGATE,
BuiltinOperator_BIDIRECTIONAL_SEQUENCE_LSTM,
BuiltinOperator_CAST,
BuiltinOperator_PRELU,
BuiltinOperator_MAXIMUM,
BuiltinOperator_ARG_MAX,
BuiltinOperator_MINIMUM,
BuiltinOperator_LESS,
BuiltinOperator_NEG,
BuiltinOperator_PADV2,
BuiltinOperator_GREATER,
BuiltinOperator_GREATER_EQUAL,
BuiltinOperator_LESS_EQUAL,
BuiltinOperator_SELECT,
BuiltinOperator_SLICE,
BuiltinOperator_SIN,
BuiltinOperator_TRANSPOSE_CONV,
BuiltinOperator_SPARSE_TO_DENSE,
BuiltinOperator_TILE,
BuiltinOperator_EXPAND_DIMS,
BuiltinOperator_EQUAL,
BuiltinOperator_NOT_EQUAL,
BuiltinOperator_LOG,
BuiltinOperator_SUM,
BuiltinOperator_SQRT,
BuiltinOperator_RSQRT,
BuiltinOperator_SHAPE,
BuiltinOperator_POW,
BuiltinOperator_ARG_MIN,
BuiltinOperator_FAKE_QUANT,
BuiltinOperator_REDUCE_PROD,
BuiltinOperator_REDUCE_MAX,
BuiltinOperator_PACK,
BuiltinOperator_LOGICAL_OR,
BuiltinOperator_ONE_HOT,
BuiltinOperator_LOGICAL_AND,
BuiltinOperator_LOGICAL_NOT,
BuiltinOperator_UNPACK,
BuiltinOperator_REDUCE_MIN,
BuiltinOperator_FLOOR_DIV,
BuiltinOperator_REDUCE_ANY,
BuiltinOperator_SQUARE,
BuiltinOperator_ZEROS_LIKE,
BuiltinOperator_FILL,
BuiltinOperator_FLOOR_MOD,
BuiltinOperator_RANGE,
BuiltinOperator_RESIZE_NEAREST_NEIGHBOR,
BuiltinOperator_LEAKY_RELU,
BuiltinOperator_SQUARED_DIFFERENCE,
BuiltinOperator_MIRROR_PAD,
BuiltinOperator_ABS,
BuiltinOperator_SPLIT_V,
BuiltinOperator_UNIQUE,
BuiltinOperator_CEIL,
BuiltinOperator_REVERSE_V2,
BuiltinOperator_ADD_N,
BuiltinOperator_GATHER_ND,
BuiltinOperator_COS,
BuiltinOperator_WHERE,
BuiltinOperator_RANK,
BuiltinOperator_ELU,
BuiltinOperator_REVERSE_SEQUENCE,
BuiltinOperator_MATRIX_DIAG,
BuiltinOperator_QUANTIZE,
BuiltinOperator_MATRIX_SET_DIAG,
BuiltinOperator_ROUND,
BuiltinOperator_HARD_SWISH,
BuiltinOperator_IF,
BuiltinOperator_WHILE,
BuiltinOperator_NON_MAX_SUPPRESSION_V4,
BuiltinOperator_NON_MAX_SUPPRESSION_V5,
BuiltinOperator_SCATTER_ND,
BuiltinOperator_SELECT_V2,
BuiltinOperator_DENSIFY,
BuiltinOperator_SEGMENT_SUM,
BuiltinOperator_BATCH_MATMUL,
BuiltinOperator_PLACEHOLDER_FOR_GREATER_OP_CODES,
BuiltinOperator_CUMSUM,
BuiltinOperator_CALL_ONCE,
BuiltinOperator_BROADCAST_TO,
BuiltinOperator_RFFT2D,
BuiltinOperator_CONV_3D,
BuiltinOperator_IMAG,
BuiltinOperator_REAL,
BuiltinOperator_COMPLEX_ABS,
BuiltinOperator_HASHTABLE,
BuiltinOperator_HASHTABLE_FIND,
BuiltinOperator_HASHTABLE_IMPORT,
BuiltinOperator_HASHTABLE_SIZE,
BuiltinOperator_REDUCE_ALL,
BuiltinOperator_CONV_3D_TRANSPOSE,
BuiltinOperator_VAR_HANDLE,
BuiltinOperator_READ_VARIABLE,
BuiltinOperator_ASSIGN_VARIABLE,
BuiltinOperator_BROADCAST_ARGS,
BuiltinOperator_RANDOM_STANDARD_NORMAL,
BuiltinOperator_BUCKETIZE,
BuiltinOperator_RANDOM_UNIFORM,
BuiltinOperator_MULTINOMIAL,
BuiltinOperator_GELU,
BuiltinOperator_DYNAMIC_UPDATE_SLICE,
BuiltinOperator_RELU_0_TO_1,
BuiltinOperator_UNSORTED_SEGMENT_PROD,
BuiltinOperator_UNSORTED_SEGMENT_MAX,
BuiltinOperator_UNSORTED_SEGMENT_SUM,
BuiltinOperator_ATAN2,
BuiltinOperator_UNSORTED_SEGMENT_MIN,
BuiltinOperator_SIGN,
BuiltinOperator_BITCAST,
BuiltinOperator_BITWISE_XOR,
BuiltinOperator_RIGHT_SHIFT,
BuiltinOperator_STABLEHLO_LOGISTIC,
BuiltinOperator_STABLEHLO_ADD,
BuiltinOperator_STABLEHLO_DIVIDE,
BuiltinOperator_STABLEHLO_MULTIPLY,
BuiltinOperator_STABLEHLO_MAXIMUM,
BuiltinOperator_STABLEHLO_RESHAPE,
BuiltinOperator_STABLEHLO_CLAMP,
BuiltinOperator_STABLEHLO_CONCATENATE,
BuiltinOperator_STABLEHLO_BROADCAST_IN_DIM,
BuiltinOperator_STABLEHLO_CONVOLUTION,
BuiltinOperator_STABLEHLO_SLICE,
BuiltinOperator_STABLEHLO_CUSTOM_CALL,
BuiltinOperator_STABLEHLO_REDUCE,
BuiltinOperator_STABLEHLO_ABS,
BuiltinOperator_STABLEHLO_AND,
BuiltinOperator_STABLEHLO_COSINE,
BuiltinOperator_STABLEHLO_EXPONENTIAL,
BuiltinOperator_STABLEHLO_FLOOR,
BuiltinOperator_STABLEHLO_LOG,
BuiltinOperator_STABLEHLO_MINIMUM,
BuiltinOperator_STABLEHLO_NEGATE,
BuiltinOperator_STABLEHLO_OR,
BuiltinOperator_STABLEHLO_POWER,
BuiltinOperator_STABLEHLO_REMAINDER,
BuiltinOperator_STABLEHLO_RSQRT,
BuiltinOperator_STABLEHLO_SELECT,
BuiltinOperator_STABLEHLO_SUBTRACT,
BuiltinOperator_STABLEHLO_TANH,
BuiltinOperator_STABLEHLO_SCATTER,
BuiltinOperator_STABLEHLO_COMPARE,
BuiltinOperator_STABLEHLO_CONVERT,
BuiltinOperator_STABLEHLO_DYNAMIC_SLICE,
BuiltinOperator_STABLEHLO_DYNAMIC_UPDATE_SLICE,
BuiltinOperator_STABLEHLO_PAD,
BuiltinOperator_STABLEHLO_IOTA,
BuiltinOperator_STABLEHLO_DOT_GENERAL,
BuiltinOperator_STABLEHLO_REDUCE_WINDOW,
BuiltinOperator_STABLEHLO_SORT,
BuiltinOperator_STABLEHLO_WHILE,
BuiltinOperator_STABLEHLO_GATHER,
BuiltinOperator_STABLEHLO_TRANSPOSE,
BuiltinOperator_DILATE,
BuiltinOperator_STABLEHLO_RNG_BIT_GENERATOR,
BuiltinOperator_REDUCE_WINDOW_DEPRECATED,
BuiltinOperator_STABLEHLO_COMPOSITE,
BuiltinOperator_STABLEHLO_SHIFT_LEFT,
BuiltinOperator_STABLEHLO_CBRT,
BuiltinOperator_STABLEHLO_CASE,
};

const char * BuiltinOperator_to_string(BuiltinOperator value){switch (value){case BuiltinOperator_ADD:return "BuiltinOperator_ADD";case BuiltinOperator_AVERAGE_POOL_2D:return "BuiltinOperator_AVERAGE_POOL_2D";case BuiltinOperator_CONCATENATION:return "BuiltinOperator_CONCATENATION";case BuiltinOperator_CONV_2D:return "BuiltinOperator_CONV_2D";case BuiltinOperator_DEPTHWISE_CONV_2D:return "BuiltinOperator_DEPTHWISE_CONV_2D";case BuiltinOperator_DEPTH_TO_SPACE:return "BuiltinOperator_DEPTH_TO_SPACE";case BuiltinOperator_DEQUANTIZE:return "BuiltinOperator_DEQUANTIZE";case BuiltinOperator_EMBEDDING_LOOKUP:return "BuiltinOperator_EMBEDDING_LOOKUP";case BuiltinOperator_FLOOR:return "BuiltinOperator_FLOOR";case BuiltinOperator_FULLY_CONNECTED:return "BuiltinOperator_FULLY_CONNECTED";case BuiltinOperator_HASHTABLE_LOOKUP:return "BuiltinOperator_HASHTABLE_LOOKUP";case BuiltinOperator_L2_NORMALIZATION:return "BuiltinOperator_L2_NORMALIZATION";case BuiltinOperator_L2_POOL_2D:return "BuiltinOperator_L2_POOL_2D";case BuiltinOperator_LOCAL_RESPONSE_NORMALIZATION:return "BuiltinOperator_LOCAL_RESPONSE_NORMALIZATION";case BuiltinOperator_LOGISTIC:return "BuiltinOperator_LOGISTIC";case BuiltinOperator_LSH_PROJECTION:return "BuiltinOperator_LSH_PROJECTION";case BuiltinOperator_LSTM:return "BuiltinOperator_LSTM";case BuiltinOperator_MAX_POOL_2D:return "BuiltinOperator_MAX_POOL_2D";case BuiltinOperator_MUL:return "BuiltinOperator_MUL";case BuiltinOperator_RELU:return "BuiltinOperator_RELU";case BuiltinOperator_RELU_N1_TO_1:return "BuiltinOperator_RELU_N1_TO_1";case BuiltinOperator_RELU6:return "BuiltinOperator_RELU6";case BuiltinOperator_RESHAPE:return "BuiltinOperator_RESHAPE";case BuiltinOperator_RESIZE_BILINEAR:return "BuiltinOperator_RESIZE_BILINEAR";case BuiltinOperator_RNN:return "BuiltinOperator_RNN";case BuiltinOperator_SOFTMAX:return "BuiltinOperator_SOFTMAX";case BuiltinOperator_SPACE_TO_DEPTH:return "BuiltinOperator_SPACE_TO_DEPTH";case BuiltinOperator_SVDF:return "BuiltinOperator_SVDF";case BuiltinOperator_TANH:return "BuiltinOperator_TANH";case BuiltinOperator_CONCAT_EMBEDDINGS:return "BuiltinOperator_CONCAT_EMBEDDINGS";case BuiltinOperator_SKIP_GRAM:return "BuiltinOperator_SKIP_GRAM";case BuiltinOperator_CALL:return "BuiltinOperator_CALL";case BuiltinOperator_CUSTOM:return "BuiltinOperator_CUSTOM";case BuiltinOperator_EMBEDDING_LOOKUP_SPARSE:return "BuiltinOperator_EMBEDDING_LOOKUP_SPARSE";case BuiltinOperator_PAD:return "BuiltinOperator_PAD";case BuiltinOperator_UNIDIRECTIONAL_SEQUENCE_RNN:return "BuiltinOperator_UNIDIRECTIONAL_SEQUENCE_RNN";case BuiltinOperator_GATHER:return "BuiltinOperator_GATHER";case BuiltinOperator_BATCH_TO_SPACE_ND:return "BuiltinOperator_BATCH_TO_SPACE_ND";case BuiltinOperator_SPACE_TO_BATCH_ND:return "BuiltinOperator_SPACE_TO_BATCH_ND";case BuiltinOperator_TRANSPOSE:return "BuiltinOperator_TRANSPOSE";case BuiltinOperator_MEAN:return "BuiltinOperator_MEAN";case BuiltinOperator_SUB:return "BuiltinOperator_SUB";case BuiltinOperator_DIV:return "BuiltinOperator_DIV";case BuiltinOperator_SQUEEZE:return "BuiltinOperator_SQUEEZE";case BuiltinOperator_UNIDIRECTIONAL_SEQUENCE_LSTM:return "BuiltinOperator_UNIDIRECTIONAL_SEQUENCE_LSTM";case BuiltinOperator_STRIDED_SLICE:return "BuiltinOperator_STRIDED_SLICE";case BuiltinOperator_BIDIRECTIONAL_SEQUENCE_RNN:return "BuiltinOperator_BIDIRECTIONAL_SEQUENCE_RNN";case BuiltinOperator_EXP:return "BuiltinOperator_EXP";case BuiltinOperator_TOPK_V2:return "BuiltinOperator_TOPK_V2";case BuiltinOperator_SPLIT:return "BuiltinOperator_SPLIT";case BuiltinOperator_LOG_SOFTMAX:return "BuiltinOperator_LOG_SOFTMAX";case BuiltinOperator_DELEGATE:return "BuiltinOperator_DELEGATE";case BuiltinOperator_BIDIRECTIONAL_SEQUENCE_LSTM:return "BuiltinOperator_BIDIRECTIONAL_SEQUENCE_LSTM";case BuiltinOperator_CAST:return "BuiltinOperator_CAST";case BuiltinOperator_PRELU:return "BuiltinOperator_PRELU";case BuiltinOperator_MAXIMUM:return "BuiltinOperator_MAXIMUM";case BuiltinOperator_ARG_MAX:return "BuiltinOperator_ARG_MAX";case BuiltinOperator_MINIMUM:return "BuiltinOperator_MINIMUM";case BuiltinOperator_LESS:return "BuiltinOperator_LESS";case BuiltinOperator_NEG:return "BuiltinOperator_NEG";case BuiltinOperator_PADV2:return "BuiltinOperator_PADV2";case BuiltinOperator_GREATER:return "BuiltinOperator_GREATER";case BuiltinOperator_GREATER_EQUAL:return "BuiltinOperator_GREATER_EQUAL";case BuiltinOperator_LESS_EQUAL:return "BuiltinOperator_LESS_EQUAL";case BuiltinOperator_SELECT:return "BuiltinOperator_SELECT";case BuiltinOperator_SLICE:return "BuiltinOperator_SLICE";case BuiltinOperator_SIN:return "BuiltinOperator_SIN";case BuiltinOperator_TRANSPOSE_CONV:return "BuiltinOperator_TRANSPOSE_CONV";case BuiltinOperator_SPARSE_TO_DENSE:return "BuiltinOperator_SPARSE_TO_DENSE";case BuiltinOperator_TILE:return "BuiltinOperator_TILE";case BuiltinOperator_EXPAND_DIMS:return "BuiltinOperator_EXPAND_DIMS";case BuiltinOperator_EQUAL:return "BuiltinOperator_EQUAL";case BuiltinOperator_NOT_EQUAL:return "BuiltinOperator_NOT_EQUAL";case BuiltinOperator_LOG:return "BuiltinOperator_LOG";case BuiltinOperator_SUM:return "BuiltinOperator_SUM";case BuiltinOperator_SQRT:return "BuiltinOperator_SQRT";case BuiltinOperator_RSQRT:return "BuiltinOperator_RSQRT";case BuiltinOperator_SHAPE:return "BuiltinOperator_SHAPE";case BuiltinOperator_POW:return "BuiltinOperator_POW";case BuiltinOperator_ARG_MIN:return "BuiltinOperator_ARG_MIN";case BuiltinOperator_FAKE_QUANT:return "BuiltinOperator_FAKE_QUANT";case BuiltinOperator_REDUCE_PROD:return "BuiltinOperator_REDUCE_PROD";case BuiltinOperator_REDUCE_MAX:return "BuiltinOperator_REDUCE_MAX";case BuiltinOperator_PACK:return "BuiltinOperator_PACK";case BuiltinOperator_LOGICAL_OR:return "BuiltinOperator_LOGICAL_OR";case BuiltinOperator_ONE_HOT:return "BuiltinOperator_ONE_HOT";case BuiltinOperator_LOGICAL_AND:return "BuiltinOperator_LOGICAL_AND";case BuiltinOperator_LOGICAL_NOT:return "BuiltinOperator_LOGICAL_NOT";case BuiltinOperator_UNPACK:return "BuiltinOperator_UNPACK";case BuiltinOperator_REDUCE_MIN:return "BuiltinOperator_REDUCE_MIN";case BuiltinOperator_FLOOR_DIV:return "BuiltinOperator_FLOOR_DIV";case BuiltinOperator_REDUCE_ANY:return "BuiltinOperator_REDUCE_ANY";case BuiltinOperator_SQUARE:return "BuiltinOperator_SQUARE";case BuiltinOperator_ZEROS_LIKE:return "BuiltinOperator_ZEROS_LIKE";case BuiltinOperator_FILL:return "BuiltinOperator_FILL";case BuiltinOperator_FLOOR_MOD:return "BuiltinOperator_FLOOR_MOD";case BuiltinOperator_RANGE:return "BuiltinOperator_RANGE";case BuiltinOperator_RESIZE_NEAREST_NEIGHBOR:return "BuiltinOperator_RESIZE_NEAREST_NEIGHBOR";case BuiltinOperator_LEAKY_RELU:return "BuiltinOperator_LEAKY_RELU";case BuiltinOperator_SQUARED_DIFFERENCE:return "BuiltinOperator_SQUARED_DIFFERENCE";case BuiltinOperator_MIRROR_PAD:return "BuiltinOperator_MIRROR_PAD";case BuiltinOperator_ABS:return "BuiltinOperator_ABS";case BuiltinOperator_SPLIT_V:return "BuiltinOperator_SPLIT_V";case BuiltinOperator_UNIQUE:return "BuiltinOperator_UNIQUE";case BuiltinOperator_CEIL:return "BuiltinOperator_CEIL";case BuiltinOperator_REVERSE_V2:return "BuiltinOperator_REVERSE_V2";case BuiltinOperator_ADD_N:return "BuiltinOperator_ADD_N";case BuiltinOperator_GATHER_ND:return "BuiltinOperator_GATHER_ND";case BuiltinOperator_COS:return "BuiltinOperator_COS";case BuiltinOperator_WHERE:return "BuiltinOperator_WHERE";case BuiltinOperator_RANK:return "BuiltinOperator_RANK";case BuiltinOperator_ELU:return "BuiltinOperator_ELU";case BuiltinOperator_REVERSE_SEQUENCE:return "BuiltinOperator_REVERSE_SEQUENCE";case BuiltinOperator_MATRIX_DIAG:return "BuiltinOperator_MATRIX_DIAG";case BuiltinOperator_QUANTIZE:return "BuiltinOperator_QUANTIZE";case BuiltinOperator_MATRIX_SET_DIAG:return "BuiltinOperator_MATRIX_SET_DIAG";case BuiltinOperator_ROUND:return "BuiltinOperator_ROUND";case BuiltinOperator_HARD_SWISH:return "BuiltinOperator_HARD_SWISH";case BuiltinOperator_IF:return "BuiltinOperator_IF";case BuiltinOperator_WHILE:return "BuiltinOperator_WHILE";case BuiltinOperator_NON_MAX_SUPPRESSION_V4:return "BuiltinOperator_NON_MAX_SUPPRESSION_V4";case BuiltinOperator_NON_MAX_SUPPRESSION_V5:return "BuiltinOperator_NON_MAX_SUPPRESSION_V5";case BuiltinOperator_SCATTER_ND:return "BuiltinOperator_SCATTER_ND";case BuiltinOperator_SELECT_V2:return "BuiltinOperator_SELECT_V2";case BuiltinOperator_DENSIFY:return "BuiltinOperator_DENSIFY";case BuiltinOperator_SEGMENT_SUM:return "BuiltinOperator_SEGMENT_SUM";case BuiltinOperator_BATCH_MATMUL:return "BuiltinOperator_BATCH_MATMUL";case BuiltinOperator_PLACEHOLDER_FOR_GREATER_OP_CODES:return "BuiltinOperator_PLACEHOLDER_FOR_GREATER_OP_CODES";case BuiltinOperator_CUMSUM:return "BuiltinOperator_CUMSUM";case BuiltinOperator_CALL_ONCE:return "BuiltinOperator_CALL_ONCE";case BuiltinOperator_BROADCAST_TO:return "BuiltinOperator_BROADCAST_TO";case BuiltinOperator_RFFT2D:return "BuiltinOperator_RFFT2D";case BuiltinOperator_CONV_3D:return "BuiltinOperator_CONV_3D";case BuiltinOperator_IMAG:return "BuiltinOperator_IMAG";case BuiltinOperator_REAL:return "BuiltinOperator_REAL";case BuiltinOperator_COMPLEX_ABS:return "BuiltinOperator_COMPLEX_ABS";case BuiltinOperator_HASHTABLE:return "BuiltinOperator_HASHTABLE";case BuiltinOperator_HASHTABLE_FIND:return "BuiltinOperator_HASHTABLE_FIND";case BuiltinOperator_HASHTABLE_IMPORT:return "BuiltinOperator_HASHTABLE_IMPORT";case BuiltinOperator_HASHTABLE_SIZE:return "BuiltinOperator_HASHTABLE_SIZE";case BuiltinOperator_REDUCE_ALL:return "BuiltinOperator_REDUCE_ALL";case BuiltinOperator_CONV_3D_TRANSPOSE:return "BuiltinOperator_CONV_3D_TRANSPOSE";case BuiltinOperator_VAR_HANDLE:return "BuiltinOperator_VAR_HANDLE";case BuiltinOperator_READ_VARIABLE:return "BuiltinOperator_READ_VARIABLE";case BuiltinOperator_ASSIGN_VARIABLE:return "BuiltinOperator_ASSIGN_VARIABLE";case BuiltinOperator_BROADCAST_ARGS:return "BuiltinOperator_BROADCAST_ARGS";case BuiltinOperator_RANDOM_STANDARD_NORMAL:return "BuiltinOperator_RANDOM_STANDARD_NORMAL";case BuiltinOperator_BUCKETIZE:return "BuiltinOperator_BUCKETIZE";case BuiltinOperator_RANDOM_UNIFORM:return "BuiltinOperator_RANDOM_UNIFORM";case BuiltinOperator_MULTINOMIAL:return "BuiltinOperator_MULTINOMIAL";case BuiltinOperator_GELU:return "BuiltinOperator_GELU";case BuiltinOperator_DYNAMIC_UPDATE_SLICE:return "BuiltinOperator_DYNAMIC_UPDATE_SLICE";case BuiltinOperator_RELU_0_TO_1:return "BuiltinOperator_RELU_0_TO_1";case BuiltinOperator_UNSORTED_SEGMENT_PROD:return "BuiltinOperator_UNSORTED_SEGMENT_PROD";case BuiltinOperator_UNSORTED_SEGMENT_MAX:return "BuiltinOperator_UNSORTED_SEGMENT_MAX";case BuiltinOperator_UNSORTED_SEGMENT_SUM:return "BuiltinOperator_UNSORTED_SEGMENT_SUM";case BuiltinOperator_ATAN2:return "BuiltinOperator_ATAN2";case BuiltinOperator_UNSORTED_SEGMENT_MIN:return "BuiltinOperator_UNSORTED_SEGMENT_MIN";case BuiltinOperator_SIGN:return "BuiltinOperator_SIGN";case BuiltinOperator_BITCAST:return "BuiltinOperator_BITCAST";case BuiltinOperator_BITWISE_XOR:return "BuiltinOperator_BITWISE_XOR";case BuiltinOperator_RIGHT_SHIFT:return "BuiltinOperator_RIGHT_SHIFT";case BuiltinOperator_STABLEHLO_LOGISTIC:return "BuiltinOperator_STABLEHLO_LOGISTIC";case BuiltinOperator_STABLEHLO_ADD:return "BuiltinOperator_STABLEHLO_ADD";case BuiltinOperator_STABLEHLO_DIVIDE:return "BuiltinOperator_STABLEHLO_DIVIDE";case BuiltinOperator_STABLEHLO_MULTIPLY:return "BuiltinOperator_STABLEHLO_MULTIPLY";case BuiltinOperator_STABLEHLO_MAXIMUM:return "BuiltinOperator_STABLEHLO_MAXIMUM";case BuiltinOperator_STABLEHLO_RESHAPE:return "BuiltinOperator_STABLEHLO_RESHAPE";case BuiltinOperator_STABLEHLO_CLAMP:return "BuiltinOperator_STABLEHLO_CLAMP";case BuiltinOperator_STABLEHLO_CONCATENATE:return "BuiltinOperator_STABLEHLO_CONCATENATE";case BuiltinOperator_STABLEHLO_BROADCAST_IN_DIM:return "BuiltinOperator_STABLEHLO_BROADCAST_IN_DIM";case BuiltinOperator_STABLEHLO_CONVOLUTION:return "BuiltinOperator_STABLEHLO_CONVOLUTION";case BuiltinOperator_STABLEHLO_SLICE:return "BuiltinOperator_STABLEHLO_SLICE";case BuiltinOperator_STABLEHLO_CUSTOM_CALL:return "BuiltinOperator_STABLEHLO_CUSTOM_CALL";case BuiltinOperator_STABLEHLO_REDUCE:return "BuiltinOperator_STABLEHLO_REDUCE";case BuiltinOperator_STABLEHLO_ABS:return "BuiltinOperator_STABLEHLO_ABS";case BuiltinOperator_STABLEHLO_AND:return "BuiltinOperator_STABLEHLO_AND";case BuiltinOperator_STABLEHLO_COSINE:return "BuiltinOperator_STABLEHLO_COSINE";case BuiltinOperator_STABLEHLO_EXPONENTIAL:return "BuiltinOperator_STABLEHLO_EXPONENTIAL";case BuiltinOperator_STABLEHLO_FLOOR:return "BuiltinOperator_STABLEHLO_FLOOR";case BuiltinOperator_STABLEHLO_LOG:return "BuiltinOperator_STABLEHLO_LOG";case BuiltinOperator_STABLEHLO_MINIMUM:return "BuiltinOperator_STABLEHLO_MINIMUM";case BuiltinOperator_STABLEHLO_NEGATE:return "BuiltinOperator_STABLEHLO_NEGATE";case BuiltinOperator_STABLEHLO_OR:return "BuiltinOperator_STABLEHLO_OR";case BuiltinOperator_STABLEHLO_POWER:return "BuiltinOperator_STABLEHLO_POWER";case BuiltinOperator_STABLEHLO_REMAINDER:return "BuiltinOperator_STABLEHLO_REMAINDER";case BuiltinOperator_STABLEHLO_RSQRT:return "BuiltinOperator_STABLEHLO_RSQRT";case BuiltinOperator_STABLEHLO_SELECT:return "BuiltinOperator_STABLEHLO_SELECT";case BuiltinOperator_STABLEHLO_SUBTRACT:return "BuiltinOperator_STABLEHLO_SUBTRACT";case BuiltinOperator_STABLEHLO_TANH:return "BuiltinOperator_STABLEHLO_TANH";case BuiltinOperator_STABLEHLO_SCATTER:return "BuiltinOperator_STABLEHLO_SCATTER";case BuiltinOperator_STABLEHLO_COMPARE:return "BuiltinOperator_STABLEHLO_COMPARE";case BuiltinOperator_STABLEHLO_CONVERT:return "BuiltinOperator_STABLEHLO_CONVERT";case BuiltinOperator_STABLEHLO_DYNAMIC_SLICE:return "BuiltinOperator_STABLEHLO_DYNAMIC_SLICE";case BuiltinOperator_STABLEHLO_DYNAMIC_UPDATE_SLICE:return "BuiltinOperator_STABLEHLO_DYNAMIC_UPDATE_SLICE";case BuiltinOperator_STABLEHLO_PAD:return "BuiltinOperator_STABLEHLO_PAD";case BuiltinOperator_STABLEHLO_IOTA:return "BuiltinOperator_STABLEHLO_IOTA";case BuiltinOperator_STABLEHLO_DOT_GENERAL:return "BuiltinOperator_STABLEHLO_DOT_GENERAL";case BuiltinOperator_STABLEHLO_REDUCE_WINDOW:return "BuiltinOperator_STABLEHLO_REDUCE_WINDOW";case BuiltinOperator_STABLEHLO_SORT:return "BuiltinOperator_STABLEHLO_SORT";case BuiltinOperator_STABLEHLO_WHILE:return "BuiltinOperator_STABLEHLO_WHILE";case BuiltinOperator_STABLEHLO_GATHER:return "BuiltinOperator_STABLEHLO_GATHER";case BuiltinOperator_STABLEHLO_TRANSPOSE:return "BuiltinOperator_STABLEHLO_TRANSPOSE";case BuiltinOperator_DILATE:return "BuiltinOperator_DILATE";case BuiltinOperator_STABLEHLO_RNG_BIT_GENERATOR:return "BuiltinOperator_STABLEHLO_RNG_BIT_GENERATOR";case BuiltinOperator_REDUCE_WINDOW_DEPRECATED:return "BuiltinOperator_REDUCE_WINDOW_DEPRECATED";case BuiltinOperator_STABLEHLO_COMPOSITE:return "BuiltinOperator_STABLEHLO_COMPOSITE";case BuiltinOperator_STABLEHLO_SHIFT_LEFT:return "BuiltinOperator_STABLEHLO_SHIFT_LEFT";case BuiltinOperator_STABLEHLO_CBRT:return "BuiltinOperator_STABLEHLO_CBRT";case BuiltinOperator_STABLEHLO_CASE:return "BuiltinOperator_STABLEHLO_CASE";default: return NULL;}}

struct OperatorCode {

unsigned char * data_;

OperatorCode(unsigned char * data) : data_(data) {}

#define OPERATORCODE_MEMBER_SIZE_OFFSET 0
#define OPERATORCODE_DEPRECATED_BUILTIN_CODE_OFFSET 2
#define OPERATORCODE_PAD3_OFFSET 3
#define OPERATORCODE_CUSTOM_CODE_OFFSET 4
#define OPERATORCODE_PAD6_OFFSET 6
#define OPERATORCODE_VERSION_OFFSET 8
#define OPERATORCODE_BUILTIN_CODE_OFFSET 12


uint8_t deprecated_builtin_code() {if(OPERATORCODE_DEPRECATED_BUILTIN_CODE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[OPERATORCODE_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<uint8_t*>(&data_[OPERATORCODE_DEPRECATED_BUILTIN_CODE_OFFSET ]);}}

StringOffset custom_code(){if(OPERATORCODE_CUSTOM_CODE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[OPERATORCODE_MEMBER_SIZE_OFFSET])){const int16_t offset = OPERATORCODE_CUSTOM_CODE_OFFSET ;return StringOffset(&data_[offset]);}}

int32_t version() {if(OPERATORCODE_VERSION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[OPERATORCODE_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[OPERATORCODE_VERSION_OFFSET ]);}}

BuiltinOperator builtin_code() {
if(OPERATORCODE_BUILTIN_CODE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[OPERATORCODE_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<BuiltinOperator*>(&data_[OPERATORCODE_BUILTIN_CODE_OFFSET ]);}}

};



struct OperatorCodeOffset {

unsigned char * data_;

OperatorCodeOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

OperatorCode value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return OperatorCode(&data_[offset]);}};enum QuantizationDetails_enum : uint16_t {

QuantizationDetails_enum_CustomQuantization,
QuantizationDetails_enum_BlockwiseQuantization,
};

const char * QuantizationDetails_enum_to_string(QuantizationDetails_enum value){switch (value){case QuantizationDetails_enum_CustomQuantization:return "QuantizationDetails_enum_CustomQuantization";case QuantizationDetails_enum_BlockwiseQuantization:return "QuantizationDetails_enum_BlockwiseQuantization";default: return NULL;}}

struct QuantizationParameters {

unsigned char * data_;

QuantizationParameters(unsigned char * data) : data_(data) {}

#define QUANTIZATIONPARAMETERS_MEMBER_SIZE_OFFSET 0
#define QUANTIZATIONPARAMETERS_MIN_OFFSET 2
#define QUANTIZATIONPARAMETERS_MAX_OFFSET 4
#define QUANTIZATIONPARAMETERS_SCALE_OFFSET 6
#define QUANTIZATIONPARAMETERS_ZERO_POINT_OFFSET 8
#define QUANTIZATIONPARAMETERS_DETAILS_TYPE_OFFSET 10
#define QUANTIZATIONPARAMETERS_DETAILS_OFFSET 12
#define QUANTIZATIONPARAMETERS_PAD14_OFFSET 14
#define QUANTIZATIONPARAMETERS_QUANTIZED_DIMENSION_OFFSET 16


Vector<float> min(){if(QUANTIZATIONPARAMETERS_MIN_OFFSET < *reinterpret_cast<uint16_t *>(&data_[QUANTIZATIONPARAMETERS_MEMBER_SIZE_OFFSET])){const int16_t offset = QUANTIZATIONPARAMETERS_MIN_OFFSET ;return Vector<float>(&data_[offset]);}}

Vector<float> max(){if(QUANTIZATIONPARAMETERS_MAX_OFFSET < *reinterpret_cast<uint16_t *>(&data_[QUANTIZATIONPARAMETERS_MEMBER_SIZE_OFFSET])){const int16_t offset = QUANTIZATIONPARAMETERS_MAX_OFFSET ;return Vector<float>(&data_[offset]);}}

Vector<float> scale(){if(QUANTIZATIONPARAMETERS_SCALE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[QUANTIZATIONPARAMETERS_MEMBER_SIZE_OFFSET])){const int16_t offset = QUANTIZATIONPARAMETERS_SCALE_OFFSET ;return Vector<float>(&data_[offset]);}}

Vector<int64_t> zero_point(){if(QUANTIZATIONPARAMETERS_ZERO_POINT_OFFSET < *reinterpret_cast<uint16_t *>(&data_[QUANTIZATIONPARAMETERS_MEMBER_SIZE_OFFSET])){const int16_t offset = QUANTIZATIONPARAMETERS_ZERO_POINT_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

QuantizationDetails_enum details_type() {
if(QUANTIZATIONPARAMETERS_DETAILS_TYPE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[QUANTIZATIONPARAMETERS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<QuantizationDetails_enum*>(&data_[QUANTIZATIONPARAMETERS_DETAILS_TYPE_OFFSET ]);}}

Union<QuantizationDetails> details(){if(QUANTIZATIONPARAMETERS_DETAILS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[QUANTIZATIONPARAMETERS_MEMBER_SIZE_OFFSET])){const int16_t offset = QUANTIZATIONPARAMETERS_DETAILS_OFFSET - 2;return Union<QuantizationDetails>(&data_[offset]);}}

int32_t quantized_dimension() {if(QUANTIZATIONPARAMETERS_QUANTIZED_DIMENSION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[QUANTIZATIONPARAMETERS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[QUANTIZATIONPARAMETERS_QUANTIZED_DIMENSION_OFFSET ]);}}

};



struct QuantizationParametersOffset {

unsigned char * data_;

QuantizationParametersOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

QuantizationParameters value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return QuantizationParameters(&data_[offset]);}};

struct SparsityParameters {

unsigned char * data_;

SparsityParameters(unsigned char * data) : data_(data) {}

#define SPARSITYPARAMETERS_MEMBER_SIZE_OFFSET 0
#define SPARSITYPARAMETERS_TRAVERSAL_ORDER_OFFSET 2
#define SPARSITYPARAMETERS_BLOCK_MAP_OFFSET 4
#define SPARSITYPARAMETERS_DIM_METADATA_OFFSET 6


Vector<int32_t> traversal_order(){if(SPARSITYPARAMETERS_TRAVERSAL_ORDER_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SPARSITYPARAMETERS_MEMBER_SIZE_OFFSET])){const int16_t offset = SPARSITYPARAMETERS_TRAVERSAL_ORDER_OFFSET ;return Vector<int32_t>(&data_[offset]);}}

Vector<int32_t> block_map(){if(SPARSITYPARAMETERS_BLOCK_MAP_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SPARSITYPARAMETERS_MEMBER_SIZE_OFFSET])){const int16_t offset = SPARSITYPARAMETERS_BLOCK_MAP_OFFSET ;return Vector<int32_t>(&data_[offset]);}}

Vector<DimensionMetadataOffset> dim_metadata(){if(SPARSITYPARAMETERS_DIM_METADATA_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SPARSITYPARAMETERS_MEMBER_SIZE_OFFSET])){const int16_t offset = SPARSITYPARAMETERS_DIM_METADATA_OFFSET ;return Vector<DimensionMetadataOffset>(&data_[offset]);}}

};



struct SparsityParametersOffset {

unsigned char * data_;

SparsityParametersOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

SparsityParameters value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return SparsityParameters(&data_[offset]);}};

struct Tensor {

unsigned char * data_;

Tensor(unsigned char * data) : data_(data) {}

#define TENSOR_MEMBER_SIZE_OFFSET 0
#define TENSOR_SHAPE_OFFSET 2
#define TENSOR_TYPE_OFFSET 4
#define TENSOR_PAD5_OFFSET 5
#define TENSOR_BUFFER_OFFSET 8
#define TENSOR_NAME_OFFSET 12
#define TENSOR_QUANTIZATION_OFFSET 14
#define TENSOR_IS_VARIABLE_OFFSET 16
#define TENSOR_PAD17_OFFSET 17
#define TENSOR_SPARSITY_OFFSET 18
#define TENSOR_SHAPE_SIGNATURE_OFFSET 20
#define TENSOR_HAS_RANK_OFFSET 22
#define TENSOR_PAD23_OFFSET 23
#define TENSOR_VARIANT_TENSORS_OFFSET 24
#define TENSOR_PAD26_OFFSET 26


Vector<int32_t> shape(){if(TENSOR_SHAPE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[TENSOR_MEMBER_SIZE_OFFSET])){const int16_t offset = TENSOR_SHAPE_OFFSET ;return Vector<int32_t>(&data_[offset]);}}

TensorType type() {
if(TENSOR_TYPE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[TENSOR_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<TensorType*>(&data_[TENSOR_TYPE_OFFSET ]);}}

uint32_t buffer() {if(TENSOR_BUFFER_OFFSET < *reinterpret_cast<uint16_t *>(&data_[TENSOR_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<uint32_t*>(&data_[TENSOR_BUFFER_OFFSET ]);}}

StringOffset name(){if(TENSOR_NAME_OFFSET < *reinterpret_cast<uint16_t *>(&data_[TENSOR_MEMBER_SIZE_OFFSET])){const int16_t offset = TENSOR_NAME_OFFSET ;return StringOffset(&data_[offset]);}}

QuantizationParametersOffset quantization(){if(TENSOR_QUANTIZATION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[TENSOR_MEMBER_SIZE_OFFSET])){const int16_t offset =TENSOR_QUANTIZATION_OFFSET ;return QuantizationParametersOffset(&data_[offset]);}}

bool is_variable() {if(TENSOR_IS_VARIABLE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[TENSOR_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[TENSOR_IS_VARIABLE_OFFSET ]);}}

SparsityParametersOffset sparsity(){if(TENSOR_SPARSITY_OFFSET < *reinterpret_cast<uint16_t *>(&data_[TENSOR_MEMBER_SIZE_OFFSET])){const int16_t offset =TENSOR_SPARSITY_OFFSET ;return SparsityParametersOffset(&data_[offset]);}}

Vector<int32_t> shape_signature(){if(TENSOR_SHAPE_SIGNATURE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[TENSOR_MEMBER_SIZE_OFFSET])){const int16_t offset = TENSOR_SHAPE_SIGNATURE_OFFSET ;return Vector<int32_t>(&data_[offset]);}}

bool has_rank() {if(TENSOR_HAS_RANK_OFFSET < *reinterpret_cast<uint16_t *>(&data_[TENSOR_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[TENSOR_HAS_RANK_OFFSET ]);}}

Vector<VariantSubTypeOffset> variant_tensors(){if(TENSOR_VARIANT_TENSORS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[TENSOR_MEMBER_SIZE_OFFSET])){const int16_t offset = TENSOR_VARIANT_TENSORS_OFFSET ;return Vector<VariantSubTypeOffset>(&data_[offset]);}}

};



struct TensorOffset {

unsigned char * data_;

TensorOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

Tensor value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return Tensor(&data_[offset]);}};

struct SubGraph {

unsigned char * data_;

SubGraph(unsigned char * data) : data_(data) {}

#define SUBGRAPH_MEMBER_SIZE_OFFSET 0
#define SUBGRAPH_TENSORS_OFFSET 2
#define SUBGRAPH_INPUTS_OFFSET 4
#define SUBGRAPH_OUTPUTS_OFFSET 6
#define SUBGRAPH_OPERATORS_OFFSET 8
#define SUBGRAPH_NAME_OFFSET 10
#define SUBGRAPH_DEBUG_METADATA_INDEX_OFFSET 12


Vector<TensorOffset> tensors(){if(SUBGRAPH_TENSORS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SUBGRAPH_MEMBER_SIZE_OFFSET])){const int16_t offset = SUBGRAPH_TENSORS_OFFSET ;return Vector<TensorOffset>(&data_[offset]);}}

Vector<int32_t> inputs(){if(SUBGRAPH_INPUTS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SUBGRAPH_MEMBER_SIZE_OFFSET])){const int16_t offset = SUBGRAPH_INPUTS_OFFSET ;return Vector<int32_t>(&data_[offset]);}}

Vector<int32_t> outputs(){if(SUBGRAPH_OUTPUTS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SUBGRAPH_MEMBER_SIZE_OFFSET])){const int16_t offset = SUBGRAPH_OUTPUTS_OFFSET ;return Vector<int32_t>(&data_[offset]);}}

Vector<OperatorOffset> operators(){if(SUBGRAPH_OPERATORS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SUBGRAPH_MEMBER_SIZE_OFFSET])){const int16_t offset = SUBGRAPH_OPERATORS_OFFSET ;return Vector<OperatorOffset>(&data_[offset]);}}

StringOffset name(){if(SUBGRAPH_NAME_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SUBGRAPH_MEMBER_SIZE_OFFSET])){const int16_t offset = SUBGRAPH_NAME_OFFSET ;return StringOffset(&data_[offset]);}}

int32_t debug_metadata_index() {if(SUBGRAPH_DEBUG_METADATA_INDEX_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SUBGRAPH_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[SUBGRAPH_DEBUG_METADATA_INDEX_OFFSET ]);}}

};



struct SubGraphOffset {

unsigned char * data_;

SubGraphOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

SubGraph value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return SubGraph(&data_[offset]);}};

struct Model {

unsigned char * data_;

Model(unsigned char * data) : data_(data) {}

#define MODEL_MEMBER_SIZE_OFFSET 0
#define MODEL_PAD2_OFFSET 2
#define MODEL_VERSION_OFFSET 4
#define MODEL_OPERATOR_CODES_OFFSET 8
#define MODEL_SUBGRAPHS_OFFSET 10
#define MODEL_DESCRIPTION_OFFSET 12
#define MODEL_BUFFERS_OFFSET 14
#define MODEL_METADATA_BUFFER_OFFSET 16
#define MODEL_METADATA_OFFSET 18
#define MODEL_SIGNATURE_DEFS_OFFSET 20
#define MODEL_PAD22_OFFSET 22


uint32_t version() {if(MODEL_VERSION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[MODEL_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<uint32_t*>(&data_[MODEL_VERSION_OFFSET + 2* OFFSET_SIZE]);}}

Vector<OperatorCodeOffset> operator_codes(){if(MODEL_OPERATOR_CODES_OFFSET < *reinterpret_cast<uint16_t *>(&data_[MODEL_MEMBER_SIZE_OFFSET])){const int16_t offset = MODEL_OPERATOR_CODES_OFFSET + 2* OFFSET_SIZE;return Vector<OperatorCodeOffset>(&data_[offset]);}}

Vector<SubGraphOffset> subgraphs(){if(MODEL_SUBGRAPHS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[MODEL_MEMBER_SIZE_OFFSET])){const int16_t offset = MODEL_SUBGRAPHS_OFFSET + 2* OFFSET_SIZE;return Vector<SubGraphOffset>(&data_[offset]);}}

StringOffset description(){if(MODEL_DESCRIPTION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[MODEL_MEMBER_SIZE_OFFSET])){const int16_t offset = MODEL_DESCRIPTION_OFFSET + 2* OFFSET_SIZE;return StringOffset(&data_[offset]);}}

Vector<BufferOffset> buffers(){if(MODEL_BUFFERS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[MODEL_MEMBER_SIZE_OFFSET])){const int16_t offset = MODEL_BUFFERS_OFFSET + 2* OFFSET_SIZE;return Vector<BufferOffset>(&data_[offset]);}}

Vector<int32_t> metadata_buffer(){if(MODEL_METADATA_BUFFER_OFFSET < *reinterpret_cast<uint16_t *>(&data_[MODEL_MEMBER_SIZE_OFFSET])){const int16_t offset = MODEL_METADATA_BUFFER_OFFSET + 2* OFFSET_SIZE;return Vector<int32_t>(&data_[offset]);}}

Vector<MetadataOffset> metadata(){if(MODEL_METADATA_OFFSET < *reinterpret_cast<uint16_t *>(&data_[MODEL_MEMBER_SIZE_OFFSET])){const int16_t offset = MODEL_METADATA_OFFSET + 2* OFFSET_SIZE;return Vector<MetadataOffset>(&data_[offset]);}}

Vector<SignatureDefOffset> signature_defs(){if(MODEL_SIGNATURE_DEFS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[MODEL_MEMBER_SIZE_OFFSET])){const int16_t offset = MODEL_SIGNATURE_DEFS_OFFSET + 2* OFFSET_SIZE;return Vector<SignatureDefOffset>(&data_[offset]);}}

};



struct ModelOffset {

unsigned char * data_;

ModelOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

Model value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return Model(&data_[offset]);}};



struct StablehloGatherOptions {

unsigned char * data_;

StablehloGatherOptions(unsigned char * data) : data_(data) {}

#define STABLEHLOGATHEROPTIONS_MEMBER_SIZE_OFFSET 0
#define STABLEHLOGATHEROPTIONS_OFFSET_DIMS_OFFSET 2
#define STABLEHLOGATHEROPTIONS_COLLAPSED_SLICE_DIMS_OFFSET 4
#define STABLEHLOGATHEROPTIONS_START_INDEX_MAP_OFFSET 6
#define STABLEHLOGATHEROPTIONS_INDEX_VECTOR_DIM_OFFSET 8
#define STABLEHLOGATHEROPTIONS_SLICE_SIZES_OFFSET 16
#define STABLEHLOGATHEROPTIONS_INDICES_ARE_SORTED_OFFSET 18
#define STABLEHLOGATHEROPTIONS_PAD19_OFFSET 19


Vector<int64_t> offset_dims(){if(STABLEHLOGATHEROPTIONS_OFFSET_DIMS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOGATHEROPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOGATHEROPTIONS_OFFSET_DIMS_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

Vector<int64_t> collapsed_slice_dims(){if(STABLEHLOGATHEROPTIONS_COLLAPSED_SLICE_DIMS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOGATHEROPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOGATHEROPTIONS_COLLAPSED_SLICE_DIMS_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

Vector<int64_t> start_index_map(){if(STABLEHLOGATHEROPTIONS_START_INDEX_MAP_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOGATHEROPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOGATHEROPTIONS_START_INDEX_MAP_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

int64_t index_vector_dim() {if(STABLEHLOGATHEROPTIONS_INDEX_VECTOR_DIM_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOGATHEROPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int64_t*>(&data_[STABLEHLOGATHEROPTIONS_INDEX_VECTOR_DIM_OFFSET ]);}}

Vector<int64_t> slice_sizes(){if(STABLEHLOGATHEROPTIONS_SLICE_SIZES_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOGATHEROPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOGATHEROPTIONS_SLICE_SIZES_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

bool indices_are_sorted() {if(STABLEHLOGATHEROPTIONS_INDICES_ARE_SORTED_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOGATHEROPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[STABLEHLOGATHEROPTIONS_INDICES_ARE_SORTED_OFFSET ]);}}

};



struct StablehloGatherOptionsOffset {

unsigned char * data_;

StablehloGatherOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

StablehloGatherOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return StablehloGatherOptions(&data_[offset]);}};







struct L2NormOptions {

unsigned char * data_;

L2NormOptions(unsigned char * data) : data_(data) {}

#define L2NORMOPTIONS_MEMBER_SIZE_OFFSET 0
#define L2NORMOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET 2


ActivationFunctionType fused_activation_function() {
if(L2NORMOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[L2NORMOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<ActivationFunctionType*>(&data_[L2NORMOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET ]);}}

};



struct L2NormOptionsOffset {

unsigned char * data_;

L2NormOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

L2NormOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return L2NormOptions(&data_[offset]);}};



struct ConcatEmbeddingsOptions {

unsigned char * data_;

ConcatEmbeddingsOptions(unsigned char * data) : data_(data) {}

#define CONCATEMBEDDINGSOPTIONS_MEMBER_SIZE_OFFSET 0
#define CONCATEMBEDDINGSOPTIONS_PAD2_OFFSET 2
#define CONCATEMBEDDINGSOPTIONS_NUM_CHANNELS_OFFSET 4
#define CONCATEMBEDDINGSOPTIONS_NUM_COLUMNS_PER_CHANNEL_OFFSET 8
#define CONCATEMBEDDINGSOPTIONS_EMBEDDING_DIM_PER_CHANNEL_OFFSET 10


int32_t num_channels() {if(CONCATEMBEDDINGSOPTIONS_NUM_CHANNELS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[CONCATEMBEDDINGSOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[CONCATEMBEDDINGSOPTIONS_NUM_CHANNELS_OFFSET ]);}}

Vector<int32_t> num_columns_per_channel(){if(CONCATEMBEDDINGSOPTIONS_NUM_COLUMNS_PER_CHANNEL_OFFSET < *reinterpret_cast<uint16_t *>(&data_[CONCATEMBEDDINGSOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = CONCATEMBEDDINGSOPTIONS_NUM_COLUMNS_PER_CHANNEL_OFFSET ;return Vector<int32_t>(&data_[offset]);}}

Vector<int32_t> embedding_dim_per_channel(){if(CONCATEMBEDDINGSOPTIONS_EMBEDDING_DIM_PER_CHANNEL_OFFSET < *reinterpret_cast<uint16_t *>(&data_[CONCATEMBEDDINGSOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = CONCATEMBEDDINGSOPTIONS_EMBEDDING_DIM_PER_CHANNEL_OFFSET ;return Vector<int32_t>(&data_[offset]);}}

};



struct ConcatEmbeddingsOptionsOffset {

unsigned char * data_;

ConcatEmbeddingsOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

ConcatEmbeddingsOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return ConcatEmbeddingsOptions(&data_[offset]);}};



struct ResizeNearestNeighborOptions {

unsigned char * data_;

ResizeNearestNeighborOptions(unsigned char * data) : data_(data) {}

#define RESIZENEARESTNEIGHBOROPTIONS_MEMBER_SIZE_OFFSET 0
#define RESIZENEARESTNEIGHBOROPTIONS_ALIGN_CORNERS_OFFSET 2
#define RESIZENEARESTNEIGHBOROPTIONS_HALF_PIXEL_CENTERS_OFFSET 3


bool align_corners() {if(RESIZENEARESTNEIGHBOROPTIONS_ALIGN_CORNERS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[RESIZENEARESTNEIGHBOROPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[RESIZENEARESTNEIGHBOROPTIONS_ALIGN_CORNERS_OFFSET ]);}}

bool half_pixel_centers() {if(RESIZENEARESTNEIGHBOROPTIONS_HALF_PIXEL_CENTERS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[RESIZENEARESTNEIGHBOROPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[RESIZENEARESTNEIGHBOROPTIONS_HALF_PIXEL_CENTERS_OFFSET ]);}}

};



struct ResizeNearestNeighborOptionsOffset {

unsigned char * data_;

ResizeNearestNeighborOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

ResizeNearestNeighborOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return ResizeNearestNeighborOptions(&data_[offset]);}};



struct SquaredDifferenceOptions {

unsigned char * data_;

SquaredDifferenceOptions(unsigned char * data) : data_(data) {}

#define SQUAREDDIFFERENCEOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct SquaredDifferenceOptionsOffset {

unsigned char * data_;

SquaredDifferenceOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

SquaredDifferenceOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return SquaredDifferenceOptions(&data_[offset]);}};



struct LocalResponseNormalizationOptions {

unsigned char * data_;

LocalResponseNormalizationOptions(unsigned char * data) : data_(data) {}

#define LOCALRESPONSENORMALIZATIONOPTIONS_MEMBER_SIZE_OFFSET 0
#define LOCALRESPONSENORMALIZATIONOPTIONS_PAD2_OFFSET 2
#define LOCALRESPONSENORMALIZATIONOPTIONS_RADIUS_OFFSET 4
#define LOCALRESPONSENORMALIZATIONOPTIONS_BIAS_OFFSET 8
#define LOCALRESPONSENORMALIZATIONOPTIONS_ALPHA_OFFSET 12
#define LOCALRESPONSENORMALIZATIONOPTIONS_BETA_OFFSET 16


int32_t radius() {if(LOCALRESPONSENORMALIZATIONOPTIONS_RADIUS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[LOCALRESPONSENORMALIZATIONOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[LOCALRESPONSENORMALIZATIONOPTIONS_RADIUS_OFFSET ]);}}

float bias() {if(LOCALRESPONSENORMALIZATIONOPTIONS_BIAS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[LOCALRESPONSENORMALIZATIONOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<float*>(&data_[LOCALRESPONSENORMALIZATIONOPTIONS_BIAS_OFFSET ]);}}

float alpha() {if(LOCALRESPONSENORMALIZATIONOPTIONS_ALPHA_OFFSET < *reinterpret_cast<uint16_t *>(&data_[LOCALRESPONSENORMALIZATIONOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<float*>(&data_[LOCALRESPONSENORMALIZATIONOPTIONS_ALPHA_OFFSET ]);}}

float beta() {if(LOCALRESPONSENORMALIZATIONOPTIONS_BETA_OFFSET < *reinterpret_cast<uint16_t *>(&data_[LOCALRESPONSENORMALIZATIONOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<float*>(&data_[LOCALRESPONSENORMALIZATIONOPTIONS_BETA_OFFSET ]);}}

};



struct LocalResponseNormalizationOptionsOffset {

unsigned char * data_;

LocalResponseNormalizationOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

LocalResponseNormalizationOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return LocalResponseNormalizationOptions(&data_[offset]);}};

enum MirrorPadMode : uint8_t {

MirrorPadMode_REFLECT,
MirrorPadMode_SYMMETRIC,
};

const char * MirrorPadMode_to_string(MirrorPadMode value){switch (value){case MirrorPadMode_REFLECT:return "MirrorPadMode_REFLECT";case MirrorPadMode_SYMMETRIC:return "MirrorPadMode_SYMMETRIC";default: return NULL;}}

struct MirrorPadOptions {

unsigned char * data_;

MirrorPadOptions(unsigned char * data) : data_(data) {}

#define MIRRORPADOPTIONS_MEMBER_SIZE_OFFSET 0
#define MIRRORPADOPTIONS_MODE_OFFSET 2


MirrorPadMode mode() {
if(MIRRORPADOPTIONS_MODE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[MIRRORPADOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<MirrorPadMode*>(&data_[MIRRORPADOPTIONS_MODE_OFFSET ]);}}

};



struct MirrorPadOptionsOffset {

unsigned char * data_;

MirrorPadOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

MirrorPadOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return MirrorPadOptions(&data_[offset]);}};

enum LSTMKernelType : uint8_t {

LSTMKernelType_FULL,
LSTMKernelType_BASIC,
};

const char * LSTMKernelType_to_string(LSTMKernelType value){switch (value){case LSTMKernelType_FULL:return "LSTMKernelType_FULL";case LSTMKernelType_BASIC:return "LSTMKernelType_BASIC";default: return NULL;}}

struct LSTMOptions {

unsigned char * data_;

LSTMOptions(unsigned char * data) : data_(data) {}

#define LSTMOPTIONS_MEMBER_SIZE_OFFSET 0
#define LSTMOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET 2
#define LSTMOPTIONS_PAD3_OFFSET 3
#define LSTMOPTIONS_CELL_CLIP_OFFSET 4
#define LSTMOPTIONS_PROJ_CLIP_OFFSET 8
#define LSTMOPTIONS_KERNEL_TYPE_OFFSET 12
#define LSTMOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET 13
#define LSTMOPTIONS_PAD14_OFFSET 14


ActivationFunctionType fused_activation_function() {
if(LSTMOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[LSTMOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<ActivationFunctionType*>(&data_[LSTMOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET ]);}}

float cell_clip() {if(LSTMOPTIONS_CELL_CLIP_OFFSET < *reinterpret_cast<uint16_t *>(&data_[LSTMOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<float*>(&data_[LSTMOPTIONS_CELL_CLIP_OFFSET ]);}}

float proj_clip() {if(LSTMOPTIONS_PROJ_CLIP_OFFSET < *reinterpret_cast<uint16_t *>(&data_[LSTMOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<float*>(&data_[LSTMOPTIONS_PROJ_CLIP_OFFSET ]);}}

LSTMKernelType kernel_type() {
if(LSTMOPTIONS_KERNEL_TYPE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[LSTMOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<LSTMKernelType*>(&data_[LSTMOPTIONS_KERNEL_TYPE_OFFSET ]);}}

bool asymmetric_quantize_inputs() {if(LSTMOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[LSTMOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[LSTMOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET ]);}}

};



struct LSTMOptionsOffset {

unsigned char * data_;

LSTMOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

LSTMOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return LSTMOptions(&data_[offset]);}};



struct StablehloReduceOptions {

unsigned char * data_;

StablehloReduceOptions(unsigned char * data) : data_(data) {}

#define STABLEHLOREDUCEOPTIONS_MEMBER_SIZE_OFFSET 0
#define STABLEHLOREDUCEOPTIONS_DIMENSIONS_OFFSET 2
#define STABLEHLOREDUCEOPTIONS_BODY_SUBGRAPH_INDEX_OFFSET 4


Vector<int64_t> dimensions(){if(STABLEHLOREDUCEOPTIONS_DIMENSIONS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOREDUCEOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOREDUCEOPTIONS_DIMENSIONS_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

int32_t body_subgraph_index() {if(STABLEHLOREDUCEOPTIONS_BODY_SUBGRAPH_INDEX_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOREDUCEOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[STABLEHLOREDUCEOPTIONS_BODY_SUBGRAPH_INDEX_OFFSET ]);}}

};



struct StablehloReduceOptionsOffset {

unsigned char * data_;

StablehloReduceOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

StablehloReduceOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return StablehloReduceOptions(&data_[offset]);}};



struct AbsOptions {

unsigned char * data_;

AbsOptions(unsigned char * data) : data_(data) {}

#define ABSOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct AbsOptionsOffset {

unsigned char * data_;

AbsOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

AbsOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return AbsOptions(&data_[offset]);}};



enum ReduceWindowFunction : int32_t {

ReduceWindowFunction_UNSUPPORTED,
ReduceWindowFunction_ADD,
ReduceWindowFunction_MUL,
ReduceWindowFunction_MINIMUM,
ReduceWindowFunction_MAXIMUM,
ReduceWindowFunction_ALL,
ReduceWindowFunction_ANY,
};

const char * ReduceWindowFunction_to_string(ReduceWindowFunction value){switch (value){case ReduceWindowFunction_UNSUPPORTED:return "ReduceWindowFunction_UNSUPPORTED";case ReduceWindowFunction_ADD:return "ReduceWindowFunction_ADD";case ReduceWindowFunction_MUL:return "ReduceWindowFunction_MUL";case ReduceWindowFunction_MINIMUM:return "ReduceWindowFunction_MINIMUM";case ReduceWindowFunction_MAXIMUM:return "ReduceWindowFunction_MAXIMUM";case ReduceWindowFunction_ALL:return "ReduceWindowFunction_ALL";case ReduceWindowFunction_ANY:return "ReduceWindowFunction_ANY";default: return NULL;}}

struct ReduceWindowOptions {

unsigned char * data_;

ReduceWindowOptions(unsigned char * data) : data_(data) {}

#define REDUCEWINDOWOPTIONS_MEMBER_SIZE_OFFSET 0
#define REDUCEWINDOWOPTIONS_PAD2_OFFSET 2
#define REDUCEWINDOWOPTIONS_REDUCE_FUNCTION_OFFSET 4


ReduceWindowFunction reduce_function() {
if(REDUCEWINDOWOPTIONS_REDUCE_FUNCTION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[REDUCEWINDOWOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<ReduceWindowFunction*>(&data_[REDUCEWINDOWOPTIONS_REDUCE_FUNCTION_OFFSET ]);}}

};



struct ReduceWindowOptionsOffset {

unsigned char * data_;

ReduceWindowOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

ReduceWindowOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return ReduceWindowOptions(&data_[offset]);}};



struct UniqueOptions {

unsigned char * data_;

UniqueOptions(unsigned char * data) : data_(data) {}

#define UNIQUEOPTIONS_MEMBER_SIZE_OFFSET 0
#define UNIQUEOPTIONS_IDX_OUT_TYPE_OFFSET 2


TensorType idx_out_type() {
if(UNIQUEOPTIONS_IDX_OUT_TYPE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[UNIQUEOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<TensorType*>(&data_[UNIQUEOPTIONS_IDX_OUT_TYPE_OFFSET ]);}}

};



struct UniqueOptionsOffset {

unsigned char * data_;

UniqueOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

UniqueOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return UniqueOptions(&data_[offset]);}};



struct ReverseV2Options {

unsigned char * data_;

ReverseV2Options(unsigned char * data) : data_(data) {}

#define REVERSEV2OPTIONS_MEMBER_SIZE_OFFSET 0


};



struct ReverseV2OptionsOffset {

unsigned char * data_;

ReverseV2OptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

ReverseV2Options value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return ReverseV2Options(&data_[offset]);}};



struct ResizeBilinearOptions {

unsigned char * data_;

ResizeBilinearOptions(unsigned char * data) : data_(data) {}

#define RESIZEBILINEAROPTIONS_MEMBER_SIZE_OFFSET 0
#define RESIZEBILINEAROPTIONS_ALIGN_CORNERS_OFFSET 2
#define RESIZEBILINEAROPTIONS_HALF_PIXEL_CENTERS_OFFSET 3


bool align_corners() {if(RESIZEBILINEAROPTIONS_ALIGN_CORNERS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[RESIZEBILINEAROPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[RESIZEBILINEAROPTIONS_ALIGN_CORNERS_OFFSET ]);}}

bool half_pixel_centers() {if(RESIZEBILINEAROPTIONS_HALF_PIXEL_CENTERS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[RESIZEBILINEAROPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[RESIZEBILINEAROPTIONS_HALF_PIXEL_CENTERS_OFFSET ]);}}

};



struct ResizeBilinearOptionsOffset {

unsigned char * data_;

ResizeBilinearOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

ResizeBilinearOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return ResizeBilinearOptions(&data_[offset]);}};



struct AddNOptions {

unsigned char * data_;

AddNOptions(unsigned char * data) : data_(data) {}

#define ADDNOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct AddNOptionsOffset {

unsigned char * data_;

AddNOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

AddNOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return AddNOptions(&data_[offset]);}};





struct StablehloScatterOptions {

unsigned char * data_;

StablehloScatterOptions(unsigned char * data) : data_(data) {}

#define STABLEHLOSCATTEROPTIONS_MEMBER_SIZE_OFFSET 0
#define STABLEHLOSCATTEROPTIONS_INDICES_ARE_SORTED_OFFSET 2
#define STABLEHLOSCATTEROPTIONS_PAD3_OFFSET 3
#define STABLEHLOSCATTEROPTIONS_UPDATE_WINDOW_DIMS_OFFSET 4
#define STABLEHLOSCATTEROPTIONS_INSERTED_WINDOW_DIMS_OFFSET 6
#define STABLEHLOSCATTEROPTIONS_SCATTER_DIMS_TO_OPERAND_DIMS_OFFSET 8
#define STABLEHLOSCATTEROPTIONS_PAD10_OFFSET 10
#define STABLEHLOSCATTEROPTIONS_INDEX_VECTOR_DIM_OFFSET 16
#define STABLEHLOSCATTEROPTIONS_UNIQUE_INDICES_OFFSET 24
#define STABLEHLOSCATTEROPTIONS_PAD25_OFFSET 25
#define STABLEHLOSCATTEROPTIONS_UPDATE_COMPUTATION_SUBGRAPH_INDEX_OFFSET 28


bool indices_are_sorted() {if(STABLEHLOSCATTEROPTIONS_INDICES_ARE_SORTED_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOSCATTEROPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[STABLEHLOSCATTEROPTIONS_INDICES_ARE_SORTED_OFFSET ]);}}

Vector<int64_t> update_window_dims(){if(STABLEHLOSCATTEROPTIONS_UPDATE_WINDOW_DIMS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOSCATTEROPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOSCATTEROPTIONS_UPDATE_WINDOW_DIMS_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

Vector<int64_t> inserted_window_dims(){if(STABLEHLOSCATTEROPTIONS_INSERTED_WINDOW_DIMS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOSCATTEROPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOSCATTEROPTIONS_INSERTED_WINDOW_DIMS_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

Vector<int64_t> scatter_dims_to_operand_dims(){if(STABLEHLOSCATTEROPTIONS_SCATTER_DIMS_TO_OPERAND_DIMS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOSCATTEROPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOSCATTEROPTIONS_SCATTER_DIMS_TO_OPERAND_DIMS_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

int64_t index_vector_dim() {if(STABLEHLOSCATTEROPTIONS_INDEX_VECTOR_DIM_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOSCATTEROPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int64_t*>(&data_[STABLEHLOSCATTEROPTIONS_INDEX_VECTOR_DIM_OFFSET ]);}}

bool unique_indices() {if(STABLEHLOSCATTEROPTIONS_UNIQUE_INDICES_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOSCATTEROPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[STABLEHLOSCATTEROPTIONS_UNIQUE_INDICES_OFFSET ]);}}

int32_t update_computation_subgraph_index() {if(STABLEHLOSCATTEROPTIONS_UPDATE_COMPUTATION_SUBGRAPH_INDEX_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOSCATTEROPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[STABLEHLOSCATTEROPTIONS_UPDATE_COMPUTATION_SUBGRAPH_INDEX_OFFSET ]);}}

};



struct StablehloScatterOptionsOffset {

unsigned char * data_;

StablehloScatterOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

StablehloScatterOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return StablehloScatterOptions(&data_[offset]);}};



struct GatherNdOptions {

unsigned char * data_;

GatherNdOptions(unsigned char * data) : data_(data) {}

#define GATHERNDOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct GatherNdOptionsOffset {

unsigned char * data_;

GatherNdOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

GatherNdOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return GatherNdOptions(&data_[offset]);}};



struct CosOptions {

unsigned char * data_;

CosOptions(unsigned char * data) : data_(data) {}

#define COSOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct CosOptionsOffset {

unsigned char * data_;

CosOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

CosOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return CosOptions(&data_[offset]);}};





struct WhereOptions {

unsigned char * data_;

WhereOptions(unsigned char * data) : data_(data) {}

#define WHEREOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct WhereOptionsOffset {

unsigned char * data_;

WhereOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

WhereOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return WhereOptions(&data_[offset]);}};



struct RankOptions {

unsigned char * data_;

RankOptions(unsigned char * data) : data_(data) {}

#define RANKOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct RankOptionsOffset {

unsigned char * data_;

RankOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

RankOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return RankOptions(&data_[offset]);}};





struct ReverseSequenceOptions {

unsigned char * data_;

ReverseSequenceOptions(unsigned char * data) : data_(data) {}

#define REVERSESEQUENCEOPTIONS_MEMBER_SIZE_OFFSET 0
#define REVERSESEQUENCEOPTIONS_PAD2_OFFSET 2
#define REVERSESEQUENCEOPTIONS_SEQ_DIM_OFFSET 4
#define REVERSESEQUENCEOPTIONS_BATCH_DIM_OFFSET 8


int32_t seq_dim() {if(REVERSESEQUENCEOPTIONS_SEQ_DIM_OFFSET < *reinterpret_cast<uint16_t *>(&data_[REVERSESEQUENCEOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[REVERSESEQUENCEOPTIONS_SEQ_DIM_OFFSET ]);}}

int32_t batch_dim() {if(REVERSESEQUENCEOPTIONS_BATCH_DIM_OFFSET < *reinterpret_cast<uint16_t *>(&data_[REVERSESEQUENCEOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[REVERSESEQUENCEOPTIONS_BATCH_DIM_OFFSET ]);}}

};



struct ReverseSequenceOptionsOffset {

unsigned char * data_;

ReverseSequenceOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

ReverseSequenceOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return ReverseSequenceOptions(&data_[offset]);}};

enum StablehloComparisonDirection : uint32_t {

StablehloComparisonDirection_STABLEHLO_COMPARISON_DIRECTION_EQ,
StablehloComparisonDirection_STABLEHLO_COMPARISON_DIRECTION_NE,
StablehloComparisonDirection_STABLEHLO_COMPARISON_DIRECTION_GE,
StablehloComparisonDirection_STABLEHLO_COMPARISON_DIRECTION_GT,
StablehloComparisonDirection_STABLEHLO_COMPARISON_DIRECTION_LE,
StablehloComparisonDirection_STABLEHLO_COMPARISON_DIRECTION_LT,
};

const char * StablehloComparisonDirection_to_string(StablehloComparisonDirection value){switch (value){case StablehloComparisonDirection_STABLEHLO_COMPARISON_DIRECTION_EQ:return "StablehloComparisonDirection_STABLEHLO_COMPARISON_DIRECTION_EQ";case StablehloComparisonDirection_STABLEHLO_COMPARISON_DIRECTION_NE:return "StablehloComparisonDirection_STABLEHLO_COMPARISON_DIRECTION_NE";case StablehloComparisonDirection_STABLEHLO_COMPARISON_DIRECTION_GE:return "StablehloComparisonDirection_STABLEHLO_COMPARISON_DIRECTION_GE";case StablehloComparisonDirection_STABLEHLO_COMPARISON_DIRECTION_GT:return "StablehloComparisonDirection_STABLEHLO_COMPARISON_DIRECTION_GT";case StablehloComparisonDirection_STABLEHLO_COMPARISON_DIRECTION_LE:return "StablehloComparisonDirection_STABLEHLO_COMPARISON_DIRECTION_LE";case StablehloComparisonDirection_STABLEHLO_COMPARISON_DIRECTION_LT:return "StablehloComparisonDirection_STABLEHLO_COMPARISON_DIRECTION_LT";default: return NULL;}}enum StablehloComparisonType : uint32_t {

StablehloComparisonType_STABLEHLO_COMPARISON_TYPE_NOTYPE,
StablehloComparisonType_STABLEHLO_COMPARISON_TYPE_FLOAT,
StablehloComparisonType_STABLEHLO_COMPARISON_TYPE_FLOAT_TOTAL_ORDER,
StablehloComparisonType_STABLEHLO_COMPARISON_TYPE_SIGNED,
StablehloComparisonType_STABLEHLO_COMPARISON_TYPE_UNSIGNED,
};

const char * StablehloComparisonType_to_string(StablehloComparisonType value){switch (value){case StablehloComparisonType_STABLEHLO_COMPARISON_TYPE_NOTYPE:return "StablehloComparisonType_STABLEHLO_COMPARISON_TYPE_NOTYPE";case StablehloComparisonType_STABLEHLO_COMPARISON_TYPE_FLOAT:return "StablehloComparisonType_STABLEHLO_COMPARISON_TYPE_FLOAT";case StablehloComparisonType_STABLEHLO_COMPARISON_TYPE_FLOAT_TOTAL_ORDER:return "StablehloComparisonType_STABLEHLO_COMPARISON_TYPE_FLOAT_TOTAL_ORDER";case StablehloComparisonType_STABLEHLO_COMPARISON_TYPE_SIGNED:return "StablehloComparisonType_STABLEHLO_COMPARISON_TYPE_SIGNED";case StablehloComparisonType_STABLEHLO_COMPARISON_TYPE_UNSIGNED:return "StablehloComparisonType_STABLEHLO_COMPARISON_TYPE_UNSIGNED";default: return NULL;}}

struct StablehloCompareOptions {

unsigned char * data_;

StablehloCompareOptions(unsigned char * data) : data_(data) {}

#define STABLEHLOCOMPAREOPTIONS_MEMBER_SIZE_OFFSET 0
#define STABLEHLOCOMPAREOPTIONS_PAD2_OFFSET 2
#define STABLEHLOCOMPAREOPTIONS_COMPARISON_DIRECTION_OFFSET 4
#define STABLEHLOCOMPAREOPTIONS_COMPARE_TYPE_OFFSET 8


StablehloComparisonDirection comparison_direction() {
if(STABLEHLOCOMPAREOPTIONS_COMPARISON_DIRECTION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCOMPAREOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<StablehloComparisonDirection*>(&data_[STABLEHLOCOMPAREOPTIONS_COMPARISON_DIRECTION_OFFSET ]);}}

StablehloComparisonType compare_type() {
if(STABLEHLOCOMPAREOPTIONS_COMPARE_TYPE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOCOMPAREOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<StablehloComparisonType*>(&data_[STABLEHLOCOMPAREOPTIONS_COMPARE_TYPE_OFFSET ]);}}

};



struct StablehloCompareOptionsOffset {

unsigned char * data_;

StablehloCompareOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

StablehloCompareOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return StablehloCompareOptions(&data_[offset]);}};



struct MatrixDiagOptions {

unsigned char * data_;

MatrixDiagOptions(unsigned char * data) : data_(data) {}

#define MATRIXDIAGOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct MatrixDiagOptionsOffset {

unsigned char * data_;

MatrixDiagOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

MatrixDiagOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return MatrixDiagOptions(&data_[offset]);}};



struct CustomQuantization {

unsigned char * data_;

CustomQuantization(unsigned char * data) : data_(data) {}

#define CUSTOMQUANTIZATION_MEMBER_SIZE_OFFSET 0
#define CUSTOMQUANTIZATION_CUSTOM_OFFSET 2


Vector<uint8_t> custom(){if(CUSTOMQUANTIZATION_CUSTOM_OFFSET < *reinterpret_cast<uint16_t *>(&data_[CUSTOMQUANTIZATION_MEMBER_SIZE_OFFSET])){const int16_t offset = CUSTOMQUANTIZATION_CUSTOM_OFFSET ;return Vector<uint8_t>(&data_[offset]);}}

};



struct CustomQuantizationOffset {

unsigned char * data_;

CustomQuantizationOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

CustomQuantization value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return CustomQuantization(&data_[offset]);}};



struct CallOptions {

unsigned char * data_;

CallOptions(unsigned char * data) : data_(data) {}

#define CALLOPTIONS_MEMBER_SIZE_OFFSET 0
#define CALLOPTIONS_PAD2_OFFSET 2
#define CALLOPTIONS_SUBGRAPH_OFFSET 4


uint32_t subgraph() {if(CALLOPTIONS_SUBGRAPH_OFFSET < *reinterpret_cast<uint16_t *>(&data_[CALLOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<uint32_t*>(&data_[CALLOPTIONS_SUBGRAPH_OFFSET ]);}}

};



struct CallOptionsOffset {

unsigned char * data_;

CallOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

CallOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return CallOptions(&data_[offset]);}};



struct BlockwiseQuantization {

unsigned char * data_;

BlockwiseQuantization(unsigned char * data) : data_(data) {}

#define BLOCKWISEQUANTIZATION_SCALES_OFFSET 0
#define BLOCKWISEQUANTIZATION_ZERO_POINTS_OFFSET 4
#define BLOCKWISEQUANTIZATION_BLOCK_SIZE_OFFSET 8


int32_t scales() {return *reinterpret_cast<int32_t*>(&data_[BLOCKWISEQUANTIZATION_SCALES_OFFSET ]);}

int32_t zero_points() {return *reinterpret_cast<int32_t*>(&data_[BLOCKWISEQUANTIZATION_ZERO_POINTS_OFFSET ]);}

int32_t block_size() {return *reinterpret_cast<int32_t*>(&data_[BLOCKWISEQUANTIZATION_BLOCK_SIZE_OFFSET ]);}

};







struct QuantizeOptions {

unsigned char * data_;

QuantizeOptions(unsigned char * data) : data_(data) {}

#define QUANTIZEOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct QuantizeOptionsOffset {

unsigned char * data_;

QuantizeOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

QuantizeOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return QuantizeOptions(&data_[offset]);}};



struct MatrixSetDiagOptions {

unsigned char * data_;

MatrixSetDiagOptions(unsigned char * data) : data_(data) {}

#define MATRIXSETDIAGOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct MatrixSetDiagOptionsOffset {

unsigned char * data_;

MatrixSetDiagOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

MatrixSetDiagOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return MatrixSetDiagOptions(&data_[offset]);}};



struct HardSwishOptions {

unsigned char * data_;

HardSwishOptions(unsigned char * data) : data_(data) {}

#define HARDSWISHOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct HardSwishOptionsOffset {

unsigned char * data_;

HardSwishOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

HardSwishOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return HardSwishOptions(&data_[offset]);}};



struct IfOptions {

unsigned char * data_;

IfOptions(unsigned char * data) : data_(data) {}

#define IFOPTIONS_MEMBER_SIZE_OFFSET 0
#define IFOPTIONS_PAD2_OFFSET 2
#define IFOPTIONS_THEN_SUBGRAPH_INDEX_OFFSET 4
#define IFOPTIONS_ELSE_SUBGRAPH_INDEX_OFFSET 8


int32_t then_subgraph_index() {if(IFOPTIONS_THEN_SUBGRAPH_INDEX_OFFSET < *reinterpret_cast<uint16_t *>(&data_[IFOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[IFOPTIONS_THEN_SUBGRAPH_INDEX_OFFSET ]);}}

int32_t else_subgraph_index() {if(IFOPTIONS_ELSE_SUBGRAPH_INDEX_OFFSET < *reinterpret_cast<uint16_t *>(&data_[IFOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[IFOPTIONS_ELSE_SUBGRAPH_INDEX_OFFSET ]);}}

};



struct IfOptionsOffset {

unsigned char * data_;

IfOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

IfOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return IfOptions(&data_[offset]);}};



struct ReshapeOptions {

unsigned char * data_;

ReshapeOptions(unsigned char * data) : data_(data) {}

#define RESHAPEOPTIONS_MEMBER_SIZE_OFFSET 0
#define RESHAPEOPTIONS_NEW_SHAPE_OFFSET 2


Vector<int32_t> new_shape(){if(RESHAPEOPTIONS_NEW_SHAPE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[RESHAPEOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = RESHAPEOPTIONS_NEW_SHAPE_OFFSET ;return Vector<int32_t>(&data_[offset]);}}

};



struct ReshapeOptionsOffset {

unsigned char * data_;

ReshapeOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

ReshapeOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return ReshapeOptions(&data_[offset]);}};



struct WhileOptions {

unsigned char * data_;

WhileOptions(unsigned char * data) : data_(data) {}

#define WHILEOPTIONS_MEMBER_SIZE_OFFSET 0
#define WHILEOPTIONS_PAD2_OFFSET 2
#define WHILEOPTIONS_COND_SUBGRAPH_INDEX_OFFSET 4
#define WHILEOPTIONS_BODY_SUBGRAPH_INDEX_OFFSET 8


int32_t cond_subgraph_index() {if(WHILEOPTIONS_COND_SUBGRAPH_INDEX_OFFSET < *reinterpret_cast<uint16_t *>(&data_[WHILEOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[WHILEOPTIONS_COND_SUBGRAPH_INDEX_OFFSET ]);}}

int32_t body_subgraph_index() {if(WHILEOPTIONS_BODY_SUBGRAPH_INDEX_OFFSET < *reinterpret_cast<uint16_t *>(&data_[WHILEOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[WHILEOPTIONS_BODY_SUBGRAPH_INDEX_OFFSET ]);}}

};



struct WhileOptionsOffset {

unsigned char * data_;

WhileOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

WhileOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return WhileOptions(&data_[offset]);}};



struct StablehloDotGeneralOptions {

unsigned char * data_;

StablehloDotGeneralOptions(unsigned char * data) : data_(data) {}

#define STABLEHLODOTGENERALOPTIONS_MEMBER_SIZE_OFFSET 0
#define STABLEHLODOTGENERALOPTIONS_LHS_BATCHING_DIMENSIONS_OFFSET 2
#define STABLEHLODOTGENERALOPTIONS_RHS_BATCHING_DIMENSIONS_OFFSET 4
#define STABLEHLODOTGENERALOPTIONS_LHS_CONTRACTING_DIMENSIONS_OFFSET 6
#define STABLEHLODOTGENERALOPTIONS_RHS_CONTRACTING_DIMENSIONS_OFFSET 8
#define STABLEHLODOTGENERALOPTIONS_PRECISION_CONFIG_OFFSET 10


Vector<int64_t> lhs_batching_dimensions(){if(STABLEHLODOTGENERALOPTIONS_LHS_BATCHING_DIMENSIONS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLODOTGENERALOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLODOTGENERALOPTIONS_LHS_BATCHING_DIMENSIONS_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

Vector<int64_t> rhs_batching_dimensions(){if(STABLEHLODOTGENERALOPTIONS_RHS_BATCHING_DIMENSIONS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLODOTGENERALOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLODOTGENERALOPTIONS_RHS_BATCHING_DIMENSIONS_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

Vector<int64_t> lhs_contracting_dimensions(){if(STABLEHLODOTGENERALOPTIONS_LHS_CONTRACTING_DIMENSIONS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLODOTGENERALOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLODOTGENERALOPTIONS_LHS_CONTRACTING_DIMENSIONS_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

Vector<int64_t> rhs_contracting_dimensions(){if(STABLEHLODOTGENERALOPTIONS_RHS_CONTRACTING_DIMENSIONS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLODOTGENERALOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLODOTGENERALOPTIONS_RHS_CONTRACTING_DIMENSIONS_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

Vector<StablehloPrecisionConfig> precision_config(){if(STABLEHLODOTGENERALOPTIONS_PRECISION_CONFIG_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLODOTGENERALOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLODOTGENERALOPTIONS_PRECISION_CONFIG_OFFSET ;return Vector<StablehloPrecisionConfig>(&data_[offset]);}}

};



struct StablehloDotGeneralOptionsOffset {

unsigned char * data_;

StablehloDotGeneralOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

StablehloDotGeneralOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return StablehloDotGeneralOptions(&data_[offset]);}};



struct SkipGramOptions {

unsigned char * data_;

SkipGramOptions(unsigned char * data) : data_(data) {}

#define SKIPGRAMOPTIONS_MEMBER_SIZE_OFFSET 0
#define SKIPGRAMOPTIONS_PAD2_OFFSET 2
#define SKIPGRAMOPTIONS_NGRAM_SIZE_OFFSET 4
#define SKIPGRAMOPTIONS_MAX_SKIP_SIZE_OFFSET 8
#define SKIPGRAMOPTIONS_INCLUDE_ALL_NGRAMS_OFFSET 12
#define SKIPGRAMOPTIONS_PAD13_OFFSET 13


int32_t ngram_size() {if(SKIPGRAMOPTIONS_NGRAM_SIZE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SKIPGRAMOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[SKIPGRAMOPTIONS_NGRAM_SIZE_OFFSET ]);}}

int32_t max_skip_size() {if(SKIPGRAMOPTIONS_MAX_SKIP_SIZE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SKIPGRAMOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[SKIPGRAMOPTIONS_MAX_SKIP_SIZE_OFFSET ]);}}

bool include_all_ngrams() {if(SKIPGRAMOPTIONS_INCLUDE_ALL_NGRAMS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SKIPGRAMOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[SKIPGRAMOPTIONS_INCLUDE_ALL_NGRAMS_OFFSET ]);}}

};



struct SkipGramOptionsOffset {

unsigned char * data_;

SkipGramOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

SkipGramOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return SkipGramOptions(&data_[offset]);}};





struct SpaceToDepthOptions {

unsigned char * data_;

SpaceToDepthOptions(unsigned char * data) : data_(data) {}

#define SPACETODEPTHOPTIONS_MEMBER_SIZE_OFFSET 0
#define SPACETODEPTHOPTIONS_PAD2_OFFSET 2
#define SPACETODEPTHOPTIONS_BLOCK_SIZE_OFFSET 4


int32_t block_size() {if(SPACETODEPTHOPTIONS_BLOCK_SIZE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SPACETODEPTHOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[SPACETODEPTHOPTIONS_BLOCK_SIZE_OFFSET ]);}}

};



struct SpaceToDepthOptionsOffset {

unsigned char * data_;

SpaceToDepthOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

SpaceToDepthOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return SpaceToDepthOptions(&data_[offset]);}};



struct DepthToSpaceOptions {

unsigned char * data_;

DepthToSpaceOptions(unsigned char * data) : data_(data) {}

#define DEPTHTOSPACEOPTIONS_MEMBER_SIZE_OFFSET 0
#define DEPTHTOSPACEOPTIONS_PAD2_OFFSET 2
#define DEPTHTOSPACEOPTIONS_BLOCK_SIZE_OFFSET 4


int32_t block_size() {if(DEPTHTOSPACEOPTIONS_BLOCK_SIZE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[DEPTHTOSPACEOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[DEPTHTOSPACEOPTIONS_BLOCK_SIZE_OFFSET ]);}}

};



struct DepthToSpaceOptionsOffset {

unsigned char * data_;

DepthToSpaceOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

DepthToSpaceOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return DepthToSpaceOptions(&data_[offset]);}};





struct StablehloDynamicSliceOptions {

unsigned char * data_;

StablehloDynamicSliceOptions(unsigned char * data) : data_(data) {}

#define STABLEHLODYNAMICSLICEOPTIONS_MEMBER_SIZE_OFFSET 0
#define STABLEHLODYNAMICSLICEOPTIONS_SLICE_SIZES_OFFSET 2


Vector<int64_t> slice_sizes(){if(STABLEHLODYNAMICSLICEOPTIONS_SLICE_SIZES_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLODYNAMICSLICEOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLODYNAMICSLICEOPTIONS_SLICE_SIZES_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

};



struct StablehloDynamicSliceOptionsOffset {

unsigned char * data_;

StablehloDynamicSliceOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

StablehloDynamicSliceOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return StablehloDynamicSliceOptions(&data_[offset]);}};



struct NonMaxSuppressionV4Options {

unsigned char * data_;

NonMaxSuppressionV4Options(unsigned char * data) : data_(data) {}

#define NONMAXSUPPRESSIONV4OPTIONS_MEMBER_SIZE_OFFSET 0


};



struct NonMaxSuppressionV4OptionsOffset {

unsigned char * data_;

NonMaxSuppressionV4OptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

NonMaxSuppressionV4Options value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return NonMaxSuppressionV4Options(&data_[offset]);}};

enum CombinerType : uint8_t {

CombinerType_SUM,
CombinerType_MEAN,
CombinerType_SQRTN,
};

const char * CombinerType_to_string(CombinerType value){switch (value){case CombinerType_SUM:return "CombinerType_SUM";case CombinerType_MEAN:return "CombinerType_MEAN";case CombinerType_SQRTN:return "CombinerType_SQRTN";default: return NULL;}}

struct EmbeddingLookupSparseOptions {

unsigned char * data_;

EmbeddingLookupSparseOptions(unsigned char * data) : data_(data) {}

#define EMBEDDINGLOOKUPSPARSEOPTIONS_MEMBER_SIZE_OFFSET 0
#define EMBEDDINGLOOKUPSPARSEOPTIONS_COMBINER_OFFSET 2


CombinerType combiner() {
if(EMBEDDINGLOOKUPSPARSEOPTIONS_COMBINER_OFFSET < *reinterpret_cast<uint16_t *>(&data_[EMBEDDINGLOOKUPSPARSEOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<CombinerType*>(&data_[EMBEDDINGLOOKUPSPARSEOPTIONS_COMBINER_OFFSET ]);}}

};



struct EmbeddingLookupSparseOptionsOffset {

unsigned char * data_;

EmbeddingLookupSparseOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

EmbeddingLookupSparseOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return EmbeddingLookupSparseOptions(&data_[offset]);}};



struct NonMaxSuppressionV5Options {

unsigned char * data_;

NonMaxSuppressionV5Options(unsigned char * data) : data_(data) {}

#define NONMAXSUPPRESSIONV5OPTIONS_MEMBER_SIZE_OFFSET 0


};



struct NonMaxSuppressionV5OptionsOffset {

unsigned char * data_;

NonMaxSuppressionV5OptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

NonMaxSuppressionV5Options value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return NonMaxSuppressionV5Options(&data_[offset]);}};



struct SelectV2Options {

unsigned char * data_;

SelectV2Options(unsigned char * data) : data_(data) {}

#define SELECTV2OPTIONS_MEMBER_SIZE_OFFSET 0


};



struct SelectV2OptionsOffset {

unsigned char * data_;

SelectV2OptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

SelectV2Options value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return SelectV2Options(&data_[offset]);}};

enum RngAlgorithm : uint8_t {

RngAlgorithm_DEFAULT,
RngAlgorithm_PHILOX,
RngAlgorithm_THREEFRY,
};

const char * RngAlgorithm_to_string(RngAlgorithm value){switch (value){case RngAlgorithm_DEFAULT:return "RngAlgorithm_DEFAULT";case RngAlgorithm_PHILOX:return "RngAlgorithm_PHILOX";case RngAlgorithm_THREEFRY:return "RngAlgorithm_THREEFRY";default: return NULL;}}

struct StablehloRngBitGeneratorOptions {

unsigned char * data_;

StablehloRngBitGeneratorOptions(unsigned char * data) : data_(data) {}

#define STABLEHLORNGBITGENERATOROPTIONS_MEMBER_SIZE_OFFSET 0
#define STABLEHLORNGBITGENERATOROPTIONS_ALGORITHM_OFFSET 2


RngAlgorithm algorithm() {
if(STABLEHLORNGBITGENERATOROPTIONS_ALGORITHM_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLORNGBITGENERATOROPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<RngAlgorithm*>(&data_[STABLEHLORNGBITGENERATOROPTIONS_ALGORITHM_OFFSET ]);}}

};



struct StablehloRngBitGeneratorOptionsOffset {

unsigned char * data_;

StablehloRngBitGeneratorOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

StablehloRngBitGeneratorOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return StablehloRngBitGeneratorOptions(&data_[offset]);}};



struct SegmentSumOptions {

unsigned char * data_;

SegmentSumOptions(unsigned char * data) : data_(data) {}

#define SEGMENTSUMOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct SegmentSumOptionsOffset {

unsigned char * data_;

SegmentSumOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

SegmentSumOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return SegmentSumOptions(&data_[offset]);}};







struct BatchMatMulOptions {

unsigned char * data_;

BatchMatMulOptions(unsigned char * data) : data_(data) {}

#define BATCHMATMULOPTIONS_MEMBER_SIZE_OFFSET 0
#define BATCHMATMULOPTIONS_ADJ_X_OFFSET 2
#define BATCHMATMULOPTIONS_ADJ_Y_OFFSET 3
#define BATCHMATMULOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET 4


int8_t adj_x() {if(BATCHMATMULOPTIONS_ADJ_X_OFFSET < *reinterpret_cast<uint16_t *>(&data_[BATCHMATMULOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int8_t*>(&data_[BATCHMATMULOPTIONS_ADJ_X_OFFSET ]);}}

bool adj_y() {if(BATCHMATMULOPTIONS_ADJ_Y_OFFSET < *reinterpret_cast<uint16_t *>(&data_[BATCHMATMULOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[BATCHMATMULOPTIONS_ADJ_Y_OFFSET ]);}}

bool asymmetric_quantize_inputs() {if(BATCHMATMULOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[BATCHMATMULOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[BATCHMATMULOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET ]);}}

};



struct BatchMatMulOptionsOffset {

unsigned char * data_;

BatchMatMulOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

BatchMatMulOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return BatchMatMulOptions(&data_[offset]);}};



struct MulOptions {

unsigned char * data_;

MulOptions(unsigned char * data) : data_(data) {}

#define MULOPTIONS_MEMBER_SIZE_OFFSET 0
#define MULOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET 2


ActivationFunctionType fused_activation_function() {
if(MULOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[MULOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<ActivationFunctionType*>(&data_[MULOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET ]);}}

};



struct MulOptionsOffset {

unsigned char * data_;

MulOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

MulOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return MulOptions(&data_[offset]);}};



struct CallOnceOptions {

unsigned char * data_;

CallOnceOptions(unsigned char * data) : data_(data) {}

#define CALLONCEOPTIONS_MEMBER_SIZE_OFFSET 0
#define CALLONCEOPTIONS_PAD2_OFFSET 2
#define CALLONCEOPTIONS_INIT_SUBGRAPH_INDEX_OFFSET 4


int32_t init_subgraph_index() {if(CALLONCEOPTIONS_INIT_SUBGRAPH_INDEX_OFFSET < *reinterpret_cast<uint16_t *>(&data_[CALLONCEOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[CALLONCEOPTIONS_INIT_SUBGRAPH_INDEX_OFFSET ]);}}

};



struct CallOnceOptionsOffset {

unsigned char * data_;

CallOnceOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

CallOnceOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return CallOnceOptions(&data_[offset]);}};





struct StablehloPadOptions {

unsigned char * data_;

StablehloPadOptions(unsigned char * data) : data_(data) {}

#define STABLEHLOPADOPTIONS_MEMBER_SIZE_OFFSET 0
#define STABLEHLOPADOPTIONS_EDGE_PADDING_LOW_OFFSET 2
#define STABLEHLOPADOPTIONS_EDGE_PADDING_HIGH_OFFSET 4
#define STABLEHLOPADOPTIONS_INTERIOR_PADDING_OFFSET 6


Vector<int64_t> edge_padding_low(){if(STABLEHLOPADOPTIONS_EDGE_PADDING_LOW_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOPADOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOPADOPTIONS_EDGE_PADDING_LOW_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

Vector<int64_t> edge_padding_high(){if(STABLEHLOPADOPTIONS_EDGE_PADDING_HIGH_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOPADOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOPADOPTIONS_EDGE_PADDING_HIGH_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

Vector<int64_t> interior_padding(){if(STABLEHLOPADOPTIONS_INTERIOR_PADDING_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOPADOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOPADOPTIONS_INTERIOR_PADDING_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

};



struct StablehloPadOptionsOffset {

unsigned char * data_;

StablehloPadOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

StablehloPadOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return StablehloPadOptions(&data_[offset]);}};



struct StablehloIotaOptions {

unsigned char * data_;

StablehloIotaOptions(unsigned char * data) : data_(data) {}

#define STABLEHLOIOTAOPTIONS_MEMBER_SIZE_OFFSET 0
#define STABLEHLOIOTAOPTIONS_PAD2_OFFSET 2
#define STABLEHLOIOTAOPTIONS_IOTA_DIMENSION_OFFSET 8


int64_t iota_dimension() {if(STABLEHLOIOTAOPTIONS_IOTA_DIMENSION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOIOTAOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int64_t*>(&data_[STABLEHLOIOTAOPTIONS_IOTA_DIMENSION_OFFSET ]);}}

};



struct StablehloIotaOptionsOffset {

unsigned char * data_;

StablehloIotaOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

StablehloIotaOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return StablehloIotaOptions(&data_[offset]);}};

enum Padding : uint8_t {

Padding_SAME,
Padding_VALID,
};

const char * Padding_to_string(Padding value){switch (value){case Padding_SAME:return "Padding_SAME";case Padding_VALID:return "Padding_VALID";default: return NULL;}}



struct PadOptions {

unsigned char * data_;

PadOptions(unsigned char * data) : data_(data) {}

#define PADOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct PadOptionsOffset {

unsigned char * data_;

PadOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

PadOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return PadOptions(&data_[offset]);}};





struct BroadcastToOptions {

unsigned char * data_;

BroadcastToOptions(unsigned char * data) : data_(data) {}

#define BROADCASTTOOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct BroadcastToOptionsOffset {

unsigned char * data_;

BroadcastToOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

BroadcastToOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return BroadcastToOptions(&data_[offset]);}};



struct DepthwiseConv2DOptions {

unsigned char * data_;

DepthwiseConv2DOptions(unsigned char * data) : data_(data) {}

#define DEPTHWISECONV2DOPTIONS_MEMBER_SIZE_OFFSET 0
#define DEPTHWISECONV2DOPTIONS_PAD2_OFFSET 2
#define DEPTHWISECONV2DOPTIONS_STRIDE_W_OFFSET 4
#define DEPTHWISECONV2DOPTIONS_STRIDE_H_OFFSET 8
#define DEPTHWISECONV2DOPTIONS_DEPTH_MULTIPLIER_OFFSET 12
#define DEPTHWISECONV2DOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET 16
#define DEPTHWISECONV2DOPTIONS_PAD17_OFFSET 17
#define DEPTHWISECONV2DOPTIONS_DILATION_W_FACTOR_OFFSET 20
#define DEPTHWISECONV2DOPTIONS_DILATION_H_FACTOR_OFFSET 24


int32_t stride_w() {if(DEPTHWISECONV2DOPTIONS_STRIDE_W_OFFSET < *reinterpret_cast<uint16_t *>(&data_[DEPTHWISECONV2DOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[DEPTHWISECONV2DOPTIONS_STRIDE_W_OFFSET ]);}}

int32_t stride_h() {if(DEPTHWISECONV2DOPTIONS_STRIDE_H_OFFSET < *reinterpret_cast<uint16_t *>(&data_[DEPTHWISECONV2DOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[DEPTHWISECONV2DOPTIONS_STRIDE_H_OFFSET ]);}}

int32_t depth_multiplier() {if(DEPTHWISECONV2DOPTIONS_DEPTH_MULTIPLIER_OFFSET < *reinterpret_cast<uint16_t *>(&data_[DEPTHWISECONV2DOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[DEPTHWISECONV2DOPTIONS_DEPTH_MULTIPLIER_OFFSET ]);}}

ActivationFunctionType fused_activation_function() {
if(DEPTHWISECONV2DOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[DEPTHWISECONV2DOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<ActivationFunctionType*>(&data_[DEPTHWISECONV2DOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET ]);}}

int32_t dilation_w_factor() {if(DEPTHWISECONV2DOPTIONS_DILATION_W_FACTOR_OFFSET < *reinterpret_cast<uint16_t *>(&data_[DEPTHWISECONV2DOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[DEPTHWISECONV2DOPTIONS_DILATION_W_FACTOR_OFFSET ]);}}

int32_t dilation_h_factor() {if(DEPTHWISECONV2DOPTIONS_DILATION_H_FACTOR_OFFSET < *reinterpret_cast<uint16_t *>(&data_[DEPTHWISECONV2DOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[DEPTHWISECONV2DOPTIONS_DILATION_H_FACTOR_OFFSET ]);}}

};



struct DepthwiseConv2DOptionsOffset {

unsigned char * data_;

DepthwiseConv2DOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

DepthwiseConv2DOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return DepthwiseConv2DOptions(&data_[offset]);}};



struct GatherOptions {

unsigned char * data_;

GatherOptions(unsigned char * data) : data_(data) {}

#define GATHEROPTIONS_MEMBER_SIZE_OFFSET 0
#define GATHEROPTIONS_PAD2_OFFSET 2
#define GATHEROPTIONS_AXIS_OFFSET 4
#define GATHEROPTIONS_BATCH_DIMS_OFFSET 8


int32_t axis() {if(GATHEROPTIONS_AXIS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[GATHEROPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[GATHEROPTIONS_AXIS_OFFSET ]);}}

int32_t batch_dims() {if(GATHEROPTIONS_BATCH_DIMS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[GATHEROPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[GATHEROPTIONS_BATCH_DIMS_OFFSET ]);}}

};



struct GatherOptionsOffset {

unsigned char * data_;

GatherOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

GatherOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return GatherOptions(&data_[offset]);}};



struct StablehloReduceWindowOptions {

unsigned char * data_;

StablehloReduceWindowOptions(unsigned char * data) : data_(data) {}

#define STABLEHLOREDUCEWINDOWOPTIONS_MEMBER_SIZE_OFFSET 0
#define STABLEHLOREDUCEWINDOWOPTIONS_WINDOW_DIMENSIONS_OFFSET 2
#define STABLEHLOREDUCEWINDOWOPTIONS_WINDOW_STRIDES_OFFSET 4
#define STABLEHLOREDUCEWINDOWOPTIONS_BASE_DILATIONS_OFFSET 6
#define STABLEHLOREDUCEWINDOWOPTIONS_WINDOW_DILATIONS_OFFSET 8
#define STABLEHLOREDUCEWINDOWOPTIONS_PAD10_OFFSET 10
#define STABLEHLOREDUCEWINDOWOPTIONS_BODY_SUBGRAPH_INDEX_OFFSET 12


Vector<int64_t> window_dimensions(){if(STABLEHLOREDUCEWINDOWOPTIONS_WINDOW_DIMENSIONS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOREDUCEWINDOWOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOREDUCEWINDOWOPTIONS_WINDOW_DIMENSIONS_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

Vector<int64_t> window_strides(){if(STABLEHLOREDUCEWINDOWOPTIONS_WINDOW_STRIDES_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOREDUCEWINDOWOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOREDUCEWINDOWOPTIONS_WINDOW_STRIDES_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

Vector<int64_t> base_dilations(){if(STABLEHLOREDUCEWINDOWOPTIONS_BASE_DILATIONS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOREDUCEWINDOWOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOREDUCEWINDOWOPTIONS_BASE_DILATIONS_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

Vector<int64_t> window_dilations(){if(STABLEHLOREDUCEWINDOWOPTIONS_WINDOW_DILATIONS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOREDUCEWINDOWOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOREDUCEWINDOWOPTIONS_WINDOW_DILATIONS_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

int32_t body_subgraph_index() {if(STABLEHLOREDUCEWINDOWOPTIONS_BODY_SUBGRAPH_INDEX_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOREDUCEWINDOWOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[STABLEHLOREDUCEWINDOWOPTIONS_BODY_SUBGRAPH_INDEX_OFFSET ]);}}

};



struct StablehloReduceWindowOptionsOffset {

unsigned char * data_;

StablehloReduceWindowOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

StablehloReduceWindowOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return StablehloReduceWindowOptions(&data_[offset]);}};



struct Rfft2dOptions {

unsigned char * data_;

Rfft2dOptions(unsigned char * data) : data_(data) {}

#define RFFT2DOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct Rfft2dOptionsOffset {

unsigned char * data_;

Rfft2dOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

Rfft2dOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return Rfft2dOptions(&data_[offset]);}};



struct BatchToSpaceNDOptions {

unsigned char * data_;

BatchToSpaceNDOptions(unsigned char * data) : data_(data) {}

#define BATCHTOSPACENDOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct BatchToSpaceNDOptionsOffset {

unsigned char * data_;

BatchToSpaceNDOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

BatchToSpaceNDOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return BatchToSpaceNDOptions(&data_[offset]);}};



struct Conv3DOptions {

unsigned char * data_;

Conv3DOptions(unsigned char * data) : data_(data) {}

#define CONV3DOPTIONS_MEMBER_SIZE_OFFSET 0
#define CONV3DOPTIONS_PAD2_OFFSET 2
#define CONV3DOPTIONS_STRIDE_D_OFFSET 4
#define CONV3DOPTIONS_STRIDE_W_OFFSET 8
#define CONV3DOPTIONS_STRIDE_H_OFFSET 12
#define CONV3DOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET 16
#define CONV3DOPTIONS_PAD17_OFFSET 17
#define CONV3DOPTIONS_DILATION_D_FACTOR_OFFSET 20
#define CONV3DOPTIONS_DILATION_W_FACTOR_OFFSET 24
#define CONV3DOPTIONS_DILATION_H_FACTOR_OFFSET 28


int32_t stride_d() {if(CONV3DOPTIONS_STRIDE_D_OFFSET < *reinterpret_cast<uint16_t *>(&data_[CONV3DOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[CONV3DOPTIONS_STRIDE_D_OFFSET ]);}}

int32_t stride_w() {if(CONV3DOPTIONS_STRIDE_W_OFFSET < *reinterpret_cast<uint16_t *>(&data_[CONV3DOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[CONV3DOPTIONS_STRIDE_W_OFFSET ]);}}

int32_t stride_h() {if(CONV3DOPTIONS_STRIDE_H_OFFSET < *reinterpret_cast<uint16_t *>(&data_[CONV3DOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[CONV3DOPTIONS_STRIDE_H_OFFSET ]);}}

ActivationFunctionType fused_activation_function() {
if(CONV3DOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[CONV3DOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<ActivationFunctionType*>(&data_[CONV3DOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET ]);}}

int32_t dilation_d_factor() {if(CONV3DOPTIONS_DILATION_D_FACTOR_OFFSET < *reinterpret_cast<uint16_t *>(&data_[CONV3DOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[CONV3DOPTIONS_DILATION_D_FACTOR_OFFSET ]);}}

int32_t dilation_w_factor() {if(CONV3DOPTIONS_DILATION_W_FACTOR_OFFSET < *reinterpret_cast<uint16_t *>(&data_[CONV3DOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[CONV3DOPTIONS_DILATION_W_FACTOR_OFFSET ]);}}

int32_t dilation_h_factor() {if(CONV3DOPTIONS_DILATION_H_FACTOR_OFFSET < *reinterpret_cast<uint16_t *>(&data_[CONV3DOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[CONV3DOPTIONS_DILATION_H_FACTOR_OFFSET ]);}}

};



struct Conv3DOptionsOffset {

unsigned char * data_;

Conv3DOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

Conv3DOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return Conv3DOptions(&data_[offset]);}};



struct LogicalAndOptions {

unsigned char * data_;

LogicalAndOptions(unsigned char * data) : data_(data) {}

#define LOGICALANDOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct LogicalAndOptionsOffset {

unsigned char * data_;

LogicalAndOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

LogicalAndOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return LogicalAndOptions(&data_[offset]);}};



struct HashtableOptions {

unsigned char * data_;

HashtableOptions(unsigned char * data) : data_(data) {}

#define HASHTABLEOPTIONS_MEMBER_SIZE_OFFSET 0
#define HASHTABLEOPTIONS_PAD2_OFFSET 2
#define HASHTABLEOPTIONS_TABLE_ID_OFFSET 4
#define HASHTABLEOPTIONS_KEY_DTYPE_OFFSET 8
#define HASHTABLEOPTIONS_VALUE_DTYPE_OFFSET 9
#define HASHTABLEOPTIONS_PAD10_OFFSET 10


int32_t table_id() {if(HASHTABLEOPTIONS_TABLE_ID_OFFSET < *reinterpret_cast<uint16_t *>(&data_[HASHTABLEOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[HASHTABLEOPTIONS_TABLE_ID_OFFSET ]);}}

TensorType key_dtype() {
if(HASHTABLEOPTIONS_KEY_DTYPE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[HASHTABLEOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<TensorType*>(&data_[HASHTABLEOPTIONS_KEY_DTYPE_OFFSET ]);}}

TensorType value_dtype() {
if(HASHTABLEOPTIONS_VALUE_DTYPE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[HASHTABLEOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<TensorType*>(&data_[HASHTABLEOPTIONS_VALUE_DTYPE_OFFSET ]);}}

};



struct HashtableOptionsOffset {

unsigned char * data_;

HashtableOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

HashtableOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return HashtableOptions(&data_[offset]);}};





struct Conv2DOptions {

unsigned char * data_;

Conv2DOptions(unsigned char * data) : data_(data) {}

#define CONV2DOPTIONS_MEMBER_SIZE_OFFSET 0
#define CONV2DOPTIONS_PAD2_OFFSET 2
#define CONV2DOPTIONS_STRIDE_W_OFFSET 4
#define CONV2DOPTIONS_STRIDE_H_OFFSET 8
#define CONV2DOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET 12
#define CONV2DOPTIONS_PAD13_OFFSET 13
#define CONV2DOPTIONS_DILATION_W_FACTOR_OFFSET 16
#define CONV2DOPTIONS_DILATION_H_FACTOR_OFFSET 20
#define CONV2DOPTIONS_QUANTIZED_BIAS_TYPE_OFFSET 24
#define CONV2DOPTIONS_PAD25_OFFSET 25


int32_t stride_w() {if(CONV2DOPTIONS_STRIDE_W_OFFSET < *reinterpret_cast<uint16_t *>(&data_[CONV2DOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[CONV2DOPTIONS_STRIDE_W_OFFSET ]);}}

int32_t stride_h() {if(CONV2DOPTIONS_STRIDE_H_OFFSET < *reinterpret_cast<uint16_t *>(&data_[CONV2DOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[CONV2DOPTIONS_STRIDE_H_OFFSET ]);}}

ActivationFunctionType fused_activation_function() {
if(CONV2DOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[CONV2DOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<ActivationFunctionType*>(&data_[CONV2DOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET ]);}}

int32_t dilation_w_factor() {if(CONV2DOPTIONS_DILATION_W_FACTOR_OFFSET < *reinterpret_cast<uint16_t *>(&data_[CONV2DOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[CONV2DOPTIONS_DILATION_W_FACTOR_OFFSET ]);}}

int32_t dilation_h_factor() {if(CONV2DOPTIONS_DILATION_H_FACTOR_OFFSET < *reinterpret_cast<uint16_t *>(&data_[CONV2DOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[CONV2DOPTIONS_DILATION_H_FACTOR_OFFSET ]);}}

TensorType quantized_bias_type() {
if(CONV2DOPTIONS_QUANTIZED_BIAS_TYPE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[CONV2DOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<TensorType*>(&data_[CONV2DOPTIONS_QUANTIZED_BIAS_TYPE_OFFSET ]);}}

};



struct Conv2DOptionsOffset {

unsigned char * data_;

Conv2DOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

Conv2DOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return Conv2DOptions(&data_[offset]);}};



struct SpaceToBatchNDOptions {

unsigned char * data_;

SpaceToBatchNDOptions(unsigned char * data) : data_(data) {}

#define SPACETOBATCHNDOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct SpaceToBatchNDOptionsOffset {

unsigned char * data_;

SpaceToBatchNDOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

SpaceToBatchNDOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return SpaceToBatchNDOptions(&data_[offset]);}};



struct TransposeOptions {

unsigned char * data_;

TransposeOptions(unsigned char * data) : data_(data) {}

#define TRANSPOSEOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct TransposeOptionsOffset {

unsigned char * data_;

TransposeOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

TransposeOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return TransposeOptions(&data_[offset]);}};



struct StablehloSortOptions {

unsigned char * data_;

StablehloSortOptions(unsigned char * data) : data_(data) {}

#define STABLEHLOSORTOPTIONS_MEMBER_SIZE_OFFSET 0
#define STABLEHLOSORTOPTIONS_PAD2_OFFSET 2
#define STABLEHLOSORTOPTIONS_DIMENSION_OFFSET 8
#define STABLEHLOSORTOPTIONS_IS_STABLE_OFFSET 16
#define STABLEHLOSORTOPTIONS_PAD17_OFFSET 17
#define STABLEHLOSORTOPTIONS_COMPARATOR_SUBGRAPH_INDEX_OFFSET 20


int64_t dimension() {if(STABLEHLOSORTOPTIONS_DIMENSION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOSORTOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int64_t*>(&data_[STABLEHLOSORTOPTIONS_DIMENSION_OFFSET ]);}}

bool is_stable() {if(STABLEHLOSORTOPTIONS_IS_STABLE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOSORTOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[STABLEHLOSORTOPTIONS_IS_STABLE_OFFSET ]);}}

int32_t comparator_subgraph_index() {if(STABLEHLOSORTOPTIONS_COMPARATOR_SUBGRAPH_INDEX_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOSORTOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[STABLEHLOSORTOPTIONS_COMPARATOR_SUBGRAPH_INDEX_OFFSET ]);}}

};



struct StablehloSortOptionsOffset {

unsigned char * data_;

StablehloSortOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

StablehloSortOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return StablehloSortOptions(&data_[offset]);}};



struct ReducerOptions {

unsigned char * data_;

ReducerOptions(unsigned char * data) : data_(data) {}

#define REDUCEROPTIONS_MEMBER_SIZE_OFFSET 0
#define REDUCEROPTIONS_KEEP_DIMS_OFFSET 2


bool keep_dims() {if(REDUCEROPTIONS_KEEP_DIMS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[REDUCEROPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[REDUCEROPTIONS_KEEP_DIMS_OFFSET ]);}}

};



struct ReducerOptionsOffset {

unsigned char * data_;

ReducerOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

ReducerOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return ReducerOptions(&data_[offset]);}};



struct SubOptions {

unsigned char * data_;

SubOptions(unsigned char * data) : data_(data) {}

#define SUBOPTIONS_MEMBER_SIZE_OFFSET 0
#define SUBOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET 2
#define SUBOPTIONS_POT_SCALE_INT16_OFFSET 3


ActivationFunctionType fused_activation_function() {
if(SUBOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SUBOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<ActivationFunctionType*>(&data_[SUBOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET ]);}}

bool pot_scale_int16() {if(SUBOPTIONS_POT_SCALE_INT16_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SUBOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[SUBOPTIONS_POT_SCALE_INT16_OFFSET ]);}}

};



struct SubOptionsOffset {

unsigned char * data_;

SubOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

SubOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return SubOptions(&data_[offset]);}};



struct DivOptions {

unsigned char * data_;

DivOptions(unsigned char * data) : data_(data) {}

#define DIVOPTIONS_MEMBER_SIZE_OFFSET 0
#define DIVOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET 2


ActivationFunctionType fused_activation_function() {
if(DIVOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[DIVOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<ActivationFunctionType*>(&data_[DIVOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET ]);}}

};



struct DivOptionsOffset {

unsigned char * data_;

DivOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

DivOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return DivOptions(&data_[offset]);}};



struct SqueezeOptions {

unsigned char * data_;

SqueezeOptions(unsigned char * data) : data_(data) {}

#define SQUEEZEOPTIONS_MEMBER_SIZE_OFFSET 0
#define SQUEEZEOPTIONS_SQUEEZE_DIMS_OFFSET 2


Vector<int32_t> squeeze_dims(){if(SQUEEZEOPTIONS_SQUEEZE_DIMS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SQUEEZEOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = SQUEEZEOPTIONS_SQUEEZE_DIMS_OFFSET ;return Vector<int32_t>(&data_[offset]);}}

};



struct SqueezeOptionsOffset {

unsigned char * data_;

SqueezeOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

SqueezeOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return SqueezeOptions(&data_[offset]);}};



struct HashtableFindOptions {

unsigned char * data_;

HashtableFindOptions(unsigned char * data) : data_(data) {}

#define HASHTABLEFINDOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct HashtableFindOptionsOffset {

unsigned char * data_;

HashtableFindOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

HashtableFindOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return HashtableFindOptions(&data_[offset]);}};



struct StablehloWhileOptions {

unsigned char * data_;

StablehloWhileOptions(unsigned char * data) : data_(data) {}

#define STABLEHLOWHILEOPTIONS_MEMBER_SIZE_OFFSET 0
#define STABLEHLOWHILEOPTIONS_PAD2_OFFSET 2
#define STABLEHLOWHILEOPTIONS_COND_SUBGRAPH_INDEX_OFFSET 4
#define STABLEHLOWHILEOPTIONS_BODY_SUBGRAPH_INDEX_OFFSET 8


int32_t cond_subgraph_index() {if(STABLEHLOWHILEOPTIONS_COND_SUBGRAPH_INDEX_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOWHILEOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[STABLEHLOWHILEOPTIONS_COND_SUBGRAPH_INDEX_OFFSET ]);}}

int32_t body_subgraph_index() {if(STABLEHLOWHILEOPTIONS_BODY_SUBGRAPH_INDEX_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOWHILEOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[STABLEHLOWHILEOPTIONS_BODY_SUBGRAPH_INDEX_OFFSET ]);}}

};



struct StablehloWhileOptionsOffset {

unsigned char * data_;

StablehloWhileOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

StablehloWhileOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return StablehloWhileOptions(&data_[offset]);}};



struct SequenceRNNOptions {

unsigned char * data_;

SequenceRNNOptions(unsigned char * data) : data_(data) {}

#define SEQUENCERNNOPTIONS_MEMBER_SIZE_OFFSET 0
#define SEQUENCERNNOPTIONS_TIME_MAJOR_OFFSET 2
#define SEQUENCERNNOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET 3
#define SEQUENCERNNOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET 4


bool time_major() {if(SEQUENCERNNOPTIONS_TIME_MAJOR_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SEQUENCERNNOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[SEQUENCERNNOPTIONS_TIME_MAJOR_OFFSET ]);}}

ActivationFunctionType fused_activation_function() {
if(SEQUENCERNNOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SEQUENCERNNOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<ActivationFunctionType*>(&data_[SEQUENCERNNOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET ]);}}

bool asymmetric_quantize_inputs() {if(SEQUENCERNNOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SEQUENCERNNOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[SEQUENCERNNOPTIONS_ASYMMETRIC_QUANTIZE_INPUTS_OFFSET ]);}}

};



struct SequenceRNNOptionsOffset {

unsigned char * data_;

SequenceRNNOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

SequenceRNNOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return SequenceRNNOptions(&data_[offset]);}};



struct StridedSliceOptions {

unsigned char * data_;

StridedSliceOptions(unsigned char * data) : data_(data) {}

#define STRIDEDSLICEOPTIONS_MEMBER_SIZE_OFFSET 0
#define STRIDEDSLICEOPTIONS_PAD2_OFFSET 2
#define STRIDEDSLICEOPTIONS_BEGIN_MASK_OFFSET 4
#define STRIDEDSLICEOPTIONS_END_MASK_OFFSET 8
#define STRIDEDSLICEOPTIONS_ELLIPSIS_MASK_OFFSET 12
#define STRIDEDSLICEOPTIONS_NEW_AXIS_MASK_OFFSET 16
#define STRIDEDSLICEOPTIONS_SHRINK_AXIS_MASK_OFFSET 20
#define STRIDEDSLICEOPTIONS_OFFSET_OFFSET 24
#define STRIDEDSLICEOPTIONS_PAD25_OFFSET 25


int32_t begin_mask() {if(STRIDEDSLICEOPTIONS_BEGIN_MASK_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STRIDEDSLICEOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[STRIDEDSLICEOPTIONS_BEGIN_MASK_OFFSET ]);}}

int32_t end_mask() {if(STRIDEDSLICEOPTIONS_END_MASK_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STRIDEDSLICEOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[STRIDEDSLICEOPTIONS_END_MASK_OFFSET ]);}}

int32_t ellipsis_mask() {if(STRIDEDSLICEOPTIONS_ELLIPSIS_MASK_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STRIDEDSLICEOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[STRIDEDSLICEOPTIONS_ELLIPSIS_MASK_OFFSET ]);}}

int32_t new_axis_mask() {if(STRIDEDSLICEOPTIONS_NEW_AXIS_MASK_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STRIDEDSLICEOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[STRIDEDSLICEOPTIONS_NEW_AXIS_MASK_OFFSET ]);}}

int32_t shrink_axis_mask() {if(STRIDEDSLICEOPTIONS_SHRINK_AXIS_MASK_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STRIDEDSLICEOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[STRIDEDSLICEOPTIONS_SHRINK_AXIS_MASK_OFFSET ]);}}

bool offset() {if(STRIDEDSLICEOPTIONS_OFFSET_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STRIDEDSLICEOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[STRIDEDSLICEOPTIONS_OFFSET_OFFSET ]);}}

};



struct StridedSliceOptionsOffset {

unsigned char * data_;

StridedSliceOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

StridedSliceOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return StridedSliceOptions(&data_[offset]);}};





struct HashtableImportOptions {

unsigned char * data_;

HashtableImportOptions(unsigned char * data) : data_(data) {}

#define HASHTABLEIMPORTOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct HashtableImportOptionsOffset {

unsigned char * data_;

HashtableImportOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

HashtableImportOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return HashtableImportOptions(&data_[offset]);}};



struct UnsortedSegmentProdOptions {

unsigned char * data_;

UnsortedSegmentProdOptions(unsigned char * data) : data_(data) {}

#define UNSORTEDSEGMENTPRODOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct UnsortedSegmentProdOptionsOffset {

unsigned char * data_;

UnsortedSegmentProdOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

UnsortedSegmentProdOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return UnsortedSegmentProdOptions(&data_[offset]);}};



struct ExpOptions {

unsigned char * data_;

ExpOptions(unsigned char * data) : data_(data) {}

#define EXPOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct ExpOptionsOffset {

unsigned char * data_;

ExpOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

ExpOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return ExpOptions(&data_[offset]);}};



struct StablehloTransposeOptions {

unsigned char * data_;

StablehloTransposeOptions(unsigned char * data) : data_(data) {}

#define STABLEHLOTRANSPOSEOPTIONS_MEMBER_SIZE_OFFSET 0
#define STABLEHLOTRANSPOSEOPTIONS_PERMUTATION_OFFSET 2


Vector<int64_t> permutation(){if(STABLEHLOTRANSPOSEOPTIONS_PERMUTATION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[STABLEHLOTRANSPOSEOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = STABLEHLOTRANSPOSEOPTIONS_PERMUTATION_OFFSET ;return Vector<int64_t>(&data_[offset]);}}

};



struct StablehloTransposeOptionsOffset {

unsigned char * data_;

StablehloTransposeOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

StablehloTransposeOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return StablehloTransposeOptions(&data_[offset]);}};



struct HashtableSizeOptions {

unsigned char * data_;

HashtableSizeOptions(unsigned char * data) : data_(data) {}

#define HASHTABLESIZEOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct HashtableSizeOptionsOffset {

unsigned char * data_;

HashtableSizeOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

HashtableSizeOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return HashtableSizeOptions(&data_[offset]);}};



struct VarHandleOptions {

unsigned char * data_;

VarHandleOptions(unsigned char * data) : data_(data) {}

#define VARHANDLEOPTIONS_MEMBER_SIZE_OFFSET 0
#define VARHANDLEOPTIONS_CONTAINER_OFFSET 2
#define VARHANDLEOPTIONS_SHARED_NAME_OFFSET 4


StringOffset container(){if(VARHANDLEOPTIONS_CONTAINER_OFFSET < *reinterpret_cast<uint16_t *>(&data_[VARHANDLEOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = VARHANDLEOPTIONS_CONTAINER_OFFSET ;return StringOffset(&data_[offset]);}}

StringOffset shared_name(){if(VARHANDLEOPTIONS_SHARED_NAME_OFFSET < *reinterpret_cast<uint16_t *>(&data_[VARHANDLEOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = VARHANDLEOPTIONS_SHARED_NAME_OFFSET ;return StringOffset(&data_[offset]);}}

};



struct VarHandleOptionsOffset {

unsigned char * data_;

VarHandleOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

VarHandleOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return VarHandleOptions(&data_[offset]);}};



struct ReadVariableOptions {

unsigned char * data_;

ReadVariableOptions(unsigned char * data) : data_(data) {}

#define READVARIABLEOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct ReadVariableOptionsOffset {

unsigned char * data_;

ReadVariableOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

ReadVariableOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return ReadVariableOptions(&data_[offset]);}};



struct DilateOptions {

unsigned char * data_;

DilateOptions(unsigned char * data) : data_(data) {}

#define DILATEOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct DilateOptionsOffset {

unsigned char * data_;

DilateOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

DilateOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return DilateOptions(&data_[offset]);}};



struct AssignVariableOptions {

unsigned char * data_;

AssignVariableOptions(unsigned char * data) : data_(data) {}

#define ASSIGNVARIABLEOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct AssignVariableOptionsOffset {

unsigned char * data_;

AssignVariableOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

AssignVariableOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return AssignVariableOptions(&data_[offset]);}};



struct RandomOptions {

unsigned char * data_;

RandomOptions(unsigned char * data) : data_(data) {}

#define RANDOMOPTIONS_MEMBER_SIZE_OFFSET 0
#define RANDOMOPTIONS_PAD2_OFFSET 2
#define RANDOMOPTIONS_SEED_OFFSET 8
#define RANDOMOPTIONS_SEED2_OFFSET 16


int64_t seed() {if(RANDOMOPTIONS_SEED_OFFSET < *reinterpret_cast<uint16_t *>(&data_[RANDOMOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int64_t*>(&data_[RANDOMOPTIONS_SEED_OFFSET ]);}}

int64_t seed2() {if(RANDOMOPTIONS_SEED2_OFFSET < *reinterpret_cast<uint16_t *>(&data_[RANDOMOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int64_t*>(&data_[RANDOMOPTIONS_SEED2_OFFSET ]);}}

};



struct RandomOptionsOffset {

unsigned char * data_;

RandomOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

RandomOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return RandomOptions(&data_[offset]);}};



struct BucketizeOptions {

unsigned char * data_;

BucketizeOptions(unsigned char * data) : data_(data) {}

#define BUCKETIZEOPTIONS_MEMBER_SIZE_OFFSET 0
#define BUCKETIZEOPTIONS_BOUNDARIES_OFFSET 2


Vector<float> boundaries(){if(BUCKETIZEOPTIONS_BOUNDARIES_OFFSET < *reinterpret_cast<uint16_t *>(&data_[BUCKETIZEOPTIONS_MEMBER_SIZE_OFFSET])){const int16_t offset = BUCKETIZEOPTIONS_BOUNDARIES_OFFSET ;return Vector<float>(&data_[offset]);}}

};



struct BucketizeOptionsOffset {

unsigned char * data_;

BucketizeOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

BucketizeOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return BucketizeOptions(&data_[offset]);}};



struct TopKV2Options {

unsigned char * data_;

TopKV2Options(unsigned char * data) : data_(data) {}

#define TOPKV2OPTIONS_MEMBER_SIZE_OFFSET 0


};



struct TopKV2OptionsOffset {

unsigned char * data_;

TopKV2OptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

TopKV2Options value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return TopKV2Options(&data_[offset]);}};



struct LogSoftmaxOptions {

unsigned char * data_;

LogSoftmaxOptions(unsigned char * data) : data_(data) {}

#define LOGSOFTMAXOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct LogSoftmaxOptionsOffset {

unsigned char * data_;

LogSoftmaxOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

LogSoftmaxOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return LogSoftmaxOptions(&data_[offset]);}};



struct CastOptions {

unsigned char * data_;

CastOptions(unsigned char * data) : data_(data) {}

#define CASTOPTIONS_MEMBER_SIZE_OFFSET 0
#define CASTOPTIONS_IN_DATA_TYPE_OFFSET 2
#define CASTOPTIONS_OUT_DATA_TYPE_OFFSET 3


TensorType in_data_type() {
if(CASTOPTIONS_IN_DATA_TYPE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[CASTOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<TensorType*>(&data_[CASTOPTIONS_IN_DATA_TYPE_OFFSET ]);}}

TensorType out_data_type() {
if(CASTOPTIONS_OUT_DATA_TYPE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[CASTOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<TensorType*>(&data_[CASTOPTIONS_OUT_DATA_TYPE_OFFSET ]);}}

};



struct CastOptionsOffset {

unsigned char * data_;

CastOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

CastOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return CastOptions(&data_[offset]);}};



struct GeluOptions {

unsigned char * data_;

GeluOptions(unsigned char * data) : data_(data) {}

#define GELUOPTIONS_MEMBER_SIZE_OFFSET 0
#define GELUOPTIONS_APPROXIMATE_OFFSET 2


bool approximate() {if(GELUOPTIONS_APPROXIMATE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[GELUOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[GELUOPTIONS_APPROXIMATE_OFFSET ]);}}

};



struct GeluOptionsOffset {

unsigned char * data_;

GeluOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

GeluOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return GeluOptions(&data_[offset]);}};



struct DequantizeOptions {

unsigned char * data_;

DequantizeOptions(unsigned char * data) : data_(data) {}

#define DEQUANTIZEOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct DequantizeOptionsOffset {

unsigned char * data_;

DequantizeOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

DequantizeOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return DequantizeOptions(&data_[offset]);}};





struct UnsortedSegmentMaxOptions {

unsigned char * data_;

UnsortedSegmentMaxOptions(unsigned char * data) : data_(data) {}

#define UNSORTEDSEGMENTMAXOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct UnsortedSegmentMaxOptionsOffset {

unsigned char * data_;

UnsortedSegmentMaxOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

UnsortedSegmentMaxOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return UnsortedSegmentMaxOptions(&data_[offset]);}};





struct LSHProjectionOptions {

unsigned char * data_;

LSHProjectionOptions(unsigned char * data) : data_(data) {}

#define LSHPROJECTIONOPTIONS_MEMBER_SIZE_OFFSET 0
#define LSHPROJECTIONOPTIONS_TYPE_OFFSET 2


LSHProjectionType type() {
if(LSHPROJECTIONOPTIONS_TYPE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[LSHPROJECTIONOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<LSHProjectionType*>(&data_[LSHPROJECTIONOPTIONS_TYPE_OFFSET ]);}}

};



struct LSHProjectionOptionsOffset {

unsigned char * data_;

LSHProjectionOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

LSHProjectionOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return LSHProjectionOptions(&data_[offset]);}};



struct MaximumMinimumOptions {

unsigned char * data_;

MaximumMinimumOptions(unsigned char * data) : data_(data) {}

#define MAXIMUMMINIMUMOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct MaximumMinimumOptionsOffset {

unsigned char * data_;

MaximumMinimumOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

MaximumMinimumOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return MaximumMinimumOptions(&data_[offset]);}};



struct UnsortedSegmentMinOptions {

unsigned char * data_;

UnsortedSegmentMinOptions(unsigned char * data) : data_(data) {}

#define UNSORTEDSEGMENTMINOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct UnsortedSegmentMinOptionsOffset {

unsigned char * data_;

UnsortedSegmentMinOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

UnsortedSegmentMinOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return UnsortedSegmentMinOptions(&data_[offset]);}};



struct NegOptions {

unsigned char * data_;

NegOptions(unsigned char * data) : data_(data) {}

#define NEGOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct NegOptionsOffset {

unsigned char * data_;

NegOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

NegOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return NegOptions(&data_[offset]);}};



struct UnsortedSegmentSumOptions {

unsigned char * data_;

UnsortedSegmentSumOptions(unsigned char * data) : data_(data) {}

#define UNSORTEDSEGMENTSUMOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct UnsortedSegmentSumOptionsOffset {

unsigned char * data_;

UnsortedSegmentSumOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

UnsortedSegmentSumOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return UnsortedSegmentSumOptions(&data_[offset]);}};



struct PadV2Options {

unsigned char * data_;

PadV2Options(unsigned char * data) : data_(data) {}

#define PADV2OPTIONS_MEMBER_SIZE_OFFSET 0


};



struct PadV2OptionsOffset {

unsigned char * data_;

PadV2OptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

PadV2Options value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return PadV2Options(&data_[offset]);}};



struct ATan2Options {

unsigned char * data_;

ATan2Options(unsigned char * data) : data_(data) {}

#define ATAN2OPTIONS_MEMBER_SIZE_OFFSET 0


};



struct ATan2OptionsOffset {

unsigned char * data_;

ATan2OptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

ATan2Options value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return ATan2Options(&data_[offset]);}};



struct GreaterEqualOptions {

unsigned char * data_;

GreaterEqualOptions(unsigned char * data) : data_(data) {}

#define GREATEREQUALOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct GreaterEqualOptionsOffset {

unsigned char * data_;

GreaterEqualOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

GreaterEqualOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return GreaterEqualOptions(&data_[offset]);}};



struct SignOptions {

unsigned char * data_;

SignOptions(unsigned char * data) : data_(data) {}

#define SIGNOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct SignOptionsOffset {

unsigned char * data_;

SignOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

SignOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return SignOptions(&data_[offset]);}};



struct SliceOptions {

unsigned char * data_;

SliceOptions(unsigned char * data) : data_(data) {}

#define SLICEOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct SliceOptionsOffset {

unsigned char * data_;

SliceOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

SliceOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return SliceOptions(&data_[offset]);}};



struct BitcastOptions {

unsigned char * data_;

BitcastOptions(unsigned char * data) : data_(data) {}

#define BITCASTOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct BitcastOptionsOffset {

unsigned char * data_;

BitcastOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

BitcastOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return BitcastOptions(&data_[offset]);}};



struct TransposeConvOptions {

unsigned char * data_;

TransposeConvOptions(unsigned char * data) : data_(data) {}

#define TRANSPOSECONVOPTIONS_MEMBER_SIZE_OFFSET 0
#define TRANSPOSECONVOPTIONS_PAD2_OFFSET 2
#define TRANSPOSECONVOPTIONS_STRIDE_W_OFFSET 4
#define TRANSPOSECONVOPTIONS_STRIDE_H_OFFSET 8
#define TRANSPOSECONVOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET 12
#define TRANSPOSECONVOPTIONS_QUANTIZED_BIAS_TYPE_OFFSET 13
#define TRANSPOSECONVOPTIONS_PAD14_OFFSET 14


int32_t stride_w() {if(TRANSPOSECONVOPTIONS_STRIDE_W_OFFSET < *reinterpret_cast<uint16_t *>(&data_[TRANSPOSECONVOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[TRANSPOSECONVOPTIONS_STRIDE_W_OFFSET ]);}}

int32_t stride_h() {if(TRANSPOSECONVOPTIONS_STRIDE_H_OFFSET < *reinterpret_cast<uint16_t *>(&data_[TRANSPOSECONVOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<int32_t*>(&data_[TRANSPOSECONVOPTIONS_STRIDE_H_OFFSET ]);}}

ActivationFunctionType fused_activation_function() {
if(TRANSPOSECONVOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET < *reinterpret_cast<uint16_t *>(&data_[TRANSPOSECONVOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<ActivationFunctionType*>(&data_[TRANSPOSECONVOPTIONS_FUSED_ACTIVATION_FUNCTION_OFFSET ]);}}

TensorType quantized_bias_type() {
if(TRANSPOSECONVOPTIONS_QUANTIZED_BIAS_TYPE_OFFSET < *reinterpret_cast<uint16_t *>(&data_[TRANSPOSECONVOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<TensorType*>(&data_[TRANSPOSECONVOPTIONS_QUANTIZED_BIAS_TYPE_OFFSET ]);}}

};



struct TransposeConvOptionsOffset {

unsigned char * data_;

TransposeConvOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

TransposeConvOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return TransposeConvOptions(&data_[offset]);}};



struct BitwiseXorOptions {

unsigned char * data_;

BitwiseXorOptions(unsigned char * data) : data_(data) {}

#define BITWISEXOROPTIONS_MEMBER_SIZE_OFFSET 0


};



struct BitwiseXorOptionsOffset {

unsigned char * data_;

BitwiseXorOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

BitwiseXorOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return BitwiseXorOptions(&data_[offset]);}};



struct SparseToDenseOptions {

unsigned char * data_;

SparseToDenseOptions(unsigned char * data) : data_(data) {}

#define SPARSETODENSEOPTIONS_MEMBER_SIZE_OFFSET 0
#define SPARSETODENSEOPTIONS_VALIDATE_INDICES_OFFSET 2


bool validate_indices() {if(SPARSETODENSEOPTIONS_VALIDATE_INDICES_OFFSET < *reinterpret_cast<uint16_t *>(&data_[SPARSETODENSEOPTIONS_MEMBER_SIZE_OFFSET])){return *reinterpret_cast<bool*>(&data_[SPARSETODENSEOPTIONS_VALIDATE_INDICES_OFFSET ]);}}

};



struct SparseToDenseOptionsOffset {

unsigned char * data_;

SparseToDenseOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

SparseToDenseOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return SparseToDenseOptions(&data_[offset]);}};





struct RightShiftOptions {

unsigned char * data_;

RightShiftOptions(unsigned char * data) : data_(data) {}

#define RIGHTSHIFTOPTIONS_MEMBER_SIZE_OFFSET 0


};



struct RightShiftOptionsOffset {

unsigned char * data_;

RightShiftOptionsOffset (unsigned char * data) : data_(data) {}


     bool is_null()
    {
        return *reinterpret_cast<uint16_t *>(data_) == 0;
    }
    

RightShiftOptions value(){ const int16_t offset = *reinterpret_cast<int16_t *>(data_);return RightShiftOptions(&data_[offset]);}};

