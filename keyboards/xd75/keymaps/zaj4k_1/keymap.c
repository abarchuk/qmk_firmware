/* Copyright 2017 Wunder
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
#include "xd75.h"

// Layer shorthand
#define _QW 0
#define _FN 1
#define _CP LCTL(KC_INS)
#define _PST LSFT(KC_INS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_QW] = {
  { KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_ESC,  KC_GRV,  KC_MINS, KC_EQL,  KC_BSPC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0     },
  { KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_TAB,  KC_INS,  KC_LBRC, KC_RBRC, KC_DEL,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P     },
  { KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _CP,     KC_VOLU, KC_MPLY, KC_HOME, KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN  },
  { KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _PST,    KC_VOLD, KC_UP,   KC_END,  KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH  },
  { KC_LCTL, KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT, KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,  MO(_FN), KC_RCTL, KC_SLSH, KC_ASTR, KC_RSFT  },
 },

 
 [_FN] = {
  { KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS, KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10   },
  { KC_GRV,  KC_TILD, KC_LPRN, KC_RPRN, KC_TAB,  KC_TRNS, RGB_HUD, RGB_HUI, KC_TRNS, KC_TRNS, KC_BSPC, KC_LCBR, KC_RCBR, KC_PIPE, KC_BSLS  },
  { KC_PLUS, KC_EQL,  KC_UNDS, KC_MINS, KC_ESC,  KC_TRNS, RGB_SAD, RGB_SAI, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS  },
  { KC_TRNS, KC_TRNS, KC_DQT,  KC_QUOT, KC_ENT,  KC_TRNS, RGB_VAD, RGB_VAI, KC_TRNS, KC_TRNS, KC_DEL,  KC_LBRC, KC_RBRC, KC_SLSH, KC_ASTR  },
  { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_RMOD,RGB_MOD, RGB_TOG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET    },
 }

};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
