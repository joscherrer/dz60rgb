#include QMK_KEYBOARD_H
#include <print.h>

enum layer_names {
    _BASE,
    _FN,
    _FN2,
    _CAPSLOCK,
    _DOFUS
};

enum custom_keycodes {
    WORKLEFT = SAFE_RANGE,
    WORKRGHT,
    CODEBLCK,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case WORKLEFT:
        if (record->event.pressed) {
            tap_code16(LALT(LCTL(KC_HOME)));
            SEND_STRING(SS_DELAY(100));
            tap_code16(LGUI(LCTL(KC_LEFT)));
        }
        break;
    case WORKRGHT:
        if (record->event.pressed) {
            tap_code16(LALT(LCTL(KC_HOME)));
            SEND_STRING(SS_DELAY(100));
            tap_code16(LGUI(LCTL(KC_RGHT)));
        }
        break;
    case CODEBLCK:
        if (record->event.pressed) {
            for (int i = 0; i < 6; i++) {
                tap_code16(KC_GRV);
                tap_code16(KC_SPC);
            }
            for (int i = 0; i < 3; i++)
                tap_code16(KC_LEFT);

            for (int i = 0; i < 2; i++)
                tap_code16(LSFT(KC_ENT));

            tap_code16(KC_UP);
        }
        break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_60_ansi( /* Base */
    KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, // 15
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, // 14
    MO(1), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, // 13
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, // 14
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(1), OSL(1), KC_LCTL // 10
  ),
  [_FN] = LAYOUT_60_ansi( /* FN */
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, // 15 + 1
    MO(2), WORKLEFT, WORKRGHT, XXXXXXX, KC_BTN1, XXXXXXX, XXXXXXX, KC_PGUP, KC_UP, KC_PGDN, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_GESC, KC_GRV, KC_GRV,
    KC_LSFT, BL_TOGG, BL_DEC, BL_INC, XXXXXXX, XXXXXXX, KC_END, XXXXXXX, TO(2), TO(3), TO(4), KC_RSFT, // 14 + 2
    KC_LCTL, KC_LGUI, KC_LALT, TO(4), KC_RALT, _______, _______, KC_RCTL // 10 + 2
  ),
  [_FN2] = LAYOUT_60_ansi(
    DEBUG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, // + 1
    _______, KC_K, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CODEBLCK, KC_ENT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(0), KC_RSFT,// + 2
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(0), KC_RCTL // + 2
  ),
  [_CAPSLOCK] = LAYOUT_60_ansi(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, // + 1
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    KC_CAPS, KC_A, KC_S, KC_D, KC_D, KC_F, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,// + 2
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_LCTL, XXXXXXX, TO(0), KC_RCTL // + 2
  ),
	[_DOFUS] = LAYOUT_60_ansi(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
    KC_F2, KC_6, KC_7, KC_8, KC_9, KC_0, KC_Y, XXXXXXX, KC_I, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_F3, LSFT(KC_COMM), LSFT(KC_DOT), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,
    KC_F1, KC_Z, KC_L, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(0),
    KC_LCTL, KC_LGUI, KC_LALT, TO(0), XXXXXXX, XXXXXXX, TO(0), XXXXXXX
  )
};

void keyboard_post_init_user(void) {
  rgb_matrix_disable_noeeprom();
}


uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    case _BASE:
      rgb_matrix_disable_noeeprom();
      break;
    case _FN:
      rgb_matrix_enable_noeeprom();
      rgb_matrix_mode(RGB_MATRIX_CUSTOM_FN);
      break;
    case _FN2:
      rgb_matrix_enable_noeeprom();
      rgb_matrix_mode(RGB_MATRIX_CUSTOM_FN2);
      break;
    case _CAPSLOCK:
      rgb_matrix_enable_noeeprom();
      rgb_matrix_mode(RGB_MATRIX_CUSTOM_CAPSLOCK);
      break;
    case _DOFUS:
      rgb_matrix_enable_noeeprom();
      rgb_matrix_mode(RGB_MATRIX_CUSTOM_DOFUS);
      break;
    default:
      rgb_matrix_disable_noeeprom();
      break;
  }
  return state;
}

uint32_t default_layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    case _DOFUS:
      rgb_matrix_enable_noeeprom();
      rgb_matrix_mode(RGB_MATRIX_CUSTOM_DOFUS);
      break;
    case _CAPSLOCK:
      rgb_matrix_enable_noeeprom();
      rgb_matrix_mode(RGB_MATRIX_CUSTOM_CAPSLOCK);
      break;
    default:
      rgb_matrix_disable_noeeprom();
      break;
  }
  return state;
}
