// Hand-written behaviour for the pxmnD layout.
//
// Oryx owns every key: keymaps[][] in keymap.c is never hand-edited, so Oryx
// fetches merge without conflicts. This file only
//   - intercepts the placeholder keycodes Oryx places (F13-F21), and
//   - adds hooks Oryx does not generate (tapping terms, Caps Word).
// Hooked into keymap.c by exactly two lines: `#include "custom.h"` and the
// first line of process_record_user. Built via `SRC += custom.c` in rules.mk.
//
// F-key map (must match the Oryx labels):
//   F13 ==   F14 !=   F15 <=   F16 >=   F17 &&   F18 ||   F19 ->
//   F20 base QWERTY (layer 0)   F21 base Colemak-DH (layer 1)
// F13-F21 never reach the host. F22-F24 are still free.

#include "custom.h"

// Linux xkb "pt" positions. Raw keycodes on purpose: QMK's
// keymap_portuguese.h redefines names Oryx's i18n.h already defines, and the
// build runs with -Werror.
#define PTX_EQL  S(KC_0)     // =
#define PTX_EXLM S(KC_1)     // !
#define PTX_LABK KC_NUBS     // <
#define PTX_RABK S(KC_NUBS)  // >
#define PTX_AMPR S(KC_6)     // &
#define PTX_PIPE S(KC_GRV)   // |
#define PTX_MINS KC_SLSH     // -

static void tap2(uint16_t a, uint16_t b) {
    tap_code16(a);
    tap_code16(b);
}

bool process_record_custom(uint16_t keycode, keyrecord_t *record) {
    if (keycode < KC_F13 || keycode > KC_F21) {
        return true;
    }
    if (!record->event.pressed) {
        return false;
    }
    switch (keycode) {
        case KC_F13: tap2(PTX_EQL,  PTX_EQL);  break;  // ==
        case KC_F14: tap2(PTX_EXLM, PTX_EQL);  break;  // !=
        case KC_F15: tap2(PTX_LABK, PTX_EQL);  break;  // <=
        case KC_F16: tap2(PTX_RABK, PTX_EQL);  break;  // >=
        case KC_F17: tap2(PTX_AMPR, PTX_AMPR); break;  // &&
        case KC_F18: tap2(PTX_PIPE, PTX_PIPE); break;  // ||
        case KC_F19: tap2(PTX_MINS, PTX_RABK); break;  // ->
        case KC_F20: set_single_persistent_default_layer(0); break;
        case KC_F21: set_single_persistent_default_layer(1); break;
    }
    return false;
}

// Per-finger tapping terms. DORMANT: only called when config.h defines
// TAPPING_TERM_PER_KEY, which it does not. It never did -- 0rNeG had this
// function without the define, so the board has run the 200 ms default on
// every key all along. Left off for the first pxmnD flash so Chordal Hold is
// the only timing change; enabling it is a deliberate Phase 4 step.
// Labels must match keymap.c exactly; a stale one silently falls to default.
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Pinkies
        case MT(MOD_LGUI, KC_A):     // both bases
        case MT(MOD_RGUI, KC_SCLN):  // QWERTY (pt: ç)
        case MT(MOD_RGUI, KC_O):     // Colemak
            return 200;
        // Ring -- right hand is Left Alt since the Oryx pass (AltGr under pt)
        case MT(MOD_LALT, KC_S):     // QWERTY
        case MT(MOD_LALT, KC_L):     // QWERTY
        case MT(MOD_LALT, KC_R):     // Colemak
        case MT(MOD_LALT, KC_I):     // Colemak
            return 190;
        // Middle
        case MT(MOD_LCTL, KC_D):     // QWERTY
        case MT(MOD_RCTL, KC_K):     // QWERTY
        case MT(MOD_LCTL, KC_S):     // Colemak
        case MT(MOD_RCTL, KC_E):     // Colemak
            return 180;
        // Index
        case MT(MOD_LSFT, KC_F):     // QWERTY
        case MT(MOD_RSFT, KC_J):     // QWERTY
        case MT(MOD_LSFT, KC_T):     // Colemak
        case MT(MOD_RSFT, KC_N):     // Colemak
            return 175;
        default:
            return TAPPING_TERM;
    }
}

// Caps Word under Linux "pt".
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Continue, shifted
        case KC_A ... KC_Z:
        case KC_SCLN:   // ç
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;

        // Continue, unshifted
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_SLSH:   // - (and _ with Shift)
        case KC_RBRC:   // dead acute / grave -- shifting it would give grave
        case KC_NUHS:   // dead tilde / circumflex -- shifting it would give ^
            return true;

        default:
            return false;
    }
}
