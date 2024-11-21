// keymap.c
#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_split_3x5_2(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    HR_S,    HR_D,    HR_F,    KC_G,         KC_H,    HR_J,    HR_K,    HR_L, KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
                            LOW_TAB, KC_LSFT,         KC_SPC, BSP_RSE
  ),

  [_LOWER] = LAYOUT_split_3x5_2(
    KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,        KC_PLUS,    KC_7,    KC_8,    KC_9, KC_TILD,
    KC_PIPE,  KC_GRV, _______, KC_COLN,  KC_EQL,        KC_MINS,    KC_4,    KC_5,    KC_6, _______,
    KC_BSLS, _______, KC_ASTR, KC_AMPR, KC_CIRC,        KC_UNDS,    KC_1,    KC_2,    KC_3, _______,
                               _______, _______,        _______,    KC_0
  ),

  [_RAISE] = LAYOUT_split_3x5_2(
    KC_ESC,  _______, _______, _______, KC_MPLY,        _______, KC_PGDN, KC_PGUP,    HOME,     END,
    _______, _______, _______, KC_MNXT, KC_VOLU,        KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,
    _______, _______, _______, KC_MPRV, KC_VOLD,        _______, SCREEN4, SCREEN5, _______, _______,
                               _______, _______,        _______, _______
  ),

  [_ADJUST] = LAYOUT_split_3x5_2(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
    xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,        xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
    xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, QK_BOOT,        xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
                               xxxxxxx, xxxxxxx,        xxxxxxx, xxxxxxx
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
        case LOW_TAB:
            return 140;
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SAVE_VIM:
            if (record->event.pressed) {
                tap_code(KC_ESC);
                tap_code16(KC_COLN);
                tap_code(KC_W);
                tap_code(KC_ENT);
            }
            return false;
        case VIM_VS:
            if (record->event.pressed) {
                tap_code16(C(KC_W));
                tap_code(KC_V);
            }
            return false;
        case VIM_SP:
            if (record->event.pressed) {
                tap_code16(C(KC_W));
                tap_code(KC_S);
            }
            return false;
        case CLOSE_WIN:
            if (record->event.pressed) {
                tap_code16(C(KC_W));
                tap_code(KC_Q);
            }
            return false;
        default:
            return true;
    }
}
