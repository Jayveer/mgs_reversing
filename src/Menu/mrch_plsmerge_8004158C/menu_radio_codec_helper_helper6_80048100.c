#include "linker.h"
#include "Menu/menuman.h"

extern menu_chara_struct *dword_800ABB38;
menu_chara_struct        *SECTION(".sbss") dword_800ABB38;

void menu_radio_codec_helper__helper6_80048100(void)
{
    sub_80047CB4(dword_800ABB38);
}