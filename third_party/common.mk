BUILD ?= Release

HAS_LINUX_MIPS_GCC = $(shell which mipsel-linux-gnu-gcc > /dev/null 2> /dev/null && echo true || echo false)

ifeq ($(HAS_LINUX_MIPS_GCC),true)
PREFIX ?= mipsel-linux-gnu
FORMAT ?= elf32-tradlittlemips
else
PREFIX ?= mipsel-none-elf
FORMAT ?= elf32-littlemips
endif

ROOTDIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

CC  = $(PREFIX)-gcc
CXX = $(PREFIX)-g++

TYPE ?= cpe
LDSCRIPT ?= $(ROOTDIR)/$(TYPE).ld
ifneq ($(strip $(OVERLAYSCRIPT)),)
LDSCRIPT := $(addprefix $(OVERLAYSCRIPT) , -T$(LDSCRIPT))
else
LDSCRIPT := $(addprefix $(ROOTDIR)/default.ld , -T$(LDSCRIPT))
endif

USE_FUNCTION_SECTIONS ?= true

ARCHFLAGS = -march=mips1 -mabi=32 -EL -fno-pic -mno-shared -mno-abicalls -mfp32
ARCHFLAGS += -fno-stack-protector -nostdlib -ffreestanding
ifeq ($(USE_FUNCTION_SECTIONS),true)
CPPFLAGS += -ffunction-sections
endif
CPPFLAGS += -mno-gpopt -fomit-frame-pointer
CPPFLAGS += -fno-builtin -fno-strict-aliasing -Wno-attributes
CPPFLAGS += $(ARCHFLAGS)
CPPFLAGS += -I$(ROOTDIR)

LDFLAGS += -Wl,-Map=$(BINDIR)$(TARGET).map -nostdlib -T$(LDSCRIPT) -static -Wl,--gc-sections
LDFLAGS += $(ARCHFLAGS) -Wl,--oformat=$(FORMAT)

CPPFLAGS_Release += -Os
LDFLAGS_Release += -Os

CPPFLAGS_Debug += -Og
CPPFLAGS_Coverage += -Og

LDFLAGS += -g
CPPFLAGS += -g

CPPFLAGS += $(CPPFLAGS_$(BUILD))
LDFLAGS += $(LDFLAGS_$(BUILD))

OBJDIR = ../obj_psx_dev/
BINDIR = $(OBJDIR)

OBJS += $(subst ../, $(OBJDIR), $(addsuffix .o, $(basename $(SRCS))))

all: dep $(BINDIR)$(TARGET).$(TYPE)

$(BINDIR)$(TARGET).$(TYPE): $(BINDIR)$(TARGET).elf
	$(PREFIX)-objcopy $(addprefix -R , $(OVERLAYSECTION)) -O binary $< $@
	$(foreach ovl, $(OVERLAYSECTION), $(PREFIX)-objcopy -j $(ovl) -O binary $< $(BINDIR)Overlay$(ovl);)

$(BINDIR)$(TARGET).elf: $(OBJS)
ifneq ($(strip $(BINDIR)),)
	@mkdir -p $(BINDIR)
endif
	$(CC) -g -o $(BINDIR)$(TARGET).elf $(OBJS) $(LDFLAGS)

$(OBJDIR)%.o: ../%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

$(OBJDIR)%.o: ../%.s
	@mkdir -p $(dir $@)
	$(CC) $(ARCHFLAGS) -I$(ROOTDIR) -g -c -o $@ $<

$(OBJDIR)%.dep: ../%.c
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -MM -MT $(addsuffix .o, $(basename $@)) -MF $@ $<

$(OBJDIR)%.dep: ../%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -MM -MT $(addsuffix .o, $(basename $@)) -MF $@ $<

$(OBJDIR)%.dep: ../%.cc
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -MM -MT $(addsuffix .o, $(basename $@)) -MF $@ $<

# A bit broken, but that'll do in most cases.
$(OBJDIR)%.dep: ../%.s
	@mkdir -p $(dir $@)
	touch $@

DEPS := $(subst ../,$(OBJDIR),$(patsubst %.cpp, %.dep,$(filter %.cpp,$(SRCS))))
DEPS := $(subst ../,$(OBJDIR),$(patsubst %.cc,  %.dep,$(filter %.cc,$(SRCS))))
DEPS += $(subst ../,$(OBJDIR),$(patsubst %.c,   %.dep,$(filter %.c,$(SRCS))))
DEPS += $(subst ../,$(OBJDIR),$(patsubst %.s,   %.dep,$(filter %.s,$(SRCS))))

dep: $(DEPS)

clean:
	rm -f -r $(OBJDIR)

ifneq ($(MAKECMDGOALS), clean)
ifneq ($(MAKECMDGOALS), deepclean)
-include $(DEPS)
endif
endif

.PHONY: clean dep all