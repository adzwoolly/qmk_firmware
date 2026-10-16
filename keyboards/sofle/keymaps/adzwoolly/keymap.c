// Copyright 2026 adzwoolly
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

// Layer numbers must match TRI_LAYER_* in config.h
enum layers {
    _DVORAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * DVORAK
 * ,-----------------------------------------.                  ,-----------------------------------------.
 * | Esc  |  1   |  2   |  3   |  4   |  5   |                  |  6   |  7   |  8   |  9   |  0   | Bspc |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * | Tab  |  '   |  ,   |  .   |  P   |  Y   |                  |  F   |  G   |  C   |  R   |  L   |  /   |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |  `   |  A   |  O   |  E   |  U   |  I   |/----\      /----\|  D   |  H   |  T   |  N   |  S   |  -   |
 * |------+------+------+------+------+------| Mute |    |MClick|------+------+------+------+------+------|
 * |LShift|  ;   |  Q   |  J   |  K   |  X   |\----/      \----/|  B   |  M   |  W   |  V   |  Z   |RShift|
 * `------'------+------+------+------+------+                  |------+------+------+------+------'------'
 *               | LGUI | LAlt | LCtl |Space |------.    ,------|Enter | RCtl | RAlt | RGUI |
 *               `------'------'------'------|LOWER |    |RAISE |------|------'------'------'
 *                                           `------'    `------'
 */
[_DVORAK] = LAYOUT(
  KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                       KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
  KC_GRV,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                       KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
  KC_LSFT,  KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_MUTE,  MS_BTN3, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
                     KC_LGUI, KC_LALT, KC_LCTL, KC_SPC,  TL_LOWR,  TL_UPPR, KC_ENT,  KC_RCTL, KC_RALT, KC_RGUI
),
/*
 * LOWER - numpad on the right, openers ( [ { down the left half's inner column, closers ) ] } down the right half's.
 * The numpad uses the normal number keys, so Shift gives the symbols above them
 * ,-----------------------------------------.                  ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |   /  |   *  |   -  |   +  |   (  |                  |   )  |   7  |   8  |   9  |   -  | F12  |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |   \  |   |  |   &  |   =  |   [  |/----\      /----\|   ]  |   4  |   5  |   6  |   +  |      |
 * |------+------+------+------+------+------|      |    |      |------+------+------+------+------+------|
 * |      |      |      |      |   #  |   {  |\----/      \----/|   }  |   1  |   2  |   3  |   .  |      |
 * `------'------+------+------+------+------+                  |------+------+------+------+------'------'
 *               |      |      |      |      |------.    ,------|      |   0  |      |      |
 *               `------'------'------'------|      |    |      |------|------'------'------'
 *                                           `------'    `------'
 */
[_LOWER] = LAYOUT(
  _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______,  KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, KC_LPRN,                    KC_RPRN, KC_7,    KC_8,    KC_9,    KC_MINS, KC_F12,
  _______,  KC_NUBS, S(KC_NUBS), KC_AMPR, KC_EQL, KC_LBRC,                 KC_RBRC, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
  _______,  XXXXXXX, XXXXXXX, XXXXXXX, KC_NUHS, KC_LCBR, _______,  _______, KC_RCBR, KC_1,    KC_2,    KC_3,    KC_DOT,  _______,
                     _______, _______, _______, _______, _______,  _______, _______, KC_0,    _______, _______
),
/*
 * RAISE - arrows on the right in a WASD shape
 * ,-----------------------------------------.                  ,-----------------------------------------.
 * |      |      |      |      |      |      |                  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                  |      |L word|  Up  |R word| PgUp |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |/----\      /----\|      | Left | Down |Right | PgDn |      |
 * |------+------+------+------+------+------|      |    |      |------+------+------+------+------+------|
 * |      |      |      |      |      |      |\----/      \----/|      | Home |      | End  |      |      |
 * `------'------+------+------+------+------+                  |------+------+------+------+------'------'
 *               |      |      |      |      |------.    ,------|      |      |      |      |
 *               `------'------'------'------|      |    |      |------|------'------'------'
 *                                           `------'    `------'
 */
[_RAISE] = LAYOUT(
  _______,  _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, C(KC_LEFT), KC_UP, C(KC_RGHT), KC_PGUP, _______,
  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,  _______, XXXXXXX, KC_HOME, XXXXXXX, KC_END,  XXXXXXX, _______,
                     _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______
),
/*
 * ADJUST (hold LOWER + RAISE) - media on the right
 * ,-----------------------------------------.                  ,-----------------------------------------.
 * | Boot |      |      |      |      |      |                  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                  |      |      | Vol+ |      |      |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |/----\      /----\|      | Prev | Play | Next |      |      |
 * |------+------+------+------+------+------|      |    |      |------+------+------+------+------+------|
 * |      |      |      |      |      |      |\----/      \----/|      |      | Vol- |      |      |      |
 * `------'------+------+------+------+------+                  |------+------+------+------+------'------'
 *               |      |      |      |      |------.    ,------|      |      |      |      |
 *               `------'------'------'------|      |    |      |------|------'------'------'
 *                                           `------'    `------'
 */
[_ADJUST] = LAYOUT(
  QK_BOOT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,  _______, XXXXXXX, XXXXXXX, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX,
                     _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______
),
};

#ifdef ENCODER_ENABLE
// Left dial: volume. Right dial: scroll.
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        tap_code(clockwise ? KC_VOLU : KC_VOLD);
    } else {
        tap_code(clockwise ? MS_WHLD : MS_WHLU);
    }
    return false;
}
#endif

#ifdef OLED_ENABLE
// Both screens portrait. The right half is mounted upside down relative to the left.
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return is_keyboard_left() ? OLED_ROTATION_270 : OLED_ROTATION_90;
}

// Same status on both screens, so either one can show the layer.
bool oled_task_user(void) {
    oled_write_ln_P(PSTR("Dvrk"), false);
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _DVORAK:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adj"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("CAPS"), host_keyboard_led_state().caps_lock);
    return false;
}
#endif
