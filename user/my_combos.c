/* Copyright 2019 Noah Frederick
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

#include "my.h"
#include "my_leader.h"

enum combo_events {
  MY_COMBO_SLSH_F,
  MY_COMBO_SLSH_H,
  MY_COMBO_SLSH_S,
  MY_COMBO_TAB_B,
  MY_COMBO_TAB_C,
  MY_COMBO_TAB_D,
  MY_COMBO_TAB_G,
  MY_COMBO_TAB_I,
  MY_COMBO_TAB_L,
  MY_COMBO_TAB_U,
  MY_COMBO_J_F,
};

const uint16_t PROGMEM combo_SLSH_F[] = { KC_SLSH, KC_F, COMBO_END };
const uint16_t PROGMEM combo_SLSH_H[] = { KC_SLSH, KC_H, COMBO_END };
const uint16_t PROGMEM combo_SLSH_S[] = { KC_SLSH, KC_S, COMBO_END };
const uint16_t PROGMEM combo_TAB_B[] = { KC_TAB, KC_B, COMBO_END };
const uint16_t PROGMEM combo_TAB_C[] = { KC_TAB, KC_C, COMBO_END };
const uint16_t PROGMEM combo_TAB_D[] = { KC_TAB, KC_D, COMBO_END };
const uint16_t PROGMEM combo_TAB_G[] = { KC_TAB, KC_G, COMBO_END };
const uint16_t PROGMEM combo_TAB_I[] = { KC_TAB, KC_I, COMBO_END };
const uint16_t PROGMEM combo_TAB_L[] = { KC_TAB, KC_L, COMBO_END };
const uint16_t PROGMEM combo_TAB_U[] = { KC_TAB, KC_U, COMBO_END };
const uint16_t PROGMEM combo_J_F[] = { KC_J, KC_F, COMBO_END };
const uint16_t PROGMEM combo_Z_X[] = { KC_Z, KC_X, COMBO_END };
const uint16_t PROGMEM combo_X_C[] = { KC_X, KC_C, COMBO_END };
const uint16_t PROGMEM combo_C_V[] = { KC_C, KC_V, COMBO_END };
const uint16_t PROGMEM combo_Z_V[] = { KC_Z, KC_V, COMBO_END };

combo_t key_combos[COMBO_COUNT] = {
  [MY_COMBO_SLSH_F] = COMBO_ACTION(combo_SLSH_F),
  [MY_COMBO_SLSH_H] = COMBO_ACTION(combo_SLSH_H),
  [MY_COMBO_SLSH_S] = COMBO_ACTION(combo_SLSH_S),
  [MY_COMBO_TAB_B] = COMBO_ACTION(combo_TAB_B),
  [MY_COMBO_TAB_C] = COMBO_ACTION(combo_TAB_C),
  [MY_COMBO_TAB_D] = COMBO_ACTION(combo_TAB_D),
  [MY_COMBO_TAB_G] = COMBO_ACTION(combo_TAB_G),
  [MY_COMBO_TAB_I] = COMBO_ACTION(combo_TAB_I),
  [MY_COMBO_TAB_L] = COMBO_ACTION(combo_TAB_L),
  [MY_COMBO_TAB_U] = COMBO_ACTION(combo_TAB_U),
  [MY_COMBO_J_F] = COMBO_ACTION(combo_J_F),
  COMBO(combo_Z_X, KC_CUT),
  COMBO(combo_X_C, KC_COPY),
  COMBO(combo_C_V, KC_PASTE),
  COMBO(combo_Z_V, KC_UNDO),
};

#define MODS_SHIFT (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define SEND_CAP_STRING(str, capitalized) if (MODS_SHIFT) { \
                                            clear_mods(); \
                                            SEND_STRING(capitalized); \
                                          } else { \
                                            SEND_STRING(str); \
                                          }

void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
    case MY_COMBO_SLSH_F:
      if (pressed) {
        SEND_CAP_STRING("ftp://", "FTP ");
      }
      break;
    case MY_COMBO_SLSH_H:
      if (pressed) {
        SEND_CAP_STRING("http://", "HTTP ");
      }
      break;
    case MY_COMBO_SLSH_S:
      if (pressed) {
        SEND_CAP_STRING("https://", "HTTPS ");
      }
      break;
    case MY_COMBO_TAB_B:
      if (pressed) {
        // Markdown strong emphasis/bold
        SEND_STRING("****" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
      }
      break;
    case MY_COMBO_TAB_C:
      if (pressed) {
        // Markdown list item with checkbox
        SEND_STRING("- [ ] ");
      }
      break;
    case MY_COMBO_TAB_D:
      if (pressed) {
        // Markdown deletion
        SEND_STRING("~~~~" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
      }
      break;
    case MY_COMBO_TAB_G:
      if (pressed) {
        // Markdown image
        SEND_STRING("![]()" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
      }
      break;
    case MY_COMBO_TAB_I:
      if (pressed) {
        // Markdown emphasis/italic
        SEND_STRING("**" SS_TAP(X_LEFT));
      }
      break;
    case MY_COMBO_TAB_L:
      if (pressed) {
        // Markdown link
        SEND_STRING("[]()" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
      }
      break;
    case MY_COMBO_TAB_U:
      if (pressed) {
        // Markdown emphasis/italic
        SEND_STRING("__" SS_TAP(X_LEFT));
      }
      break;
    case MY_COMBO_J_F:
      if (pressed) {
        leader_activate_or_cancel();
      }
      break;
  }
}
