// keymap.c
#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "g/keymap_combo.h"

// layer definitions
enum layers {
    _QWERTY,  // the default layer
    _LOWER,   // extra layer
    _RAISE,   // frequently used symbols
    _ADJUST,  // infrequently used symbols
};

// Tap Dance definitions
enum {
    DANCE_1,
    DANCE_2,
};

// miscellaneous shortcuts
#define xxxxxxx XXXXXXX

// thumb key assignments
#define LOW_TAB  LT(_LOWER, KC_TAB)
#define BSP_RSE  LT(_RAISE, KC_BSPC)
#define SFT_ENT  LSFT_T(KC_ENT)

// Home Row Mods
// left hand
#define HR_A   LSFT_T(KC_A)
#define HR_S   LCTL_T(KC_S)
#define HR_D   LALT_T(KC_D)
#define HR_F   LGUI_T(KC_F)
// right hand
#define HR_J   LGUI_T(KC_J)
#define HR_K   LALT_T(KC_K)
#define HR_L   LCTL_T(KC_L)
#define HR_SC  LSFT_T(KC_SCLN)

// Tap Dance
// ---------------------------
// tap: Q, hold: COPY
#define TD_Q   TD(DANCE_1)
// tap: W, hold: PASTE
#define TD_W   TD(DANCE_2)

// shortcuts
#define HOME     G(KC_LEFT)
#define END      G(KC_RIGHT)
#define COPY     G(KC_C)
#define PASTE    G(KC_V)

// oneshots
#define OSALT    OSM(MOD_LALT)
#define OSCTL    OSM(MOD_LCTL)
#define OSGUI    OSM(MOD_LGUI)
#define OSSFT    OSM(MOD_LSFT)
#define SCREEN4  G(S(KC_4))
#define SCREEN5  G(S(KC_5))
#define DIVVY    G(KC_E)
#define ONEPASS  G(KC_NONE)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         HR_A,    HR_S,    HR_D,    HR_F,    KC_G,                         KC_H,    HR_J,    HR_K,    HR_L,   HR_SC,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
                                 LOW_TAB, SFT_ENT,                       KC_SPC, BSP_RSE
                             //`-----------------'                    `-----------------'
  ),

  [_LOWER] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_PLUS,    KC_7,    KC_8,    KC_9, KC_TILD,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_PIPE,  KC_GRV, _______, _______,  KC_EQL,                      KC_MINS,    KC_4,    KC_5,    KC_6, _______,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_BSLS, _______, KC_CIRC, KC_AMPR, KC_ASTR,                      KC_UNDS,    KC_1,    KC_2,    KC_3, _______,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
                                 _______, _______,                      _______,    KC_0
                             //`-----------------'                    `-----------------'
  ),

  [_RAISE] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
       KC_ESC, _______, _______, _______, KC_MPLY,                      _______, KC_PGUP, KC_PGDN,    HOME,     END,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _______, _______, _______, _______, KC_VOLU,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _______, _______, _______, _______, KC_VOLD,                      _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
                                 _______, _______,                      _______, _______
                             //`-----------------'                    `-----------------'
  ),

  [_ADJUST] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, QK_BOOT,                      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
                                 xxxxxxx, xxxxxxx,                      xxxxxxx, xxxxxxx
                             //`-----------------'                    `-----------------'
  ),

};

// Enable ADJUST layer when holding down LOWER and RAISE keys
layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// Set tapping term for specific keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BSP_RSE:
        case SFT_ENT:
        case LOW_TAB:
            return 150;
        case HR_A:
        case HR_S:
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}

// -----------------------------------------------------------------------------
//                               TAP DANCE
// -----------------------------------------------------------------------------
/*
extern bool g_suspend_state;
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF
uint16_t last_keycode = KC_NO;
uint8_t last_modifier = 0;

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state = {
    .is_press_action = true,
    .step = 0
};

void on_dance_1(tap_dance_state_t *state, void *user_data);
uint8_t dance_1_dance_step(tap_dance_state_t *state);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
	if(state->count == 3) {
		tap_code16(KC_Q);
		tap_code16(KC_Q);
		tap_code16(KC_Q);
	}
	if(state->count > 3) {
		tap_code16(KC_Q);
	}
}

uint8_t dance_1_dance_step(tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) return SINGLE_TAP;
		else return SINGLE_HOLD;
	} else if (state->count == 2) {
		if (state->interrupted) return DOUBLE_SINGLE_TAP;
		else if (state->pressed) return DOUBLE_HOLD;
		else return DOUBLE_TAP;
	}
	return MORE_TAPS;
}
void dance_1_finished(tap_dance_state_t *state, void *user_data) {
	dance_state.step = dance_1_dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_Q); break;
		case SINGLE_HOLD: register_code16(COPY); break;
		case DOUBLE_TAP: register_code16(KC_Q); register_code16(KC_Q); break;
		case DOUBLE_SINGLE_TAP: tap_code16(KC_Q); register_code16(KC_Q);
	}
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_Q); break;
		case SINGLE_HOLD: unregister_code16(COPY); break;
		case DOUBLE_TAP: unregister_code16(KC_Q); break;
		case DOUBLE_SINGLE_TAP: unregister_code16(PASTE); break;
	}
	dance_state.step = 0;
}

void on_dance_2(tap_dance_state_t *state, void *user_data);
uint8_t dance_2_dance_step(tap_dance_state_t *state);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
	if(state->count == 3) {
		tap_code16(KC_W);
		tap_code16(KC_W);
		tap_code16(KC_W);
	}
	if(state->count > 3) {
		tap_code16(KC_W);
	}
}

uint8_t dance_2_dance_step(tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) return SINGLE_TAP;
		else return SINGLE_HOLD;
	} else if (state->count == 2) {
		if (state->interrupted) return DOUBLE_SINGLE_TAP;
		else if (state->pressed) return DOUBLE_HOLD;
		else return DOUBLE_TAP;
	}
	return MORE_TAPS;
}
void dance_2_finished(tap_dance_state_t *state, void *user_data) {
	dance_state.step = dance_2_dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_W); break;
		case SINGLE_HOLD: register_code16(PASTE); break;
		case DOUBLE_TAP: register_code16(KC_W); register_code16(KC_W); break;
		case DOUBLE_SINGLE_TAP: tap_code16(KC_W); register_code16(KC_W);
	}
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_W); break;
		case SINGLE_HOLD: unregister_code16(PASTE); break;
		case DOUBLE_TAP: unregister_code16(KC_W); break;
		case DOUBLE_SINGLE_TAP: unregister_code16(PASTE); break;
	}
	dance_state.step = 0;
}


tap_dance_action_t tap_dance_actions[] = {
    [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
    [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
};

*/
