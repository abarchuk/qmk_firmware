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
#include "z52.h"

#define _DEFAULT 0
#define SYMB 1
#define NUM 2
#define _CP LCTL(KC_INS)
#define _PST LSFT(KC_INS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DEFAULT] = {
    { KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0    },
    { KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_BSPC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    },
    { KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_ENT,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN },
    { KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ESC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH },
    { KC_TRNS, KC_TAB,  KC_LCTL, KC_LALT, KC_LSFT, KC_SPC,  MO(SYMB),MO(NUM), KC_LGUI, KC_DEL,  KC_TRNS }
},

[SYMB] = { 
    { _CP,     _PST,    KC_VOLD, KC_VOLU, KC_MPLY, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL  },
    { KC_GRV,  KC_TILD, KC_LPRN, KC_RPRN, KC_TAB,  KC_TRNS, KC_BSPC, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC },
    { KC_PLUS, KC_EQL,  KC_UNDS, KC_MINS, KC_ESC,  KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PIPE },
    { KC_TRNS, KC_TRNS, KC_DQT,  KC_QUOT, KC_DEL,  KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BSLS },
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
},

[NUM] = {
    { KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10  },
    { KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0    },
    { KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_F11,  KC_F12  },
    { KC_TRNS, KC_TRNS, _CP,     _PST,    KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
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
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
