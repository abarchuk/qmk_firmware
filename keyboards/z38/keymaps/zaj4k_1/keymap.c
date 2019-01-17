/* Copyright 2017 REPLACE_WITH_YOUR_NAME
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

extern keymap_config_t keymap_config;

#include "z38.h"

#define _QWERTY 0
#define _RAISE 1
#define _LOWER 2
#define _ADJUST 16
#define _CP LCTL(KC_INS)
#define _PST LSFT(KC_INS)
#define _______ KC_TRNS

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = {
    { KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    },
    { KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN },
    { KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LSFT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH },
    { _______, _______, _______, KC_LALT, MO(_LOWER),KC_SPC,MO(_RAISE),KC_LCTL,_______,_______, _______ }
},

[_RAISE] = { 
    { KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0    },
    { KC_TAB,  KC_BSLS, KC_EQL,  KC_MINS, KC_ESC,  _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT  },
    { _______, KC_GRV,  KC_LBRC, KC_RBRC, _______, _______, _______, KC_QUOT, _______, _______, KC_DEL  },
    { _______, _______, _______, _______, _______, KC_BSPC, _______, _______, _______, _______, _______ }
},

[_LOWER] = {
    { KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN },
    { KC_TAB,  KC_PIPE, KC_PLUS, KC_UNDS, KC_ESC,  _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_COLN },
    { _______, KC_TILD, KC_LCBR, KC_RCBR, _______, _______, _______, KC_DQT,  KC_LT,   KC_GT,   KC_QUES },
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
},

[_ADJUST] = {
    { KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10  },
    { _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_F11  },
    { _______, _______, _CP,     _PST,    _______, _______, _______, KC_MPLY, _______, _______, KC_F12  },
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
}

};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
