#pragma once

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    // Direct dead keys ~`^
    TILD = QK_USER,
    GRV,
    CIRC,

    // Vim
    SAVE_VIM,
    VIM_VS,
    VIM_SP,
};

// Home Row Mods
#define HR_S   LCTL_T(KC_S)
#define HR_D   LALT_T(KC_D)
#define HR_F   LGUI_T(KC_F)
#define HR_J   LGUI_T(KC_J)
#define HR_K   LALT_T(KC_K)
#define HR_L   LCTL_T(KC_L)

// thumbs
#define LOW_TAB  LT(_LOWER, KC_TAB)
#define BSP_RSE  LT(_RAISE, KC_BSPC)

// misc
#define xxxxxxx KC_NO
#define SCREEN4  G(S(KC_4))
#define SCREEN5  G(S(KC_5))
#define HOME     G(KC_LEFT)
#define END      G(KC_RIGHT)
