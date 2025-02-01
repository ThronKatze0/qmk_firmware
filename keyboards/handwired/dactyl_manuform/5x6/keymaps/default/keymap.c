#include <keymap_german.h>

#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _PROGRAM 1
#define _NAV 2

#define NAV MO(_NAV)
#define PROGRAM OSL(_PROGRAM)



enum custom_keycodes {
    SMTD_KEYCODES_BEGIN = SAFE_RANGE,
    CKC_A, // reads as C(ustom) + KC_A, but you may give any name here
    CKC_S,
    CKC_D,
    CKC_F,
    CKC_J,
    CKC_K,
    CKC_L,
    CKC_OE,
    SMTD_KEYCODES_END,
};

#include "sm_td.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }
    return true;
}

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT(CKC_A, DE_A, KC_LEFT_GUI)
        SMTD_LT(CKC_S, DE_S, _NAV)
        SMTD_MT(CKC_D, DE_D, KC_LEFT_CTRL)
        SMTD_MT(CKC_F, DE_F, KC_LSFT)
        SMTD_MT(CKC_J, DE_J, KC_LSFT)
        SMTD_MT(CKC_K, DE_K, KC_LEFT_CTRL)
        SMTD_LT(CKC_L, DE_L, _NAV)
        SMTD_MT(CKC_OE, DE_ODIA, KC_LEFT_GUI)
    }
}

uint32_t get_smtd_timeout(uint16_t keycode, smtd_timeout timeout) {
    switch (keycode) {
        case CKC_F:
        case CKC_J:
            if (timeout == SMTD_TIMEOUT_TAP) return 150;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 5;
        case CKC_D:
        case CKC_K:
            if (timeout == SMTD_TIMEOUT_TAP) return 150;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 5;
        case CKC_S:
        case CKC_L:
            if (timeout == SMTD_TIMEOUT_TAP) return 250;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 5;
        case CKC_A:
        case CKC_OE:
            if (timeout == SMTD_TIMEOUT_TAP) return 270;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 5;
    }

    return get_smtd_timeout_default(timeout);
}

enum combos {
  KL_ESC,
  ENTER_BKSP_CW_TOGG,
  OT_OPEN_TERMINAL,
  KW_KILL_WINDOW,
  ENTER_A_WORKSPACE_1,
  ENTER_S_WORKSPACE_2,
  ENTER_D_WORKSPACE_3,
  ENTER_F_WORKSPACE_4,
  ENTER_J_WORKSPACE_5,
  ENTER_K_WORKSPACE_6,
  ENTER_L_WORKSPACE_7,
  ENTER_OE_WORKSPACE_8,
  EM_EMAIL,
};

const uint16_t PROGMEM kl_combo[] = {CKC_K, CKC_L, COMBO_END};
const uint16_t PROGMEM cw_togg[] = {KC_ENT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM ot_open_terminal[] = {DE_O, DE_T, COMBO_END};
const uint16_t PROGMEM kw_kill_window[] = {CKC_K, DE_W, COMBO_END};
const uint16_t PROGMEM workspace_1_combo[] = {KC_ENT, CKC_A, COMBO_END};
const uint16_t PROGMEM workspace_2_combo[] = {KC_ENT, CKC_S, COMBO_END};
const uint16_t PROGMEM workspace_3_combo[] = {KC_ENT, CKC_D, COMBO_END};
const uint16_t PROGMEM workspace_4_combo[] = {KC_ENT, CKC_F, COMBO_END};
const uint16_t PROGMEM workspace_5_combo[] = {KC_ENT, CKC_J, COMBO_END};
const uint16_t PROGMEM workspace_6_combo[] = {KC_ENT, CKC_K, COMBO_END};
const uint16_t PROGMEM workspace_7_combo[] = {KC_ENT, CKC_L, COMBO_END};
const uint16_t PROGMEM workspace_8_combo[] = {KC_ENT, CKC_OE, COMBO_END};
const uint16_t PROGMEM email_combo[] = {KC_A, KC_B, COMBO_END};

combo_t key_combos[] = {
  [KL_ESC] = COMBO(kl_combo, KC_ESC),
  [ENTER_BKSP_CW_TOGG] = COMBO(cw_togg, CW_TOGG),
  [OT_OPEN_TERMINAL] = COMBO(ot_open_terminal, LGUI(KC_ENT)),
  [KW_KILL_WINDOW] = COMBO(kw_kill_window, LGUI(DE_Q)),
  [ENTER_A_WORKSPACE_1] = COMBO(workspace_1_combo, LGUI(DE_1)),
  [ENTER_S_WORKSPACE_2] = COMBO(workspace_2_combo, LGUI(DE_2)),
  [ENTER_D_WORKSPACE_3] = COMBO(workspace_3_combo, LGUI(DE_3)),
  [ENTER_F_WORKSPACE_4] = COMBO(workspace_4_combo, LGUI(DE_4)),
  [ENTER_J_WORKSPACE_5] = COMBO(workspace_5_combo, LGUI(DE_5)),
  [ENTER_K_WORKSPACE_6] = COMBO(workspace_6_combo, LGUI(DE_6)),
  [ENTER_L_WORKSPACE_7] = COMBO(workspace_7_combo, LGUI(DE_7)),
  [ENTER_OE_WORKSPACE_8] = COMBO(workspace_8_combo, LGUI(DE_8)),
  // EM_EMAIL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x6(
        KC_ESC , DE_1  , DE_2  , DE_3  , DE_4  , DE_5  ,                         DE_6  , DE_7  , DE_8  , DE_9  , DE_0  ,DE_SS,
        KC_TAB , DE_Q  , DE_W  , DE_E  , DE_R  , DE_T  ,                         DE_Z  , DE_U  , DE_I  , DE_O  , DE_P  ,DE_UDIA,
        KC_LSFT, CKC_A , CKC_S , CKC_D , CKC_F , DE_G  ,                         DE_H  , CKC_J , CKC_K , CKC_L ,CKC_OE ,DE_ADIA,
        KC_LCTL, DE_Y  , DE_X  , DE_C  , DE_V  , DE_B  ,                         DE_N  , DE_M  ,DE_COMM,DE_DOT ,DE_MINS,DE_SLSH,
                        KC_HOME,KC_END,                                                       _______, _______,
                                         KC_BSPC,KC_SPC,                        PROGRAM, KC_ENT,
                                         KC_TAB,KC_LCTL,                         PROGRAM,  KC_DEL,
                                         KC_TAB, KC_TAB,                        KC_LGUI, KC_LALT
    ),

    // [_PROGRAM] = LAYOUT_5x6(
    //     KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5 ,                         KC_F6  , KC_F7  , KC_F8  , KC_F9 , KC_F10 , KC_F11 ,
    //     _______, _______, DE_EXLM, DE_QUES, DE_ASTR, DE_TILD,                        DE_DLR , DE_MINS, DE_UNDS, DE_AT , _______, _______,
    //     _______, DE_PLUS, DE_LBRC, DE_LCBR, DE_LPRN, DE_QUOT,                        DE_DQUO, DE_RPRN, DE_RCBR, DE_RBRC, DE_EQL , _______,
    //     _______, _______, DE_AMPR, DE_HASH ,DE_LABK, DE_GRV ,                        DE_PIPE, DE_RABK, DE_SCLN, _______, _______, _______,
    //                       _______, _______,                                                            _______, _______,
    //                                                 _______, _______,            _______, _______,
    //                                                 _______, _______,            _______, _______,
    //                                                 _______, _______,            _______, _______
    // ),

    [_PROGRAM] = LAYOUT_5x6(
        KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5 ,                         KC_F6  , KC_F7  , KC_F8  , KC_F9 , KC_F10 , KC_F11 ,
        _______, DE_AMPR, DE_BSLS, DE_LCBR, DE_RCBR, DE_PERC,                        DE_QUOT, DE_LABK, DE_RABK, DE_QUOT, _______, _______,
        _______, DE_PIPE, _______, DE_LPRN, DE_RPRN, DE_QUES,                        DE_EXLM, DE_MINS, DE_PLUS, DE_EQL , DE_HASH, _______,
        _______, DE_TILD, DE_DLR , DE_LBRC ,DE_RBRC, DE_AT  ,                        DE_CIRC, DE_ASTR, DE_SCLN, DE_COLN, DE_UNDS, DE_SLSH,
                          _______, _______,                                                            _______, _______,
                                                    _______, _______,            _______, _______,
                                                    _______, _______,            _______, _______,
                                                    _______, _______,            _______, _______
    ),

    [_NAV] = LAYOUT_5x6(
        KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5 ,                         KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
          _______,_______,DE_7   ,DE_8   ,DE_9   ,_______,                    _______,  _______ ,  _______ ,  _______,_______,_______,
          _______,_______,DE_4   ,DE_5   ,DE_6   ,_______,                    _______,  KC_LEFT ,  KC_DOWN ,  KC_UP , KC_RIGHT,_______,
          _______,_______,DE_1   ,DE_2   ,DE_3   ,_______,                    _______,  _______ ,  _______ ,  _______ ,_______,_______,
                          _______,DE_0   ,                                              _______ , _______,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______
    )
};
