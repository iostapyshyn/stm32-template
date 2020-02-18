PROJECT = project
BUILD_DIR = bin

CFILES = main.c

DEVICE = stm32f103c8t6
OOCD_INTERFACE = stlink-v2
OOCD_TARGET = stm32f1x

OPENCM3_DIR = libopencm3

include $(OPENCM3_DIR)/mk/genlink-config.mk
include rules.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk
