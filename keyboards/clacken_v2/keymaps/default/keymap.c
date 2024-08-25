// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _ALPHA_QWERTY = 0,
    _NUMBER,
    _FUNCTION,
    _CTL,
    _GAMING,
    _GAMING_NUMBER,
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
    KC_KB_VOLUME_DOWN,  XXXXXXX,        XXXXXXX,        XXXXXXX,        DF(_GAMING),        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_BRID,
    KC_KB_MUTE,         XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,            XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                        _______,        _______,        _______,            _______,        _______,        _______),

    [_GAMING]       = LAYOUT_clack(
        KC_ESC,         KC_Q,           KC_W,               KC_E,           KC_R,               KC_F1,          KC_F2,          KC_F3,          KC_F4,           KC_F5,
        KC_LSFT,        KC_A,           KC_S,               KC_D,           KC_F,               KC_F6,          KC_F7,          KC_F8,          KC_F9,           KC_F10,
        KC_TAB,         KC_Z,           KC_X,               KC_C,           KC_V,               KC_F11,         KC_F12,         KC_F12,         KC_KB_VOLUME_UP, KC_KB_VOLUME_DOWN,
                                        MO(_GAMING_NUMBER), KC_SPC,         KC_LCTL,            KC_DEL,         KC_ENTER,       DF(_ALPHA_QWERTY)),

    [_GAMING_NUMBER] = LAYOUT_clack(
        KC_1,           KC_2,           KC_3,               KC_4,           KC_5,               XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        KC_6,           KC_7,           KC_8,               KC_9,           KC_0,               XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,            XXXXXXX,        XXXXXXX,            XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                        MO(_GAMING_NUMBER), KC_SPC,         KC_LCTL,            XXXXXXX,        XXXXXXX,        XXXXXXX)

};


// Defining combos
const uint16_t PROGMEM layers_combo[] = {MO(_NUMBER), MO(_FUNCTION), COMBO_END};
const uint16_t PROGMEM escape[] = {CTL_T(KC_A), KC_Q, COMBO_END};
// Enabling combos
combo_t key_combos[]   = {
    COMBO(layers_combo, MO(_CTL)),
    COMBO(escape, KC_ESC),
};



// The rest of this file is for defining lighting layers

// Caps layer
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {8, 2, 0, 255, 65}       // Light 2 LEDs, starting with LED 8
);

// _ALPHA_QWERTY Layer
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 2, 201, 255, 65}
);

// _NUMBER Layer
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 2, 169, 255, 65}
);

// _FUNCTION Layer
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 2, 106, 255, 65}
);

// _CTL Layer
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 2, 21, 255, 65}
);
// _GAMING Layer
const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 2, 0, 0, 250}
);
// _GAMING_NUMBER Layer
const rgblight_segment_t PROGMEM my_layer6_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 2, 20, 100, 250}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer,     // Overrides other layers
    my_layer4_layer,
    my_layer5_layer,
    my_layer6_layer
);

void keyboard_post_init_user(){
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _ALPHA_QWERTY));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
        // rgblight_set_layer_state(0, host_keyboard_led_state().caps_lock);
        rgblight_set_layer_state(2, layer_state_cmp(state, _NUMBER));
        rgblight_set_layer_state(3, layer_state_cmp(state, _FUNCTION));
        rgblight_set_layer_state(4, layer_state_cmp(state, _CTL));
        rgblight_set_layer_state(5, layer_state_cmp(state, _GAMING));
        rgblight_set_layer_state(6, layer_state_cmp(state, _GAMING_NUMBER));
    return state;
}
