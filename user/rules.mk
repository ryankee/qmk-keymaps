EXTRAFLAGS += -flto
TMK_COMMON_DEFS += -DLINK_TIME_OPTIMIZATION_ENABLE

COMMAND_ENABLE  = no   # Disable shift combination, which conflicts with shift-parens
CONSOLE_ENABLE  = no
MIDI_ENABLE     = yes
MOUSEKEY_ENABLE = yes
NKRO_ENABLE     = yes
DYNAMIC_MACRO_ENABLE = yes
LEADER_ENABLE = yes

SRC += my.c

ifeq ($(strip $(COMBO_ENABLE)), yes)
  SRC += my_combos.c
  SRC += my_leader.c
  SRC += my_leader_dictionary.c
endif

ifeq ($(strip $(UCIS_ENABLE)), yes)
  SRC += my_unicode_dictionary.c
endif

ifneq ("$(wildcard $(USER_PATH)/private.h)", "")
  OPT_DEFS += -DPRIVATE_MACROS
endif
