#ifndef GM_CONTROL_H
#define GM_CONTROL_H

#include <sys/types.h>
#include <libgte.h>

typedef struct Res_Control_unknown
{
    short field_0_scriptData_orHashedName;
    short field_2_name_hash;
    short field_4_trigger_Hash_Name_or_camera_w;
    short field_6_count;
    int field_8_wordPtr;
    int field_C;
    int field_10;
    SVECTOR field_14_vec;
} Res_Control_unknown;

struct map_record;

typedef struct Res_Control
{
    SVECTOR field_0_vec;
    SVECTOR field_8_vec;
    Res_Control_unknown field_10_pStruct_hzd_unknown;
    struct map_record *field_2C_map;
    unsigned short field_30_scriptData;
    short field_32_height;
    short field_34;
    short field_36;
    short field_38;
    short field_3A;
    short field_3C;
    short field_3E;
    short field_40;
    short field_42;
    SVECTOR field_44_vec;
    SVECTOR field_4C_turn_vec;
    char field_54;
    char field_55_flags;
    char field_56;
    char field_57;
    char field_58;
    char field_59;
    short field_5A;
    int field_5C_mesg;
    SVECTOR field_60_vecs_ary[2];
    int field_70;
    int field_74;
    short field_78;
    short field_7A;
} Res_Control;

#define MAX_CONTROLS 96

#endif // GM_CONTROL_H
