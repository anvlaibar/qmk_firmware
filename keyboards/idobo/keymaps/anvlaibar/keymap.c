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
#include "keymap_norwegian.h"
#include "eeconfig.h"

// Aliases
#define ___ KC_TRNS
#define XXX KC_NO

// Layers
#define _QW 0
#define _FN 1
#define _RGB 2

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QUERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FUNCTION,
  RGB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* QWERTY-Win Norwegian - LAYER 0
  * .-----------------------------------------------------------------------------------------------------------------------.
  * | ESC   | 1     | 2     | 3     | 4     | 5     | 6     | 7     | 8     | 9     | 0     | +     | \     | ~     | BKSP  |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * | TAB   | Q     | W     | E     | R     | T     | Y     | U     | I     | O     | P     | Å     | ¨     | {     | }     |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * | |     | A     | S     | D     | F     | G     | H     | J     | K     | L     | Ø     | Æ     | '     | (     | ENTER |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
  * | SHIFT | <     | Z     | X     | C     | V     | B     | N     | M     | ,     | .     | -     | ;     | UP    | DEL   |
  * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+--- ---+-------+-------+-------|
  * | CTRL  | GUI   | %     | /     | ALT   | LOWER | SPACE | SPACE | RAISE | ALTGR | FN    | &     | LEFT  | DOWN  | RIGHT |
  * '-----------------------------------------------------------------------------------------------------------------------'
  */
 [_QW] = LAYOUT_ortho_5x15( \
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, NO_PLUS, NO_BSLS, KC_TILD, KC_BSPC, \
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, NO_AA, NO_QUOT, KC_LBRC, KC_RBRC, \
    NO_PIPE, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, NO_OSLH, NO_AE, NO_ASTR, KC_LSPO, KC_ENT, \
    KC_LSFT, NO_LESS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_MINS, KC_SCOLON, KC_UP, KC_DEL, \
    KC_LCTL, KC_LGUI, KC_PERC, KC_PSLS, KC_LALT, LOWER, KC_SPC, XXX, RAISE, KC_RALT, LT(1, KC_RSFT), KC_AMPR, KC_LEFT, KC_DOWN, KC_RGHT \
  ),

 /* Function & Media keys - LAYER 1
  * .-----------------------------------------------------------------------------------------------------------------------.
	* | -     | F1    | F2    | F3    | F4    | F5    | F6    | F7    | F8    | F9    | F10   | F11   | F12   | F13   | -     |
	* |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
	* | LEADR | PLAYPS| STOP  | PREV  | NEXT  | VLMMUT| VLM-  | VLM+  | -     | PRTSCR| SCRLK | PAUSE | INS   | -     | CALC  |
	* |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
	* | KEYLK | -     | -     | -     | -     | -     | -     | -     | -     | -     | -     | -     |  -    | -     | -     |
	* |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
	* | -     | -     | -     | -     | -     | -     | -     | -     | -     | -     | -     | -     | -     | PGUP  | -     |
	* |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
	* | RESET | -     | -     |  -    | QUERTY| LOWER | -     | -     | RAISE | RGB   | -     | -     | HOME  | PG DN | END   |
	* '-----------------------------------------------------------------------------------------------------------------------'
	*/
 	[_FN] = LAYOUT_ortho_5x15(
  	___, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_F13, XXX, \
  	KC_LEAD, KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, XXX, KC_PSCR, KC_SLCK, KC_PAUS, KC_INS, XXX, KC_CALC, \
  	KC_LOCK, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, \
  	XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, KC_PGUP, XXX, \
  	RESET, XXX, XXX, XXX, QUERTY, LOWER, XXX, XXX, RAISE, RGB, XXX, XXX, KC_HOME, KC_PGDN, KC_END \
	),

 /* RGB-controls - LAYER 2
	* .-----------------------------------------------------------------------------------------------------------------------.
	* | -     | -     | -     | -     | -     | -     | -     | -     | -     | -     | -     | -     | -     | -     | -     |
	* |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
	* | -     | -     | -     | -     | -     | -     | -     | -     | -     | -     | -     | -     | -     | -     | -     |
	* |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
	* | -     |BKLTTGL| BKLT-X| BKLT+ | BKLT- | PULSE | -     | -     | -     | -     | -     | -     |  -    | -     | -     |
	* |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
	* | -     | RGBTGL| RGB-  | RGB+  | HUE-  | HUE+  | SAT-  | SAT+  | RGBMD | RGBRMD| RAINBW| PLAIN | SWIRL | XMAS  | KNIGHT|
	* |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
	* | -     | -     | -     |  -    | QUERTY| LOWER | -     | -     | LOWER | -     | -     | -     | RGBTST| GRDINT| SNAKE |
	* '-----------------------------------------------------------------------------------------------------------------------'
	*/
 	[_RGB] = LAYOUT_ortho_5x15(
  	___, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, ___, \
  	XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, \
  	XXX, BL_TOGG, BL_STEP, BL_INC, BL_DEC, BL_BRTG, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, \
  	___, RGB_TOG, RGB_VAI, RGB_VAD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_MOD, RGB_RMOD, RGB_M_R, RGB_M_P, RGB_M_SW, RGB_M_X, RGB_M_K, \
  	___, ___, XXX, XXX, QUERTY, LOWER, ___, ___, LOWER, ___, XXX, XXX, RGB_M_T, RGB_M_G, RGB_M_SN \
	),
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}


LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_T) {
      // Re-open closed tab in browser. CTRL + SHIFT + T
      SEND_STRING(SS_LCTRL(SS_LSFT("t")));
    }
    SEQ_ONE_KEY(KC_W) {
      // Export for web in photoshop: LALT + SHIFT + CTRL + W
      SEND_STRING(SS_LALT(SS_LSFT(SS_LCTRL("w"))));
    }
    SEQ_TWO_KEYS(KC_5, KC_5) {
      // Hard refresh in browser. CTRL + F5
      SEND_STRING(SS_LCTRL(X_F5));
    }

  }
}


/* Detect layer change and change light */
uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case RAISE:
        rgblight_setrgb (0x00,  0x00, 0xFF);
        break;
    case LOWER:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
        rgblight_setrgb (0x00,  0xFF, 0x00);
        break;
    case RGB:
        rgblight_setrgb (0x7A,  0x00, 0xFF);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x00,  0xFF, 0xFF);
        break;
    }
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QW);
      }
      return false;
      break;
    case FUNCTION:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_FN);
      }
      return false;
      break;
    case RGB:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_RGB);
      }
      return false;
      break;

      case LOWER:
        if (record->event.pressed) {
          layer_on(_RGB);
          update_tri_layer(_FN, _RGB);
        } else {
          layer_off(_RGB);
          update_tri_layer(_FN, _RGB);
        }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_FN);
        update_tri_layer(_FN, _RGB);
      } else {
        layer_off(_FN);
        update_tri_layer(_FN, _RGB);
      }
      return false;
      break;
     }
  return true;
}


