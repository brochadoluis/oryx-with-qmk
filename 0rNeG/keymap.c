#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_EQUAL,       KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        TT(7),                                          KC_TRANSPARENT, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_MINUS,       
    TG(4),          KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           TT(8),                                          KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    KC_PSCR,        MT(MOD_LGUI, KC_A),MT(MOD_LALT, KC_S),MT(MOD_LCTL, KC_D),MT(MOD_LSFT, KC_F),KC_G,           KC_HYPR,                                                                        KC_MEH,         KC_H,           MT(MOD_RSFT, KC_J),MT(MOD_RCTL, KC_K),MT(MOD_RALT, KC_L),MT(MOD_RGUI, KC_SCLN),KC_QUOTE,       
    CW_TOGG,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       TG(5),          
    QK_BOOT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME,        LT(6, KC_INSERT),                                                                                                KC_CAPS,        KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_SPACE,       KC_BSPC,        LT(3, KC_TAB),                  LT(2, KC_ESCAPE),KC_DELETE,      KC_ENTER
  ),
  [1] = LAYOUT_moonlander(
    KC_EQUAL,       KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        TG(7),                                          KC_TRANSPARENT, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_MINUS,       
    TG(4),          KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           TG(8),                                          KC_TRANSPARENT, KC_J,           KC_L,           KC_U,           KC_I,           KC_SCLN,        KC_BSLS,        
    KC_PSCR,        MT(MOD_LGUI, KC_A),MT(MOD_LALT, KC_R),MT(MOD_LCTL, KC_S),MT(MOD_LSFT, KC_T),KC_G,           KC_HYPR,                                                                        KC_MEH,         KC_M,           MT(MOD_RSFT, KC_N),MT(MOD_RCTL, KC_E),MT(MOD_RALT, KC_I),MT(MOD_RGUI, KC_O),KC_QUOTE,       
    CW_TOGG,        KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,                                           KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_SLASH,       TG(5),          
    QK_BOOT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME,        LT(6, KC_INSERT),                                                                                                KC_CAPS,        KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_SPACE,       KC_BSPC,        LT(3, KC_TAB),                  LT(2, KC_ESCAPE),KC_DELETE,      KC_ENTER
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_NEXT_TRACK,KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_GRAVE,       KC_TILD,        KC_PIPE,        KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_EXLM,        KC_SLASH,       KC_BSLS,        KC_QUES,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_UNDS,        KC_PLUS,        KC_MINUS,       KC_LABK,        KC_RABK,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_LPRN,        KC_RPRN,        KC_LBRC,        KC_RBRC,        KC_LCBR,        KC_RCBR,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_SLASH,       KC_ASTR,        KC_MINUS,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_PLUS,        KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_MINUS,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_1,           KC_2,           KC_3,           KC_ENTER,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_0,           KC_DOT,         KC_COMMA,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_moonlander(
    AU_TOGG,        KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_UP,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_UP,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    MU_TOGG,        KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_UP,       KC_MS_WH_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_UP,       KC_MS_WH_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT, 
    MU_NEXT,        KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_MS_BTN1,     KC_MS_BTN2,     KC_MS_BTN3,                     KC_MS_BTN3,     KC_MS_BTN2,     KC_MS_BTN1
  ),
  [6] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, PT_TILD,        PT_CIRC,        PT_ACUT,        PT_GRV,         KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, PT_MORD,        PT_FORD,        PT_CCED,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, PT_CCED,        KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [7] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,       
    KC_LEFT_CTRL,   KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_SPACE,       KC_BSPC,        KC_TAB,                         KC_ESCAPE,      KC_DELETE,      KC_ENTER
  ),
  [8] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, PT_QUOT,        PT_COMM,        PT_DOT,         KC_H,           KC_X,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_W,           KC_L,           KC_T,           KC_C,           KC_P,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_I,           KC_E,           KC_A,           KC_O,           KC_U,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_M,           KC_D,           KC_S,           KC_R,           KC_N,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Y,           PT_CCED,        KC_J,           KC_B,           KC_K,                                           KC_Q,           KC_V,           KC_G,           KC_F,           KC_Z,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


const uint16_t PROGMEM combo0[] = { MT(MOD_RSFT, KC_N), MT(MOD_RCTL, KC_E), COMBO_END};
const uint16_t PROGMEM combo1[] = { MT(MOD_LSFT, KC_T), MT(MOD_LCTL, KC_S), COMBO_END};
const uint16_t PROGMEM combo2[] = { MT(MOD_LALT, KC_R), MT(MOD_LCTL, KC_S), COMBO_END};
const uint16_t PROGMEM combo3[] = { MT(MOD_RCTL, KC_E), MT(MOD_RALT, KC_I), COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo5[] = { MT(MOD_RSFT, KC_J), MT(MOD_RCTL, KC_K), COMBO_END};
const uint16_t PROGMEM combo6[] = { MT(MOD_LCTL, KC_D), MT(MOD_LSFT, KC_F), COMBO_END};
const uint16_t PROGMEM combo7[] = { MT(MOD_LALT, KC_S), MT(MOD_LCTL, KC_D), COMBO_END};
const uint16_t PROGMEM combo8[] = { MT(MOD_RCTL, KC_K), MT(MOD_RALT, KC_L), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_ESCAPE),
    COMBO(combo1, KC_TAB),
    COMBO(combo2, KC_CAPS),
    COMBO(combo3, KC_ENTER),
    COMBO(combo4, LALT(KC_F4)),
    COMBO(combo5, KC_ESCAPE),
    COMBO(combo6, KC_TAB),
    COMBO(combo7, KC_CAPS),
    COMBO(combo8, KC_ENTER),
};



extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [2] = { {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255}, {155,255,255} },

    [3] = { {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255}, {8,255,255} },

    [4] = { {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255}, {102,255,255} },

    [5] = { {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255} },

    [6] = { {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255} },

    [7] = { {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255} },

    [8] = { {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255}, {193,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
    switch (biton32(layer_state)) {
      case 2:
        set_layer_color(2);
        break;
      case 3:
        set_layer_color(3);
        break;
      case 4:
        set_layer_color(4);
        break;
      case 5:
        set_layer_color(5);
        break;
      case 6:
        set_layer_color(6);
        break;
      case 7:
        set_layer_color(7);
        break;
      case 8:
        set_layer_color(8);
        break;
     default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}





bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX: 
    // Mouse keys with modifiers work inconsistently across operating systems, this makes sure that modifiers are always
    // applied to the mouse key that was pressed.
    if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
    if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;

    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
  }
  return true;
}

