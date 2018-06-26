// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include <stdarg.h>
#include "mitosis.h"
#include "action_layer.h"
#include "action_util.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum mitosis_layers
{
	_MAIN,
	_SYM,
    _NAV
};

enum mitosis_keycodes 
{
  FNKEY = SAFE_RANGE,
  SHIFT
};


// Macro definitions for readability
enum mitosis_macros
{
	VOLU,
	VOLD,
	ESCM
};

//Macros
enum {
  KF_1 = 0, // 1, F1
  KF_2, // ...
  KF_3,
  KF_4,
  KF_5,
  KF_6,
  KF_7,
  KF_8,
  KF_9,
  KF_10,
  KF_11,
  KF_12
};

uint16_t kf_timers[12];

#define LONGPRESS_DELAY 150
#define LAYER_TOGGLE_DELAY 300

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// symbol defs
#define KN_HALF KC_GRV          // 1/2
#define KN_PLUS KC_MINS         // +
#define KN_ACUT KC_EQL          // ´
#define KN_AO	 KC_LBRC         // Å
#define KN_UMLA KC_RBRC         // ¨
#define KN_OE	 KC_SCLN         // Ö
#define KN_AE	 KC_QUOT         // Ä
#define KN_QUOT KC_NUHS         // '
#define KN_LABK KC_NUBS         // <
#define KN_MINS KC_SLSH         // -
#define KN_EXLM LSFT(KC_1)      // !
#define KN_DQT  LSFT(KC_2)      // "
#define KN_AT   RALT(KC_2)      // @
#define KN_HASH LSFT(KC_3)      // #
#define KN_EUR  LSFT(KC_4)      // €
#define KN_DLR  RALT(KC_4)      // $
#define KN_PERC LSFT(KC_5)      // %
#define KN_AMPR LSFT(KC_6)      // &
#define KN_SLSH LSFT(KC_7)      // /
#define KN_LPRN LSFT(KC_8)      // (
#define KN_RPRN LSFT(KC_9)      // )
#define KN_EQL  LSFT(KC_0)      // =
#define KN_UNDS LSFT(KN_MINS)   // _
#define KN_QUES LSFT(KN_PLUS)   // ?
#define KN_GRAV LSFT(KN_ACUT)   // `
#define KN_LCBR RALT(KC_7)      // {
#define KN_RCBR RALT(KC_0)      // }
#define KN_LBRC RALT(KC_8)      // [
#define KN_RBRC RALT(KC_9)      // ]
#define KN_RABK LSFT(KN_LABK)   // <
#define KN_COLN LSFT(KC_DOT)    // :
#define KN_SCLN LSFT(KC_COMM)   // :
#define KN_PIPE RALT(KN_LABK)   // |
#define KN_QUES LSFT(KN_PLUS)   // ?
#define KN_CIRC LSFT(KN_UMLA)   // ^
#define KN_ASTR LSFT(KN_QUOT)   // *
#define KN_TILD RALT(KN_UMLA)   // ~
#define KN_BSLS RALT(KN_PLUS)   //
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_MAIN] = { /* Main Layout, customised for reduced columns (ex: quote and shift locations) */
  {M(KF_11), M(KF_1), M(KF_2),  M(KF_3),  M(KF_4), M(KF_5), M(KF_6), M(KF_7), M(KF_8), M(KF_9),  M(KF_10), M(KF_12)  },
  {KC_TAB,   KC_Q,    KC_W,     KC_E,     KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,     XXXXXXX },
  {KC_LGUI,  KC_A,    KC_S,     KC_D,     KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     XXXXXXX,  KC_LALT },
  {KC_LCTL,  KC_Z,    KC_X,     KC_C,     KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   XXXXXXX,  KC_LCTL },
  {XXXXXXX,  XXXXXXX, MO(_NAV), MO(_SYM), KC_BSPC, KC_LSFT, KC_ENT,  KC_SPC,  KC_LGUI, MO(_NAV), XXXXXXX,  XXXXXXX }
},

[_SYM] = { /* Symbol layer */
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______ },
  {_______, KC_LABK, KC_RABK, KC_LCBR, KC_RCBR, KC_PLUS, KC_AT,   KC_DQT,  KC_QUOT, KC_GRAVE, KC_SLSH, _______ },
  {_______, KC_EXLM, KC_EQL,  KC_LPRN, KC_RPRN, KC_MINS, KC_UNDS, KC_CIRC, KC_DLR,  KC_AMPR,  KC_PIPE, _______ },
  {_______, _______, KC_PERC, KC_LBRC, KC_RBRC, KC_ASTR, KC_HASH, KC_SCLN, KC_COLN, KC_QUES,  KC_BSLS, _______ },
  {XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______,  XXXXXXX, XXXXXXX }
},

[_NAV] = { /* Navigation later */
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______ },
  {_______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   _______, KC_MUTE },
  {_______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, KC_VOLU },
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, KC_VOLD },
  {XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______,  XXXXXXX, XXXXXXX }

}
};


const uint16_t PROGMEM fn_actions[] = {

};

/*static uint16_t key_timer;*/

/*const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)*/
/*{*/
  /*// MACRODOWN only works in this function*/
    /*switch(id) {*/

          /*//switch multiplexing for media, short tap for volume up, long press for play/pause*/
        /*case VOLU:*/
            /*if (record->event.pressed) {*/
                /*key_timer = timer_read(); // if the key is being pressed, we start the timer.*/
              /*} else { // this means the key was just released, so we can figure out how long it was pressed for (tap or "held down").*/
                /*if (timer_elapsed(key_timer) > LONGPRESS_DELAY) { // LONGPRESS_DELAY being 150ms, the threshhold we pick for counting something as a tap.*/
                  /*return MACRO(T(MPLY), END);*/
                /*} else {*/
                  /*return MACRO(T(VOLU), END);*/
                /*}*/
              /*}*/
              /*break;*/

		/*//switch multiplexing for media, short tap for volume down, long press for next track*/
        /*case VOLD:*/
            /*if (record->event.pressed) {*/
                /*key_timer = timer_read();*/
              /*} else {*/
                /*if (timer_elapsed(key_timer) > LONGPRESS_DELAY) {*/
                  /*return MACRO(T(MNXT), END);*/
                /*} else {*/
                  /*return MACRO(T(VOLD), END);*/
                /*}*/
              /*}*/
              /*break;*/

        /*//switch multiplexing for escape, short tap for escape, long press for context menu*/
        /*case ESCM:*/
            /*if (record->event.pressed) {*/
                /*key_timer = timer_read();*/
              /*} else {*/
                /*if (timer_elapsed(key_timer) > LONGPRESS_DELAY) {*/
                  /*return MACRO(T(APP), END);*/
                /*} else {*/
                  /*return MACRO(T(ESC), END);*/
                /*}*/
              /*}*/
              /*break;     */

        /*break;*/
    /*}*/
    /*return MACRO_NONE;*/
/*};*/

/*static bool singular_key = false;*/

/*bool process_record_user(uint16_t keycode, keyrecord_t *record) {*/

	/*uint8_t layer;*/
  /*layer = biton32(layer_state);  // get the current layer*/

  /*//custom layer handling for tri_layer,*/
  /*switch (keycode) {*/
  /*case FNKEY:*/
      /*if (record->event.pressed) {*/
      /*key_timer = timer_read();*/
      /*singular_key = true;*/
        /*layer_on(_FUNCTION);*/
      /*} else {*/
      /*if (timer_elapsed(key_timer) < LAYER_TOGGLE_DELAY || !singular_key) {*/
        /*layer_off(_FUNCTION);*/
      /*}*/
      /*}*/
    /*update_tri_layer(_FUNCTION, _SHIFTED, _FUNCSHIFT);*/
      /*return false;*/
      /*break;*/
  /*//SHIFT is handled as LSHIFT in the general case*/
  /*case SHIFT:*/
      /*if (record->event.pressed) {*/
      /*key_timer = timer_read();*/
      /*singular_key = true;*/
        /*layer_on(_SHIFTED);*/
        /*register_code(KC_LSFT);*/
      /*} else {*/
        /*if (timer_elapsed(key_timer) < LAYER_TOGGLE_DELAY || !singular_key) {*/
        /*layer_off(_SHIFTED);*/
          /*unregister_code(KC_LSFT);*/
      /*}*/
    /*}*/
    /*update_tri_layer(_FUNCTION, _SHIFTED, _FUNCSHIFT);*/
      /*return false;*/
      /*break;*/

  /*//If any other key was pressed during the layer mod hold period,*/
  /*//then the layer mod was used momentarily, and should block latching*/
  /*default:*/
    /*singular_key = false;*/
    /*break;*/
  /*}*/

  /*//FUNCSHIFT has been shifted by the SHIFT handling, some keys need to be excluded*/
  /*if (layer == _FUNCSHIFT) {*/
      /*//F1-F12 should be sent as unshifted keycodes, */
      /*//and ] needs to be unshifted or it is sent as }*/
      /*if ( (keycode >= KC_F1 && keycode <= KC_F12)*/
         /*|| keycode == KC_RBRC ) {*/
          /*if (record->event.pressed) {*/
              /*unregister_mods(MOD_LSFT);*/
          /*} else {*/
              /*register_mods(MOD_LSFT);*/
          /*}*/
      /*}*/
  /*}*/

  /*return true;*/
/*};*/

/*void matrix_scan_user(void) {*/
    /*uint8_t layer = biton32(layer_state);*/
    
    /*switch (layer) {*/
        /*case _MALT:*/
            /*set_led_off;*/
            /*break;*/
        /*case _FUNCTION:*/
            /*set_led_blue;*/
            /*break;*/
        /*case _SHIFTED:*/
            /*set_led_red;*/
            /*break;*/
        /*case _FUNCSHIFT:*/
            /*set_led_green;*/
            /*break;*/
        /*default:*/
            /*break;*/
    /*}*/
/*};*/

static void m_handle_kf (keyrecord_t *record, uint8_t id) {
  uint8_t code = id - KF_1;

  if (record->event.pressed) {
    kf_timers[code] = timer_read ();
  } else {
    uint8_t kc_base;
    uint8_t long_press = (kf_timers[code] && timer_elapsed (kf_timers[code]) > TAPPING_TERM);

    kf_timers[code] = 0;

    switch(id){
      case KF_1 ... KF_10:
        if (long_press) {
          // Long press
          kc_base = KC_F1;
        } else {
          kc_base = KC_1;
        }
        code += kc_base;
        break;
      case KF_11:
        code = long_press ? KC_F11 : KC_ESC;
        break;
      case KF_12:
        code = long_press ? KC_F12 : KN_PLUS;
        break;
    }
    register_code (code);
    unregister_code (code);
  }
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch (id) {
    case KF_1 ... KF_12:
      m_handle_kf(record, id);
      break;
  }
  return MACRO_NONE;
};
