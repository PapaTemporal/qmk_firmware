// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// custom send strings
enum custom_keycodes {
    WUP = SAFE_RANGE,
    WPWD,
    HPWD,
    LAYER_TOGGLE
};

// tap dance declarations
enum {
    LEFT_GUI_TOGGLE,
};

void left_gui_toggle(tap_dance_state_t *state, void *user_data) {
    static bool layer_toggle = false; // keep track of the layer state

    if (state->count == 1) {
        register_code(KC_LEFT_GUI);
    } else if (state->count == 2) {
        layer_toggle = !layer_toggle; // toggle the layer state
        if (layer_toggle) {
            layer_on(1);
            layer_off(0);
        } else {
            layer_on(0);
            layer_off(1);
        }
    }
}

void left_gui_toggle_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_LEFT_GUI);
    }
}

// tap dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [LEFT_GUI_TOGGLE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, left_gui_toggle, left_gui_toggle_reset),
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
     * │ L1  │   │   │   │     │     │  │     │     │   │   │   │ ALT │
     * ├─────┼───┼───┼───┼─────┼─────┤  ├─────┼─────┼───┼───┼───┼─────┤
     * │     │   │   │   │ SPC │ SFT │  │ BSP │ ENT │   │   │   │     │
     * │     │   │   │   │ CTL │     │  │ L2  │ L3  │   │   │   │     │
     * └─────┴───┴───┴───┴─────┴─────┘  └─────┴─────┴───┴───┴───┴─────┘
     */
    [0] = LAYOUT_ortho_12x4(
        KC_ESC,       KC_Q,   KC_W,   KC_F,   KC_P,     KC_B,            KC_J,    KC_L,     KC_U,    KC_Y,   KC_SCLN, KC_DEL,
        KC_TAB,       KC_A,   KC_R,   KC_S,   KC_T,     KC_G,            KC_M,    KC_N,     KC_E,    KC_I,   KC_O,    KC_QUOT,
        TD(LEFT_GUI_TOGGLE),  KC_Z,   KC_X,   KC_C,   KC_D,     KC_V,            KC_K,    KC_H,     KC_COMM, KC_DOT, KC_SLSH, MT(MOD_LALT, KC_BSLS),
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
     * │ L1  │   │   │   │     │     │  │     │     │   │   │   │ ALT │
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
     * ┌─────┬───┬───┬───┬─────┬─────┐  ┌─────┬─────┬───┬───┬───┬─────┐
     * │  `  │ ! │ @ │ # │  {  │  }  │  │ NUM │  7  │ 8 │ 9 │ - │ CPS │
     * ├─────┼───┼───┼───┼─────┼─────┤  ├─────┼─────┼───┼───┼───┼─────┤
     * │  ^  │ $ │ % │ = │  (  │  )  │  │  *  │  4  │ 5 │ 6 │ + │  /  │
     * │ SFT │   │   │   │     │     │  │     │     │   │   │   │     │
     * ├─────┼───┼───┼───┼─────┼─────┤  ├─────┼─────┼───┼───┼───┼─────┤
     * │ CMD │ & │ * │ _ │  [  │  ]  │  │  .  │  1  │ 2 │ 3 │ 0 │ ENT │
     * │ L1  │   │   │   │     │     │  │     │     │   │   │   │     │
     * ├─────┼───┼───┼───┼─────┼─────┤  ├─────┼─────┼───┼───┼───┼─────┤
     * │     │   │   │   │ SPC │ SFT │  │ BSP │ ENT │   │   │   │     │
     * │     │   │   │   │ CTL │     │  │ L2  │ L3  │   │   │   │     │
     * └─────┴───┴───┴───┴─────┴─────┘  └─────┴─────┴───┴───┴───┴─────┘
     */
    [2] = LAYOUT_ortho_12x4(
        KC_GRAVE,       LSFT(KC_1),   LSFT(KC_2),   LSFT(KC_3),    LSFT(KC_LBRC),  LSFT(KC_RBRC),         KC_NUM, KC_P7,     KC_P8,    KC_P9,   KC_PMNS,    KC_CAPS,
        LSFT(KC_6),     LSFT(KC_4),   LSFT(KC_5),   KC_EQUAL,      LSFT(KC_9),     LSFT(KC_0),            KC_PAST, KC_P4,     KC_P5,    KC_P6,   KC_PPLS, KC_PSLS,
        KC_TRANSPARENT, LSFT(KC_7),   LSFT(KC_8),   LSFT(KC_MINUS),KC_LBRC,        KC_RBRC,               KC_PDOT, KC_P1,     KC_P2,    KC_P3,   KC_P0, KC_PENT,
        KC_NO,          KC_NO,        KC_NO,        KC_NO,         KC_TRANSPARENT, KC_TRANSPARENT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,   KC_NO,  KC_NO,   KC_NO
    ),
    /*
     * NAVIGATION & FUNCTION KEYS
     * ┌──────┬─────┬────┬────┬─────┬──────┐  ┌─────┬──────┬────┬──────┬───┬────┐
     * │ BOOT │ F10 │ F9 │ F8 │ F7  │ CUST │  │     │ HOME │ UP │ END  │   │ L4 │
     * ├──────┼─────┼────┼────┼─────┼──────┤  ├─────┼──────┼────┼──────┼───┼────┤
     * │      │ F11 │ F6 │ F5 │ F4  │ CUST │  │     │ LEFT │ DN │ RGT  │   │    │
     * ├──────┼─────┼────┼────┼─────┼──────┤  ├─────┼──────┼────┼──────┼───┼────┤
     * │ CMD  │ F12 │ F3 │ F2 │ F1  │ CUST │  │     │ PGUP │ ,  │ PGDN │   │    │
     * ├──────┼─────┼────┼────┼─────┼──────┤  ├─────┼──────┼────┼──────┼───┼────┤
     * │      │     │    │    │ SPC │ SFT  │  │ BSP │ ENT  │    │      │   │    │
     * │      │     │    │    │ CTL │      │  │ L2  │ L3   │    │      │   │    │
     * └──────┴─────┴────┴────┴─────┴──────┘  └─────┴──────┴────┴──────┴───┴────┘
     */
    [3] = LAYOUT_ortho_12x4(
        QK_BOOT,        KC_F10,   KC_F9,   KC_F8,   KC_F7,          WUP,            KC_NO,    KC_HOME,     KC_UP,          KC_END,   KC_NO,   TO(4),
        KC_NO,          KC_F11,   KC_F6,   KC_F5,   KC_F4,          WPWD,           KC_NO,    KC_LEFT,     KC_DOWN,        KC_RIGHT, KC_NO,   KC_NO,
        KC_LEFT_GUI,  KC_F12,   KC_F3,   KC_F2,   KC_F1,          HPWD,           KC_NO,    KC_PGUP,     KC_TRANSPARENT, KC_PGDN,  KC_NO,   KC_NO,
        KC_NO,          KC_NO,    KC_NO,   KC_NO,   KC_TRANSPARENT, KC_TRANSPARENT,    KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_NO,    KC_NO,   KC_NO
    ),
    /*
     * GAMING OFFSET
     * ┌─────┬─────┬───┬───┬─────┬───┐  ┌─────┬─────┬───┬───┬───┬─────┐
     * │ ESC │ TAB │ Q │ W │  E  │ R │  │ F1  │  L  │ U │ Y │ ; │ L0  │
     * ├─────┼─────┼───┼───┼─────┼───┤  ├─────┼─────┼───┼───┼───┼─────┤
     * │  M  │ SFT │ A │ S │  D  │ F │  │ F4  │  N  │ E │ I │ O │  '  │
     * ├─────┼─────┼───┼───┼─────┼───┤  ├─────┼─────┼───┼───┼───┼─────┤
     * │ ALT │ CTL │ Z │ X │  C  │ V │  │  M  │  H  │ , │ . │ / │  \  │
     * │     │     │   │   │     │   │  │     │     │   │   │   │ ALT │
     * ├─────┼─────┼───┼───┼─────┼───┤  ├─────┼─────┼───┼───┼───┼─────┤
     * │     │     │   │   │ SPC │   │  │ BSP │ ENT │   │   │   │     │
     * └─────┴─────┴───┴───┴─────┴───┘  └─────┴─────┴───┴───┴───┴─────┘
     */
    [4] = LAYOUT_ortho_12x4(
        KC_ESC,        KC_TAB,    KC_Q,   KC_W,   KC_E,     KC_R,      KC_F1,    KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,   KC_TRANSPARENT,   TO(0),
        KC_M,          KC_LSFT,   KC_A,   KC_S,   KC_D,     KC_F,      KC_F4,    KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,   KC_TRANSPARENT,   KC_TRANSPARENT,
        KC_LALT,       KC_LCTL,   KC_Z,   KC_X,   KC_C,     KC_V,      KC_TRANSPARENT,    KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,   KC_TRANSPARENT,   KC_TRANSPARENT,
        KC_NO,         KC_NO,     KC_NO,  KC_NO,  KC_SPACE, KC_NO,     KC_BSPC,    KC_ENTER,     KC_NO,              KC_NO,            KC_NO,            KC_NO
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WUP:
            if (record->event.pressed) {
                SEND_STRING("<some sample string>");
            }
            return false;
        case WPWD:
            if (record->event.pressed) {
                SEND_STRING("<some other sample string>");
            }
            return false;
        case HPWD:
            if (record->event.pressed) {
                SEND_STRING("<remember to tip your waiter>");
            }
            return false;
    }

    return true;
}
