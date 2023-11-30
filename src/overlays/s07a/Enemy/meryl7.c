#include "../../s00a/Enemy/enemy.h"
#include "chara/snake/shadow.h"
#include "libgcl/hash.h"
#include "Game/camera.h"

extern ENEMY_COMMAND EnemyCommand_800E0D98;
extern SVECTOR       ENEMY_TARGET_SIZE_800C35A4;
extern SVECTOR       ENEMY_TARGET_FORCE_800C35AC;
extern SVECTOR       ENEMY_ATTACK_SIZE_800C35B4;
extern SVECTOR       ENEMY_ATTACK_FORCE_800C35BC;
extern SVECTOR       ENEMY_TOUCH_SIZE_800C35C4;
extern SVECTOR       ENEMY_TOUCH_FORCE_800C35CC;
extern SVECTOR       COM_NO_POINT_800C35D4;
extern unsigned short COM_EYE_LENGTH_800E0D8C;

extern GM_Camera      GM_Camera_800B77E8;
extern int            GM_PlayerMap_800ABA0C;

extern void *NewGunLight_800D3AD4( MATRIX* mat, int **enable );

/*  Modified version of RootFlagCheck_800C3EE8
    (last two switch cases removed)

    ルート変更フラグチェック
    指定フラグが立てば次のルートへ変更
    ここではコマンダーに変更ルートをセットする
    変更後の各敵兵はポイントアクションの時にルート変更する
    ついでにフェイズアウト、イン等のメッセージ処理も行う。
    */
int s07a_meryl7_800D50F8( WatcherWork* work )
{
    int count;
    GV_MSG *msg;
    SVECTOR svec;
    CONTROL *ctrl;

    ctrl = &work->control;
    ctrl->field_56 = GV_ReceiveMessage_80016620( ctrl->field_30_scriptData, &work->control.field_5C_mesg );
    count = ctrl->field_56;
    msg = ctrl->field_5C_mesg;

    if ( count <= 0 ) return 0 ;

    for ( ; count > 0 ; --count, msg++ )
    {
        switch ( msg->message[0] )
        {
        case 0x430F:
            work->field_B7E = msg->message[1];
            svec.vx = msg->message[2];
            svec.vy = msg->message[3];
            svec.vz = msg->message[4];

            if ( svec.vy < 0x7530 )
            {
                work->field_B7C = HZD_GetAddress_8005C6C4( work->control.field_2C_map->field_8_hzd, &svec, -1 );
            }
            else
            {
                work->field_B7C = -1;
            }
            return 1;
        case 0xF1BD:
            work->hom->flag = 0 ;
            work->alert_level = 0 ;
            GM_ConfigControlAttribute_8002623C( &(work->control), 0 ) ;
            work->visible = 0 ;
            work->target->class = TARGET_AVAIL;

            work->faseout = 1 ;
            work->act_status = EN_FASEOUT ;
            break;
        case 0x1DC4:
            if ( EnemyCommand_800E0D98.field_0xC8[ work->field_B78 ].field_04 == 2 )
            {
                work->visible = 1;
            }
            GM_ConfigControlAttribute_8002623C( ctrl, 13 );
            work->faseout = 0;
            work->act_status = 0;
            break;
        }
    }
    return 0;
}

// Identical to s00a_watcher_800C409C
void s07a_meryl7_800D528C( WatcherWork* work )
{
    if ( GM_GameStatus_800AB3CC & STATE_ENEMY_OFF )
    {
        if ( work->faseout == 0 )
        {
            work->hom->flag = 0 ;
            work->alert_level = 0 ;
            GM_ConfigControlAttribute_8002623C( &(work->control), 0 ) ;
            work->visible = 0 ;
            work->target->class = TARGET_AVAIL;

            work->faseout = 1 ;
            work->act_status = EN_FASEOUT ;
        }
    }
}

// Identical to s00a_watcher_800C410C
void s07a_meryl7_800D52FC( WatcherWork* work )
{
    s07a_meryl7_800D50F8( work );
    s07a_meryl7_800D528C( work );
}

// Identical to s00a_watcher_800C4138
void s07a_meryl7_800D5328( DG_OBJS* objs, DG_DEF* def )
{
    int i;
    DG_OBJ *obj;
    DG_FreeObjsPacket_8001ABA8( objs, 0 );
    DG_FreeObjsPacket_8001ABA8( objs, 1 );

    objs->def = def;
    obj = objs->objs;
    for ( i = 0 ; i < 16 ; i++ )
    {
        obj->model   = &def->model[ i ];
        obj->n_packs =  def->model[ i ].numFaces_4;
        obj++;
    }
}

// Based on s00a_watcher_800C41B4, one "if" missing
void s07a_meryl7_800D53A4( WatcherWork *work )
{
    if ( work->visible )
    {
        if ( work->field_B7B == 1 )
        {
            if ( GM_GameStatus_800AB3CC & 0x50 || GM_Camera_800B77E8.field_22 )
            {
                if ( work->field_180 != work->field_B7B )
                {
                    work->field_180 = work->field_B7B;
                    s07a_meryl7_800D5328( work->body.objs, work->def );
                }
            }
            else if ( work->field_180 )
            {
                work->field_180 = 0;
                s07a_meryl7_800D5328( work->body.objs, work->kmd );
            }
        }
        DG_VisibleObjs( work->body.objs );
        DG_VisibleObjs( work->field_7A4.objs );
        work->field_AF4[0] = 1;
        work->field_AFC[0] = 1;
    }
    else
    {
        DG_InvisibleObjs( work->body.objs );
        DG_InvisibleObjs( work->field_7A4.objs );
        work->field_AF4[0] = 0;
        work->field_AFC[0] = 0;
    }
}

int s07a_meryl7_800D54DC( SVECTOR* svec )
{
    if ( ( (unsigned short)svec->vx - 0xFA0 >= 0x157Du ) || ( svec->vz < -0x5014 ) || (svec->vz >= -0x2EDF ) )
    {
        return 0;
    }

    return 1;
}

int s07a_meryl7_800D5520( SVECTOR* svec )
{
    if ( ( (unsigned short)svec->vx - 0x1B58 >= 0x5DDu ) || ( svec->vz < -0x5014 ) || (svec->vz >= -0x4A37 ) )
    {
        return 0;
    }

    return 1;
}

int s07a_meryl7_800D5564( SVECTOR* svec )
{
    if ( ( (unsigned short)svec->vx - 0xFA0 >= 0x157Du ) || ( svec->vz < -0x5014 ) || (svec->vz >= -0x4073 ) )
    {
        return 0;
    }

    return 1;
}


extern int *s07a_dword_800E3650;
extern int *s07a_dword_800E3654;

extern SVECTOR GM_PlayerPosition_800ABA10;

void s07a_meryl7_800D55A8(WatcherWork *work )
{
    if ( s07a_meryl7_800D54DC( &work->control.field_0_mov ) != 0 )
    {
        *s07a_dword_800E3650 = 0;
    } else 
    {
        *s07a_dword_800E3650 = 1;
    }
    
    if ( s07a_meryl7_800D5564( &GM_PlayerPosition_800ABA10 ) != 0)
    {
        *s07a_dword_800E3654 = 0;
    }
    else
    {
        *s07a_dword_800E3654 = 1;
    }
}

int s07a_meryl7_800D5614( WatcherWork *work )
{
    return s07a_meryl7_800D5520( &GM_PlayerPosition_800ABA10 );
}

void EnemyPushMove_800DB23C( WatcherWork *work ); // EnemyPushMove_800CA0E8
void EnemyActionMain_800DB1D0( WatcherWork *work ); // EnemyActionMain_800CA07C

// Modified version of WatcherAct_800C430C
void EnemyMerylAct_800D5638( WatcherWork *work )
{
    VECTOR   vec;
    TARGET  *trgt;
    CONTROL *ctrl;
    TARGET  *trgt2;

    ctrl = &( work->control ) ;
    if (GM_CheckMessage_8002631C( &( work->actor ) , ctrl->field_30_scriptData, HASH_KILL ) )
    {
        GV_DestroyActor_800151C8( &( work->actor ) );
        return;
    }

    s07a_meryl7_800D52FC( work );
    s07a_meryl7_800D55A8( work );
    s07a_meryl7_800D5614( work );
    if ( !work->faseout )
    {
        EnemyPushMove_800DB23C( work );
        GM_ActControl_80025A7C( ctrl );
        GM_ActObject2_80034B88( &( work->body ) );
        GM_ActObject2_80034B88( &( work->field_7A4 ) );

        DG_GetLightMatrix2_8001A5D8( &( ctrl->field_0_mov ), &( work->field_888 ) );

        EnemyActionMain_800DB1D0( work );
        trgt = work->target;
        GM_Target_SetVector_8002D500( trgt, &( ctrl->field_0_mov ) );

        sub_8002DA14( trgt );

        if ( trgt->class & TARGET_TOUCH )
        {
            trgt2 = &work->field_94C;
            if ( trgt2->class & TARGET_TOUCH )
            {
                if ( trgt2->field_6_flags & TARGET_TOUCH )
                {
                    trgt2->field_6_flags &= ~TARGET_TOUCH;
                }
                GM_Target_SetVector_8002D500( &( work->field_94C ), &( ctrl->field_0_mov ) );
                GM_TouchTarget_8002D6D8( &( work->field_94C ) );
            }
        }
        vec.vx = vec.vy = vec.vz = work->scale;
        ScaleMatrix( &( work->body.objs->world ), &vec );
    }
    s07a_meryl7_800D53A4( work );
}

// Identical to InitTarget_800C444C
void s07a_meryl7_800D5780( WatcherWork *work )
{
    TARGET *target;
    TARGET *target2;
    int life;
    int faint;

    target = work->target;
    life   = work->param_life;
    faint  = work->param_faint;

    GM_SetTarget_8002DC74( target, ( TARGET_FLAG | TARGET_AVAIL ), ENEMY_SIDE, &ENEMY_TARGET_SIZE_800C35A4 );
    GM_Target_8002DCCC( target, 1, -1, life, faint, &ENEMY_TARGET_FORCE_800C35AC );
    GM_Target_8002DCB4( target, -1, faint, NULL, NULL);

    sub_8002DD14( target, &( work->body.objs->objs[1].world ) );

    target2 = &work->field_904;
    GM_SetTarget_8002DC74( target2, TARGET_POWER, PLAYER_SIDE, &ENEMY_ATTACK_SIZE_800C35B4 );
    GM_Target_8002DCCC( target2, 7, 5, 0, 3, &ENEMY_ATTACK_FORCE_800C35BC );

    target2 = &work->field_94C;
    GM_SetTarget_8002DC74( target2, ( TARGET_TOUCH ), ENEMY_SIDE, &ENEMY_TOUCH_SIZE_800C35C4 );
    GM_Target_8002DCCC( target2, 7, 5, 0, 0, &ENEMY_TOUCH_FORCE_800C35CC );
}

// Identical to s00a_watcher_800C4578
void s07a_meryl7_800D58AC( WatcherWork* work )
{
    WatcherUnk *s;
    s = (WatcherUnk*)&work->field_8C8;

    GV_ZeroMemory_8001619C(s, 0x24);
    s->field_00 = 0;
    s->field_1C = 0x1C2;
    s->field_1E = 1;

    work->action = 0;
    work->action2 = 0;
    work->time = 0;
    work->time2 = 0;
}

int ENE_SetPutChar_800D9D6C( WatcherWork *work, int put ); // ENE_SetPutChar_800C979C

// Modified s00a_watcher_800C45D4
int s07a_meryl7_800D5908( WatcherWork* work, int name, int where )
{
    int has_kmd;
    int opt, opt2;
    CONTROL *ctrl;
    OBJECT  *body, *body2;
    OBJECT  *arm; //?
    SVECTOR  shadow;

    ctrl = &work->control;
    if ( GM_InitLoader_8002599C( ctrl, name, where ) < 0 ) return -1;

    opt = GCL_GetOption_80020968( 'p' );

    GM_ConfigControlString_800261C0( ctrl, (char*)opt, (char*)GCL_GetOption_80020968( 'd' ) ) ;
    GM_ConfigControlAttribute_8002623C( ctrl, 13 );
    GM_ConfigControlInterp_80026244( ctrl, 4 );

    ctrl->field_59 = 2;

    GM_ConfigControlTrapCheck_80026308( ctrl );

    body2 = &work->body;
    if (ctrl)
    {
        body = body2;
    }
    else
    {
        body = body2;
    }
    arm = &work->field_7A4;

    GM_InitObject_80034A18( body, 0x96B6, 0x32D, 0xA8A1 ) ;
    GM_ConfigObjectJoint_80034CB4( body ) ;
    GM_ConfigMotionControl_80034F08( body, &work->m_ctrl, 0xA8A1, work->field_1DC, &work->field_1DC[17], ctrl, work->rots );
    GM_ConfigObjectLight_80034C44( body, &work->field_888 );

    work->field_B7B = 0;

    opt2 = GCL_GetOption_80020968( 'y' );
    if ( opt2 ) {
        work->field_B7B = GCL_StrToInt_800209E8( (char*)opt2 );
    }

    has_kmd = work->field_B7B;
    if ( has_kmd == 1 )
    {
        work->def = work->body.objs->def;
        work->kmd = GV_GetCache_8001538C( GV_CacheID_800152DC (0xD7E3, 'k' ) );
        work->field_180 = has_kmd;
        body = body2;
    }

    work->hom = HomingTarget_Alloc_80032C8C( &work->body.objs->objs[6].world, ctrl );
    GM_InitObject_80034A18( arm, 0x4725, 0x6D, 0 );
    GM_ConfigObjectLight_80034C44( arm, &work->field_888 ) ;
    GM_ConfigObjectRoot_80034C5C( arm, body, 4 );

    shadow.vy  = 6;
    shadow.vz  = 12;
    shadow.pad = 15;
    shadow.vx  = 0;

    work->field_AF0 = (void*)shadow_init2_80060384( ctrl, body, shadow,  &work->field_AF4 ) ;
    work->field_AF8 = NewGunLight_800D3AD4( &( body->objs->objs[4].world ), &work->field_AFC ) ;

    ENE_SetPutChar_800D9D6C( work, 0 );
    s07a_meryl7_800D58AC ( work );

    return 0;
}

// Identical to s00a_watcher_800C4814
//FreeWatcher?
void s07a_meryl7_800D5B28( WatcherWork* work )
{
    HomingTarget_Free_80032CFC( work->hom );
    GM_FreeControl_800260CC( &( work->control ) );
    GM_FreeObject_80034BF8( &( work->body ) );
    GM_FreeObject_80034BF8( &( work->field_7A4 ) );
    GM_FreeTarget_8002D4B0( work->target );
    GV_DestroyOtherActor_800151D8( work->field_AF8 );
    GV_DestroyOtherActor_800151D8( work->field_AF0 );
}

// Identical to WatcherDie_800C487C
void EnemyMerylDie_800D5B90( WatcherWork* work )
{
    s07a_meryl7_800D5B28( work );
}

// Identical to ReadNodes_800C489C
int s07a_meryl7_800D5BB0( WatcherWork* work )
{
    int i;
    HZD_PAT *patrol;
    HZD_PTP *points;

    patrol = work->control.field_2C_map->field_8_hzd->f00_header->routes;
    patrol = &patrol[ work->field_B7D ];

    work->field_9E8 = patrol->n_points;

    if ( work->field_9E8 <= 0 ) return -1;

    points = patrol->points;
    for ( i = 0 ; i < work->field_9E8 ; i++ )
    {
        work->nodes[i].vx = points->x;
        work->nodes[i].vy = points->y;
        work->nodes[i].vz = points->z;
        work->nodes[i].pad = points->command;
        points++;
    }
    return 0;
}

// Identical to s00a_watcher_800C4990
int s07a_meryl7_800D5C4C( int opt, short* s )
{
    int i;
    unsigned char *res;

    for ( i = 0 ; ( res = GCL_Get_Param_Result_80020AA4() ) ; i++ )
    {
        *s = GCL_StrToInt_800209E8( res );
         s++;
    }

    return i;
}

// Identical to s00a_watcher_800C49E8
int s07a_meryl7_800D5CA4( int opt, int* l )
{
    int i;
    unsigned char *res;

    for ( i = 0 ; ( res = GCL_Get_Param_Result_80020AA4() ) ; i++ )
    {
        *l = GCL_StrToInt_800209E8( res );
         l++;
    }

    return i;
}

extern unsigned short s07a_dword_800C3618[];
extern const char s07a_aErrerrerrsettimeover_800E2E40[];
extern const char s07a_aErrerrerrsetdirover_800E2E5C[];

int s07a_meryl7_800D5CFC( WatcherWork* work ) 
{
    int i;
    int opt;
    int ret;

    for ( i = 0 ; i < 8 ; i++ )
    {
        work->field_BB0[i] = s07a_dword_800C3618[i];
    }

    opt = GCL_GetOption_80020968( 't' );
    if ( opt )
    {
        ret = s07a_meryl7_800D5CA4( opt, &work->field_BB0[1] );
        if ( ret > 4 )
        {
            printf( s07a_aErrerrerrsettimeover_800E2E40 ) ;
            return -1;
        }
    }

    for ( i = 0 ; i < 4 ; i++ )
    {
        work->field_BD0[i] = i * 1024;
    }

    opt = GCL_GetOption_80020968( 'i' );

    if ( opt )
    {
        ret = s07a_meryl7_800D5C4C( opt, work->field_BD0 );
        if ( ret > 4 )
        {
            printf( s07a_aErrerrerrsetdirover_800E2E5C ) ;
            return -1;
        }
    }

    return 0;
}

extern const char s07a_aErrerrerrsoundbuffover_800E2E78[];
int s07a_meryl7_800D5DD4( WatcherWork *work )
{
    int opt;

    opt = GCL_GetOption_80020968('v');
    if (opt != NULL && s07a_meryl7_800D5CA4(opt, &work->field_C40) > 2)
    {
        fprintf(0, s07a_aErrerrerrsoundbuffover_800E2E78);
        return -1;
    }

    return 0;    
}

extern const char s07a_dword_800E2E98[];
extern const char s07a_dword_800E2EA0[];

extern GV_ACT *s07a_dymc_seg_800D65C8(int arg0, SVECTOR *min, SVECTOR *max, int min_h, int max_h, int flag, void **arg6);

void s07a_meryl7_800D5E34( WatcherWork *work ) 
{
    int flag;
    SVECTOR min, max;

    flag = 0xFE;    
    
    min.vx = 0x157C;
    min.vy = 0;
    min.vz = -0x251C;
    
    max.vx = 0x1B58;
    max.vy = 0;
    max.vz = -0x251C;
    
    s07a_dymc_seg_800D65C8( GV_StrCode_80016CCC( s07a_dword_800E2E98 ), &min, &max, 3000, 3000, 0xFE, (void**)&s07a_dword_800E3650 );

    flag = 0xF7;
    
    min.vx = 0x1194;
    min.vy = 0;
    min.vz = -0x4844;
    
    max.vx = 0x1B58;
    max.vy = 0;
    max.vz = -0x4844;
    s07a_dymc_seg_800D65C8( GV_StrCode_80016CCC( s07a_dword_800E2EA0 ), &min, &max, 3000, 3000, 0xF7, (void**)&s07a_dword_800E3654 );
}

extern const char s07a_aErrnotenoughwork_800E2EAC[];// = "Err not enough work !!\n";
extern const char s07a_aMerylcactionpointerr_800E2EC4[];// = "meryl.c : action point Err\n";

extern int s07a_dword_800C35F8[8];
extern int s07a_dword_800E3658;
extern const char s07a_aAsiatoooo_800E2EE0[];

extern void  GM_ConfigControlRadarparam_800262EC( CONTROL *pControl, unsigned short param_2, unsigned short param_3, unsigned short param_4, unsigned short param_5 );

void EnemyMerylGetResources_800D5F24( WatcherWork *work, int name, int where )
{
    SVECTOR svec;
    int addr;
    int opt;
    int i;

    s07a_meryl7_800D5908( work, name, where ) ;
    work->field_B78 = s00a_command_800CEA2C( work ) ;

    if ( work->field_B78  << 24 < 0  )
    {
       printf( s07a_aErrnotenoughwork_800E2EAC ) ;
    }

    s07a_meryl7_800D5CFC( work ) ;

    work->field_B7D = 0;
    opt = GCL_GetOption_80020968( 'r' );
    if ( opt )
    {
        work->field_B7D = GCL_StrToInt_800209E8( ( char* )opt );
    }

    work->param_life = 192;
    opt = GCL_GetOption_80020968( 'l' );
    if ( opt )
    {
        work->param_life = GCL_StrToInt_800209E8( ( char* )opt );
    }

    work->param_faint = 10;
    opt = GCL_GetOption_80020968( 'f' );
    if ( opt )
    {
        work->param_faint = GCL_StrToInt_800209E8( ( char* )opt );
    }

    work->param_blood = 65;
    opt = GCL_GetOption_80020968( 'b' );
    if ( opt )
    {
        work->param_blood = GCL_StrToInt_800209E8( ( char* )opt );
    }
    
    work->field_B81 = 0xFF;
    
    opt = GCL_GetOption_80020968('g');
    if ( opt )
    {
        work->field_B81 = GCL_StrToInt_800209E8( ( char* )opt );
    }
    if ( work->param_blood == 'Z' )
    {
        work->field_B81 = 0;
    }

    
    work->field_C34 = 0;
    work->field_C35[0] = 0;
    
    opt = GCL_GetOption_80020968( 'e' );
    if ( opt )
    {
        work->field_C3C = GCL_StrToInt_800209E8( GCL_Get_Param_Result_80020AA4() );
    }
    else
    {
        work->field_C3C = -1;
    }

    s07a_dword_800E3658 = -1;
    opt = GCL_GetOption_80020968( 'k' );
    if ( opt )
    {
        s07a_dword_800E3658 = GCL_StrToInt_800209E8( GCL_Get_Param_Result_80020AA4() );
    }

    s07a_meryl7_800D5DD4( work );
    work->field_BFC = s07a_dword_800C35F8[ work->field_B78 ];
    work->field_C00 = work->field_B78;
    work->field_B7C = 0xFF;
    
    opt = GCL_GetOption_80020968( 'n' );
    if ( opt )
    {
        GCL_StrToSV_80020A14( ( char* )opt, &svec );
        if ( svec.vy < 0x7530 )
        {
            work->field_B7C = HZD_GetAddress_8005C6C4( work->control.field_2C_map->field_8_hzd, &svec, -1 );
        }
        else
        {
            work->field_B7C = 0xFF;
        }
    }

    work->param_area = 'A';
    opt = GCL_GetOption_80020968( 'a' );
    if (opt != 0)
    {
        work->param_area = GCL_StrToInt_800209E8( ( char* )opt );
    }

    if ( work->param_area == 'S' ) ENE_SetPutChar_800D9D6C( work, PUTBREATH ) ; /* 白い息はく */
    work->scale = 4096 ;            /* スケール */

    if ( ( opt = GCL_GetOption_80020968( 's' ) ) != NULL ) work->scale += GCL_StrToInt_800209E8( ( char* )opt );
    work->param_item = 1;

    //fprintf(0,"Life=%d Faint=%d Blood=%c Area=%c \n",
    //  work->param.life, work->param.faint, work->param.blood,work->param.area);

    if( s07a_meryl7_800D5BB0( work ) < 0 ) printf( s07a_aMerylcactionpointerr_800E2EC4 );

    /*
        当たりデータを初期化する
    */
    if( ( work->target =  GM_AllocTarget_8002D400() ) != NULL ) s07a_meryl7_800D5780( work ) ;

    /*
        思考ルーチン用データを初期化する
    */
    s07a_meryl7_800D5E34( work );
    work->think1 = 0 ;
    work->think2 = 0 ;
    work->think3 = 0 ;
    work->think4 = 0 ;
    work->count3 = 0 ;
    work->l_count = 0 ;
    work->t_count = 0 ;
    work->mark_time = 0 ;
    work->next_node = 0 ;
    work->search_flag = 0 ;
    work->act_status = 0 ;

    work->target_pos = work->nodes[ 0 ] ;
    work->target_addr = HZD_GetAddress_8005C6C4( work->control.field_2C_map->field_8_hzd, &( work->target_pos ), -1 ) ;
    work->target_map  = GM_CurrentMap_800AB9B0;

    work->alert_level = 0;
    work->visible = 1;
    work->vision.field_B8E = 0x200;
    work->vision.facedir = 0;
    work->field_B94 = 0;
    work->pad.sound = 0;
    work->pad.time  = 0;
    work->vision.length = COM_EYE_LENGTH_800E0D8C;
    work->field_BA4 = COM_NO_POINT_800C35D4;
    
    work->subweapon = 0;

    work->control.field_0_mov = work->nodes[ 0 ] ;
    work->field_B7E = work->field_B7D;
    work->field_B7F = work->field_B7C;

    for ( i = 0 ; i <= 7 ; i++ )
    {
        work->modetime[i] = 0;
    }

    work->field_BA3 =  7;
    work->field_BA0 = -1;

    opt = GCL_GetOption_80020968( 'c' );
    if ( opt )
    {
        printf( s07a_aAsiatoooo_800E2EE0 );
        work->field_BA3 |= 0x10;
    }

    GM_ConfigControlRadarparam_800262EC( &work->control , 0, 0x200, COM_EYE_LENGTH_800E0D8C, 0 );
    work->start_pos = work->nodes[ 0 ] ;
    work->start_map = GM_CurrentMap_800AB9B0;
    addr = HZD_GetAddress_8005C6C4( work->control.field_2C_map->field_8_hzd, &( work->control.field_0_mov ), -1 );

    work->start_addr = addr;
    work->field_C08 = addr;
    work->field_BF0 = addr;

    work->field_C14 = work->start_pos;    
}


extern const char s07a_aMeryl7_800E2F04[];
extern const char s07a_aEnemyworksized_800E2EEC[];

GV_ACT* NewEnemyMeryl_800D63A4( int name, int where, int argc, char **argv ) {
    WatcherWork *work ;

    printf( s07a_aEnemyworksized_800E2EEC, sizeof( WatcherWork ) );
    work = (WatcherWork *)GV_NewActor_800150E4( 4, sizeof( WatcherWork ) ) ;
    if ( work != NULL ) {
        GV_SetNamedActor_8001514C( &( work->actor ), ( TActorFunction )EnemyMerylAct_800D5638, ( TActorFunction )EnemyMerylDie_800D5B90, s07a_aMeryl7_800E2F04 );
        EnemyMerylGetResources_800D5F24( work, name, where );
    }
    return (void *)work ;
}