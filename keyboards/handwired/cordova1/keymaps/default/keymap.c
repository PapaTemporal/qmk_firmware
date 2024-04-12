// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// custom send strings
enum custom_keycodes {
    CUST1 = SAFE_RANGE,
    CUST2,
    CUST3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * COLEMAK-DH
     * ┌─────┬───┬───┬───┬─────┬─────┐  ┌─────┬─────┬───┬───┬───┬─────┐
     * │ ESC │ Q │ W │ F │  P  │  B  │  │  J  │  L  │ U │ Y │ ; │ DEL │
     * ├─────┼───┼───┼───┼─────┼─────┤  ├─────┼─────┼───┼───┼───┼─────┤
     * │ TAB │ A │ R │ S │  T  │  G  │  │  M  │  N  │ E │ I │ O │  '  │
     * ├─────┼───┼───┼───┼─────┼─────┤  ├─────┼─────┼───┼───┼───┼─────┤
     * │ CMD │ Z │ X │ C │  D  │  V  │  │  K  │  H  │ , │ . │ / │  \  │
     * │     │   │   │   │     │     │  │     │     │   │   │   │ ALT │
     * ├─────┼───┼───┼───┼─────┼─────┤  ├─────┼─────┼───┼───┼───┼─────┤
     * │     │   │   │   │ SPC │ SFT │  │ BSP │ ENT │   │   │   │     │
     * │     │   │   │   │ CTL │     │  │ L2  │ L3  │   │   │   │     │
     * └─────┴───┴───┴───┴─────┴─────┘  └─────┴─────┴───┴───┴───┴─────┘
     */
    [0] = LAYOUT_ortho_12x4(
        KC_ESC,       KC_Q,   KC_W,   KC_F,   KC_P,     KC_B,            KC_J,    KC_L,     KC_U,    KC_Y,   KC_SCLN, KC_DEL,
        KC_TAB,       KC_A,   KC_R,   KC_S,   KC_T,     KC_G,            KC_M,    KC_N,     KC_E,    KC_I,   KC_O,    KC_QUOT,
        KC_LEFT_GUI,  KC_Z,   KC_X,   KC_C,   KC_D,     KC_V,            KC_K,    KC_H,     KC_COMM, KC_DOT, KC_SLSH, MT(MOD_LALT, KC_BSLS),
        KC_NO,        KC_NO,  KC_NO,  KC_NO,  MT(MOD_LCTL, KC_SPACE), KC_LEFT_SHIFT,   LT(2, KC_BSPC), LT(3, KC_ENTER), KC_NO,   KC_NO,  KC_NO,   KC_NO
    ),
    /*
     * QWERTY
     * ┌─────┬───┬───┬───┬─────┬─────┐  ┌─────┬─────┬───┬───┬───┬─────┐
     * │ ESC │ Q │ W │ E │  R  │  T  │  │  Y  │  U  │ I │ O │ P │ DEL │
     * ├─────┼───┼───┼───┼─────┼─────┤  ├─────┼─────┼───┼───┼───┼─────┤
     * │ TAB │ A │ S │ D │  F  │  G  │  │  H  │  J  │ K │ L │ ; │  '  │
     * ├─────┼───┼───┼───┼─────┼─────┤  ├─────┼─────┼───┼───┼───┼─────┤
     * │ CMD │ Z │ X │ C │  V  │  B  │  │  N  │  M  │ , │ . │ / │  \  │
     * │     │   │   │   │     │     │  │     │     │   │   │   │ ALT │
     * ├─────┼───┼───┼───┼─────┼─────┤  ├─────┼─────┼───┼───┼───┼─────┤
     * │     │   │   │   │ SPC │ SFT │  │ BSP │ ENT │   │   │   │     │
     * │     │   │   │   │ CTL │     │  │ L2  │ L3  │   │   │   │     │
     * └─────┴───┴───┴───┴─────┴─────┘  └─────┴─────┴───┴───┴───┴─────┘
     */
    [1] = LAYOUT_ortho_12x4(
        KC_TRANSPARENT,       KC_Q,   KC_W,   KC_E,   KC_R,     KC_T,            KC_Y,    KC_U,     KC_I,    KC_O,   KC_P,    KC_TRANSPARENT,
        KC_TRANSPARENT,       KC_A,   KC_S,   KC_D,   KC_F,     KC_G,            KC_H,    KC_J,     KC_K,    KC_L,   KC_SCLN, KC_TRANSPARENT,
        KC_TRANSPARENT,  KC_Z,   KC_X,   KC_C,   KC_V,     KC_B,            KC_N,    KC_M,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_NO,        KC_NO,  KC_NO,  KC_NO,  KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,   KC_NO,  KC_NO,   KC_NO
    ),
    /*
     * NUMBERS & SYMBOLS
     * ┌───┬───┬───┬───┬─────┬───┐  ┌─────┬───┬───┬───┬───┬─────┐
     * │ ` │ ! │ @ │ # │  {  │ } │  │ NUM │ 7 │ 8 │ 9 │ * │ CPS │
     * ├───┼───┼───┼───┼─────┼───┤  ├─────┼───┼───┼───┼───┼─────┤
     * │ ^ │ $ │ & │ _ │  (  │ ) │  │  -  │ 4 │ 5 │ 6 │ 0 │  /  │
     * ├───┼───┼───┼───┼─────┼───┤  ├─────┼───┼───┼───┼───┼─────┤
     * │ ~ │ % │ * │ - │  [  │ ] │  │  +  │ 1 │ 2 │ 3 │ . │ ENT │
     * ├───┼───┼───┼───┼─────┼───┤  ├─────┼───┼───┼───┼───┼─────┤
     * │   │   │   │   │ SPC │ = │  │     │   │   │   │   │     │
     * └───┴───┴───┴───┴─────┴───┘  └─────┴───┴───┴───┴───┴─────┘
     */
    [2] = LAYOUT_ortho_12x4(
        KC_GRAVE,       LSFT(KC_1),   LSFT(KC_2),   LSFT(KC_3),     LSFT(KC_LBRC),  LSFT(KC_RBRC),   KC_NUM,          KC_P7,    KC_P8,    KC_P9,   KC_PAST,  KC_CAPS,
        LSFT(KC_6),     LSFT(KC_4),   LSFT(KC_7),   LSFT(KC_MINUS), LSFT(KC_9),     LSFT(KC_0),      KC_PMNS,         KC_P4,    KC_P5,    KC_P6,   KC_P0,    KC_PSLS,
        LSFT(KC_GRAVE), LSFT(KC_5),   LSFT(KC_8),   KC_MINUS,       KC_LBRC,        KC_RBRC,         KC_PPLS,         KC_P1,    KC_P2,    KC_P3,   KC_PDOT,  KC_PENT,
        KC_NO,          KC_NO,        KC_NO,        KC_NO,          KC_SPACE,       KC_NO,           KC_TRANSPARENT,  KC_NO,    KC_NO,    KC_NO,   KC_NO,    KC_NO
    ),
    /*
     * NAVIGATION & FUNCTION KEYS
     * ┌──────┬─────┬────┬────┬─────┬──────┐  ┌───┬──────┬────┬──────┬───┬────┐
     * │ BOOT │ F10 │ F9 │ F8 │ F7  │ CUST │  │   │ HOME │ UP │ END  │   │ L4 │
     * ├──────┼─────┼────┼────┼─────┼──────┤  ├───┼──────┼────┼──────┼───┼────┤
     * │      │ F11 │ F6 │ F5 │ F4  │ CUST │  │   │ LEFT │ DN │ RGT  │   │ L1 │
     * ├──────┼─────┼────┼────┼─────┼──────┤  ├───┼──────┼────┼──────┼───┼────┤
     * │      │ F12 │ F3 │ F2 │ F1  │ CUST │  │   │ PGUP │ ,  │ PGDN │   │    │
     * ├──────┼─────┼────┼────┼─────┼──────┤  ├───┼──────┼────┼──────┼───┼────┤
     * │      │     │    │    │ CTL │ SFT  │  │   │      │    │      │   │    │
     * └──────┴─────┴────┴────┴─────┴──────┘  └───┴──────┴────┴──────┴───┴────┘
     */
    [3] = LAYOUT_ortho_12x4(
        QK_BOOT,  KC_F10,   KC_F9,   KC_F8,   KC_F7,      CUST1,           KC_NO,    KC_HOME,        KC_UP,      KC_END,   KC_NO,   TO(4),
        KC_NO,    KC_F11,   KC_F6,   KC_F5,   KC_F4,      CUST2,           KC_NO,    KC_LEFT,        KC_DOWN,    KC_RIGHT, KC_NO,   TO(1),
        KC_NO,    KC_F12,   KC_F3,   KC_F2,   KC_F1,      CUST3,           KC_NO,    KC_PGUP,        KC_NO,      KC_PGDN,  KC_NO,   KC_NO,
        KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_LCTL,    KC_LEFT_SHIFT,   KC_NO,    KC_TRANSPARENT, KC_NO,      KC_NO,    KC_NO,   KC_NO
    ),
    /*
     * GAMING OFFSET (the right hand is using transparent so it will depend on which default layer is active 0 or 1)
     * ┌─────┬─────┬───┬───┬─────┬───┐  ┌─────┬─────┬───┬───┬───┬────┐
     * │ ESC │ TAB │ Q │ W │  E  │ R │  │ F1  │  ?  │ ? │ ? │   │ L0 │
     * ├─────┼─────┼───┼───┼─────┼───┤  ├─────┼─────┼───┼───┼───┼────┤
     * │  M  │ SFT │ A │ S │  D  │ F │  │ F4  │  ?  │ ? │ ? │   │    │ M here is for mute toggle
     * ├─────┼─────┼───┼───┼─────┼───┤  ├─────┼─────┼───┼───┼───┼────┤
     * │ ALT │ CTL │ Z │ X │  C  │ V │  │  ?  │  ?  │ ? │ ? │ ? │    │
     * ├─────┼─────┼───┼───┼─────┼───┤  ├─────┼─────┼───┼───┼───┼────┤
     * │     │     │   │   │ SPC │   │  │ BSP │ ENT │   │   │   │    │
     * └─────┴─────┴───┴───┴─────┴───┘  └─────┴─────┴───┴───┴───┴────┘
     */
    [4] = LAYOUT_ortho_12x4(
        KC_ESC,        KC_TAB,    KC_Q,   KC_W,   KC_E,     KC_R,      KC_F1,    KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,   KC_NO,   TO(0),
        KC_M,          KC_LSFT,   KC_A,   KC_S,   KC_D,     KC_F,      KC_F4,    KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,   KC_NO,   KC_NO,
        KC_LALT,       KC_LCTL,   KC_Z,   KC_X,   KC_C,     KC_V,      KC_TRANSPARENT,    KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,   KC_TRANSPARENT,   KC_NO,
        KC_NO,         KC_NO,     KC_NO,  KC_NO,  KC_SPACE, KC_NO,     KC_BSPC,    KC_ENTER,     KC_NO,              KC_NO,            KC_NO,            KC_NO
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CUST1:
            if (record->event.pressed) {
                SEND_STRING("<some sample string>");
            }
            return false;
        case CUST2:
            if (record->event.pressed) {
                SEND_STRING("<some other sample string>");
            }
            return false;
        case CUST3:
            if (record->event.pressed) {
                SEND_STRING("<remember to tip your waiter>");
            }
            return false;
    }

    return true;
}
