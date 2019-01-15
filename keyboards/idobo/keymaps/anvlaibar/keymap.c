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
#include "action_layer.h"
#include "quantum.h"
#include "send_string_keycodes.h"
#include "eeconfig.h"

// Aliases
#define ___ KC_TRNS
#define XXX KC_NO
#define ALT_TAB LALT(KC_TAB)
#define TAB MT(ALT_TAB,KC_TAB)

// Layers
#define _QW 0
#define _FN 1
#define _RGB 2


// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FUNCTION,
  RGB,
  LOREM,
  M_LDAQ,
  M_RDAQ
};

//Tap Dance Declarations
enum {
  TD_ESC = 0
};

void esc_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LCTL);
    register_code (KC_LALT);
    register_code (KC_ESC);
  } else {
    register_code (KC_ESC);
  }
}
void esc_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_LCTL);
    unregister_code (KC_LALT);
    unregister_code (KC_ESC);
  } else {
    unregister_code (KC_ESC);
  }
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for CTRL + SHIFT + ESC (Task manager)
  [TD_ESC]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, esc_finished, esc_reset)
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* QWERTY-Win Norwegian - LAYER 0
  * ╭───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────╮
  * │ ESC   │ 1     │ 2     │ 3     │ 4     │ 5     │ 6     │ 7     │ 8     │ 9     │ 0     │ +     │ \     │ ~     │ BKSP  │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │ TAB   │ Q     │ W     │ E     │ R     │ T     │ Y     │ U     │ I     │ O     │ P     │ Å     │ ¨     │ {     │ }     │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │ |     │ A     │ S     │ D     │ F     │ G     │ H     │ J     │ K     │ L     │ Ø     │ Æ     │ '     │ (     │ ENTER │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │ SHIFT │ <     │ Z     │ X     │ C     │ V     │ B     │ N     │ M     │ ,     │ .     │ -     │ ;     │ UP    │ DEL   │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │ CTRL  │ GUI   │ HYPER │ /     │ ALT   │ LOWER │ SPACE │ SPACE │ RAISE │ ALTGR │ FN    │ &     │ LEFT  │ DOWN  │ RIGHT │
  * ╰───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────╯
  */
 [_QW] = LAYOUT_ortho_5x15( \
    TD_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, NO_PLUS, NO_BSLS, KC_TILD, KC_BSPC, \
    TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, NO_AA, NO_QUOT, KC_LBRC, KC_RBRC, \
    NO_PIPE, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, NO_OSLH, NO_AE, NO_ASTR, KC_RSPC, KC_ENT, \
    KC_LSPO, NO_LESS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_MINS, KC_SCOLON, KC_UP, KC_DEL, \
    KC_LCTL, KC_LGUI, KC_HYPR, KC_PSLS, KC_LALT, LOWER, KC_SPC, XXX, RAISE, KC_RALT, MO(_FN), KC_AMPR, KC_LEFT, KC_DOWN, KC_RGHT \
  ),

 /* Function & Media keys - LAYER 1
	* ╭───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────╮
	* │ -     │ F1    │ F2    │ F3    │ F4    │ F5    │ F6    │ F7    │ F8    │ F9    │ F10   │ F11   │ F12   │ F13   │ -     │
	* ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
	* │ LEADR │ ⏯     │ ⏹     │ ⏮    │ ⏭    │ 🔈     │ 🔉     │ 🔊    │ -     │ PRTSCR│ SCRLK │ PAUSE │ INS   │ -     │ CALC  │
	* ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
	* │ KEYLK │ -     │ -     │ -     │ -     │ -     │ -     │ LOREM │ -     │ -     │ -     │ -     │ «     │ »     │ -     │
	* ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
	* │ -     │ -     │ -     │ -     │ -     │ -     │ -     │ -     │ -     │ -     │ -     │ -     │ -     │ PGUP  │ -     │
	* ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
	* │ RESET │ -     │ -     │  -    │ QWERTY│ LOWER │ -     │ -     │ RAISE │ RGB   │ FN    │ -     │ HOME  │ PG DN │ END   │
	* ╰───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────╯
	*/
 	[_FN] = LAYOUT_ortho_5x15( \
  	___, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_F13, ___, \
  	KC_LEAD, KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, XXX, KC_PSCR, KC_SLCK, KC_PAUS, KC_INS, XXX, KC_CALC, \
  	KC_LOCK, XXX, XXX, XXX, XXX, XXX, XXX, XXX, LOREM, XXX, XXX, XXX, M_LDAQ, M_RDAQ, ___, \
  	___, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, KC_PGUP, ___, \
  	RESET, ___, ___, XXX, QWERTY, LOWER, ___, ___, RAISE, RGB, MO(_RGB), XXX, KC_HOME, KC_PGDN, KC_END \
	),

 /* RGB-controls - LAYER 2
	* ╭───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────╮
	* │ -     │ -     │ -     │ -     │ -     │ -     │ -     │ -     │ -     │ -     │ -     │ -     │ -     │ -     │ -     │
	* ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
	* │ -     │ -     │ -     │ -     │ -     │ -     │ -     │ -     │ -     │ -     │ -     │ -     │ -     │ -     │ -     │
	* ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
	* │ -     │BKLTTGL│ BKLT+-│ BKLT+ │ BKLT- │ BKLTMX│ PULSE │ -     │ -     │ -     │ -     │ -     │  -    │ -     │ -     │
	* ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
	* │ -     │ RGBTGL│ RGB+  │ RGB-  │ HUE+  │ HUE-  │ SAT+  │ SAT-  │ RGBMD │ RGBRMD│ RAINBW│ PLAIN │ SWIRL │ XMAS  │ KNIGHT│
	* ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
	* │ -     │ -     │ -     │  -    │ QWERTY│ LOWER │ -     │ -     │ RAISE │ -     │ -     │ -     │ RGBTST│ GRDINT│ SNAKE │
	* ╰───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────╯
	*/
 	[_RGB] = LAYOUT_ortho_5x15( \
  	___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, XXX, XXX, XXX, ___, \
  	___, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, XXX, \
  	___, BL_TOGG, BL_STEP, BL_INC, BL_DEC, BL_ON, BL_BRTG, XXX, XXX, XXX, XXX, XXX, XXX, XXX, ___, \
  	___, RGB_TOG, RGB_VAI, RGB_VAD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_MOD, RGB_RMOD, RGB_M_R, RGB_M_P, RGB_M_SW, RGB_M_X, RGB_M_K, \
  	___, ___, XXX, XXX, QWERTY, LOWER, ___, ___, RAISE, ___, XXX, XXX, RGB_M_T, RGB_M_G, RGB_M_SN \
	)
};

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
      SEND_STRING(SS_LCTRL(SS_TAP(X_F5)));
    }
    SEQ_TWO_KEYS(KC_V, KC_V) {
      // Linux paste. CTRL + SHIFT + V
      SEND_STRING(SS_LCTRL(SS_LSFT("v")));
    }
    SEQ_THREE_KEYS(KC_C,KC_M,KC_D) {
      // Open cmd
      SEND_STRING(SS_LGUI("r"));
      _delay_ms(500);
      SEND_STRING("cmd" SS_TAP(X_ENTER));
    }

  }
}

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case _QW:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QW);
      }
      return false;
      break;
    case _FN:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_FN);
      }
      return false;
      break;
    case _RGB:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_RGB);
      }
      return false;
      break;

      case LOWER:
        if (record->event.pressed) {
          layer_on(_RGB);
          update_tri_layer(_QW, _FN, _RGB);
        } else {
          layer_off(_RGB);
          update_tri_layer(_QW, _FN, _RGB);
        }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_FN);
        update_tri_layer(_QW, _FN, _RGB);
      } else {
        layer_off(_FN);
        update_tri_layer(_QW, _FN, _RGB);
      }
      return false;
      break;

      // Prints a paragraph of Lorem Ipsum
      case LOREM:
      if (record->event.pressed) {
        SEND_STRING("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Maecenas sapien lorem, volutpat ac finibus a, luctus ut sapien. Vestibulum id rutrum purus, vitae fermentum purus. Mauris egestas eleifend erat commodo luctus. Nam blandit tincidunt egestas. Suspendisse sed purus sit amet turpis sagittis vulputate. Fusce elementum venenatis ipsum eget aliquet. Sed dictum tellus ut orci varius pharetra. Etiam nec nunc sed elit tincidunt faucibus. Phasellus pretium nulla eget tempor facilisis.");
      } else {

      }
      return false;
      break;

      case M_LDAQ:
        if (record->event.pressed) {
          SEND_STRING("«");
        }
      return false;
      break;

      case M_RDAQ:
        if (record->event.pressed) {
          SEND_STRING("»");
        }
      return false;
      break;



     }
  return true;
}

/* Detect layer change and change light */
uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    case _FN:
        rgblight_setrgb (0x00,  0x00, 0xFF);
        break;
    case _RGB:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x00,  0xFF, 0xFF);
        break;
    }
  return state;
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    return MACRO_NONE;
};


