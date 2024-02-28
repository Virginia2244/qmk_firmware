// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐  
      * │CTL│ Q │ W │ E │ R │  
      * ├───┼───┼───┼───┼───┤  
      * │SFT│ A │ S │ D │ F │  
      * └───┴───┴───┴───┴───┘  
      *           ┌───┐        
      *           │LA1├───┐    
      *           └───┤SPC├───┐
      *               └───┤BSP│
      *                   └───┘
      * ┌───┬───┬───┬───┬───┐  
      * │ 1 │ 2 │ 3 │ 4 │ 5 │  
      * ├───┼───┼───┼───┼───┤  
      * │ 6 │ 7 │ 8 │ 9 │DF2│  
      * └───┴───┴───┴───┴───┘  
      *           ┌───┐        
      *           │---├───┐    
      *           └───┤---├───┐
      *               └───┤BOT│
      *                   └───┘
      * ┌───┬───┬───┬───┬───┐  
      * │VUP│PRV│NXT│BUP│PSC│  
      * ├───┼───┼───┼───┼───┤  
      * │VDW│MUT│PLY│BDW│DF0│  
      * └───┴───┴───┴───┴───┘  
      *           ┌───┐        
      *           │---├───┐    
      *           └───┤---├───┐
      *               └───┤---│
      *                   └───┘
      */
    [0] = LAYOUT_2x5_3(
        KC_LCTL,    KC_Q,   KC_W,   KC_E,   KC_R,
        KC_LSFT,    KC_A,   KC_S,   KC_D,   KC_F,
                                    MO(1),  KC_SPC, KC_BSPC
    ),
    [1] = LAYOUT_2x5_3(
        KC_1,   KC_2,   KC_3,   KC_4,       KC_5,
        KC_6,   KC_7,   KC_8,   KC_9,       DF(2),
                                _______,    _______,    QK_BOOT
    ),
    [2] = LAYOUT_2x5_3(
        KC_VOLU,    KC_MPRV,   KC_MNXT,   KC_BRIU,    KC_PSCR,
        KC_VOLD,    KC_MUTE,   KC_MPLY,   KC_BRID,    DF(0),
                                          KC_NO,      KC_NO,    KC_NO
    ),
};

const uint16_t PROGMEM pinky_combo[] = {KC_LCTL, KC_LSFT, COMBO_END};
combo_t key_combos[] = {
    COMBO(pinky_combo, KC_ESC),
};

// Layer 1
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, 85, 255, 65}
);

// Layer 2
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, 169, 255, 65}
);

// Layer 3
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, 222, 255, 100}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer     // Overrides other layers
);

void keyboard_post_init_user(){
    // Setting the Seeed Xiao's onboard LED pin as an output, then to high
    setPinOutput(GP11);
    writePinHigh(GP11);
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
        rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    return state;
}