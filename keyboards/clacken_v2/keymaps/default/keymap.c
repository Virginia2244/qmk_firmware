// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _ALPHA_QWERTY = 0,
    _NUMBER,
    _FUNCTION,
    _CTL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
     * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
     * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
     * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
     *           ┌───┐                   ┌───┐
     *           │MO1├───┐           ┌───┤MO2│
     *           └───┤SPC├───┐   ┌───┤Ent├───┘
     *               └───┤BSP│   │DEL├───┘
     *                   └───┘   └───┘
     */
    [_ALPHA_QWERTY] = LAYOUT_clack(
        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,               KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,
        CTL_T(KC_A),    SFT_T(KC_S),    ALT_T(KC_D),    KC_F,           LWIN_T(KC_G),       RWIN_T(KC_H),   KC_J,           RALT_T(KC_K),   RSFT_T(KC_L),   RCTL_T(KC_SCLN),
        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,               KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,
                                        MO(_NUMBER),    KC_SPC,         KC_BSPC,            KC_DEL,         KC_ENTER,       MO(_FUNCTION)),

    /*
     * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
     * │F1 │F2 │F3 │F4 │F5 │       │F6 │F7 │F8 │F9 │F10│
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │CTL│SFT│ALT│TAB│GUI│       │PUp│PDw│UP │End│F11│
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │PSC│Cap│   │   │   │       │PDw│LFT│DWN│RIT│F12│
     * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
     *           ┌───┐                   ┌───┐
     *           │MO1├───┐           ┌───┤MO2│
     *           └───┤SPC├───┐   ┌───┤Ent├───┘
     *               └───┤BSP│   │DEL├───┘
     *                   └───┘   └───┘
     */
    [_FUNCTION]     = LAYOUT_clack(
        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,              KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,
        KC_LCTL,        KC_LSFT,        KC_LALT,        KC_TAB,         KC_LGUI,            KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         KC_F11,
        KC_PSCR,        KC_CAPS,        XXXXXXX,        XXXXXXX,        XXXXXXX,            KC_PAGE_DOWN,   KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_F12,
                                        _______,        _______,        _______,            _______,        _______,        _______),
    /*
     * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
     * │ 1 │ 2 │ 3 │ 4 │ 5 │       │ 6 │ 7 │ 8 │ 9 │  0│
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │CTL│SFT│ALT│TAB│GUI│       │   │ ` │ ' │ [ │ ] │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │   │   │   │   │   │       │   │ - │ = │ \ │ / │
     * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
     *           ┌───┐                   ┌───┐
     *           │MO1├───┐           ┌───┤MO2│
     *           └───┤SPC├───┐   ┌───┤Ent├───┘
     *               └───┤BSP│   │DEL├───┘
     *                   └───┘   └───┘
     */
    [_NUMBER]       = LAYOUT_clack(
        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,               KC_6,           KC_7,           KC_8,           KC_9,           KC_0,
        KC_LCTL,        KC_LSFT,        KC_LALT,        KC_TAB,         KC_LGUI,            XXXXXXX,        KC_GRV,         KC_QUOT,        KC_LBRC,        KC_RBRC,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,            XXXXXXX,        KC_MINS,        KC_EQL,         KC_BSLS,        KC_SLSH,
                                        _______,        _______,        _______,            _______,        KC_RSFT,        _______),
    [_CTL]          = LAYOUT_clack(
    KC_KB_VOLUME_UP,    KC_MPRV,        KC_MPLY,        KC_MNXT,        XXXXXXX,            XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_BRIU,
    KC_KB_VOLUME_DOWN,  XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,            XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_BRID,
    KC_KB_MUTE,         XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,            XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                        _______,        _______,        _______,            _______,        _______,        _______)
};

