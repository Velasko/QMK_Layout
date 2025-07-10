import json
import os

PATH = "/mnt/barracuda/Documents/keyboard/qmk_firmware-bluebell-swoop-velasco/keyboards/bluebell/swoop/keymaps/velasco/"
os.makedirs(PATH, exist_ok=True)

key_replaces = {
  "ANY(ALT_TAB)": "ALT_TAB",
  "ANY(ALT_QUOTE)": "ALT_QUOTE",
  "ANY(TD(TD_LSFT_HOLD))": "TD(TD_LSFT_HOLD)",
  "ANY(TD(TD_W_HOLD))": "TD(TD_W_HOLD)"
}

key_double_tap_hold = [
  "W",
  "LSFT"
]

with open("velasco.json", "r") as file:
    data = "".join(file.readlines())
    for key, value in key_replaces.items():
      data = data.replace(key,value)
    kmap = json.loads(data)

keymap_c = '''

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
        register_code(KC_GRV);
      } else {
        unregister_code(KC_GRV);
      }
      break;
  }
  return true;
}

enum layers {
    LAYER_''' + ",\n\tLAYER_".join(str(e) for e in range(16)) + '''
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

// Tap Dance declarations ############
enum {
  ''' + ",\n  ".join([
  f"TD_{key}_HOLD" for key in key_double_tap_hold
]) + '''
} tap_hold_keys;
''' + "\n".join(['''
void ''' + key + '''_DOUBLE_TAP_HOLD(tap_dance_state_t *state, void *user_data){
    register_code(KC_''' + key + ''');
}

void ''' + key + '''_DOUBLE_TAP_HOLD_RELEASE(tap_dance_state_t *state, void *user_data){
    if(state->count != 2){
      unregister_code(KC_''' + key + ''');
    }
}''' for key in key_double_tap_hold ]) + '''

tap_dance_action_t tap_dance_actions[] = {
  ''' + ",\n  ".join([
  f"[TD_{key}_HOLD] = ACTION_TAP_DANCE_FN_ADVANCED({key}_DOUBLE_TAP_HOLD, NULL, {key}_DOUBLE_TAP_HOLD_RELEASE)"
  for key in key_double_tap_hold
]) + '''
};

// Tap Dance declarations End  ############

const key_override_t c_key_override = ko_make_basic(MOD_MASK_ALT, KC_C, KC_SCLN);

const key_override_t **key_overrides = (const key_override_t *[]){
    &c_key_override,
    NULL
};

const uint16_t PROGMEM keymaps [][MATRIX_ROWS][MATRIX_COLS] = {
''' + ",\n".join([
'''[LAYER_{0}] = LAYOUT_split_3x5_3(
    {1}
)
'''.format(i, ", ".join(
    kmap["layers"][i]
)) for i in range(16)
]) + "\n};"

with open(f"{PATH}/keymap.c", "w") as file:
    file.write(keymap_c)

print(keymap_c)
