#include "linker.h"
#include "libdg.h"

extern void System_void_allocation_80016078(unsigned int, void *);
int DG_GetLightMatrix2_8001A670(DG_OBJ *pObj, int idx);
void DG_WriteObjPacketUV_8001A6E4(DG_OBJ *pPrim, int idx);
void DG_8001A774(DG_OBJ *pObj, int idx);
void DG_WriteObjPacketRGB_8001A9B8(DG_OBJ *pDGObj, int idx);

int DG_8001AA50(DG_OBJ *pPrim, int idx, int flags)
{
    if (DG_GetLightMatrix2_8001A670(pPrim, idx) < 0)
    {
        return -1;
    }

    DG_WriteObjPacketUV_8001A6E4(pPrim, idx);

    if ((flags & 1) != 0)
    {
        DG_8001A774(pPrim, idx);
    }

    if ((flags & 2) != 0)
    {
        DG_WriteObjPacketRGB_8001A9B8(pPrim, idx);
    }

    return 0;
}

void DG_void_prim_buffer_8001AAD0(DG_OBJ *pObj, int idx)
{
    POLY_GT4 **ppPack;

    ppPack = &pObj->packs[idx];
    if (*ppPack)
    {
        System_void_allocation_80016078(idx, ppPack);
        *ppPack = 0;
    }
}

int sub_8001AB14(DG_OBJS *pObjs, int idx)
{

    int flag = pObjs->flag;
    int n_models = pObjs->n_models;

    DG_OBJ *pObj = pObjs->objs;
    while (n_models > 0)
    {
        if (!pObj->packs[idx])
        {
            if (DG_8001AA50(pObj, idx, flag) < 0)
            {
                return -1;
            }
        }
        pObj++;
        n_models--;
    }
    return 0;
}

void DG_void_all_prim_buffers_8001ABA8(DG_OBJS *pObjs, int idx)
{
    int n_models;
    DG_OBJ *pObj;

    n_models = pObjs->n_models;
    for (pObj = pObjs->objs; n_models > 0; ++pObj)
    {
        DG_void_prim_buffer_8001AAD0(pObj, idx);
        --n_models;
    }
}

void sub_8001AC00()
{
}