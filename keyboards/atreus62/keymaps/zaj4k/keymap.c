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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DEFAULT] = {
		{ KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS, KC_6,    KC_7,    KC_8,        KC_9,    KC_0,    KC_BSPC },
		{ KC_TRNS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_TRNS, KC_Y,    KC_U,    KC_I,        KC_O,    KC_P,    KC_TRNS },
		{ KC_TRNS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TRNS, KC_H,    KC_J,    KC_K,        KC_L,    KC_SCLN, KC_TRNS },
		{ KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT,  KC_N,    KC_M,    KC_COMM,     KC_DOT,  KC_SLSH, KC_TRNS },
		{ KC_TRNS, KC_TRNS ,KC_TAB,  MO(MED), KC_LALT, KC_LSFT, KC_SPC,  MO(SYMB),KC_RCTL, LSFT(KC_INS),KC_DEL,  KC_TRNS, KC_TRNS }
},

[SYMB] = { 
		{ KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS, KC_F6,   KC_F7,   KC_F8,       KC_F9,   KC_F10,  KC_TRNS },
		{ KC_TRNS, KC_GRV,  KC_PIPE, KC_LPRN, KC_RPRN, KC_TAB,  KC_TRNS, KC_BSPC, KC_PGUP, KC_HOME,     KC_F11,  KC_F12,  KC_TRNS },
		{ KC_TRNS, KC_PLUS, KC_EQL,  KC_UNDS, KC_MINS, KC_ESC,  KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,       KC_RGHT, KC_BSLS, KC_TRNS },
		{ KC_TRNS, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_GRV,  KC_TRNS, KC_DEL,  KC_PGDN, KC_END,      KC_DQT,  KC_QUOT, KC_TRNS },
		{ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_INS),KC_TRNS, KC_TRNS, KC_TRNS }
},

[MED] = {
		{ KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS, KC_TRNS, KC_TRNS,     KC_VOLU, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS, KC_TRNS, KC_MPRV,     KC_MPLY, KC_MNXT,     KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS },
		{ KC_TRNS, KC_TRNS, LCTL(KC_INS),KC_VOLD, LSFT(KC_INS),KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS }
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
