#include "SD/sd.h"

extern int sng_status_800BF158;
extern int sng_fout_term_800C0518;
extern int sng_fade_time_800C0430[14];
extern int sd_KaihiMode_800BF05C;

#pragma INCLUDE_ASM("asm/SD/IntSdMain_80084494.s")
#pragma INCLUDE_ASM("asm/SD/SD_SongFadeIn_80084CCC.s")

int SngFadeOutP_80084D60(unsigned int a1)
{
    int temp; // $a1
    int i; // $v1

    if ( sng_status_800BF158 && sng_fout_term_800C0518 != 0x1FFF )
    {
        switch (a1)
        {
            case 0x1FFFF06: temp = 1310; break;
            case 0x1FFFF07: temp = 655; break;
            case 0x1FFFF08: temp = 218; break;
            case 0x1FFFF09: temp = 131; break;
            //default: temp = 0; break; // we like UB
        }

        if ( !temp )
        {
            temp = 1;
        }

        for (i = 0; i < 13; i++)
        {
            if ( ((sng_fout_term_800C0518 >> i) & 1) == 0 )
            {
                sng_fade_time_800C0430[i] = temp;
            }
        }
        
        sd_KaihiMode_800BF05C = 0;
        return 0;
    }
    else
    {
        return -1;
    }
}

#pragma INCLUDE_ASM("asm/SD/SD_SongFadeoutAndStop_80084E48.s")
#pragma INCLUDE_ASM("asm/SD/SD_SongKaihiMode_80084F88.s")
#pragma INCLUDE_ASM("asm/SD/SD_80085020.s")
#pragma INCLUDE_ASM("asm/SD/SD_80085164.s")
#pragma INCLUDE_ASM("asm/SD/SD_80085480.s")
#pragma INCLUDE_ASM("asm/SD/SD_800854F0.s")
#pragma INCLUDE_ASM("asm/SD/SD_8008559C.s")
#pragma INCLUDE_ASM("asm/SD/sng_adrs_set_80085658.s")
#pragma INCLUDE_ASM("asm/SD/SD_8008576C.s")

void sng_track_init_800859B8(SOUND_W *pSoundW)
{
    pSoundW->field_4_ngc = 1;
    pSoundW->field_38_pvod = 127;
    pSoundW->field_44_vol = 127;
    pSoundW->field_48_pand = 2560;
    pSoundW->field_54_panf = 10;
    pSoundW->field_B4_tmpd = 1;
    pSoundW->field_98_rdmd = 0;
    pSoundW->field_5_ngo = 0;
    pSoundW->field_6_ngs = 0;
    pSoundW->field_7_ngg = 0;
    pSoundW->field_8_lp1_cnt = 0;
    pSoundW->field_9_lp2_cnt = 0;
    pSoundW->field_C_lp1_vol = 0;
    pSoundW->field_10_lp2_vol = 0;
    pSoundW->field_14_lp1_freq = 0;
    pSoundW->field_18_lp2_freq = 0;
    pSoundW->field_34_pvoc = 0;
    pSoundW->field_55 = 0;
    pSoundW->field_56_panmod = 0;
    pSoundW->field_6A_swsk = 0;
    pSoundW->field_68_swsc = 0;
    pSoundW->field_7C_vibd = 0;
    pSoundW->field_80_vibdm = 0;
    pSoundW->field_9E_tred = 0;
    pSoundW->field_A4_snos = 0;
    pSoundW->field_A8_ptps = 0;
    pSoundW->field_AC_dec_vol = 0;
    pSoundW->field_B0_tund = 0;
    pSoundW->field_B8_tmp = -1;
    pSoundW->field_C0_tmpc = 0;
}