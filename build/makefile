TARGET = _mgsi
TYPE = ps-exe

#main files
SRCS = ../src/main/main.c             \
       ../src/libfs/select.c          \
       ../src/libgv/gvd.c             \
       ../src/libgv/actor.c           \
       ../src/data/bss_psx.c          \
       ../src/libgv/cache.c           \
       ../src/libgv/debug.c           \
       ../src/libgv/memory.c          \
       ../src/libgv/message.c         \
       ../src/libgv/pad.c             \
       ../src/libgv/strcode.c         \
       ../src/libgv/math.c            \
       ../src/libdg/display.c         \
       ../src/libdg/chanl.c           \
       ../src/libdg/bound.c           \
       ../src/libdg/divide.c          \
       ../src/libdg/light.c           \
       ../src/libdg/opack.c           \
       ../src/libdg/prim.c            \
       ../src/libdg/screen.c          \
       ../src/libdg/shade.c           \
       ../src/libdg/sort.c            \
       ../src/libdg/text.c            \
       ../src/libdg/trans.c           \
       ../src/libdg/matrix.c          \
       ../src/libdg/dgd.c             \
       ../src/libdg/loader.c          \
       ../src/libdg/palette.c         \
       ../src/libgcl/gcl_init.c       \
       ../src/libgcl/command.c        \
       ../src/libgcl/basic.c          \
       ../src/libgcl/expr.c           \
       ../src/libgcl/parse.c          \
       ../src/libgcl/variable.c       \
       ../src/libhzd/hzdd.c           \
       ../src/libfs/fscd.c            \
       ../src/libfs/cdbios.c          \
       ../src/libfs/srchfile.c        \
       ../src/libfs/cdstage.c         \
       ../src/libfs/stageld.c         \
       ../src/libfs/movie.c           \
       ../src/libfs/stream.c          \
       ../src/memcard/memcard.c       \
       ../src/Game/control.c          \
       ../src/libgv/math_near.c       \
       ../src/libhzd/unknown.c        \
       ../src/libhzd/level.c          \
       ../src/libhzd/event.c          \
       ../src/Game/area.c             \
       ../src/Game/chara.c            \
       ../src/Game/gamed.c            \
       ../src/Game/script.c           \
       ../src/Game/target.c           \
       ../src/Game/loader.c           \
       ../src/Game/alert.c            \
       ../src/Game/camera.c           \
       ../src/Game/map.c              \
       ../src/libdg/obj.c             \
       ../src/libdg/pshade.c          \
       ../src/Game/sound.c            \
       ../src/Game/homing.c           \
       ../src/Game/delay.c            \
       ../src/Game/item.c             \
       ../src/Game/object.c           \
       ../src/Game/motion.c           \
       ../src/Game/over.c             \
       ../src/Game/strctrl.c          \
       ../src/Game/jimctrl.c          \
       ../src/Menu/menuman.c          \
       ../src/Menu/radar.c            \
       ../src/Menu/item.c             \
       ../src/Menu/weapon.c           \
       ../src/Menu/life.c             \
       ../src/Menu/radio.c            \
       ../src/Menu/debug.c            \
       ../src/Font/font.c             \
       ../src/Menu/radiotex.c         \
       ../src/Menu/radioanim.c        \
       ../src/Menu/radiomes.c         \
       ../src/Menu/radiofacedraw.c    \
       ../src/Menu/jimaku.c           \
       ../src/Menu/radiotable.c       \
       ../src/Menu/datasave.c         \
       ../src/Menu/radiomem.c         \
       ../src/chara/snake/snake.c     \
       ../src/chara/snake/sna_init.c  \
       ../src/libhzd/zone.c           \
       ../src/Game/vibrate.c          \
       ../src/Anime/animeconv/anime.c \
       ../src/chara/snake/shadow.c    \
       ../src/chara/snake/afterse.c   \
       ../src/chara/snake/sna_hzd.c   \
       ../src/Equip/bodyarm.c         \
       ../src/Equip/gasmask.c         \
       ../src/Equip/effect.c          \
       ../src/Equip/kogaku2.c         \
       ../src/Equip/box.c             \
       ../src/Equip/bandana.c         \
       ../src/Equip/tabako.c          \
       ../src/Equip/scope.c           \
       ../src/Equip/gmsight.c         \
       ../src/Equip/jpegcam.c         \
       ../src/Weapon/socom.c          \
       ../src/Weapon/famas.c          \
       ../src/Weapon/grenade.c        \
       ../src/Weapon/rcm.c            \
       ../src/Weapon/aam.c            \
       ../src/Weapon/mine.c           \
       ../src/Weapon/bomb.c           \
       ../src/Weapon/rifle.c          \
       ../src/Weapon/stnsight.c       \
       ../src/Weapon/rfsight.c        \
       ../src/Bullet/tenage.c         \
       ../src/Bullet/bakudan.c        \
       ../src/Bullet/jirai.c          \
       ../src/Bullet/rmissile.c       \
       ../src/Bullet/amissile.c       \
       ../src/Bullet/blast.c          \
       ../src/Thing/door.c            \
       ../src/libhzd/dynamic.c        \
       ../src/Thing/sgtrect3.c        \
       ../src/Thing/sight.c           \
       ../src/Okajima/blood.c         \
       ../src/Okajima/d_blood.c       \
       ../src/Okajima/d_bloodr.c      \
       ../src/Okajima/claymore.c      \
       ../src/Okajima/spark.c         \
       ../src/Okajima/stngrnd.c       \
       ../src/Okajima/stgfd_io.c      \
       ../src/Okajima/bullet.c        \
       ../src/Okajima/chafgrnd.c      \
       ../src/Takabe/goggle.c         \
       ../src/Equip/gglmng.c          \
       ../src/Equip/gglsight.c        \
       ../src/Takabe/scn_mask.c       \
       ../src/Takabe/goggleir.c       \
       ../src/Takabe/palette.c        \
       ../src/Takabe/prim.c           \
       ../src/Kojo/demothrd.c         \
       ../src/libfs/memfile.c         \
       ../src/Kojo/demo.c             \
       ../src/Kojo/m1e1catr.c         \
       ../src/SD/sd_main.c            \
       ../src/SD/sd_str.c             \
       ../src/SD/sd_file.c            \
       ../src/SD/sd_drv.c             \
       ../src/SD/sd_sub1.c            \
       ../src/SD/sd_sub2.c            \
       ../src/SD/sd_ioset.c           \
       ../src/SD/sd_cli.c             \
       ../src/SD/se_tbl.c             \
       ../src/SD/sd_wk.c              \
       ../src/mts/mts_new.c           \
       ../src/mts/mts_pad.c           \
       ../src/mts/mask.c              \
       ../src/libsio/dummy.c          \

#overlay files
SRCS += ../src/overlays/dev/overlay.c                \
        ../src/overlays/select1/Game/select.c        \
        ../src/overlays/s00a/Game/pad.c              \
        ../src/overlays/s00a/chara/snake/breath.c    \
        ../src/overlays/s00a/Anime/animeconv/breath.c\
        ../src/overlays/s00a/Thing/emitter.c         \
        ../src/overlays/s00a/Enemy/watcher.c         \
        ../src/overlays/s00a/Enemy/check.c           \
        ../src/overlays/s00a/Enemy/action.c          \
        ../src/overlays/s00a/Enemy/enemy.c           \
        ../src/overlays/s00a/Anime/animeconv/mark.c  \
        ../src/overlays/s00a/Anime/animeconv/fog.c   \
        ../src/overlays/s00a/Anime/animeconv/smoke.c \
        ../src/overlays/s00a/Anime/animeconv/sleep.c \
        ../src/overlays/s00a/Enemy/think.c           \
        ../src/overlays/s00a/Enemy/command_bss_pad.c \
        ../src/overlays/s00a/Enemy/command.c         \
        ../src/overlays/s00a/Enemy/eyeflash.c        \
        ../src/overlays/s00a/Enemy/asiato.c          \
        ../src/overlays/s00a/Enemy/l_sight.c         \
        ../src/overlays/s00a/Enemy/grnad_e.c         \
        ../src/overlays/s00a/Enemy/boxkeri.c         \
        ../src/overlays/s00a/Enemy/smoke.c           \
        ../src/overlays/s00a/Enemy/glight.c          \
        ../src/overlays/s00a/Okajima/mouse.c         \
        ../src/overlays/s00a/Okajima/bubble_s.c      \
        ../src/overlays/s00a/Okajima/pato_lmp.c      \
        ../src/overlays/s00a/Takabe/ripple.c         \
        ../src/overlays/s00a/Takabe/rsurface.c       \
        ../src/overlays/s00a/Takabe/ripples.c        \
        ../src/overlays/s00a/Takabe/elevator.c       \
        ../src/overlays/s00a/Takabe/wt_area.c        \
        ../src/overlays/s00a/Okajima/splash2.c       \
        ../src/overlays/s00a/Takabe/wt_view.c        \
        ../src/overlays/s00a/Takabe/object.c         \
        ../src/overlays/s00a/Takabe/mosaic.c         \
        ../src/overlays/s00a/Takabe/pad_demo.c       \
        ../src/overlays/s00a/Takabe/telop.c          \
        ../src/overlays/s00a/Takabe/cinema.c         \
        ../src/overlays/s00a/Takabe/o2_damge.c       \
        ../src/overlays/s00a/Takabe/env_snd.c        \
        ../src/overlays/s00a/Takabe/camshake.c       \
        ../src/overlays/s00a/Takabe/cat_in.c         \
        ../src/overlays/s16b/Enemy/wall.c            \
        ../src/overlays/s16b/Enemy/asioto.c          \
        ../src/overlays/s16b/Takabe/thing.c          \
        ../src/overlays/s16b/Takabe/fadeio.c         \
        ../src/overlays/s16b/Takabe/dymc_seg.c       \
        ../src/overlays/s16b/Takabe/shakemdl.c       \

#sys files
SRCS += ../third_party/common/syscalls/printf.s \
        ../third_party/common/crt0/crt0.s       \

CPPFLAGS += -I../third_party/common
CPPFLAGS += -I../third_party/psyq/include
CPPFLAGS += -I../src/include
CPPFLAGS += -I../src
LDFLAGS += -L../third_party/psyq/lib
LDFLAGS += -Wl,--start-group
LDFLAGS += -lapi
LDFLAGS += -lc
LDFLAGS += -lsn
LDFLAGS += -lcd
LDFLAGS += -lc2
LDFLAGS += -lcard
LDFLAGS += -lcomb
LDFLAGS += -lds
LDFLAGS += -letc
LDFLAGS += -lgpu
LDFLAGS += -lgs
LDFLAGS += -lgte
LDFLAGS += -lgpu
LDFLAGS += -lgun
LDFLAGS += -lhmd
LDFLAGS += -lmath
LDFLAGS += -lmcrd
LDFLAGS += -lmcx
LDFLAGS += -lpad
LDFLAGS += -lpress
LDFLAGS += -lsio
LDFLAGS += -lsnd
LDFLAGS += -lspu
LDFLAGS += -ltap
LDFLAGS += -Wl,--end-group

CPPFLAGS += -DDEV_EXE
CPPFLAGS += -DPSX_DEV_EXE
CPPFLAGS += -funsigned-char 
CPPFLAGS += -fno-zero-initialized-in-bss

BUILD=Debug

OVERLAYSCRIPT  ?= ../third_party/overlay_dev.ld
OVERLAYSECTION ?= .dev

include ../third_party/common.mk
