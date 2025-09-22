#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif


// =============================================================================
// LAYER DEFINITIONS
// =============================================================================
enum layers {
    BASE_QWERTY,
    BASE_COLEMAK_DH,
    NAV,
    SYMBOLS,
    NUMPAD,
    MOUSE,
    PT_NATIVE,
    GAMING,
    PT_LAYOUT
};


// =============================================================================
// CUSTOM KEYCODES
// =============================================================================
enum custom_keycodes {
    RGB_SLD = SAFE_RANGE,
    
    // OS-aware shortcuts
    CUT, COPY, PASTE, UNDO, REDO, SELECT_ALL,

    // Browser controls
    BR_NEW, BR_CLOSE, BR_PREV, BR_NEXT, BR_REOPEN, BR_REFRESH, BR_FOCUS,

    // Screenshot shortcuts
    SS_FULL, SS_AREA, SS_WINDOW, SS_CLIPBOARD,
    
    // Comparison operators 
    OP_EQ, OP_NEQ, OP_LTE, OP_GTE, OP_AND, OP_OR, OP_ARROW,
    
    // Layer switchers
    DF_QWERTY, DF_COLEMAK
};


// =============================================================================
// TAP DANCE
// =============================================================================
typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

enum {
    TD_NEW_CLOSE_TAB,
};

static tap dance_state[1]; 

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void on_new_close_tab(tap_dance_state_t *state, void *user_data);
void new_close_tab_finished(tap_dance_state_t *state, void *user_data);
void new_close_tab_reset(tap_dance_state_t *state, void *user_data);

void new_close_tab_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
      case SINGLE_TAP: 
        // New tab - OS aware
        switch (detected_host_os()) {
          case OS_MACOS:
          case OS_IOS:
            tap_code16(LGUI(KC_T));
            break;
          default:
            tap_code16(LCTL(KC_T));
            break;
        }
        break;
            
      case DOUBLE_TAP: 
        // Close tab - OS aware
        switch (detected_host_os()) {
          case OS_MACOS:
          case OS_IOS:
            tap_code16(LGUI(KC_W));
            break;
          default:
            tap_code16(LCTL(KC_W));
            break;
        }
        break;
            
      case DOUBLE_SINGLE_TAP: 
        // Handle accidental double single tap as single tap
        switch (detected_host_os()) {
          case OS_MACOS:
          case OS_IOS:
            tap_code16(LGUI(KC_T));
            break;
          default:
            tap_code16(LCTL(KC_T));
            break;
        }
        break;
    }
}

void new_close_tab_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    dance_state[0].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_NEW_CLOSE_TAB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, new_close_tab_finished, new_close_tab_reset),
};

// =============================================================================
// KEYMAPS
// =============================================================================
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE_QWERTY] = LAYOUT_moonlander(
    KC_EQUAL,       KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        TT(GAMING),                                          KC_TRANSPARENT, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_MINUS,       
    TG(NUMPAD),          KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           TT(PT_LAYOUT),                                          KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    KC_PSCR,        MT(MOD_LGUI, KC_A),MT(MOD_LALT, KC_S),MT(MOD_LCTL, KC_D),MT(MOD_LSFT, KC_F),KC_G,           KC_HYPR,                                                                        KC_MEH,         KC_H,           MT(MOD_RSFT, KC_J),MT(MOD_RCTL, KC_K),MT(MOD_RALT, KC_L),MT(MOD_RGUI, KC_SCLN),KC_QUOTE,       
    CW_TOGG,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       TG(MOUSE),          
    QK_BOOT,        DF_QWERTY, DF_COLEMAK, KC_TRANSPARENT, KC_HOME,        LT(PT_NATIVE, KC_INSERT),                                                                                                CW_TOGG,        KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_SPACE,       KC_BSPC,        LT(SYMBOLS, KC_TAB),                  LT(NAV, KC_ESCAPE),KC_DELETE,      KC_ENTER
  ),
  [BASE_COLEMAK_DH] = LAYOUT_moonlander(
    KC_EQUAL,       KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        TG(GAMING),                                          KC_TRANSPARENT, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_MINUS,       
    TG(NUMPAD),          KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           TG(PT_LAYOUT),                                          KC_TRANSPARENT, KC_J,           KC_L,           KC_U,           KC_I,           KC_SCLN,        KC_BSLS,        
    KC_PSCR,        MT(MOD_LGUI, KC_A),MT(MOD_LALT, KC_R),MT(MOD_LCTL, KC_S),MT(MOD_LSFT, KC_T),KC_G,           KC_HYPR,                                                                        KC_MEH,         KC_M,           MT(MOD_RSFT, KC_N),MT(MOD_RCTL, KC_E),MT(MOD_RALT, KC_I),MT(MOD_RGUI, KC_O),KC_QUOTE,       
    CW_TOGG,        KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,                                           KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_SLASH,       TG(MOUSE),          
    QK_BOOT,        DF_QWERTY, DF_COLEMAK, KC_TRANSPARENT, KC_HOME,        LT(PT_NATIVE, KC_INSERT),                                                                                                CW_TOGG,        KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_SPACE,       KC_BSPC,        LT(SYMBOLS, KC_TAB),                  LT(NAV, KC_ESCAPE),KC_DELETE,      KC_ENTER
  ),
  [NAV] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,RGB_TOG, RGB_VAD, RGB_VAI, RGB_MODE_FORWARD,                                 KC_TRANSPARENT, KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, UNDO,           REDO, CUT, COPY, PASTE, SELECT_ALL,                                 KC_TRANSPARENT, BR_REFRESH, KC_MEDIA_NEXT_TRACK,KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,BR_FOCUS, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, BR_REOPEN,  TD(TD_NEW_CLOSE_TAB), BR_PREV, BR_NEXT, KC_TRANSPARENT,                                 KC_TRANSPARENT, SS_FULL, SS_AREA, SS_WINDOW, SS_CLIPBOARD, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [SYMBOLS] = LAYOUT_moonlander(
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_GRAVE,       KC_TILD,        KC_PIPE,        KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_EXLM,        KC_SLASH,       KC_BSLS,        KC_QUES,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_UNDS,        KC_PLUS,        KC_MINUS,       KC_LABK,        KC_RABK,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_LPRN,        KC_RPRN,        KC_LBRC,        KC_RBRC,        KC_LCBR,        KC_RCBR,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [NUMPAD] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_SLASH,       KC_ASTR,        KC_MINUS,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_PLUS,        KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_MINUS,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_1,           KC_2,           KC_3,           KC_ENTER,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_0,           KC_DOT,         KC_COMMA,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [MOUSE] = LAYOUT_moonlander(
    AU_TOGG,        KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_UP,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_UP,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    MU_TOGG,        KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_UP,       KC_MS_WH_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_UP,       KC_MS_WH_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT, 
    MU_NEXT,        KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_MS_BTN1,     KC_MS_BTN2,     KC_MS_BTN3,                     KC_MS_BTN3,     KC_MS_BTN2,     KC_MS_BTN1
  ),
  [PT_NATIVE] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, PT_TILD,        PT_CIRC,        PT_ACUT,        PT_GRV,         KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, PT_MORD,        PT_FORD,        PT_CCED,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, PT_CCED,        KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [GAMING] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,       
    KC_LEFT_CTRL,   KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_SPACE,       KC_BSPC,        KC_TAB,                         KC_ESCAPE,      KC_DELETE,      KC_ENTER
  ),
  [PT_LAYOUT] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, PT_QUOT,        PT_COMM,        PT_DOT,         KC_H,           KC_X,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_W,           KC_L,           KC_T,           KC_C,           KC_P,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_I,           KC_E,           KC_A,           KC_O,           KC_U,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_M,           KC_D,           KC_S,           KC_R,           KC_N,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Y,           PT_CCED,        KC_J,           KC_B,           KC_K,                                           KC_Q,           KC_V,           KC_G,           KC_F,           KC_Z,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


// =============================================================================
// COMBOS
// =============================================================================
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
    COMBO(combo2, CW_TOGG),
    COMBO(combo3, KC_ENTER),
    COMBO(combo4, LALT(KC_F4)),
    COMBO(combo5, KC_ESCAPE),
    COMBO(combo6, KC_TAB),
    COMBO(combo7, CW_TOGG),
    COMBO(combo8, KC_ENTER),
};

// =============================================================================
// TAPPING TERM OPTIMIZATION
// =============================================================================
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Pinkies
        case MT(MOD_LGUI, KC_A): // Both
        case MT(MOD_RGUI, KC_SCLN):
        case MT(MOD_RGUI, KC_O):  // Colemak
            return 200;
        // Ring fingers
        case MT(MOD_LALT, KC_S):
        case MT(MOD_RALT, KC_L):  
        case MT(MOD_LALT, KC_R):  // Colemak
        case MT(MOD_RALT, KC_I):  // Colemak
            return 190;
        // Middle fingers
        case MT(MOD_LCTL, KC_D):
        case MT(MOD_RCTL, KC_K):
        case MT(MOD_LCTL, KC_S):  // Colemak
        case MT(MOD_RCTL, KC_E):  // Colemak
            return 180;
        // Index fingers
        case MT(MOD_LSFT, KC_F):
        case MT(MOD_RSFT, KC_J):
        case MT(MOD_LSFT, KC_T):  // Colemak
        case MT(MOD_RSFT, KC_N):  // Colemak
            return 175;
        default:
            return TAPPING_TERM;
    }
}


// =============================================================================
// RGB LAYER INDICATION
// =============================================================================
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
      case BASE_QWERTY:
      case BASE_COLEMAK_DH:
        rgb_matrix_set_color_all(0, 0, 0);
        break;    
      case NAV:        // Ice Blue
        rgb_matrix_set_color_all(100, 200, 255);  // #64C8FF
        break;    
      case SYMBOLS:    // Orange
        rgb_matrix_set_color_all(255, 100, 0);   // #FF6400
          break;  
      case NUMPAD:     // Green
        rgb_matrix_set_color_all(0, 180, 0);     // #00B400
        break;    
      case MOUSE:      // Coral
        rgb_matrix_set_color_all(255, 80, 80);   // #FF5050
        break;    
      case PT_NATIVE:  // Purple
        rgb_matrix_set_color_all(160, 100, 220); // #A064DC
        break;      
      case GAMING:     // Magenta
        rgb_matrix_set_color_all(220, 0, 150);   // #DC0096
        break;    
      case PT_LAYOUT:  // Dark Purple
        rgb_matrix_set_color_all(80, 50, 120);   // #503278
        break;
    }
  return state;
}


// =============================================================================
// MACRO IMPLEMENTATIONS
// =============================================================================
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

  if (record->event.pressed) {
    switch (keycode) {
      // Layer switchers
      case DF_QWERTY:
        set_single_persistent_default_layer(BASE_QWERTY);
        return false;
      case DF_COLEMAK:
        set_single_persistent_default_layer(BASE_COLEMAK_DH);
        return false;
      // OS-aware shortcuts
      case CUT:
        switch (detected_host_os()) {
          case OS_MACOS:
          case OS_IOS:
            tap_code16(LGUI(KC_X));
            break;
          default:
            tap_code16(LCTL(KC_X));
            break;
        }
        return false;
        
      case COPY:
        switch (detected_host_os()) {
          case OS_MACOS:
          case OS_IOS:
            tap_code16(LGUI(KC_C));
            break;
          default:
            tap_code16(LCTL(KC_C));
            break;
        }
        return false;
        
      case PASTE:
        switch (detected_host_os()) {
          case OS_MACOS:
          case OS_IOS:
            tap_code16(LGUI(KC_V));
            break;
          default:
            tap_code16(LCTL(KC_V));
            break;
        }
        return false;
        
      case UNDO:
        switch (detected_host_os()) {
          case OS_MACOS:
          case OS_IOS:
            tap_code16(LGUI(KC_Z));
            break;
          default:
            tap_code16(LCTL(KC_Z));
            break;
        }
        return false;
        
      case REDO:
        switch (detected_host_os()) {
          case OS_MACOS:
          case OS_IOS:
            tap_code16(LGUI(LSFT(KC_Z)));
            break;
          case OS_LINUX:
            tap_code16(LCTL(LSFT(KC_Z)));
            break;
          default: // Windows
            tap_code16(LCTL(KC_Y));
            break;
        }
        return false;
        
      case SELECT_ALL:
        switch (detected_host_os()) {
          case OS_MACOS:
          case OS_IOS:
            tap_code16(LGUI(KC_A));
            break;
          default:
            tap_code16(LCTL(KC_A));
            break;
        }
        return false;
    
      // Browser controls
      case BR_NEW:
        switch (detected_host_os()) {
          case OS_MACOS:
          case OS_IOS:
            tap_code16(LGUI(KC_T));
            break;
          default:
            tap_code16(LCTL(KC_T));
            break;
        }
        return false;
        
      case BR_CLOSE:
        switch (detected_host_os()) {
          case OS_MACOS:
          case OS_IOS:
            tap_code16(LGUI(KC_W));
            break;
          default:
            tap_code16(LCTL(KC_W));
            break;
        }
        return false;
        
      case BR_PREV:
        switch (detected_host_os()) {
          case OS_MACOS:
          case OS_IOS:
            tap_code16(LGUI(LALT(KC_LEFT)));
            break;
          default:
            tap_code16(LCTL(LSFT(KC_TAB)));
            break;
        }
        return false;
        
      case BR_NEXT:
        switch (detected_host_os()) {
          case OS_MACOS:
          case OS_IOS:
            tap_code16(LGUI(LALT(KC_RGHT)));
            break;
          default:
            tap_code16(LCTL(KC_TAB));
            break;
        }
        return false;
        
      case BR_REOPEN:
        switch (detected_host_os()) {
          case OS_MACOS:
          case OS_IOS:
            tap_code16(LGUI(LSFT(KC_T)));
            break;
          default:
            tap_code16(LCTL(LSFT(KC_T)));
            break;
        }
        return false;
        
      case BR_REFRESH:
        switch (detected_host_os()) {
          case OS_MACOS:
          case OS_IOS:
            tap_code16(LGUI(KC_R));
            break;
          default:
            tap_code16(LCTL(KC_R));
            break;
        }
        return false;
        
      case BR_FOCUS:
        switch (detected_host_os()) {
          case OS_MACOS:
          case OS_IOS:
            tap_code16(LGUI(KC_L));
            break;
          default:
            tap_code16(LCTL(KC_L));
            break;
        }
        return false;
    
      // Comparison operators 
      case OP_EQ:
        tap_code16(KC_EQL);
        tap_code16(KC_EQL);
        return false;
      case OP_NEQ:
        tap_code16(KC_EXLM);    
        tap_code16(KC_EQL);      
        return false;
      case OP_LTE:
        tap_code16(KC_LABK);    
        tap_code16(KC_EQL);    
        return false;
      case OP_GTE:
        tap_code16(KC_RABK);    
        tap_code16(KC_EQL);    
        return false;
      // Screenshot shortcuts
      case SS_FULL:
        switch (detected_host_os()) {
          case OS_MACOS:
          case OS_IOS:
            tap_code16(LGUI(LSFT(KC_3)));
            break;
          default:
            tap_code16(KC_PSCR);
            break;
        }
        return false;
        
      case SS_AREA:
        switch (detected_host_os()) {
          case OS_MACOS:
          case OS_IOS:
            tap_code16(LGUI(LSFT(KC_4)));
            break;
          case OS_LINUX:
            tap_code16(LSFT(KC_PSCR));
            break;
          default:
            tap_code16(LGUI(LSFT(KC_S)));
            break;
        }
        return false;
        
      case SS_WINDOW:
        switch (detected_host_os()) {
          case OS_MACOS:
          case OS_IOS:
            tap_code16(LGUI(LSFT(KC_4)));
            wait_ms(100);
            tap_code(KC_SPC);
            break;
          case OS_LINUX:
            tap_code16(LALT(KC_PSCR));
            break;
          default:
            tap_code16(LALT(KC_PSCR));
            break;
        }
        return false;
        
      case SS_CLIPBOARD:
        switch (detected_host_os()) {
          case OS_MACOS:
          case OS_IOS:
            tap_code16(LGUI(LCTL(LSFT(KC_4))));
            break;
          case OS_LINUX:
            tap_code16(LCTL(LSFT(KC_PSCR)));
            break;
          default:
            tap_code16(LGUI(LSFT(KC_S)));
            break;
        }
        return false;
    }
  }

  return true;
}


// =============================================================================
// CAPS WORD CONFIGURATION
// =============================================================================
bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied
    case KC_A ... KC_Z:
      add_weak_mods(MOD_BIT(KC_LSFT));
      return true;

    // Keycodes that continue Caps Word, without shift
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case KC_UNDS:
    case KC_MINS:
      return true;
    default:
      return false;  // Deactivate Caps Word
  }
}


// =============================================================================
// INITIALIZATION
// =============================================================================
void keyboard_post_init_user(void) {
  // Enable RGB for layer indication
  rgb_matrix_enable();

  // Auto-swap modifiers for macOS
  if (detected_host_os() == OS_MACOS || detected_host_os() == OS_IOS) {
    keymap_config.swap_lalt_lgui = true;
    keymap_config.swap_ralt_rgui = true;
    eeconfig_update_keymap(&keymap_config);
  }
}
