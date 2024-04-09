// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌─────┬───┬───┬───┬─────┬─────┐  ┌─────┬─────┬───┬───┬───┬─────┐
     * │ ESC │ Q │ W │ F │  P  │  B  │  │  J  │  L  │ U │ Y │ ; │ CPS │
     * ├─────┼───┼───┼───┼─────┼─────┤  ├─────┼─────┼───┼───┼───┼─────┤
     * │ TAB │ A │ R │ S │  T  │  G  │  │  M  │  N  │ E │ I │ O │  '  │
     * ├─────┼───┼───┼───┼─────┼─────┤  ├─────┼─────┼───┼───┼───┼─────┤
     * │ CMD │ Z │ X │ C │  D  │  V  │  │  K  │  H  │ , │ . │ / │  \  │
     * ├─────┼───┼───┼───┼─────┼─────┤  ├─────┼─────┼───┼───┼───┼─────┤
     * │     │   │   │   │ SPC │ SFT │  │ BSP │ ENT │   │   │   │     │
     * └─────┴───┴───┴───┴─────┴─────┘  └─────┴─────┴───┴───┴───┴─────┘
     */
    [0] = LAYOUT_ortho_12x4(
        KC_ESC,       KC_Q,   KC_W,   KC_F,   KC_P,     KC_B,            KC_J,    KC_L,     KC_U,    KC_Y,   KC_SCLN, KC_CAPS,
        KC_TAB,       KC_A,   KC_R,   KC_S,   KC_T,     KC_G,            KC_M,    KC_N,     KC_E,    KC_I,   KC_O,    KC_QUOT,
        KC_LEFT_GUI,  KC_Z,   KC_X,   KC_C,   KC_D,     KC_V,            KC_K,    KC_H,     KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
        KC_NO,        KC_NO,  KC_NO,  KC_NO,  KC_SPACE, KC_LEFT_SHIFT,   KC_BSPC, KC_ENTER, KC_NO,   KC_NO,  KC_NO,   KC_NO
    )
};
