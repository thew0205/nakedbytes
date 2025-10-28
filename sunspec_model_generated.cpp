
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>



struct SunspecPointData_enum; 
struct SunspecPointDef; 
struct SunspecPointData; 
struct SunspecModelDef; 
struct SunspecGroupType; 
struct SunspecGroupPointDef; 
struct SunspecPointAccessType; 
struct SunspecPointMandatoryType; 


struct SunspecPointDef {

unsigned char * data_;

SunspecPointDef(unsigned char * data) : data_(data) {}

#define SUNSPECPOINTDEF_ID_OFFSET 0
#define SUNSPECPOINTDEF_SF_ID_OFFSET 2
#define SUNSPECPOINTDEF_UNITS_OFFSET 4
#define SUNSPECPOINTDEF_LABEL_OFFSET 6
#define SUNSPECPOINTDEF_DATA_TYPE_OFFSET 8
#define SUNSPECPOINTDEF_DATA_OFFSET 10
#define SUNSPECPOINTDEF_COUNT_OFFSET 12
#define SUNSPECPOINTDEF_SIZE_OFFSET 13
#define SUNSPECPOINTDEF_SF_OFFSET 14
#define SUNSPECPOINTDEF_ACCESS_OFFSET 15
#define SUNSPECPOINTDEF_MANDATORY_OFFSET 16
#define SUNSPECPOINTDEF_PAD17_OFFSET 17


uint8_t id() {}

uint8_t sf_id() {}

uint8_t units() {}

uint8_t label() {}

SunspecPointData_enum data_type() {}

SunspecPointData data() {}

uint8_t count() {}

uint8_t size() {}

uint8_t sf() {}

SunspecPointAccessType access() {}

SunspecPointMandatoryType mandatory() {}

uint8_t pad17() {}

};

struct SunspecModelDef {

unsigned char * data_;

SunspecModelDef(unsigned char * data) : data_(data) {}

#define SUNSPECMODELDEF_ID_OFFSET 0
#define SUNSPECMODELDEF_GROUP_OFFSET 2


uint8_t id() {}

SunspecGroupPointDef group() {}

};

struct SunspecGroupPointDef {

unsigned char * data_;

SunspecGroupPointDef(unsigned char * data) : data_(data) {}

#define SUNSPECGROUPPOINTDEF_ID_OFFSET 0
#define SUNSPECGROUPPOINTDEF_COUNT_POINT_ID_OFFSET 2
#define SUNSPECGROUPPOINTDEF_POINTS_OFFSET 4
#define SUNSPECGROUPPOINTDEF_GROUPS_OFFSET 6
#define SUNSPECGROUPPOINTDEF_LABEL_OFFSET 8
#define SUNSPECGROUPPOINTDEF_COUNT_OFFSET 10
#define SUNSPECGROUPPOINTDEF_TYPE_OFFSET 11


uint8_t id() {}

uint8_t count_point_id() {}

SunspecPointDef points() {}

SunspecGroupPointDef groups() {}

uint8_t label() {}

uint8_t count() {}

SunspecGroupType type() {}

};

