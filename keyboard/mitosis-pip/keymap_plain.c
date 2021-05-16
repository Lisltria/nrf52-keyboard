/*
Copyright (C) 2018,2019 Jim Jiang <jim@lotlab.org>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "keymap_common.h"
#include "keyboard_fn.h"

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	KEYMAP(
		KC_T,   KC_U,       KC_V,       KC_W,       KC_X,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,
		KC_A,   KC_B,       KC_C,       KC_D,       KC_E,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,
		KC_F,   KC_G,       KC_H,       KC_I,       KC_J,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,
		KC_K,   KC_L,       KC_M,       KC_N,       KC_O,       KC_Y,       KC_U,       KC_I,
		KC_P,   KC_Q,       KC_R,       KC_S,       KC_T,       KC_Y,       KC_U,       KC_I),

	KEYMAP(
		KC_Q,   KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,
		KC_A,   KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN, 
		KC_LSFT,KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,
		        KC_LCTL,    KC_LGUI,    KC_LALT,    KC_SPC,     KC_FN0,     KC_LALT,    KC_MENU,    KC_LCTL,
		        KC_LCTL,    KC_LGUI,    KC_LALT,    KC_SPC,     KC_FN0,     KC_LALT,    KC_MENU,    KC_LCTL),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_FN2,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_FN1,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

};
const action_t fn_actions[] = {
    /* Poker Layout */
    ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
    ACTION_FUNCTION(KEYBOARD_CONTROL), // sleep
    ACTION_FUNCTION(SWITCH_DEVICE) // switch between usb and ble
};

