// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "atreus62.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEFAULT 0
#define SYMB 1
#define MED 2
#define NUM 3
#define _CP LCTL(KC_INS)
#define _PST LSFT(KC_INS)
#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DEFAULT] = {
		{ KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC },
		{ KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL  },
		{ KC_HOME, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_PGUP },
		{ KC_END,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_PGDN },
		{ _______, KC_LCTL, _______, KC_LCTL, KC_LALT, KC_LSFT, KC_SPC,  MO(SYMB),MO(NUM), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT }
},

[SYMB] = { 
		{ _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11  },
		{ _______, KC_TILD, KC_GRV,  KC_LPRN, KC_RPRN, KC_TAB,  _______, KC_BSPC, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_F12  },
		{ _______, KC_PLUS, KC_EQL,  KC_UNDS, KC_MINS, KC_ESC,  _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PIPE, _______ },
		{ _______, _______, _______, KC_DQT,  KC_QUOT, KC_DEL,  _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BSLS, _______ },
		{ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
},

[NUM] = { 
		{ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
		{ _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_VOLU },
		{ _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_VOLD },
		{ _______, _______, _______, _CP,     _PST,    _______, _______, _______, KC_PLUS, KC_EQL,  KC_SLSH, KC_ASTR, KC_MPLY },
		{ _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT }
}

};



const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	// MACRODOWN only works in this function
	switch (id) {
	case 0:
		if (record->event.pressed) {
			register_code(KC_RSFT);
		}
		else {
			unregister_code(KC_RSFT);
		}
		break;
	}
	return MACRO_NONE;
};
