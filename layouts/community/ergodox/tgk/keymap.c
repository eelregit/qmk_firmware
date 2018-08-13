/*
   Copyright
   2016 Yin Li <eelregit@gmail.com>

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// algernon
// german-manuneo
// coderkun_neo2 overriding
//
// slow ^{[(
// compose key not working

#include QMK_KEYBOARD_H
#include "greek_unicode.h"

enum layers {
    LATL = 0,
    LATU,
    SYMB,
    GRKL,
    GRKU,
};

/* modifiers */
#define OSM_ALT OSM(MOD_LALT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_SALT OSM(MOD_LALT | MOD_LSFT)
#define OSM_SCTL OSM(MOD_LCTL | MOD_LSFT)
#define OSM_SGUI OSM(MOD_LGUI | MOD_LSFT)

/* map right alt to compose key in GNOME */
#define X_COMP KC_RALT

/* Ergodox geometry
 * ┏━━━━━┯━━━━┯━━━━┯━━━━┯━━━━┯━━━━┯━━━━┳━━━━┯━━━━┯━━━━┯━━━━┯━━━━┯━━━━┯━━━━━┓
 * ┃     │    │    │    │    │    │    ┃    │    │    │    │    │    │     ┃
 * ┠─────┼────┼────┼────┼────┼────┼────╂────┼────┼────┼────┼────┼────┼─────┨
 * ┃     │    │    │    │    │    │    ┃    │    │    │    │    │    │     ┃
 * ┠─────┼────┼────┼────┼────┼────┤    ┃    ├────┼────┼────┼────┼────┼─────┨
 * ┃     │    │    │    │    │    ├────╂────┤    │    │    │    │    │     ┃
 * ┠─────┼────┼────┼────┼────┼────┤    ┃    ├────┼────┼────┼────┼────┼─────┨
 * ┃     │    │    │    │    │    │    ┃    │    │    │    │    │    │     ┃
 * ┗┱────┼────┼────┼────┼────╆━━━━┷━━━━┻━━━━┷━━━━╅────┼────┼────┼────┼────┲┛
 *  ┃    │    │    │    │    ┃                   ┃    │    │    │    │    ┃
 *  ┗━━━━┷━━━━┷━━━━┷━━━━┷━━━━┛                   ┗━━━━┷━━━━┷━━━━┷━━━━┷━━━━┛
 *                          ┏━━━━┯━━━━┓ ┏━━━━┯━━━━┓
 *                          ┃    │    ┃ ┃    │    ┃
 *                     ┏━━━━╃────┼────┨ ┠────┼────╄━━━━┓
 *                     ┃    │    │    ┃ ┃    │    │    ┃
 *                     ┃    │    ├────┨ ┠────┤    │    ┃
 *                     ┃    │    │    ┃ ┃    │    │    ┃
 *                     ┗━━━━┷━━━━┷━━━━┛ ┗━━━━┷━━━━┷━━━━┛
 */

/* keymap */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Latin lowercase
 * ┏━━━━━┯━━━━┯━━━━┯━━━━┯━━━━┯━━━━┯━━━━┳━━━━┯━━━━┯━━━━┯━━━━┯━━━━┯━━━━┯━━━━━┓
 * ┃     │ 9  │ 7  │ 5  │ 3  │ 1  │F11 ┃ F12│  0 │  2 │  4 │  6 │  8 │     ┃
 * ┠─────┼────┼────┼────┼────┼────┼────╂────┼────┼────┼────┼────┼────┼─────┨
 * ┃     │ :  │ /  │ .  │ p  │ y  │    ┃    │  f │  g │  c │  r │  l │     ┃
 * ┠─────┼────┼────┼────┼────┼────┤    ┃    ├────┼────┼────┼────┼────┼─────┨
 * ┃  ↹  │ a  │ o  │ e  │ u  │ i  ├────╂────┤  d │  h │  t │  n │  s │  ⎋  ┃
 * ┠─────┼────┼────┼────┼────┼────┤    ┃    ├────┼────┼────┼────┼────┼─────┨
 * ┃  ⌫  │ '  │ q  │ j  │ k  │ x  │    ┃    │  b │  m │  w │  v │  z │  ⌦  ┃
 * ┗┱────┼────┼────┼────┼────╆━━━━┷━━━━┻━━━━┷━━━━╅────┼────┼────┼────┼────┲┛
 *  ┃    │ ←  │ →  │ ↓  │ ↑  ┃                   ┃  ⇞ │  ⇟ │  ⇺ │  ⇻ │    ┃
 *  ┗━━━━┷━━━━┷━━━━┷━━━━┷━━━━┛                   ┗━━━━┷━━━━┷━━━━┷━━━━┷━━━━┛
 *                          ┏━━━━┯━━━━┓ ┏━━━━┯━━━━┓
 *                          ┃    │    ┃ ┃    │    ┃
 *                     ┏━━━━╃────┼────┨ ┠────┼────╄━━━━┓
 *                     ┃    │    │ ♫  ┃ ┃  ☯ │    │    ┃
 *                     ┃ ⇧1 │ ␣  ├────┨ ┠────┤  ↩ │ ⇧2 ┃
 *                     ┃    │    │ ⎇  ┃ ┃  ⎈ │    │    ┃
 *                     ┗━━━━┷━━━━┷━━━━┛ ┗━━━━┷━━━━┷━━━━┛
 */
[LATL] = LAYOUT_ergodox(
KC_NO,      KC_9,       KC_7,       KC_5,       KC_3,       KC_1,       KC_F11,
KC_NO,      KC_COLN,    KC_SLSH,    KC_DOT,     KC_P,       KC_Y,       KC_NO,
KC_TAB,     KC_A,       KC_O,       KC_E,       KC_U,       KC_I,
KC_BSPC,    KC_QUOT,    KC_Q,       KC_J,       KC_K,       KC_X,       KC_NO,
KC_NO,      KC_LEFT,    KC_RGHT,    KC_DOWN,    KC_UP,
                                                            KC_NO,      KC_NO,
                                                                        X_COMP,
                                                OSL(LATU),  KC_SPC,     OSM_ALT,
KC_F12,     KC_0,       KC_2,       KC_4,       KC_6,       KC_8,       KC_NO,
KC_NO,      KC_F,       KC_G,       KC_C,       KC_R,       KC_L,       KC_NO,
            KC_D,       KC_H,       KC_T,       KC_N,       KC_S,       KC_ESC,
KC_NO,      KC_B,       KC_M,       KC_W,       KC_V,       KC_Z,       KC_DEL,
                        KC_PGUP,    KC_PGDN,    KC_HOME,    KC_END,     KC_NO,
KC_NO,      KC_NO,
OSM_GUI,
OSM_CTL,   KC_ENT,     OSL(SYMB)),

/* Latin uppercase
 * ┏━━━━━┯━━━━┯━━━━┯━━━━┯━━━━┯━━━━┯━━━━┳━━━━┯━━━━┯━━━━┯━━━━┯━━━━┯━━━━┯━━━━━┓
 * ┃     │    │    │    │    │    │    ┃    │    │    │    │    │    │     ┃
 * ┠─────┼────┼────┼────┼────┼────┼────╂────┼────┼────┼────┼────┼────┼─────┨
 * ┃     │ ;  │ \  │ ,  │ P  │ Y  │    ┃    │  F │  G │  C │  R │  L │     ┃
 * ┠─────┼────┼────┼────┼────┼────┤    ┃    ├────┼────┼────┼────┼────┼─────┨
 * ┃     │ A  │ O  │ E  │ U  │ I  ├────╂────┤  D │  H │  T │  N │  S │     ┃
 * ┠─────┼────┼────┼────┼────┼────┤    ┃    ├────┼────┼────┼────┼────┼─────┨
 * ┃     │ "  │ Q  │ J  │ K  │ X  │    ┃    │  B │  M │  W │  V │  Z │     ┃
 * ┗┱────┼────┼────┼────┼────╆━━━━┷━━━━┻━━━━┷━━━━╅────┼────┼────┼────┼────┲┛
 *  ┃    │    │    │    │    ┃                   ┃    │    │    │    │    ┃
 *  ┗━━━━┷━━━━┷━━━━┷━━━━┷━━━━┛                   ┗━━━━┷━━━━┷━━━━┷━━━━┷━━━━┛
 *                          ┏━━━━┯━━━━┓ ┏━━━━┯━━━━┓
 *                          ┃    │    ┃ ┃    │    ┃
 *                     ┏━━━━╃────┼────┨ ┠────┼────╄━━━━┓
 *                     ┃    │    │    ┃ ┃    │    │    ┃
 *                     ┃    │    ├────┨ ┠────┤    │ ⇧4 ┃
 *                     ┃    │    │    ┃ ┃    │    │    ┃
 *                     ┗━━━━┷━━━━┷━━━━┛ ┗━━━━┷━━━━┷━━━━┛
 */
[LATU] = LAYOUT_ergodox(
KC_NO,      S(KC_9),    S(KC_7),    S(KC_5),    S(KC_3),    S(KC_1),    S(KC_F11),
KC_NO,      KC_SCLN,    KC_BSLS,    KC_COMM,    S(KC_P),    S(KC_Y),    KC_NO,
S(KC_TAB),  S(KC_A),    S(KC_O),    S(KC_E),    S(KC_U),    S(KC_I),
S(KC_BSPC), KC_DQT,     S(KC_Q),    S(KC_J),    S(KC_K),    S(KC_X),    KC_NO,
KC_NO,      S(KC_LEFT), S(KC_RGHT), S(KC_DOWN), S(KC_UP),
                                                            KC_NO,      KC_NO,
                                                                        KC_NO,
                                                KC_TRNS,    S(KC_SPC),  OSM_SALT,
S(KC_F12),  S(KC_0),    S(KC_2),    S(KC_4),    S(KC_6),    S(KC_8),    KC_NO,
KC_NO,      S(KC_F),    S(KC_G),    S(KC_C),    S(KC_R),    S(KC_L),    KC_NO,
            S(KC_D),    S(KC_H),    S(KC_T),    S(KC_N),    S(KC_S),    S(KC_ESC),
KC_NO,      S(KC_B),    S(KC_M),    S(KC_W),    S(KC_V),    S(KC_Z),    S(KC_DEL),
                        S(KC_PGUP), S(KC_PGDN), S(KC_HOME), S(KC_END),  KC_NO,
KC_NO,      KC_NO,
OSM_SGUI,
OSM_SCTL,   S(KC_ENT),  OSL(GRKU)),

/* symbols
 * ┏━━━━━┯━━━━┯━━━━┯━━━━┯━━━━┯━━━━┯━━━━┳━━━━┯━━━━┯━━━━┯━━━━┯━━━━┯━━━━┯━━━━━┓
 * ┃     │ F9 │ F7 │ F5 │ F3 │ F1 │F11 ┃ F12│ F10│ F2 │ F4 │ F6 │ F8 │     ┃
 * ┠─────┼────┼────┼────┼────┼────┼────╂────┼────┼────┼────┼────┼────┼─────┨
 * ┃     │    │ _  │ ~  │ *  │    │    ┃    │    │  + │  - │  = │    │     ┃
 * ┠─────┼────┼────┼────┼────┼────┤    ┃    ├────┼────┼────┼────┼────┼─────┨
 * ┃     │ ^  │ {  │ [  │ (  │ <  ├────╂────┤  > │  ) │  ] │  } │  $ │     ┃
 * ┠─────┼────┼────┼────┼────┼────┤    ┃    ├────┼────┼────┼────┼────┼─────┨
 * ┃     │ `  │ ?  │ @  │ &  │    │    ┃    │    │  | │  # │  ! │  % │     ┃
 * ┗┱────┼────┼────┼────┼────╆━━━━┷━━━━┻━━━━┷━━━━╅────┼────┼────┼────┼────┲┛
 *  ┃    │ ⏮  │ ⏭  │ 🔉 │ 🔊 ┃                   ┃  ↺ │  ↻ │    │    │    ┃
 *  ┗━━━━┷━━━━┷━━━━┷━━━━┷━━━━┛                   ┗━━━━┷━━━━┷━━━━┷━━━━┷━━━━┛
 *                          ┏━━━━┯━━━━┓ ┏━━━━┯━━━━┓
 *                          ┃    │    ┃ ┃    │    ┃
 *                     ┏━━━━╃────┼────┨ ┠────┼────╄━━━━┓
 *                     ┃    │    │    ┃ ┃    │    │    ┃
 *                     ┃ ⇧3 │ ⏯  ├────┨ ┠────┤    │    ┃
 *                     ┃    │    │    ┃ ┃    │    │    ┃
 *                     ┗━━━━┷━━━━┷━━━━┛ ┗━━━━┷━━━━┷━━━━┛
 */
[SYMB] = LAYOUT_ergodox(
KC_NO,      KC_F9,      KC_F7,      KC_F5,      KC_F3,      KC_F1,      KC_F11,
KC_NO,      KC_NO,      KC_UNDS,    KC_TILD,    KC_ASTR,    KC_NO,      KC_NO,
KC_NO,      KC_CIRC,    KC_LCBR,    KC_LBRC,    KC_LPRN,    KC_LABK,
KC_NO,      KC_GRV,     KC_QUES,    KC_AT,      KC_AMPR,    KC_NO,      KC_NO,
KC_NO,      KC_MPRV,    KC_MNXT,    KC_VOLD,    KC_VOLU,
                                                            KC_NO,      KC_NO,
                                                                        KC_NO,
                                                OSL(GRKL),  KC_MPLY,    KC_MSTP,
KC_F12,     KC_F10,     KC_F2,      KC_F4,      KC_F6,      KC_F8,      KC_NO,
KC_NO,      KC_NO,      KC_PLUS,    KC_MINS,    KC_EQL,     KC_NO,      KC_NO,
            KC_RABK,    KC_RPRN,    KC_RBRC,    KC_RCBR,    KC_DLR,     KC_NO,
KC_NO,      KC_NO,      KC_PIPE,    KC_HASH,    KC_EXLM,    KC_PERC,    KC_NO,
                        KC_WBAK,    KC_WFWD,    KC_NO,      KC_NO,      KC_NO,
KC_NO,      KC_NO,
KC_NO,
KC_NO,      KC_NO,      KC_TRNS),

/* Greek lowercase
 * https://en.wikipedia.org/wiki/Keyboard_layout#Greek
 * ┏━━━━━┯━━━━┯━━━━┯━━━━┯━━━━┯━━━━┯━━━━┳━━━━┯━━━━┯━━━━┯━━━━┯━━━━┯━━━━┯━━━━━┓
 * ┃     │    │    │    │    │    │    ┃    │    │    │    │    │    │     ┃
 * ┠─────┼────┼────┼────┼────┼────┼────╂────┼────┼────┼────┼────┼────┼─────┨
 * ┃     │    │    │    │ π  │ υ  │    ┃    │  ϕ │  γ │  ψ │  ρ │  λ │     ┃
 * ┠─────┼────┼────┼────┼────┼────┤    ┃    ├────┼────┼────┼────┼────┼─────┨
 * ┃     │ α  │ ο  │ ϵ  │ θ  │ ι  ├────╂────┤  δ │  η │  τ │  ν │  σ │     ┃
 * ┠─────┼────┼────┼────┼────┼────┤    ┃    ├────┼────┼────┼────┼────┼─────┨
 * ┃     │    │    │ ξ  │ κ  │ χ  │    ┃    │  β │  μ │    │  ω │  ζ │     ┃
 * ┗┱────┼────┼────┼────┼────╆━━━━┷━━━━┻━━━━┷━━━━╅────┼────┼────┼────┼────┲┛
 *  ┃    │    │    │    │    ┃                   ┃    │    │    │    │    ┃
 *  ┗━━━━┷━━━━┷━━━━┷━━━━┷━━━━┛                   ┗━━━━┷━━━━┷━━━━┷━━━━┷━━━━┛
 *                          ┏━━━━┯━━━━┓ ┏━━━━┯━━━━┓
 *                          ┃    │    ┃ ┃    │    ┃
 *                     ┏━━━━╃────┼────┨ ┠────┼────╄━━━━┓
 *                     ┃    │    │    ┃ ┃    │    │    ┃
 *                     ┃    │    ├────┨ ┠────┤    │    ┃
 *                     ┃    │    │    ┃ ┃    │    │    ┃
 *                     ┗━━━━┷━━━━┷━━━━┛ ┗━━━━┷━━━━┷━━━━┛
 */
[GRKL] = LAYOUT_ergodox(
KC_NO,      S(KC_F9),   S(KC_F7),   S(KC_F5),   S(KC_F3),   S(KC_F1),   S(KC_F11),
KC_NO,      KC_NO,      KC_NO,      KC_NO,      GR_pi,      GR_upsl,    KC_NO,
KC_NO,      GR_alph,    GR_omcr,    GR_epsl,    GR_tht,     GR_iota,
KC_NO,      KC_NO,      KC_NO,      GR_xi,      GR_kapp,    GR_chi,     KC_NO,
KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                                                            KC_NO,      KC_NO,
                                                                        KC_NO,
                                                KC_TRNS,    KC_NO,      KC_NO,
S(KC_F12),  S(KC_F10),  S(KC_F2),   S(KC_F4),   S(KC_F6),   S(KC_F8),   KC_NO,
KC_NO,      GR_phi,     GR_gamm,    GR_psi,     GR_rho,     GR_lmbd,    KC_NO,
            GR_dlt,     GR_eta,     GR_tau,     GR_nu,      GR_sgm,     KC_NO,
KC_NO,      GR_beta,    GR_mu,      KC_NO,      GR_omg,     GR_zeta,    KC_NO,
                        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
KC_NO,      KC_NO,
KC_NO,
KC_NO,      KC_NO,      KC_NO),

/* Greek uppercase
 * https://en.wikipedia.org/wiki/Keyboard_layout#Greek
 * ┏━━━━━┯━━━━┯━━━━┯━━━━┯━━━━┯━━━━┯━━━━┳━━━━┯━━━━┯━━━━┯━━━━┯━━━━┯━━━━┯━━━━━┓
 * ┃     │F21 │F19 │F17 │F15 │F13 │F23 ┃ F24│ F22│ F14│ F16│ F18│ F20│     ┃
 * ┠─────┼────┼────┼────┼────┼────┼────╂────┼────┼────┼────┼────┼────┼─────┨
 * ┃     │    │    │    │ Π  │ Υ  │    ┃    │  Φ │  Γ │  Ψ │  Ρ │  Λ │     ┃
 * ┠─────┼────┼────┼────┼────┼────┤    ┃    ├────┼────┼────┼────┼────┼─────┨
 * ┃     │ Α  │ Ο  │ Ε  │ Θ  │ Ι  ├────╂────┤  Δ │  Η │  Τ │  Ν │  Σ │     ┃
 * ┠─────┼────┼────┼────┼────┼────┤    ┃    ├────┼────┼────┼────┼────┼─────┨
 * ┃     │    │    │ Ξ  │ Κ  │ Χ  │    ┃    │  Β │  Μ │    │  Ω │  Ζ │     ┃
 * ┗┱────┼────┼────┼────┼────╆━━━━┷━━━━┻━━━━┷━━━━╅────┼────┼────┼────┼────┲┛
 *  ┃    │    │    │    │    ┃                   ┃    │    │    │    │    ┃
 *  ┗━━━━┷━━━━┷━━━━┷━━━━┷━━━━┛                   ┗━━━━┷━━━━┷━━━━┷━━━━┷━━━━┛
 *                          ┏━━━━┯━━━━┓ ┏━━━━┯━━━━┓
 *                          ┃    │    ┃ ┃    │    ┃
 *                     ┏━━━━╃────┼────┨ ┠────┼────╄━━━━┓
 *                     ┃    │    │    ┃ ┃    │    │    ┃
 *                     ┃    │    ├────┨ ┠────┤    │    ┃
 *                     ┃    │    │    ┃ ┃    │    │    ┃
 *                     ┗━━━━┷━━━━┷━━━━┛ ┗━━━━┷━━━━┷━━━━┛
 */
[GRKU] = LAYOUT_ergodox(
KC_NO,      KC_F21,     KC_F19,     KC_F17,     KC_F15,     KC_F13,     KC_F23,
KC_NO,      KC_NO,      KC_NO,      KC_NO,      GR_PI,      GR_UPSL,    KC_NO,
KC_NO,      GR_ALPH,    GR_OMCR,    GR_EPSL,    GR_THT,     GR_IOTA,
KC_NO,      KC_NO,      KC_NO,      GR_XI,      GR_KAPP,    GR_CHI,     KC_NO,
KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                                                            KC_NO,      KC_NO,
                                                                        KC_NO,
                                                KC_NO,      KC_NO,      KC_NO,
KC_F24,     KC_F22,     KC_F14,     KC_F16,     KC_F18,     KC_F20,     KC_NO,
KC_NO,      GR_PHI,     GR_GAMM,    GR_PSI,     GR_RHO,     GR_LMBD,    KC_NO,
            GR_DLT,     GR_ETA,     GR_TAU,     GR_NU,      GR_SGM,     KC_NO,
KC_NO,      GR_BETA,    GR_MU,      KC_NO,      GR_OMG,     GR_ZETA,    KC_NO,
                        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
KC_NO,      KC_NO,
KC_NO,
KC_NO,      KC_NO,      KC_TRNS),
};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro (keyrecord_t *record, uint8_t id, uint8_t opt) {
    return MACRO_NONE;
};

void matrix_init_user (void) {
    set_unicode_input_mode (UC_LNX);
};

void matrix_scan_user (void) {
    uint8_t layer = biton32 (layer_state);
    switch (layer) {
        case LATL:
            ergodox_right_led_1_off ();
            ergodox_right_led_2_off ();
            ergodox_right_led_3_off ();
            break;
        case LATU:
            ergodox_right_led_1_on ();
            ergodox_right_led_2_off ();
            ergodox_right_led_3_off ();
            break;
        case SYMB:
            ergodox_right_led_1_off ();
            ergodox_right_led_2_on ();
            ergodox_right_led_3_off ();
            break;
        case GRKL ... GRKU:
            ergodox_right_led_1_on ();
            ergodox_right_led_2_on ();
            ergodox_right_led_3_off ();
            break;
    }
}

bool process_record_user (uint16_t keycode, keyrecord_t *record) {
    return true;
}
