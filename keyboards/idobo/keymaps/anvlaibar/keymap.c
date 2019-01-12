/* Copyright 2018 MechMerlin
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
//#include "keymap_nordic.h"
#include "keymap_norwegian.h"

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /* QWERTY-Win - LAYER 0
  * .--------------------------------------------------------------------------------------------------------------------------------------.
  * | ESC    | 1      | 2      | 3      | 4      | 5      | 6     | 7      | 8      | 9      | 0      | +      | \       | ~     | BACKSP  |
  * |--------+--------+--------+--------+--------+--------+-------+--------+--------+--------+--------+--------+------- -+-------+---------|
  * | TAB    | Q      | W      | E      | R      | T      | Y     | U      | I      | O      | P      | Å      | ¨       | {     | [       |
  * |--------+--------+--------+--------+--------+--------+-------+--------+--------+--------+--------+--------+------- -+-------+---------|
  * | |      | A      | S      | D      | F      | G      | H     | J      | K      | L      | Ø      | Æ      | '       | (     | ENTER   |
  * |--------+--------+--------+--------+--------+--------+-------+--------+--------+--------+--------+------ -+---------+-------+---------|
  * | LSHIFT | <      | Z      | X      | C      | V      | B     | N      | M      | ,      | .      | -      | ;       | UP    | DEL     |
  * |--------+--------+--------+--------+--------+--------+-------+--------+--------+--------+--------+---- ---+---------+-------+---------|
  * | CTRL   | LGUI   | %      | /      | LALT   | FN     | SPACE | SPACE  | FN     | ALTGR  | FN-TEMP| &      | LEFT    | DOWN  | RIGHT   |
  * '--------------------------------------------------------------------------------------------------------------------------------------'
  */
 [0] = LAYOUT_ortho_5x15( \
    KC_ESC,    KC_1,      KC_2,      KC_3,      KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,       KC_0,        NO_PLUS,     NO_BSLS,     NO_GRV,     KC_BSPC, \
    KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,       KC_P,        NO_AA,       NO_QUOT,     KC_LBRC,    KC_RBRC, \
    NO_PIPE,    KC_A,      KC_S,      KC_D,      KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,       NO_OSLH,     NO_AE,       NO_ASTR,     KC_RSPC,    KC_ENT,  \
    KC_LSFT,   NO_LESS,   KC_Z,      KC_X,      KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,    KC_DOT,      NO_MINS,     KC_SCOLON,   KC_UP,      KC_DEL,  \
    KC_LCTL,   KC_LGUI,   KC_NO,     KC_PSLS,   KC_LALT,  DF(0),    KC_SPC,   KC_SPC,   OSL(1),   KC_RALT,    LT(1, KC_SPC),   KC_NO,       KC_LEFT,     KC_DOWN,    KC_RGHT  \
  ),
};

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
} */

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
