/* Copyright 2019 Ryota Goto
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
#include QMK_KEYBOARD_H

#include "keymap_norwegian.h"

// Add headers for raw hid communication
#include "raw_hid.h"

/* 	K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K212, K014, \ 16
 *	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113,       K114, \ 15
 *	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211,       K213,       K214, \ 14
 *	K300, K404, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311,       K313, K314, \ 15
 *	K400, K401, K402,       K403,       K405,       K407,       K409, K410,       K411, K413, K414  \ 11 (9)
 */

extern uint8_t is_master;

// Aliases
#define ___ KC_TRNS

// Layer defines
#define _BASE 0
#define _RAISE 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_all( /* Base */
// ╭──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────╮
    KC_ESC , KC_1 , KC_2  , KC_3  , KC_4 , KC_5  , KC_6 ,  KC_7 , KC_8  , KC_9 , KC_0  ,KC_MINS,KC_EQL,KC_BSPC,KC_DEL,KC_HOME,
// ├──────┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴──────┼──────┤
      KC_TAB   , KC_Q  , KC_W , KC_E  , KC_R  , KC_T , KC_Y  , KC_U , KC_I  , KC_O  , KC_P ,KC_LBRC,KC_RBRC, KC_BSLS ,KC_PGUP,
// ├──────────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┐       ├──────┤
      KC_NUBS    , KC_A  , KC_S ,  KC_D , KC_F  , KC_G , KC_H  , KC_J  , KC_K , KC_L  ,KC_SCLN,KC_QUOT, /*?*/ KC_ENT ,KC_PGDN,
// ├────────┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴─┬────┴┬─────┴─┬────┴──────┴┬──────┼──────┤
  	 KC_LSFT ,KC_GRV,  KC_Z , KC_X  , KC_C , KC_V  , KC_B  , KC_N , KC_M ,KC_COMM,KC_DOT,KC_SLSH,   KC_RSFT   ,KC_UP , KC_END,
// ├────────┼──────┴─┬────┴───┬──┴──────┴──────┴──────┴──────┴──────┴──┬──┴─────┼───────┴┐╭───╮┌─────┼──────┼──────┤
	   KC_LCTL , KC_LALT ,KC_LGUI ,    KC_SPC,         KC_SPC,         KC_SPC  , KC_RALT ,OSL(_RAISE),  KC_LEFT ,KC_DOWN,KC_RGHT
// ╰────────┴────────┴────────┴────────────────────────────────────────┴────────┴─────────╯   ╰──────┴──────┴──────╯
),
[_RAISE] = LAYOUT_all( /* FN */
// ╭──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────╮
     RESET , KC_F1, KC_F2 , KC_F3, KC_F4 , KC_F5 ,KC_F6 , KC_F7 , KC_F8 ,KC_F9 ,KC_F10 ,KC_F11, KC_F12,  ___  , ___  ,KC_MPLY, 
// ├──────┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴──────┼──────┤
        ___    ,  ___  ,  ___ ,  ___  ,  ___  ,  ___ ,  ___  , ___   , ___  ,  ___  ,KC_PSCR, ___  ,  ___  ,   ___   , AU_TOG,  
// ├──────────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┐       ├──────┤
       KC_CAPS   ,KC_APP ,KC_SLEP, ___  , ___   , ___  ,  ___  ,  ___  ,  ___ ,  ___  ,  ___  , ___  , /*?*/    ___  ,CK_TOGG,   
// ├────────┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴─┬────┴┬─────┴─┬────┴──────┴┬──────┼──────┤
       ___   ,  ___ ,  ___  ,  ___  ,  ___  , ___  ,  ___  , ___  ,  ___  , ___  , ___ ,  ___   ,     ___     ,KC_VOLU, ___  ,   
// ├────────┼──────┴─┬────┴───┬──┴──────┴──────┴──────┴──────┴──────┴──┬──┴─────┼───────┴┐╭───╮┌─────┼──────┼──────┤
       ___   ,  ___    ,  KC_HYPR    ,   ___,             ___,            ___    ,  ___    ,   ___   ,KC_MRWD,KC_VOLD,KC_MFFD
// ╰────────┴────────┴────────┴────────────────────────────────────────┴────────┴─────────╯   ╰──────┴──────┴──────╯
  ),
};

// Raw hid variables
uint8_t layer_index = 0;


// TODO: Implement Raw HID, to be able to send layer state to host
void raw_hid_send_layer_index(void) {
  // Send the current info screen index to the connected node script so that it can pass back the new data
  uint8_t send_data[32] = {0};
  send_data[0] = layer_index + 1; // Add one so that we can distinguish it from a null byte
  raw_hid_send(send_data, sizeof(send_data));
};
// TODO: Implement layer change code
// https://docs.qmk.fm/#/custom_quantum_functions?id=layer-change-code
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _BASE:
        layer_index = 0;
        raw_hid_send_layer_index();
        break;
    case _RAISE:
        layer_index = 1;
        raw_hid_send_layer_index();
        break;
    default: //  for any other layers, or the default layer
        layer_index = 0;
        raw_hid_send_layer_index();
        break;
    }
  return state;
};




