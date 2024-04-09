// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// custom send strings
enum custom_keycodes {
    WUP = SAFE_RANGE,
    WPWD,
    HPWD
};

// tap dance declarations
enum {
    LEFT_GUI_TOGGLE,
};

// tap dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [LEFT_GUI_TOGGLE] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_GUI, TG(1)),
};

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
        TD(LEFT_GUI_TOGGLE),  KC_Z,   KC_X,   KC_C,   KC_D,     KC_V,            KC_K,    KC_H,     KC_COMM, KC_DOT, KC_SLSH, MT(MOD_LALT, KC_BSLS),
        KC_NO,        KC_NO,  KC_NO,  KC_NO,  MT(MOD_LCTL, KC_SPACE), KC_LEFT_SHIFT,   LT(2, KC_BSPC), LT(3, KC_ENTER), KC_NO,   KC_NO,  KC_NO,   KC_NO
    ),
    [1] = LAYOUT_ortho_12x4(
        KC_TRANSPARENT,       KC_Q,   KC_W,   KC_E,   KC_R,     KC_T,            KC_Y,    KC_U,     KC_I,    KC_O,   KC_P,    KC_TRANSPARENT,
        KC_TRANSPARENT,       KC_A,   KC_S,   KC_D,   KC_F,     KC_G,            KC_H,    KC_J,     KC_K,    KC_L,   KC_SCLN, KC_TRANSPARENT,
        KC_TRANSPARENT,  KC_Z,   KC_X,   KC_C,   KC_V,     KC_B,            KC_N,    KC_M,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_NO,        KC_NO,  KC_NO,  KC_NO,  KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,   KC_NO,  KC_NO,   KC_NO
    ),
    [2] = LAYOUT_ortho_12x4(
        KC_GRAVE,       LSFT(KC_1),   LSFT(KC_2),   LSFT(KC_3),    LSFT(KC_LBRC),  LSFT(KC_RBRC),         KC_NUM, KC_P7,     KC_P8,    KC_P9,   KC_PMNS,    KC_DEL,
        LSFT(KC_6),     LSFT(KC_4),   LSFT(KC_5),   KC_EQUAL,      LSFT(KC_9),     LSFT(KC_0),            KC_PAST, KC_P4,     KC_P5,    KC_P6,   KC_PPLS, KC_PSLS,
        KC_TRANSPARENT, LSFT(KC_7),   LSFT(KC_8),   LSFT(KC_MINUS),KC_LBRC,        KC_RBRC,               KC_PDOT, KC_P1,     KC_P2,    KC_P3,   KC_P0, KC_PENT,
        KC_NO,          KC_NO,        KC_NO,        KC_NO,         KC_TRANSPARENT, KC_TRANSPARENT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,   KC_NO,  KC_NO,   KC_NO
    ),
    [3] = LAYOUT_ortho_12x4(
        QK_BOOT,        KC_F10,   KC_F9,   KC_F8,   KC_F7,          WUP,            KC_NO,    KC_HOME,     KC_UP,          KC_END,   KC_NO,   KC_NO,
        KC_NO,          KC_F11,   KC_F6,   KC_F5,   KC_F4,          WPWD,           KC_NO,    KC_LEFT,     KC_DOWN,        KC_RIGHT, KC_NO,   KC_NO,
        KC_LEFT_SHIFT,  KC_F12,   KC_F3,   KC_F2,   KC_F1,          HPWD,           KC_NO,    KC_PGUP,     KC_TRANSPARENT, KC_PGDN,  KC_NO,   KC_NO,
        KC_NO,          KC_NO,    KC_NO,   KC_NO,   KC_TRANSPARENT, KC_LEFT_GUI,    KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_NO,    KC_NO,   KC_NO
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WUP:
            if (record->event.pressed) {
                SEND_STRING("WAZZZUP!");
            }
            return false;
        case WPWD:
            if (record->event.pressed) {
                SEND_STRING("WAZZIPOWERED!");
            }
            return false;
        case HPWD:
            if (record->event.pressed) {
                SEND_STRING("YOUKNOWTHISISNTREALRIGHT?");
            }
            return false;
    }

    return true;
}
