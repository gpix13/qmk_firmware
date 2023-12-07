#pragma once

// layer definitions
enum layers {
  _QWERTY,  // the default layer
  _LOWER,   // extra layer
  _RAISE,   // frequently used symbols
  _ADJUST,  // infrequently used symbols
};

// thumb key assignments
#define LOW_TAB  LT(_LOWER, KC_TAB)
#define BSP_RSE  LT(_RAISE, KC_BSPC)
#define SFT_ENT  LSFT_T(KC_ENT)

// home row mods
#define HR_A   LSFT_T(KC_A)
#define HR_S   LCTL_T(KC_S)
#define HR_D   LALT_T(KC_D)
#define HR_F   LGUI_T(KC_F)
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

