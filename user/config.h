/* Copyright 2018 Noah Frederick
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "my_combos_config.h"

// Disable action_get_macro and fn_actions, since we don't use these
// and it saves on space in the firmware.
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#ifdef AUDIO_ENABLE
// Play sounds when the default layer is set.
#define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                              SONG(COLEMAK_SOUND) }
#endif

#define DYNAMIC_MACRO_SIZE 128

#define DEFAULT_LED_HUE 0
#define DEFAULT_LED_SAT 0
#define DEFAULT_LED_BRIGHTNESS 0x99

// Delay needed for rotary encoder to trigger media keys
#define TAP_CODE_DELAY 10
#define RGB_DISABLE_WHEN_USB_SUSPENDED true // turn off effects when suspended
// Planck EZ colors
#define ORYX_CONFIGURATOR
#define PLANCK_EZ_USER_LEDS
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR
#define MIDI_ADVANCED
