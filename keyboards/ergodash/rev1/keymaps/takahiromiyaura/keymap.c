#include QMK_KEYBOARD_H
#include "keymap_jp.h"

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  FN,
};

enum layer_names {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FN,
};

#define KC_DSPY LGUI(KC_P)
#define KC_FFHF LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |   -  |                    |   =  |   6  |   7  |   8  |   9  |   0  |   `  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | TAB  |   Q  |   W  |   E  |   R  |   T  |   [  |                    |   ]  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | F/H  |   A  |   S  |   D  |   F  |   G  |   \  |                    |   /  |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |||||||| Raise|      | Lower||||||||   N  |   M  |   ,  |   .  |  UP  | Enter|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  FN  |  ALT ||||||||  WIN | Home | Space|  Del |||||||| Shift| Space| PGUP | PGDN |||||||| Left | Down | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,                        KC_EQL ,    KC_6,    KC_7,    KC_8,   KC_9,   KC_0,  KC_GRV, \
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                        KC_RBRC,    KC_Y,    KC_U,    KC_I,   KC_O,   KC_P, KC_BSPC, \
    KC_FFHF,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_BSLS,                        KC_SLSH,    KC_H,    KC_J,    KC_K,   KC_L,KC_SCLN, KC_QUOT, \
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             RAISE,           LOWER,            KC_N,    KC_M, KC_COMM, KC_DOT,  KC_UP,  KC_ENT, \
    KC_LCTL,    FN, KC_LALT,          KC_LGUI, KC_HOME,    KC_SPC ,KC_DEL,         KC_RSFT,KC_SPC , KC_PGUP, KC_PGDN         ,KC_LEFT,KC_DOWN, KC_RGHT  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |                    |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |  UP  |      |      |      |      |                    |      |      |      |      |      |      | Bksp |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      | Left | Down | Right|      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|      |      |      |      |      |||||||| Raise|      | Lower||||||||      |      |      |      |  UP  | Enter|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  FN  |  ALT ||||||||  WIN | Home | Space|  Del |||||||| Shift| Space| PGUP | PGDN |||||||| Left | Down | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F11,                         KC_F12,   KC_F6,   KC_F7,   KC_F8,   KC_F9, KC_F10,  XXXXXXX, \
    XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         _______,       _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, \
    _______, _______, _______,          _______, _______, _______, KC_INS,       _______, _______, _______, _______,          _______, _______, _______ \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |                    |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      | PGUP |      |      |      |      |                    |      |      |      |      |      |      | Bksp |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      | Home | PGDN |  End |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|      |      |      |      |      |||||||| Raise|      | Lower||||||||      |      |      |      |  UP  | Enter|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  FN  |  ALT ||||||||  WIN | Home | Space|  INS |||||||| Shift| Space| PGUP | PGDN |||||||| Left | Down | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F11,                         KC_F12,   KC_F6,   KC_F7,   KC_F8,  KC_F9,   KC_F10, XXXXXXX, \
    XXXXXXX, XXXXXXX, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    XXXXXXX, KC_HOME, KC_PGDN,  KC_END, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         _______,       _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, \
    _______, _______, _______,          _______, _______, _______, KC_INS,       _______, _______, _______, _______,          _______, _______, _______ \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Reset|      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |RGB ON|  HUE-|  HUE+|      |      |                    |      |      | BL ON|  DEC |   INC|      | Bksp |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |  MODE|  SAT-|  SAT+|      |      |                    |      |      |  BRTG|      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |  VAL-|  VAL+|      |      |      |      |      |      |      |      |      |      |  UP  | Enter|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  FN  |  ALT ||||||||  WIN | Home | Space|  INS |||||||| Shift| Space| PGUP | PGDN |||||||| Left | Down | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    RESET  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, RGB_TOG, RGB_HUD, RGB_HUI, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, BL_TOGG, BL_DEC,  BL_INC,  XXXXXXX, _______, \
    XXXXXXX, XXXXXXX, RGB_MOD, RGB_SAD, RGB_SAI, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, BL_BRTG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, RGB_VAD, RGB_VAI, XXXXXXX,         _______,       _______,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, \
    _______, _______, _______,          _______, _______, _______, KC_INS,       _______,_______, _______, _______,          _______, _______, _______ \
  ),
  
  /* FN
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      | Mute | VDwn | Vup  |PTrack| Play |NTrack|                    | PSCRN| Disp | BUp  | BDwn | BL ON| INC  |  DEC |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      | Bksp |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |  UP  | Enter|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  FN  |  ALT ||||||||  WIN | Home | Space|  INS |||||||| Shift| Space| PGUP | PGDN |||||||| Left | Down | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_FN] = LAYOUT(
    XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT,                       KC_PSCR, KC_DSPY, KC_BRIU, KC_BRID, BL_TOGG, BL_DEC, BL_INC, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         _______,       _______,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, \
    _______, _______, _______, _______,          _______,_______,  KC_INS,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case FN:
      if (record->event.pressed) {
        layer_on(_FN);
      } else {
        layer_off(_FN);
      }
      return false;
      break;
  }
  return true;
}
