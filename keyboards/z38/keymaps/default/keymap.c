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
#include "z38.h"

#define _DEFAULT 0
#define _RAISE 1
#define _LOWER 2
#define MED 3
#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DEFAULT] = {
    { KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, KC_Y,      KC_U,      KC_I,    KC_O,    KC_P    },
    { KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, KC_H,      KC_J,      KC_K,    KC_L,    KC_SCLN },
    { KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT,  KC_N,      KC_M,      KC_COMM, KC_DOT,  RCTL_T(KC_SLSH) },
    { _______, _______, KC_LCTL, KC_LALT, KC_LSFT, KC_SPC,  MO(_RAISE),MO(_LOWER),MO(MED), _______, _______ }
},

[_RAISE] = { 
    { KC_GRV,  KC_TILD, KC_LPRN, KC_RPRN, KC_TAB,  _______, KC_BSPC, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC },
    { KC_PLUS, KC_EQL,  KC_UNDS, KC_MINS, KC_ESC,  _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PIPE },
    { _______, _______, KC_DQT,  KC_QUOT, KC_DEL,  _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BSLS },
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
},

[_LOWER] = {
    { KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0    },
    { KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN },
    { _______, _______, _______, _______, _______, _______, _______, KC_PLUS, KC_EQL,  KC_SLSH, KC_ASTR },
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
},

[MED] = {
    { KC_F1,   KC_F2,       KC_F3,   KC_F4,       KC_F5,   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10  },
    { _______, _______,     _______, _______,     _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_F11  },
    { _______, _______,LCTL(KC_INS), LSFT(KC_INS),_______, _______, _______, KC_MPLY, _______, _______, KC_F12  },
    { _______, _______,     _______, _______,     _______, KC_MPLY, _______, _______, _______, _______, _______ }
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
