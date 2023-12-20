# enable clean combos in combos.def
COMBO_ENABLE = yes
VPATH += keyboards/gboards

TAP_DANCE_ENABLE = no
LTO_ENABLE = yes
BOOTLOADER = atmel-dfu

SRC += oneshot.c
SRC += swapper.c
