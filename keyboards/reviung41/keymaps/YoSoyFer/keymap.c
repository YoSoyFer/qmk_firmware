/* Copyright 2020 gtips
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap_spanish.h"

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _NUM,
    _ADJUST
};

#define LOCK_OS LGUI(KC_L)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty 0
   * ,-----------------------------------------+         +-----------------------------------------.
   * | Esc  |   Q  |   W  |   E  |   R  |   T  |         |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------+         +------+------+------+------+------+------|
   * |Ctl(TAB)| A  |   S  |   D  |   F  |   G  |         |   H  |   J  |   K  |   L  |   Ñ  |Ctl(´)|
   * |------+------+------+------+------+------+         +------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |         |   N  |   M  |   ,  |   .  |   -  |Shift(ENT)|
   * |------+------+------+------+------+------+         +------+------+------+------+------+------|
   *                             | Alt  | Lower|Space Num| Raise| Win |
   *                             +------------/          \-------------+
   */
  [_BASE] = LAYOUT_reviung41(
    KC_ESC,          KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,                      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    RCTL_T(KC_TAB),  KC_A,     KC_S,     KC_D,     KC_F,      KC_G,                      KC_H,     KC_J,     KC_K,     KC_L,     ES_NTIL,  RCTL_T(ES_ACUT),
    KC_LSFT,         KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,                      KC_N,     KC_M,     ES_COMM,  ES_DOT,   ES_MINS,  RSFT_T(KC_ENT),
                                                   KC_LALT,   MO(1),    LT(3, KC_SPC),    MO(2),    KC_LGUI
  ),

  /* LOWER 1
  * ,-----------------------------------------+         +-----------------------------------------.
  * |      |      |      |      |      |      |         | PGUP | HOME |  UP  | END  |      |      |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  * |      | Win  | Alt  |Shift | Ctrl |      |         | PDOWN| LEFT | DOWN | RIGHT|      |      |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |         |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  *                             |      |      |         |      |      |
  *                             +-------------/         \-------------+
  */
  [_LOWER] = LAYOUT_reviung41(
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   XXXXXXX,  _______,
    _______,  KC_LGUI,  KC_LALT,  KC_LSFT,  KC_LCTL,   XXXXXXX,            KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  _______,
    KC_F1,    KC_F2,    KC_F3,    KC_F4,     KC_F5,    KC_F6,              KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
                                            _______,   _______,  _______,    MO(4),  _______
  ),

  /* RAISE 2
 * ,-----------------------------------------+         +-----------------------------------------.
 * |   ç  |   ª  |   @  |   <  |   >  |   ¡  |         |   !  |   (  |   )  |   *  |   `  |  Del |
 * |------+------+------+------+------+------+         +------+------+------+------+------+------|
 * |   ¬  |   º  |   +  |  %   |   =  |   ¿  |         |   ?  |   {  |   }  |   "  |   '  |      |
 * |------+------+------+------+------+------+         +------+------+------+------+------+------|
 * |      |   $  |   #  |   |  |   &  |   \  |         |   /  |   [  |   ]  |   ^  |   ~  |      |
 * |------+------+------+------+------+------+         +------+------+------+------+------+------|
 *                             |      |      |  Space  |      |      |
 *                             +-------------/         \-------------+
 */
  [_RAISE] = LAYOUT_reviung41(
    ES_CCED,  ES_FORD,  ES_AT  ,  ES_LABK,  ES_RABK,   ES_IEXL,            ES_EXLM,  ES_LPRN,  ES_RPRN,  ES_ASTR,  ES_GRV ,  KC_DEL ,
    ES_NOT ,  ES_MORD,  ES_PLUS,  ES_PERC,  ES_EQL ,   ES_IQUE,            ES_QUES,  ES_LCBR,  ES_RCBR,  ES_DQUO,  ES_QUOT,  XXXXXXX,
    XXXXXXX,   ES_DLR,  ES_HASH,  ES_PIPE,  ES_AMPR,   ES_BSLS,            ES_SLSH,  ES_LBRC,  ES_RBRC,  ES_CIRC,  ES_TILD,  XXXXXXX,
                                            XXXXXXX,     MO(4),  KC_SPC,   _______,  XXXXXXX
  ),


  /* NUM 3
  * ,-----------------------------------------+         +-----------------------------------------.
  * |      |   1  |   2  |   3  |   4  |   5  |         |   6  |   7  |   8  |   9  |   0  |  BSP |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  * |      |      |      |      |      |      |         |   +  |   4  |   5  |   6  |   *  |   ,  |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  * | LOCK |      |      |      | MUTE | PSCR |         |   -  |   1  |   2  |   3  |   /  | P_ENT |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  *                             |      |      |         |  0   |   .  |
  *                             +-------------/         \-------------+
  */
  [_NUM] = LAYOUT_reviung41(
    XXXXXXX,     KC_1,     KC_2,     KC_3,     KC_4,      KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,  _______,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            KC_PPLS,     KC_4,     KC_5,     KC_6,  KC_PAST,  KC_PCMM,
    LOCK_OS,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MUTE,   KC_PSCR,            KC_PMNS,     KC_1,     KC_2,     KC_3,  KC_PSLS,  KC_PENT,
                                            XXXXXXX,   XXXXXXX,  XXXXXXX,     KC_0,  KC_PDOT
  ),


  /* _ADJUST 4
  * ,-----------------------------------------+         +-----------------------------------------.
  * |      |      |      |      |      |      |         |      |      |      |      |      |      |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  * |      |      |      |      |      |      |         |      |      |      |      |      |      |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  * |      |      |      |      |      |      |         |      |      |      |      |      |      |
  * |------+------+------+------+------+------+         +------+------+------+------+------+------|
  *                             |      |      |         |      |      |
  *                             +-------------/         \-------------+
  */
  [_ADJUST] = LAYOUT_reviung41(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RESET,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                            _______,   _______,  XXXXXXX,  _______,  _______
  ),
};
