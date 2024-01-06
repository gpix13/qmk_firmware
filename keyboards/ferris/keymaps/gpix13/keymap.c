#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"
#include "keycodes.h"

// layer definitions
enum layers {
  BASE,  // the default layer
  SYM,   // extra layer
  NAV,   // frequently used symbols
  FUNC,  // infrequently used symbols
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_split_3x5_2(
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
         HR_A,    HR_S,    HR_D,    HR_F,    KC_G,                         KC_H,    HR_J,    HR_K,    HR_L,   HR_SC,
         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
                                          TAB_SYM, SFT_ENT,     KC_SPC, BSP_NAV
  ),
  [SYM] = LAYOUT_split_3x5_2(
      KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_PLUS, KC_TILD,  KC_GRV, XXXXXXX,
                                          _______, _______,    _______, _______
  ),
  [NAV] = LAYOUT_split_3x5_2(
       KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_PGUP, KC_PGDN,    HOME,     END,
      _______, _______, _______, _______, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                          _______, _______,    _______, _______
  ),
  [FUNC] = LAYOUT_split_3x5_2(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
      XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT,                      XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                          XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
  ),
};

// Set tapping term for specific keys based on my typing style
// (this is trial and error..)
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BSP_NAV:
        case SFT_ENT:
        case TAB_SYM:
            return 150;
        case HR_A:
        case HR_S:
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}

// Enable NUM layer when holding down SYM and NAV layer keys
layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, SYM, NAV, FUNC);
}

