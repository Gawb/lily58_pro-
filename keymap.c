#include QMK_KEYBOARD_H
#include "keymap_spanish_latin_america.h"      // alias ES_* (teclas físicas LatAm)
#include "sendstring_spanish_latin_america.h"  // mapeo correcto para SEND_STRING en LatAm

enum layer_number {
  _BASE = 0,
  _LOWER,
  _HIGHER,
  _ADJUST,
};

enum custom_keycodes {
  ES_NTILDE = SAFE_RANGE,  // ñ personalizada
  ES_FORD,                 // ª (feminine ordinal) via Alt Code
};

/* ---------------------------- TAP DANCE ---------------------------------- */
// Índices de tap dance
enum {
  TD_SQUO = 0,  // ' (tap)  /  " (double tap)
};

// ' o " via strings (independiente del layout físico gracias a sendstring_*_latam)
void dance_quot_finished(tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    SEND_STRING("'");   // apóstrofe ASCII
  } else {
    SEND_STRING("\"");  // comilla doble
  }
}
void dance_quot_reset(tap_dance_state_t *state, void *user_data) {}

tap_dance_action_t tap_dance_actions[] = {
  [TD_SQUO] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_quot_finished, dance_quot_reset),
};
/* ------------------------------------------------------------------------ */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE - QWERTY + optimizaciones
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  1!  |  2"  |  3#  |  4$  |  5%  |                    |  6&  |  7/  |  8(  |  9)  |  0=  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  ´¨  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Shift |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |  ñÑ  | ' / "|
 * |------+------+------+------+------+------|  |    |    |  Del  |------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |  ,;  |  .:  |  - _ | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                 | Alt  | GUI  |LOWER |  /Space  /       \Enter \  |HIGHER| Bksp | Ctrl |
 */
[_BASE] = LAYOUT(
  KC_ESC,   KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                        KC_6,     KC_7,     KC_8,     KC_9,     KC_0,      ES_BSLS,
  KC_TAB,   KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                        KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,      KC_LBRC,
  KC_LSFT,  KC_A,      KC_S,      KC_D,      KC_F,      KC_G,                        KC_H,     KC_J,     KC_K,     KC_L,     ES_NTILDE, TD(TD_SQUO),
  KC_LCTL,  KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_GRV,  KC_DEL,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   ES_MINS,   KC_RSFT,
                           KC_LALT, KC_LGUI,  MO(_LOWER), KC_SPC,   KC_ENT, MO(_HIGHER), KC_BSPC, KC_RCTL
),

/* LOWER - Símbolos de programación y numpad (sin duplicar 0)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |                    |   7  |   8  |   9  |   /  |   *  | Vol+ |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Shift |   [  |   ]  |   {  |   }  |   =  |-------.    ,-------|   4  |   5  |   6  |   -  |   +  | Mute |
 * |------+------+------+------+------+------|   \   |    |   "   |------+------+------+------+------+------|
 * | Ctrl |   <  |   >  |   (  |   )  |   ;  |-------|    |-------|   1  |   2  |   3  |   .  |   ,  | Vol- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | Alt  | GUI  |(stay)| /Space  /       \Enter \  |   0  |   =  | PLAY |
 */
[_LOWER] = LAYOUT(
  KC_ESC,  KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
  KC_TAB,  S(KC_1),   RALT(KC_Q),S(KC_3),   S(KC_4),   S(KC_5),                    KC_7,    KC_8,    KC_9,    KC_PSLS, KC_PAST, KC_VOLU,
  KC_LSFT, ES_LBRC,   ES_RBRC,   ES_LCBR,   ES_RCBR,   ES_EQL,                      KC_4,    KC_5,    KC_6,    KC_PMNS, KC_PPLS, KC_MUTE,
  KC_LCTL, KC_NUBS,   S(KC_NUBS),S(KC_8),    S(KC_9),   S(KC_COMM), ES_BSLS,  S(KC_2),    KC_1,    KC_2,    KC_3,    KC_PDOT, KC_COMM, KC_VOLD,
                          KC_LALT, KC_LGUI,  _______,   KC_SPC,    KC_ENT,         KC_0,    ES_EQL,  KC_MPLY
),

/* HIGHER - Navegación/edición y símbolos extra
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  | F11  | F12  | F13  | F14  | F15  |                    |   ^  |  [{  |  ]}  |  =+  |      | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   °  |   ~  |   ª  | Calc | Expl |                    | PgUp |   ¿  |  ↑   |  ?   | Home |  Ins |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Shift | PrvTb| NxtTb|   ^  |   `  | ClsW |-------.    ,-------| PgDn |  ←   |  ↓   |  →   | End  | PrtSc|
 * |------+------+------+------+------+------|   /   |    |  Caps |------+------+------+------+------+------|
 * | Ctrl | Undo | Cut  | Copy |Paste | Redo |-------|    |-------|BkWord| Del  |DelWrd|      | Menu |Pause |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | Alt  | GUI  |LOWER | /Space  /       \Enter \  |(stay)| Bksp |  GUI |
 */
[_HIGHER] = LAYOUT(
  KC_ESC,  KC_F11,       KC_F12,       KC_F13,    KC_F14,       KC_F15,                   ES_CIRC,  ES_LBRC,  ES_RBRC,  ES_EQL,   XXXXXXX,  KC_BSPC,
  KC_TAB,  ES_MORD,      ES_TILD,      ES_FORD,   KC_CALC,      LGUI(KC_E),               KC_PGUP,  ES_IQUE,  KC_UP,    ES_QUES,  KC_HOME,  KC_INS,
  KC_LSFT, C(S(KC_TAB)), C(KC_TAB),    ES_CIRC,   ES_GRV,       A(KC_F4),                 KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_END,   KC_PSCR,
  KC_LCTL, C(KC_Z),      C(KC_X),      C(KC_C),   C(KC_V),      C(KC_Y), KC_SLSH, KC_CAPS, C(KC_BSPC), KC_DEL, C(KC_DEL), XXXXXXX, KC_APP,  KC_PAUS,
                           KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC,  KC_ENT,         _______,   KC_BSPC, KC_RGUI
),

/* ADJUST - RGB/utilidades (LOWER + HIGHER)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Reset|      |      |      |      |      |                    |      |      |      |      |      | Clear|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      | TOGG |                    |      |      |      |      |      | Boot |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | HUE+ | SAT+ | VAL+ | SPD+ | NEXT |-------.    ,-------| Vol+ | Prev | Play | Next |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | HUE- | SAT- | VAL- | SPD- | PREV |-------|    |-------| Vol- | Mute |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | Alt  | GUI  |      | /Space  /       \Enter \  |      |      |      |
 */
[_ADJUST] = LAYOUT(
  QK_RBT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UG_TOGG,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  XXXXXXX, UG_HUEU, UG_SATU, UG_VALU, UG_SPDU, UG_NEXT,                   KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  XXXXXXX, UG_HUED, UG_SATD, UG_VALD, UG_SPDD, UG_PREV, XXXXXXX, XXXXXXX, KC_VOLD, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                           KC_LALT, KC_LGUI, _______, KC_SPC, KC_ENT,  _______, XXXXXXX, XXXXXXX
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _HIGHER, _ADJUST);
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) return OLED_ROTATION_180;
  return rotation;
}
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);
bool oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
  } else {
    oled_write(read_logo(), false);
  }
  return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    switch (keycode) {
      case ES_NTILDE: // ñ en LatAm (scancode US ';')
        tap_code(KC_SCLN);
        return false;
      case ES_FORD: // ª (feminine ordinal) via Alt Code 166
        register_code(KC_LALT);
        tap_code(KC_P1);
        tap_code(KC_P6);
        tap_code(KC_P6);
        unregister_code(KC_LALT);
        return false;
    }
  }
  return true;
}
