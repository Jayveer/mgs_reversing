#include "libgcl/libgcl.h"
#include "libdg/libdg.h"

#define EXEC_LEVEL 5

typedef struct LampWork
{
    GV_ACT         actor;
    DG_PRIM       *field_20_prim;
    short          field_24;
    char           field_26;
    char           field_27;
    unsigned short field_28_name;
    short          field_2A;
    int            field_2C;
    int            field_30;
    unsigned char *field_34_gcl_nextStrPtr;
    unsigned char *field_38;
    unsigned char *field_3C;
    SVECTOR        field_40_children[0];
} LampWork;

extern unsigned char *GCL_NextStrPtr_800AB9A0;
extern int            GM_CurrentMap_800AB9B0;
extern const char     d11c_aLampc_800C6700[]; // = "lamp.c";

#pragma INCLUDE_ASM("asm/overlays/d11c/d11c_800C326C.s")
void d11c_800C326C(LampWork *, int);

unsigned char *d11c_800C34C4(LampWork *work, int arg1)
{
    unsigned char *strptr;

    strptr = work->field_34_gcl_nextStrPtr;
    while (strptr[0] == 'P')
    {
        if (strptr[1] == arg1)
        {
            return strptr + 3;
        }
        strptr = strptr + strptr[2] + 2;
    }
    return NULL;
}

void d11c_800C3518(LampWork *work, int arg1)
{
    unsigned char *temp_v0;

    temp_v0 = d11c_800C34C4(work, arg1);
    work->field_38 = temp_v0;
    work->field_3C = temp_v0;
    work->field_30 = 0;
    work->field_2A = -1;
}

void d11c_800C3550(LampWork *work)
{
    GV_MSG *message;
    int     message_result;

    message_result = GV_ReceiveMessage_80016620(work->field_28_name, &message);
    for (; message_result > 0; message_result--, message++)
    {
        switch (message->message[0])
        {
        case 0xE4E:
            d11c_800C326C(work, message->message[1]);
            work->field_3C = 0;
            break;
        case 0xC927:
            d11c_800C326C(work, 0);
            work->field_3C = 0;
            break;
        case 0xBCD2:
            d11c_800C3518(work, message->message[1]);
            break;
        }
    }
}

extern const char d11c_aTexparseerror_800C66EC[]; // = "TEX:PARSE ERROR\n";

void d11c_800C361C(LampWork *work)
{
    int param1, param2, param3;
    int type;

    if (work->field_3C == NULL)
    {
        work->field_30 = -1;
        return;
    }
    GCL_SetArgTop_80020690(work->field_3C);

    while (GCL_Get_Param_Result_80020AA4())
    {
        type = GCL_StrToInt_800209E8(GCL_Get_Param_Result_80020AA4());

        switch (type)
        {
        case 0xDD19:
            param1 = GCL_StrToInt_800209E8(GCL_Get_Param_Result_80020AA4());
            param2 = GCL_StrToInt_800209E8(GCL_Get_Param_Result_80020AA4());
            d11c_800C326C(work, param1);
            work->field_30 = param2;
            work->field_3C = GCL_Get_Param_Result_80020AA4();
            return;
        case 0xCA87:
            if (GCL_Get_Param_Result_80020AA4())
            {
                param3 = GCL_StrToInt_800209E8(GCL_Get_Param_Result_80020AA4());
            }
            else
            {
                param3 = 0;
            }
            if (work->field_2A >= 0)
            {
                if (param3 > 0)
                {
                    if (--work->field_2A < 2)
                    {
                        work->field_30 = -1;
                        work->field_3C = 0;
                        return;
                    }
                }
            }
            else
            {
                work->field_2A = param3;
            }
            GCL_SetArgTop_80020690(work->field_38);
            break;
        case 0x11F8:
            d11c_800C3518(work, GCL_StrToInt_800209E8(GCL_Get_Param_Result_80020AA4()));
            GCL_SetArgTop_80020690(work->field_3C);
        default:
            printf(d11c_aTexparseerror_800C66EC);
            break;
        }
    }
}

void d11c_800C37A4(LampWork *work)
{
    d11c_800C3550(work);
    if (work->field_30 >= 0)
    {
        if (work->field_30 > 0)
        {
            work->field_30--;
            return;
        }
        d11c_800C361C(work);
    }
}

void d11c_800C37F0(LampWork *work)
{
    DG_PRIM *prim;

    prim = work->field_20_prim;
    if (prim)
    {
        DG_DequeuePrim_800182E0(prim);
        DG_FreePrim_8001BC04(prim);
    }
}

#pragma INCLUDE_ASM("asm/overlays/d11c/d11c_800C382C.s")
void d11c_800C382C(SVECTOR *, int, int, int, int);

int LampGetResources_800C3914(LampWork *work, int map, int name, int a3, int a4)
{
    MATRIX   mat;
    SVECTOR  svec1;
    SVECTOR  svec2;
    int      param1;
    DG_PRIM *prim;
    SVECTOR *field_40_children;
    int      param2;
    int      prim_count;
    int      param3;
    int      primType;
    int      param4;
    int      param5;

    GM_CurrentMap_800AB9B0 = map;
    GCL_StrToSV_80020A14(GCL_Get_Param_Result_80020AA4(), &svec1);
    GCL_StrToSV_80020A14(GCL_Get_Param_Result_80020AA4(), &svec2);
    param1 = GCL_GetNextParamValue_80020AD4();
    param2 = GCL_GetNextParamValue_80020AD4();
    param3 = GCL_GetNextParamValue_80020AD4();
    work->field_28_name = name;
    work->field_38 = 0;
    work->field_3C = 0;
    work->field_30 = -1;
    work->field_34_gcl_nextStrPtr = GCL_NextStrPtr_800AB9A0;

    if (GCL_GetOption_80020968('I'))
    {
        param4 = GCL_GetNextParamValue_80020AD4();
        primType = 0x1012;
    }
    else
    {
        param4 = 0;
        primType = 0x1012;
    }

    if (GCL_GetOption_80020968('T'))
    {
        primType = 0x12;
    }

    if (GCL_GetOption_80020968('R'))
    {
        param5 = GCL_GetNextParamValue_80020AD4();
    }
    else
    {
        param5 = 0x01808080;
    }

    work->field_2C = param5 | 0x2C000000;
    if (GCL_GetOption_80020968('S'))
    {
        work->field_2C |= 0x02000000;
    }

    prim_count = a3 * a4;
    field_40_children = work->field_40_children;

    prim = DG_MakePrim_8001BABC(primType, prim_count, 0, field_40_children, NULL);
    if (prim != NULL)
    {
        int map;
        DG_QueuePrim_80018274(prim);
        map = GM_CurrentMap_800AB9B0;
        prim->group_id = map;
    }

    work->field_20_prim = prim;
    work->field_24 = prim_count;

    if (prim == NULL)
    {
        return 0;
    }

    RotMatrix(&svec2, &mat);

    mat.t[0] = svec1.vx;
    mat.t[1] = svec1.vy;
    mat.t[2] = svec1.vz;

    DG_SetPos_8001BC44(&mat);
    DG_PutPrim_8001BE00(&prim->world);

    prim->field_2E_k500 = param3;
    work->field_26 = a3;
    work->field_27 = a4;

    d11c_800C326C(work, param4);
    d11c_800C382C(field_40_children, param1, param2, a3, a4);

    return 1;
}

GV_ACT *NewLamp_800C3B34(int name, int where, int argc, char **argv)
{
    LampWork      *work;
    unsigned char *nextStrPtr;
    int            param1, param2;

    nextStrPtr = GCL_NextStrPtr_800AB9A0;

    if (GCL_GetOption_80020968('D'))
    {
        param1 = GCL_GetNextParamValue_80020AD4();
        param2 = GCL_GetNextParamValue_80020AD4();
    }
    else
    {
        param2 = 1;
        param1 = 1;
    }

    GCL_NextStrPtr_800AB9A0 = nextStrPtr;

    work = (LampWork *)GV_NewActor_800150E4(EXEC_LEVEL, ((param1 * param2) * sizeof(SVECTOR) * 4) + sizeof(LampWork));
    if (work)
    {
        GV_SetNamedActor_8001514C(&work->actor, (TActorFunction)d11c_800C37A4, (TActorFunction)d11c_800C37F0,
                                  d11c_aLampc_800C6700);
        if (LampGetResources_800C3914(work, where, name, param1, param2) == 0)
        {
            GV_DestroyActor_800151C8(&work->actor);
            return NULL;
        }
    }
    return &work->actor;
}