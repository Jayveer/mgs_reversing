#include "linker.h"
#include <SYS/TYPES.H>
#include <LIBGTE.H>
#include <LIBGPU.H>

const char SECTION(".rdata") aBullet[] = "bullet"; // 80012F9C
const char SECTION(".rdata") aBulletC[] = "bullet.c";
const char SECTION(".rdata") aEffect[] = "effect";
const char SECTION(".rdata") aChafgrndC[] = "chafgrnd.c";
const char SECTION(".rdata") aGoggles_0[] = "goggles";
const char SECTION(".rdata") aGoggleC[] = "goggle.c";
const char SECTION(".rdata") aGglmngC[] = "gglmng.c";
const char SECTION(".rdata") a02d[] = "%02d";
const char SECTION(".rdata") aLd[] = "%ld\n";
const char SECTION(".rdata") aScan[] = "SCAN";
const char SECTION(".rdata") aModeB[] = "MODE - B";
const char SECTION(".rdata") aModeA[] = "MODE - A";
const char SECTION(".rdata") aGglsightC[] = "gglsight.c";
const char SECTION(".rdata") aScnMaskC[] = "scn_mask.c";
const char SECTION(".rdata") aGoggles_1[] = "goggles";
const char SECTION(".rdata") aGoggleirC[] = "goggleir.c";
const char SECTION(".rdata") aDemothrdC[] = "demothrd.c";
const char SECTION(".rdata") aDemoFileS[] = "Demo file = \"%s\"\n";
const char SECTION(".rdata") aSNotFound[] = "\"%s\" not found\n";
const char SECTION(".rdata") aErrorInitializ[] = "Error:Initialize demo\n";
const char SECTION(".rdata") aPlaydemosound[] = "PlayDemoSound\n";
const char SECTION(".rdata") aCacheBufferCle[] = "Cache Buffer Cleared\n";
const char SECTION(".rdata") aCacheReadEnabl[] = "Cache Read Enable\n";
const char SECTION(".rdata") aNoloadModelSta[] = "Noload model ( Stage )\n";
const char SECTION(".rdata") aNoloadModelSce[] = "Noload model ( Scene = No.%d )\n";
const char SECTION(".rdata") aErrorInitContr[] = "Error init control ( Scene = No.%d )\n";
const char SECTION(".rdata") a16dO4a[] = "16d_o4a";
const char SECTION(".rdata") a16dO5a[] = "16d_o5a";
const char SECTION(".rdata") a16dO6a[] = "16d_o6a";
const char SECTION(".rdata") a16dO7a[] = "16d_o7a";
const char SECTION(".rdata") a16dO8a[] = "16d_o8a";
const char SECTION(".rdata") a16dO9a[] = "16d_o9a";
const char SECTION(".rdata") a16dO10a[] = "16d_o10a";
const char SECTION(".rdata") a16dO4b[] = "16d_o4b";
const char SECTION(".rdata") a16dO5b[] = "16d_o5b";
const char SECTION(".rdata") a16dO6b[] = "16d_o6b";
const char SECTION(".rdata") a16dO7b[] = "16d_o7b";
const char SECTION(".rdata") a16dO8b[] = "16d_o8b";
const char SECTION(".rdata") a16dO9b[] = "16d_o9b";
const char SECTION(".rdata") a16dO10b[] = "16d_o10b";
const char SECTION(".rdata") a16dO4c[] = "16d_o4c";
const char SECTION(".rdata") a16dO5c[] = "16d_o5c";
const char SECTION(".rdata") a16dO6c[] = "16d_o6c";
const char SECTION(".rdata") a16dO7c[] = "16d_o7c";
const char SECTION(".rdata") a16dO8c[] = "16d_o8c";
const char SECTION(".rdata") a16dO9c[] = "16d_o9c";
const char SECTION(".rdata") a16dO10c[] = "16d_o10c";
const char SECTION(".rdata") a02aR8[] = "02a_r8";
const char SECTION(".rdata") aMgrexw[] = "mgrexw";
const char SECTION(".rdata") aMgrexll[] = "mgrexll";
const char SECTION(".rdata") aMgrexrl[] = "mgrexrl";
const char SECTION(".rdata") aPitT[] = "pit_t";
const char SECTION(".rdata") aPitU[] = "pit_u";
const char SECTION(".rdata") aPitLiq[] = "pit_liq";
const char SECTION(".rdata") aRadarF1[] = "radar_f1";
const char SECTION(".rdata") aRadarF2[] = "radar_f2";
const char SECTION(".rdata") aRadarF3[] = "radar_f3";
const char SECTION(".rdata") aLHatch1[] = "l_hatch1";
const char SECTION(".rdata") aLHatch2[] = "l_hatch2";
const char SECTION(".rdata") aLHatch3[] = "l_hatch3";
const char SECTION(".rdata") aLHatch4[] = "l_hatch4";
const char SECTION(".rdata") aRHatch1[] = "r_hatch1";
const char SECTION(".rdata") aRHatch2[] = "r_hatch2";
const char SECTION(".rdata") aRHatch3[] = "r_hatch3";
const char SECTION(".rdata") aRHatch4[] = "r_hatch4";
const char SECTION(".rdata") aM1e1[] = "m1e1";
const char SECTION(".rdata") aM1e1demo[] = "m1e1demo";
const char SECTION(".rdata") aM1e1cl1[] = "m1e1cl1";
const char SECTION(".rdata") aM1e1cl2[] = "m1e1cl2";
const char SECTION(".rdata") aM1e1cl3[] = "m1e1cl3";
const char SECTION(".rdata") aM1e1cr1[] = "m1e1cr1";
const char SECTION(".rdata") aM1e1cr2[] = "m1e1cr2";
const char SECTION(".rdata") aM1e1cr3[] = "m1e1cr3";
const char SECTION(".rdata") aHind[] = "hind";
const char SECTION(".rdata") aHinddemo[] = "hinddemo";
const char SECTION(".rdata") aNull[] = "null";
const char SECTION(".rdata") aNoloadModelNul[] = "Noload model ( null.kmd )\n";
const char SECTION(".rdata") aErrorInitContr_0[] = "Error init control ( null.kmd )\n";
const int  SECTION(".rdata") jpt_80013334[] = {
     0x8007AED4, 0x8007AEFC, 0x8007AF04, 0x8007AF04, 0x8007AFB8, 0x8007AFE0, 0x8007B014, 0x8007B048, 0x8007B050,
     0x8007B0A4, 0x8007B10C, 0x8007B114, 0x8007B170, 0x8007B178, 0x8007B2B4, 0x8007B340, 0x8007B3C4, 0x8007B3CC,
     0x8007B498, 0x8007B498, 0x8007B498, 0x8007B66C, 0x8007B674, 0x8007B7A8, 0x8007B89C, 0x8007B928, 0x8007B950,
     0x8007B994, 0x8007BA64, 0x8007B498, 0x8007BAA4, 0x8007BB10, 0x8007BBDC, 0x8007BC24, 0x8007BC68, 0x8007BCF8,
     0x8007BD1C, 0x8007BD40, 0x8007BDF0, 0x8007BDF8, 0x8007BE58, 0x8007BF3C, 0x8007C030, 0x8007C09C, 0x8007C0E8,
     0x8007C134, 0x8007C1D8, 0x8007C200, 0x8007C224, 0x8007C22C, 0x8007C254, 0x8007C27C, 0x8007C348, 0x8007C8D8,
     0x8007C3AC, 0x8007C430, 0x8007C438, 0x8007C4DC, 0x8007C520, 0x8007C58C, 0x8007C61C, 0x8007C6A8, 0x8007C7DC,
     0x8007C8D8, 0x8007C90C, 0x8007C930, 0x8007C948, 0x8007CA4C, 0x8007CBB8, 0x8007CBEC, 0x8007CC18, 0x8007CC44,
     0x8007CC6C, 0x8007CCF4};
const int SECTION(".rdata") dword_8001345C[] = {
    0x12700,    0xCFE0105,  0xFF010500, 0x64000A,   0xF1F10864, 0x10002F1, 0x5000C0D, 0x10AFF01, 0x82C012C,  0x2E2E2E2,
    0xF0D0100,  0x24A00,    0x1200007,  0x5000CFE,  0x2FF01,    0xC0D01,   0x8FF010A, 0x2FAFAFA, 0xF0D0100,  0xCFE01,
    0x2C010A04, 0xFF012C01, 0xD010002,  0xA0A000C,  0x46004600, 0x2FF01,   0xC0D01,   0xAFF010A, 0x50005000, 0xF0F0F008,
    0xD010002,  0xF,        0x12C00,    0xCFE0105,  0xFF010500, 0xD010002, 0x105000C, 0x5000AFF, 0x20500,    0xC0D01,
    0x8FF010F,  0xAF0F0F0,  0x5000500,  0xD010002,  0xF,        0x34900,   0x1E0009,  0xCFE0138, 0x20400,    0xC0D01,
    0xECEC0804, 0x10002EC,  0xFE010F0D, 0xFC18FC0A, 0x4000C18,  0xD010002, 0x804000C, 0x2ECECEC, 0xF0D0100,  0xFB0AFE01,
    0xC50FB50,  0x20400,    0xC0D01,    0xECEC0804, 0x10002EC,  0xF0D};
const char SECTION(".rdata") aSoundLaunchArg[] = "SOUND_LAUNCH(argc:%d)\n";
const char SECTION(".rdata") aArgDS[] = "ARG%d:[%s]\n";
const char SECTION(".rdata") aStartTaskSdmai[] = "Start Task:SdMain\n";
const char SECTION(".rdata") aBgmTerminate[] = "***BGM Terminate***\n";
const int  SECTION(".rdata") jpt_800135B4[] = {0x80081B40, 0x80081B78, 0x80081B78, 0x80081B78,
                                               0x80081B78, 0x80081BA0, 0x80081B88};
const char SECTION(".rdata") aStartTaskSdint[] = "Start Task:SdInt\n";
const char SECTION(".rdata") aBlankDataAddrX[] = "blank_data_addr=%x\n";
const char SECTION(".rdata") aSpuWaveStartPt[] = "spu_wave_start_ptr=%x\n";
const char SECTION(".rdata") aSpuBgmStartPtr[] = "spu_bgm_start_ptr_r=%x\n";
const char SECTION(".rdata") aSpuBufferOver[] = "SPU Buffer Over!!\n";
const char SECTION(".rdata") aSpuBgmStartPtr_0[] = "spu_bgm_start_ptr_l=%x\n";
const char SECTION(".rdata") aSpuReverbBuffe[] = "SPU Reverb Buffer Over!!\n";
const char SECTION(".rdata") aSoundErrorSpuO[] = "SOUND ERROR:SPU OFF ENV ON(STR_TRACK_R=%x)\n";
const char SECTION(".rdata") aSoundErrorSpuO_0[] = "SOUND ERROR:SPU OFF ENV ON(STR_TRACK_L=%x)\n";
const char SECTION(".rdata") aSngDataX[] = "sng_data %X\n";
const char SECTION(".rdata") aWaveHeaderX[] = "wave_header %X\n";
const char SECTION(".rdata") aVoiceTblX[] = "voice_tbl %X\n";
const char SECTION(".rdata") aSeHeaderX[] = "se_header %X\n";
const char SECTION(".rdata") aSeDataX[] = "se_data %X\n";
const char SECTION(".rdata") aCdloadBufXXX[] = "CDLOAD_BUF %X %X %X\n";
const char SECTION(".rdata") aStrHeaderX[] = "str_header %X\n";
const char SECTION(".rdata") aCanceledStrFad[] = "Canceled STR FadeOut(%x:%x:%x)";
const char SECTION(".rdata") aStreamFilePosE[] = "Stream:File Pos Error\n";
const char SECTION(".rdata") aStartstreamXVo[] = "StartStream(%x:vol=%x)\n";
const int  SECTION(".rdata") jpt_8001378C[] = {0x8008272C, 0x8008272C, 0x8008267C, 0x8008268C, 0x800826CC};
const char SECTION(".rdata") aSoundStreaming[] = "\nSOUND STREAMING ERROR:NO LAST LEFT DATA\n";
const char SECTION(".rdata") aStrUnplaySizeX[] = "str_unplay_size=%x\n";
const char SECTION(".rdata") asc_800137E0[] = "*";
const int  SECTION(".rdata") jpt_800137E4[] = {0x80082828, 0x80082A28, 0x80082BC8, 0x80082D20, 0x800832BC, 0x80083358};
const char SECTION(".rdata") aErrorSeFileAlr[] = "ERROR:SE File Already Opened.\n";
const char SECTION(".rdata") aLoadsefileFile[] = "LoadSeFile:File Open Error(%x)\n";
const char SECTION(".rdata") aErrorWaveFileA[] = "ERROR:Wave File Already Opened.\n";
const char SECTION(".rdata") aLoadwavefileFi[] = "LoadWaveFile:File Open Error(%x)\n";
const char SECTION(".rdata") aSupOffsetXSize[] = "SUP OFFSET=%x:SIZE=%x\n";
const char SECTION(".rdata") aSrcXDstX[] = "    SRC=%x:DST=%x\n";
const char SECTION(".rdata") aBinOffsetX[] = "BIN OFFSET=%x\n";
const char SECTION(".rdata") aSpuOffsetXSize[] = "SPU OFFSET=%x:SIZE=%x\n";
const char SECTION(".rdata") aCompleteLoadSe[] = "Complete Load Se:%x\n";
const char SECTION(".rdata") aSdSngdataloadi[] = "SD_SngDataLoadInit\n";
const char SECTION(".rdata") aLoadinitD[] = "LoadInit %d\n";
const char SECTION(".rdata") asc_80013914[] = "$";
const char SECTION(".rdata") aSdWavLoadBufOv[] = "!!! SD WAV LOAD BUF OVER !!!\n";
const char SECTION(".rdata") aUnloadD[] = "unload %d\n";
const char SECTION(".rdata") aSngcodeX[] = "SngCode=%x\n";
const char SECTION(".rdata") aSongpauseon[] = "SongPauseOn\n";
const char SECTION(".rdata") aSongpauseoff[] = "SongPauseOff\n";
const char SECTION(".rdata") aSongfadein[] = "SongFadein\n";
const char SECTION(".rdata") aSongfadeoutPau[] = "SongFadeout&Pause\n";
const char SECTION(".rdata") aSongfadeoutSto[] = "SongFadeout&Stop\n";
const char SECTION(".rdata") aSongkaihimode[] = "SongKaihiMode\n";
const char SECTION(".rdata") aSongsyukanmode[] = "SongSyukanMode On\n";
const char SECTION(".rdata") aSongsyukanmode_0[] = "SongSyukanMode Off\n";
const char SECTION(".rdata") aSongstop[] = "SongStop\n";
const char SECTION(".rdata") aErrorSngPlayCo[] = "ERROR:SNG PLAY CODE(%x/%x)\n";
const char SECTION(".rdata") aSngStatusX[] = "sng_status=%x\n";
const char SECTION(".rdata") aSamesonghasalr[] = "SameSongHasAlreadyPlayed\n";
const char SECTION(".rdata") aSoundWorkIsBro[] = "*** SOUND WORK IS BROKEN !!! ***\n";
const char SECTION(".rdata") aSongEndXX[] = "*** song_end:%x -> %x        ***\n";
const char SECTION(".rdata") aSngFadeoutStar[] = "SNG FADEOUT START(status=%x)\n";
const char SECTION(".rdata") aSngFadeoutCanc[] = "SNG FADEOUT CANCELED(status=%x)\n";
const char SECTION(".rdata") aLoadsngdataFil[] = "LoadSngData:File Open Error(%x)\n";
const char SECTION(".rdata") aCompletedloads[] = "CompletedLoadSong(%x)\n";
const char SECTION(".rdata") aXaSoundStart[] = "***XA Sound Start***\n";
const char SECTION(".rdata") aXaSoundStop[] = "***XA Sound Stop***\n";
const char SECTION(".rdata") aSdcodeX[] = "SdCode=%x\n";
const char SECTION(".rdata") aToomuchbgmsoun[] = "***TooMuchBGMSoundCode(%x)***\n";
const char SECTION(".rdata") aSdsetLastStrea[] = "SdSet:Last Stream Not Terminated.(status=%x)\n";
const char SECTION(".rdata") aSdsetSameStrea[] = "SdSet:Same Stream is Already Played.(code=%x)\n";
const char SECTION(".rdata") aStrFoS[] = "*** STR FO(S) ***\n";
const char SECTION(".rdata") aStrFoM[] = "*** STR FO(M) ***\n";
const char SECTION(".rdata") aStrFoL[] = "*** STR FO(L) ***\n";
const char SECTION(".rdata") aStrFoLl[] = "*** STR FO(LL) ***\n";
const char SECTION(".rdata") aStrFiMAtNextSt[] = "*** STR FI(M) at Next STR ***\n";
const char SECTION(".rdata") aStrFiMStart[] = "*** STR FI(M) Start ***\n";
const char SECTION(".rdata") aErrStrFiM[] = "*** ERR:STR FI(M) ***\n";
const char SECTION(".rdata") aStrFiLAtNextSt[] = "*** STR FI(L) at Next STR***\n";
const char SECTION(".rdata") aStrFiLStart[] = "*** STR FI(L) Start ***\n";
const char SECTION(".rdata") aErrStrFiL[] = "*** ERR:STR FI(L) ***\n";
const char SECTION(".rdata") aStrFoSStop[] = "*** STR FO(S)+STOP ***\n";
const char SECTION(".rdata") aStrFoMStop[] = "*** STR FO(M)+STOP ***\n";
const char SECTION(".rdata") aStrFoLStop[] = "*** STR FO(L)+STOP ***\n";
const char SECTION(".rdata") aStrFoLlStop[] = "*** STR FO(LL)+STOP ***\n";
const int  SECTION(".rdata") dword_80013D10[] = {0x3F3F3F,   0xDDA1AAA5, 0xDDA1D0A5, 0xEDA5D5A5, 0xDDA1,
                                                 0xD7A5B3A5, 0xEDA5,     0xF3CCBDCD, 0xE1CEBFCC, 0,
                                                 0xECA5D6A5, 0xAFA5DDA1, 0xA4A5DDA5, 0xC8A5F3A5, 0};
const int  SECTION(".rdata") dword_80013D4C[] = {0xB9A5B7A5, 0xE0A5C6A5, 0xDDA1B3A5, 0xEBA5, 0xDDA1C7A5,
                                                 0xD0A5BFA5, 0xA8A5B9A5, 0xDDA1E9A5, 0};
const int  SECTION(".rdata") dword_80013D70[] = {0xE1CEBFCC, 0xB9A5D0A5, 0xE9A5A8A5, 0xDDA1, 0xC8A5B9A5, 0xFEBBA2A5,
                                                 0xC9A5A2A5, 0xB9A5ECA5, 0xE9A5A8A5, 0xDDA1, 0xDDA1EDA5, 0xFEBBC9A5,
                                                 0xC9A5A2A5, 0xB9A5ECA5, 0xE9A5A8A5, 0xDDA1, 0x53424C54, 0};
const char SECTION(".rdata") aTlbl[] = "TLBL";
const int  SECTION(".rdata") dword_80013DC0[] = {0x646F4D, 0xF4C9B0B3, 0xEAA4E4B3, 0xDFA4FEB9, 0};
const char SECTION(".rdata") aTaskStartDX[] = "TASK START: %d %X\n";
const char SECTION(".rdata") aAssertionFaled[] = "assertion faled : %s line %d : Task %d\n";
const char SECTION(".rdata") aMtsNewC[] = "mts_new.c";
const char SECTION(".rdata") aTaskStartBody[] = "task_start_body";
const char SECTION(".rdata") asc_80013E2C[] = "\n";
const char SECTION(".rdata") aGetNewVblContr[] = "get_new_vbl_control_table";
const char SECTION(".rdata") aWaitvblD[] = "waitvbl %d";
const char SECTION(".rdata") aTaskCreateXX[] = "task_create %x %x";
const char SECTION(".rdata") aSendDstD[] = "send dst %d";
const char SECTION(".rdata") aSendStateDeadD[] = "send state DEAD %d";
const char SECTION(".rdata") aIsendDstD[] = "isend dst %d";
const char SECTION(".rdata") aIsendStateDead[] = "isend state DEAD %d";
const char SECTION(".rdata") aRcvSrcD[] = "rcv src %d";
const char SECTION(".rdata") aRcvStateDeadD[] = "rcv state DEAD %d";
const char SECTION(".rdata") aRcvCallerD[] = "rcv caller %d";
const char SECTION(".rdata") aRcvSpDStateD[] = "rcv sp %d state %d";
const char SECTION(".rdata") aRcvSpMessageX[] = "rcv sp message %X";
const char SECTION(".rdata") aSendTD[] = "send t %d";
const char SECTION(".rdata") aRcvSpDMessageX[] = "rcv sp %d message %x";
const char SECTION(".rdata") aRecvSrcD[] = "RECV ?? SRC %d";
const char SECTION(".rdata") aWupDeadD[] = "wup DEAD %d";
const char SECTION(".rdata") aMultiTaskSched[] = "Multi Task Scheduler for PSX ver2.02 %s %s\n";
const char SECTION(".rdata") aJul111998[] = "Jul 11 1998";
const char SECTION(".rdata") a221633[] = "22:16:33";
const char SECTION(".rdata") aProgramBottomX[] = "PROGRAM BOTTOM %X\n";
const char SECTION(".rdata") aBootTasknrD[] = "boot tasknr %d";
const char SECTION(".rdata") aSystemClientD[] = "system client %d";
const char SECTION(".rdata") aTaskDStart[] = "TASK %d START:";
const char SECTION(".rdata") aTaskDAlreadyEx[] = "TASK %d already exist\n";
const char SECTION(".rdata") aSystemExitDead[] = "system exit DEAD %d";
const char SECTION(".rdata") aSystemExitCall[] = "system exit caller %d";
const char SECTION(".rdata") aTaskExit[] = "TASK EXIT";
const char SECTION(".rdata") aSystemWrongCod[] = "system wrong code %d";
const char SECTION(".rdata") aMtsStaTskServe[] = "mts_sta_tsk server %d";
const char SECTION(".rdata") aMtsExtTsk[] = "mts_ext_tsk";
const char SECTION(".rdata") aPending[] = "Pending";
const char SECTION(".rdata") aWaitvbl[] = "WaitVBL";
const char SECTION(".rdata") aSleeping[] = "Sleeping";
const char SECTION(".rdata") aReady[] = "Ready";
const char SECTION(".rdata") aReceiving[] = "Receiving";
const char SECTION(".rdata") aSending[] = "Sending";
const char SECTION(".rdata") aProcessList[] = "\nProcess list\n";
const char SECTION(".rdata") aC[] = "%c";
const char SECTION(".rdata") aTask02dSp04dUs[] = "Task %02d SP %04d USE %04d/%04d";
const char SECTION(".rdata") aTask02dSpUse[] = " Task %02d SP ---- USE ----/----";
const int  SECTION(".rdata") dword_800140F0 = 0x732520;
const char SECTION(".rdata") aRunning[] = "Running";
const char SECTION(".rdata") aD_0[] = " %d\n";
const char SECTION(".rdata") aTaskState08x[] = "TASK STATE = %08X\n";
const char SECTION(".rdata") aVblWaitCue[] = "VBL wait cue";
const char SECTION(".rdata") a02dD[] = " : %02d (%d)";
const char SECTION(".rdata") aTickCountD[] = "Tick count %d\n\n";
const char SECTION(".rdata") aCdinitInitFail[] = "CdInit: Init failed\n";
const int  SECTION(".rdata") dword_crap9[] = {0, 0};
const char SECTION(".rdata") aNone_0[] = "none";
const int  SECTION(".rdata") dword_crap10[] = {0, 0};
const char SECTION(".rdata") aCdlreads[] = "CdlReadS";
const char SECTION(".rdata") aCdlseekp[] = "CdlSeekP";
const char SECTION(".rdata") aCdlseekl[] = "CdlSeekL";
const char SECTION(".rdata") aCdlgettd[] = "CdlGetTD";
const char SECTION(".rdata") aCdlgettn[] = "CdlGetTN";
const char SECTION(".rdata") aCdlgetlocp[] = "CdlGetlocP";
const char SECTION(".rdata") aCdlgetlocl[] = "CdlGetlocL";
const int  SECTION(".rdata") dword_800141CC[] = {0x3F,       0x536C6443, 0x6F6D7465, 0x6564,
                                                 0x536C6443, 0x69667465, 0x7265746C, 0};
const char SECTION(".rdata") aCdldemute[] = "CdlDemute";
const char SECTION(".rdata") aCdlmute[] = "CdlMute";
const char SECTION(".rdata") aCdlreset[] = "CdlReset";
const char SECTION(".rdata") aCdlpause[] = "CdlPause";
const char SECTION(".rdata") aCdlstop[] = "CdlStop";
const char SECTION(".rdata") aCdlstandby[] = "CdlStandby";
const char SECTION(".rdata") aCdlreadn[] = "CdlReadN";
const char SECTION(".rdata") aCdlbackward[] = "CdlBackward";
const char SECTION(".rdata") aCdlforward[] = "CdlForward";
const char SECTION(".rdata") aCdlplay[] = "CdlPlay";
const char SECTION(".rdata") aCdlsetloc[] = "CdlSetloc";
const char SECTION(".rdata") aCdlnop[] = "CdlNop";
const char SECTION(".rdata") aCdlsync[] = "CdlSync";
const char SECTION(".rdata") aDiskerror_0[] = "DiskError";
const char SECTION(".rdata") aDataend[] = "DataEnd";
const char SECTION(".rdata") aAcknowledge[] = "Acknowledge";
const char SECTION(".rdata") aComplete_0[] = "Complete";
const char SECTION(".rdata") aDataready[] = "DataReady";
const char SECTION(".rdata") aNointr[] = "NoIntr";
const char SECTION(".rdata") aCdTimeout[] = "CD timeout: ";
const char SECTION(".rdata") aSSSyncSReadyS[] = "%s:(%s) Sync=%s, Ready=%s\n";
const char SECTION(".rdata") aDiskerror[] = "DiskError: ";
const char SECTION(".rdata") aComSCode02x02x[] = "com=%s,code=(%02x:%02x)\n";
const char SECTION(".rdata") aCdromUnknownIn[] = "CDROM: unknown intr";
const char SECTION(".rdata") aD_1[] = "(%d)\n";
const int  SECTION(".rdata") dword_crap11 = 0;
const int  SECTION(".rdata") jpt_80014328[] = {0x8008D290, 0x8008D244, 0x8008D144, 0x8008D310, 0x8008D390};
const char SECTION(".rdata") aCdSync[] = "CD_sync";
const char SECTION(".rdata") aCdReady[] = "CD_ready";
const char SECTION(".rdata") aS[] = "%s...\n";
const char SECTION(".rdata") aSNoParam[] = "%s: no param\n";
const char SECTION(".rdata") aCdCw[] = "CD_cw";
const char SECTION(".rdata") aIdBiosCV186199[] = "$Id: bios.c,v 1.86 1997/03/28 07:42:42 makoto Exp yos $";
const char SECTION(".rdata") aCdInit[] = "CD_init:";
const char SECTION(".rdata") aAddr08x[] = "addr=%08x\n";
const char SECTION(".rdata") aCdDatasync[] = "CD_datasync";
const int  SECTION(".rdata") dword_crap12[] = {0, 0, 0};
const char SECTION(".rdata") a0123456789abcd[] = "0123456789ABCDEF";
const char SECTION(".rdata") a0123456789abcd_0[] = "0123456789abcdef";
const int  SECTION(".rdata") jpt_80014400[] = {
     0x8008EB50, 0x8008F000, 0x8008F000, 0x8008F000, 0x8008F000, 0x8008F000, 0x8008F000, 0x8008F000,
     0x8008F000, 0x8008F000, 0x8008F000, 0x8008F000, 0x8008EE08, 0x8008F000, 0x8008F000, 0x8008F000,
     0x8008F000, 0x8008F000, 0x8008F000, 0x8008F000, 0x8008F000, 0x8008F000, 0x8008F000, 0x8008EF20,
     0x8008EB7C, 0x8008F000, 0x8008F000, 0x8008F000, 0x8008EB38, 0x8008EB7C, 0x8008F000, 0x8008F000,
     0x8008EB44, 0x8008F000, 0x8008EFCC, 0x8008ECF4, 0x8008EDF4, 0x8008F000, 0x8008F000, 0x8008EF40,
     0x8008F000, 0x8008EBD4, 0x8008F000, 0x8008F000, 0x8008EE14, 0};
const char SECTION(".rdata") aNull_0[] = "<NULL>";
const int  SECTION(".rdata") dword_crap13[] = {0, 0};
const char SECTION(".rdata") aIdSysCV1140199[] = "$Id: sys.c,v 1.140 1998/01/12 07:52:27 noda Exp yos $";
const char SECTION(".rdata") aResetgraphJtb0[] = "ResetGraph:jtb=%08x,env=%08x\n";
const char SECTION(".rdata") aResetgraphD[] = "ResetGraph(%d)...\n";
const char SECTION(".rdata") aSetgraphdebugL[] = "SetGraphDebug:level:%d,type:%d reverse:%d\n";
const char SECTION(".rdata") aSetgrapqueD[] = "SetGrapQue(%d)...\n";
const char SECTION(".rdata") aDrawsynccallba[] = "DrawSyncCallback(%08x)...\n";
const char SECTION(".rdata") aSetdispmaskD[] = "SetDispMask(%d)...\n";
const char SECTION(".rdata") aDrawsyncD[] = "DrawSync(%d)...\n";
const char SECTION(".rdata") aSBadRect[] = "%s:bad RECT";
const char SECTION(".rdata") aDDDD[] = "(%d,%d)-(%d,%d)\n";
const char SECTION(".rdata") aS_0[] = "%s:";
const char SECTION(".rdata") aClearimage[] = "ClearImage";
const char SECTION(".rdata") aClearimage2[] = "ClearImage2";
const char SECTION(".rdata") aLoadimage[] = "LoadImage";
const char SECTION(".rdata") aStoreimage[] = "StoreImage";
const char SECTION(".rdata") aMoveimage[] = "MoveImage";
const char SECTION(".rdata") aClearotag08xD[] = "ClearOTag(%08x,%d)...\n";
const char SECTION(".rdata") aClearotagr08xD[] = "ClearOTagR(%08x,%d)...\n";
const char SECTION(".rdata") aDrawotag08x[] = "DrawOTag(%08x)...\n";
const char SECTION(".rdata") aPutdrawenv08x[] = "PutDrawEnv(%08x)...\n";
const char SECTION(".rdata") aDrawotagenv08x[] = "DrawOTagEnv(%08x,&08x)...\n";
const char SECTION(".rdata") aPutdispenv08x[] = "PutDispEnv(%08x)...\n";
const char SECTION(".rdata") aGpuTimeoutQueD[] = "GPU timeout:que=%d,stat=%08x,chcr=%08x,madr=%08x\n";
const char SECTION(".rdata") aLoadimage2[] = "LoadImage2";
const char SECTION(".rdata") aSpuTOS[] = "SPU:T/O [%s]\n";
const char SECTION(".rdata") aWaitReset[] = "wait (reset)";
const char SECTION(".rdata") aWaitWrdyHL[] = "wait (wrdy H -> L)";
const char SECTION(".rdata") aWaitDmafClearW[] = "wait (dmaf clear/W)";
const int  SECTION(".rdata") dword_crap14[] = {0, 0};
const char SECTION(".rdata") aSpuTOS_0[] = "SPU:T/O [%s]\n";
const char SECTION(".rdata") aWaitIrqOn[] = "wait (IRQ/ON)";
const char SECTION(".rdata") aWaitIrqOff[] = "wait (IRQ/OFF)";
const int  SECTION(".rdata") jpt_80014768[] = {0x800970C8, 0x80097090, 0x80097098, 0x800970A0,
                                               0x800970A8, 0x800970B0, 0x800970B8, 0x800970C0};
const int  SECTION(".rdata") jpt_80014788[] = {0x80097188, 0x80097150, 0x80097158, 0x80097160,
                                               0x80097168, 0x80097170, 0x80097178, 0x80097180};
const int  SECTION(".rdata") jpt_800147A8[] = {0x80097654, 0x8009765C, 0x80097664, 0x8009766C,
                                               0x80097674, 0x8009767C, 0x80097684, 0};
const int  SECTION(".rdata") jpt_800147C8[] = {0x80097734, 0x8009773C, 0x80097744, 0x8009774C,
                                               0x80097754, 0x8009775C, 0x80097764, 0};
const char SECTION(".rdata") aVsyncTimeout[] = "VSync: timeout\n";
const char SECTION(".rdata") aIdIntrCV175199[] = "$Id: intr.c,v 1.75 1997/02/07 09:00:36 makoto Exp $";
const char SECTION(".rdata") aUnexpectedInte[] = "unexpected interrupt(%04x)\n";
const char SECTION(".rdata") aIntrTimeout04x[] = "intr timeout(%04x:%04x)\n";
const int  SECTION(".rdata") dword_crap15 = 0;
const char SECTION(".rdata") aDmaBusErrorCod[] = "DMA bus error: code=%08x\n";
const char SECTION(".rdata") aMadrD08x[] = "MADR[%d]=%08x\n";
const int  SECTION(".rdata") dword_crap16 = 0;
const int  SECTION(".rdata") jpt_80014898[] = {0x8009A4FC, 0x8009A508, 0x8009A514, 0x8009A520, 0x8009A52C, 0, 0, 0};