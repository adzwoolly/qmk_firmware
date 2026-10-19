// Copyright 2026 adzwoolly
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "luna.h"

// Layer numbers must match TRI_LAYER_* in config.h
enum layers {
    _DVORAK,
    _LOWER,
    _RAISE,
    _ADJUST,
    _SKETCH,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * DVORAK
 * ,-----------------------------------------.                  ,-----------------------------------------.
 * |  `   |  1   |  2   |  3   |  4   |  5   |                  |  6   |  7   |  8   |  9   |  0   |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * | Esc  |  '   |  ,   |  .   |  P   |  Y   |                  |  F   |  G   |  C   |  R   |  L   | Bspc |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * | Tab  |  A   |  O   |  E   |  U   |  I   |/----\      /----\|  D   |  H   |  T   |  N   |  S   |      |
 * |------+------+------+------+------+------| Mute |    |MClick|------+------+------+------+------+------|
 * |LShift|  ;   |  Q   |  J   |  K   |  X   |\----/      \----/|  B   |  M   |  W   |  V   |  Z   |RShift|
 * `------'------+------+------+------+------+                  |------+------+------+------+------'------'
 *               | LGUI | LAlt | LCtl |Space |------.    ,------|Enter | RCtl | RAlt | RGUI |
 *               `------'------'------'------|LOWER |    |RAISE |------|------'------'------'
 *                                           `------'    `------'
 */
[_DVORAK] = LAYOUT(
  KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_ESC,   KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                       KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
  KC_TAB,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                       KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    _______,
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
 * |      |   /  |      |      |   #  |   {  |\----/      \----/|   }  |   1  |   2  |   3  |   .  |      |
 * `------'------+------+------+------+------+                  |------+------+------+------+------'------'
 *               |      |      |      |      |------.    ,------|      |   0  |      |      |
 *               `------'------'------'------|      |    |      |------|------'------'------'
 *                                           `------'    `------'
 */
[_LOWER] = LAYOUT(
  _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______,  KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, KC_LPRN,                    KC_RPRN, KC_7,    KC_8,    KC_9,    KC_MINS, KC_F12,
  _______,  KC_NUBS, S(KC_NUBS), KC_AMPR, KC_EQL, KC_LBRC,                 KC_RBRC, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
  _______,  KC_SLSH, XXXXXXX, XXXXXXX, KC_NUHS, KC_LCBR, _______,  _______, KC_RCBR, KC_1,    KC_2,    KC_3,    KC_DOT,  _______,
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
 * |Sketch|      |      |      |      |      |                  |      |      | Vol+ |      |      |      |
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
  TG(_SKETCH), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                  XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,  _______, XXXXXXX, XXXXXXX, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX,
                     _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______
),
/*
 * SKETCH (toggled from ADJUST, toggle again the same way to leave) - dials steer the mouse like an Etch A Sketch.
 * Left dial: X, right dial: Y. Pressing the left dial right clicks, pressing the right dial left clicks. Every key falls through to the layers below.
 */
[_SKETCH] = LAYOUT(
  _______,  _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
  _______,  _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
  _______,  _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
  _______,  _______, _______, _______, _______, _______, MS_BTN2,  MS_BTN1, _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______
),
};

#ifdef ENCODER_ENABLE
// Left dial: volume. Right dial: scroll.
// In the SKETCH layer, left dial moves the mouse in X and right dial in Y.
static void nudge_mouse(uint16_t keycode) {
    mousekey_on(keycode);
    mousekey_send();
    mousekey_off(keycode);
    mousekey_send();
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (IS_LAYER_ON(_SKETCH)) {
        if (index == 0) {
            nudge_mouse(clockwise ? MS_RGHT : MS_LEFT);
        } else {
            nudge_mouse(clockwise ? MS_DOWN : MS_UP);
        }
        return false;
    }
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
    //return is_keyboard_left() ? OLED_ROTATION_270 : OLED_ROTATION_270;
    return OLED_ROTATION_270;
}

// Luna the pet. Sits when idle, walks and runs with typing speed, sneaks while
// Ctrl is held, jumps on Space and barks while Caps Lock is on.
#define LUNA_X 0
#define LUNA_Y 13
#define LUNA_FRAME_MS 200
#define LUNA_WALK_WPM 10
#define LUNA_RUN_WPM 40

static bool is_sneaking = false;
static bool is_jumping  = false;
static bool showed_jump = true;

static void animate_luna(void) {
    static uint8_t frame = 0;

    // Jumping draws one row higher, so clear whichever rows aren't in use
    if (is_jumping || !showed_jump) {
        oled_set_cursor(LUNA_X, LUNA_Y + 2);
        oled_write_P(PSTR("     "), false);
        oled_set_cursor(LUNA_X, LUNA_Y - 1);
        showed_jump = true;
    } else {
        oled_set_cursor(LUNA_X, LUNA_Y - 1);
        oled_write_P(PSTR("     "), false);
        oled_set_cursor(LUNA_X, LUNA_Y);
    }

    frame = (frame + 1) % 2;
    uint8_t wpm = get_current_wpm();

    if (host_keyboard_led_state().caps_lock) {
        oled_write_raw_P(bark[frame], LUNA_FRAME_SIZE);
    } else if (is_sneaking) {
        oled_write_raw_P(sneak[frame], LUNA_FRAME_SIZE);
    } else if (wpm <= LUNA_WALK_WPM) {
        oled_write_raw_P(sit[frame], LUNA_FRAME_SIZE);
    } else if (wpm <= LUNA_RUN_WPM) {
        oled_write_raw_P(walk[frame], LUNA_FRAME_SIZE);
    } else {
        oled_write_raw_P(run[frame], LUNA_FRAME_SIZE);
    }
}

// Shift + Backspace sends Delete
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

const key_override_t *key_overrides[] = {
    &delete_key_override,
    NULL
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LCTL:
        case KC_RCTL:
            is_sneaking = record->event.pressed;
            break;
        case KC_SPC:
            is_jumping = record->event.pressed;
            if (is_jumping) {
                showed_jump = false;
            }
            break;
    }
    return true;
}

// Same status on both screens, so either one can show the layer.
// The screen is 5 characters wide. Every string is padded to 5 and drawn at a
// fixed row, so a full-width line can't wrap and shift the rows below it.
bool oled_task_user(void) {
    oled_set_cursor(0, 0);
    oled_write_P(PSTR("Dvrk "), false);
    oled_set_cursor(0, 3);
    oled_write_P(PSTR("LAYER"), false);
    oled_set_cursor(0, 4);
    switch (get_highest_layer(layer_state)) {
        case _DVORAK:
            oled_write_P(PSTR("Base "), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj  "), false);
            break;
        case _SKETCH:
            oled_write_P(PSTR("Sketc"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_set_cursor(0, 7);
    oled_write_P(PSTR("CAPS "), host_keyboard_led_state().caps_lock);

    static uint32_t anim_timer = 0;
    if (timer_elapsed32(anim_timer) > LUNA_FRAME_MS) {
        anim_timer = timer_read32();
        animate_luna();
    }
    return false;
}
#endif
