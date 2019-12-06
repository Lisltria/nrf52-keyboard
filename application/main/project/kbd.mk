ifndef TMK_CORE_DIR
TMK_CORE_DIR = ../../../tmk/tmk_core
endif

ifndef APP_SRC_DIR
APP_SRC_DIR := ../src
endif

# project specific files
SRC_FILES += $(APP_SRC_DIR)/keyboard/keyboard_matrix.c \
    $(APP_SRC_DIR)/keyboard/host_driver.c \
    $(APP_SRC_DIR)/keyboard/eeconfig.c \
    $(APP_SRC_DIR)/keyboard/ble_keyboard.c \
    $(APP_SRC_DIR)/keyboard/keyboard_timer.c \
    $(APP_SRC_DIR)/keyboard/glue_layer.c \
    $(APP_SRC_DIR)/keyboard/keyboard_fn.c \
    $(APP_SRC_DIR)/keyboard/keyboard_led.c \
    $(APP_SRC_DIR)/keyboard/passkey.c \
    $(APP_SRC_DIR)/keyboard/keymap_storage.c \
    $(APP_SRC_DIR)/keyboard/keyboard_evt.c \
    $(APP_SRC_DIR)/keyboard/usb_comm.c \
    $(APP_SRC_DIR)/keyboard/power_button.c

ifeq (yes,$(strip $(STATUS_LED_ENABLE)))
    SRC_FILES += $(APP_SRC_DIR)/drivers/status_led/status_led.c
	INC_FOLDERS += $(APP_SRC_DIR)/drivers/status_led
endif

ifeq (yes,$(strip $(COMMAND_ENABLE)))
    SRC_FILES += $(APP_SRC_DIR)/keyboard/keyboard_command.c
endif

INC_FOLDERS += $(APP_SRC_DIR)/keyboard

# Source files common to all targets
ifeq (yes,$(strip $(RGBLIGHT_ENABLE)))
INC_FOLDERS += \
	$(APP_SRC_DIR)/drivers/ws2812

SRC_FILES += \
	$(APP_SRC_DIR)/drivers/ws2812/ws2812.c \
	$(APP_SRC_DIR)/drivers/ws2812/rgblight.c \
	$(APP_SRC_DIR)/drivers/ws2812/led_tables.c \
	$(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_pwm.c
endif



# Version string
VERSION := $(shell (git describe --always --dirty || echo 'unknown') 2> /dev/null)
OPT_DEFS += -DVERSION=$(VERSION)

include $(APP_PROJ_DIR)/tmk.mk
include $(APP_PROJ_DIR)/app.mk