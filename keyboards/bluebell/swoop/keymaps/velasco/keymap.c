

#include QMK_KEYBOARD_H

bool is_alt_active = false;

enum custom_keycodes {
  ALT_TAB = SAFE_RANGE,
  ALT_QUOTE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) { // This will do most of the grunt work with the keycodes.
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_active) {
          is_alt_active = true;
          register_code(KC_LALT);
        }
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
    case ALT_QUOTE:
      if (record->event.pressed) {
        if (!is_alt_active) {
          is_alt_active = true;
          register_code(KC_LALT);
        }
        register_code(KC_QUOTE);
      } else {
        unregister_code(KC_QUOTE);
      }
      break;
  }
  return true;
}

enum layers {
    LAYER_0,
	LAYER_1,
	LAYER_2,
	LAYER_3,
	LAYER_4,
	LAYER_5,
	LAYER_6,
	LAYER_7,
	LAYER_8,
	LAYER_9,
	LAYER_10,
	LAYER_11,
	LAYER_12,
	LAYER_13,
	LAYER_14,
	LAYER_15
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 0: //Layer exit
        unregister_code(KC_LALT);
        is_alt_active = false;
        break;
    }
  return state;
}

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BACKSPACE, KC_DEL);
const key_override_t c_key_override = ko_make_basic(MOD_MASK_ALT, KC_C, KC_SCLN);

const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    &c_key_override,
    NULL
};

const uint16_t PROGMEM keymaps [][MATRIX_ROWS][MATRIX_COLS] = {
[LAYER_0] = LAYOUT_split_3x5_3(
    KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SLSH, LGUI_T(KC_A), RALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G, KC_M, RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O), KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_INT1, LT(12,KC_ESC), LT(14,KC_BSPC), LT(15,KC_ENT), LT(2,KC_SPC), LT(13,KC_TAB), KC_NO
)
,
[LAYER_1] = LAYOUT_split_3x5_3(
    KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SLSH), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_INT1, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO
)
,
[LAYER_2] = LAYOUT_split_3x5_3(
    KC_NO, KC_RCBR, KC_PIPE, KC_CAPS, KC_NO, KC_NO, KC_LCBR, KC_CIRC, KC_NO, KC_NO, KC_NO, KC_LPRN, KC_RPRN, KC_LSFT, KC_NO, KC_NO, KC_LBRC, KC_QUOT, KC_DQUO, KC_NO, KC_NUBS, KC_RBRC, KC_NUHS, KC_NO, KC_NO, KC_NO, KC_UNDS, KC_TILD, KC_GRV, KC_INT1, KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
,
[LAYER_3] = LAYOUT_split_3x5_3(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
,
[LAYER_4] = LAYOUT_split_3x5_3(
    KC_TAB, KC_1, KC_2, KC_3, TT(5), KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_LSFT, KC_A, KC_W, KC_D, KC_R, KC_NO, KC_4, KC_5, KC_6, KC_NO, KC_LCTL, KC_Q, KC_S, KC_E, KC_F, KC_NO, KC_1, KC_2, KC_3, KC_NO, LT(12,KC_ESC), LT(14,KC_C), LT(15,KC_SPC), KC_NO, KC_NO, KC_NO
)
,
[LAYER_5] = LAYOUT_split_3x5_3(
    KC_4, KC_5, KC_6, KC_7, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_G, KC_H, KC_J, KC_K, KC_L, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_M, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO
)
,
[LAYER_6] = LAYOUT_split_3x5_3(
    KC_COMM, KC_7, KC_8, KC_9, KC_MINS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DOT, KC_4, KC_5, KC_6, KC_EQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LSFT, KC_1, KC_2, KC_3, KC_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
,
[LAYER_7] = LAYOUT_split_3x5_3(
    KC_NO, KC_NO, KC_NO, KC_PGUP, KC_HOME, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LSFT, KC_LEFT, KC_UP, KC_RGHT, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCTL, KC_NO, KC_DOWN, KC_PGDN, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
,
[LAYER_8] = LAYOUT_split_3x5_3(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
,
[LAYER_9] = LAYOUT_split_3x5_3(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
,
[LAYER_10] = LAYOUT_split_3x5_3(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
,
[LAYER_11] = LAYOUT_split_3x5_3(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
,
[LAYER_12] = LAYOUT_split_3x5_3(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_VAI, RGB_MOD, RGB_HUI, RGB_SAI, RGB_SPI, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SN, KC_TRNS, RGB_VAD, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_SPD, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, KC_TRNS, KC_TRNS, RGB_TOG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
,
[LAYER_13] = LAYOUT_split_3x5_3(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_NO, KC_MRWD, KC_MPLY, KC_MFFD, KC_NO, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
,
[LAYER_14] = LAYOUT_split_3x5_3(
    LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), KC_PPLS, KC_7, KC_8, KC_9, KC_SLSH, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO, KC_EQL, KC_4, KC_5, KC_6, KC_DOT, DF(0), DF(1), DF(4), DF(6), DF(7), KC_MINS, KC_1, KC_2, KC_3, KC_COMM, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_INT1, KC_NO
)
,
[LAYER_15] = LAYOUT_split_3x5_3(
    ALT_QUOTE, LCTL(KC_TAB), LCTL(KC_W), LCTL(KC_R), LGUI(KC_T), KC_HOME, KC_PGUP, KC_NO, KC_NO, KC_NO, KC_LSFT, ALT_TAB, LALT(KC_Q), LCTL(KC_F), KC_NO, KC_NO, KC_LEFT, KC_UP, KC_RGHT, KC_RSFT, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_B), KC_END, KC_PGDN, KC_DOWN, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_RCTL, KC_TRNS, KC_TRNS
)

};