/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H

#define BASE 0 // default / base layer
#define NUMB 1 // numbers and symbols
#define FNLY 2 // function keys and motion

// Blank template at the bottom

enum customKeycodes {
	URL  = 1
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Basic layer
   *
   * ,-------------------------------------------.                         ,-------------------------------------------.
   * |  ESC   |   Q  |   W  |   E  |   R  |   T  |                         |   Y  |   U  |   I  |   O  |   P  |  | \   |
   * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
   * | PrScr  |   A  |   S  |   D  |   F  |   G  |      |           |      |   H  |   J  |   K  |   L  | ;  : |  ' "   |
   * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
   * |  Lay1  |   Z  |   X  |   C  |   V  |   B  | Lay1 |           |      |   N  |   M  | ,  < | . >  | /  ? |  - _   |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *                        .-------.   .-------.                           .-------.   .-------.
   *                        | Super |   | LShft |                           | Space |   | BSPC  |
   *                        '-------'   '-------'                           `-------.   '-------'
   *                                         ,-------.                 ,-------.
   *                                         | Lay2  |                 | Lay2  |
   *                                  ,------|-------|                 |-------|------.
   *                                  |      |       |                 |       |      |
   *                                  | Alt  | Ctrl  |                 | Enter | Tab  |
   *                                  |      |       |                 |       |      |
   *                                  `--------------'                 `--------------'
   */
  [BASE] = LAYOUT_gergo(
			KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
			KC_PSCR,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_NO,                             KC_NO,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
			MO(NUMB), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,   MO(FNLY),       MO(FNLY), KC_NO,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
			                                     KC_LGUI, KC_LSFT, KC_LALT, KC_LCTL,        KC_ENTER, KC_TAB,  KC_SPC,  KC_BSPC
			),

  /* Keymap 1: Number and Symbols layer
   *
   * ,-------------------------------------------.                         ,-------------------------------------------.
   * |  TRNS  |  1   |  2   |  3   |  4   |  5   |                         |   6  |   7  |   8  |   9  |   0  |   =    |
   * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
   * |  TRNS  |  !   |  @   |  #   |  $   |  %   | PgUp |           |      |   ^  |   &  |   *  |   (  |   )  |   +    |
   * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
   * |  TRNS  |  `   |  ~   |  ;   |  {   |  }   | PgDn |           |      |   [  |   ]  | TRNS | TRNS | TRNS |  TRNS  |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *                        .-------.   .-------.                           .-------.   .-------.
   *                        | TRNS  |   | TRNS  |                           |  TRNS |   |  TRNS |
   *                        '-------'   '-------'                           `-------.   '-------'
   *                                         ,-------.                 ,-------.
   *                                         | TRNS  |                 |  TRNS |
   *                                  ,------|-------|                 |-------|------.
   *                                  |      |       |                 |       |      |
   *                                  | TRNS | TRNS  |                 |  TRNS | TRNS |
   *                                  |      |       |                 |       |      |
   *                                  `--------------'                 `--------------'
   */
  [NUMB] = LAYOUT_gergo(
			KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
			KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_PGUP,                           KC_NO,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
			KC_TRNS, KC_GRV,  KC_TILD, KC_SCLN, KC_LCBR, KC_RCBR, KC_PGDN, KC_TRNS,         KC_TRNS, KC_NO,   KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
			                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
			),

  /* Keymap 2: Function Layer
   *
   * ,-------------------------------------------.                         ,-------------------------------------------.
   * |  TRNS  |  F1  |  F2  |  F3  |  F4  |  F5  |                         |  F6  |  F7  |  F8  |  F9  | F10  | VolUp  |
   * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
   * |  TRNS  | F11  | F12  | TRNS | TRNS | TRNS | TRNS |           | Play | LEFT | DOWN |  UP  | RGHT | BrUp | VolDn  |
   * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
   * |  TRNS  | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |           | Skip | MLFT | MDWN | MUP  | MRHGT| BrDn |  Mute  |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *                        .-------.   .-------.                           .-------.   .-------.
   *                        | TRNS  |   | TRNS  |                           |  TRNS |   |  TRNS |
   *                        '-------'   '-------'                           `-------.   '-------'
   *                                         ,-------.                 ,-------.
   *                                         | TRNS  |                 |  TRNS |
   *                                  ,------|-------|                 |-------|------.
   *                                  |      |       |                 |       |      |
   *                                  | TRNS | TRNS  |                 |  TRNS | TRNS |
   *                                  |      |       |                 |       |      |
   *                                  `--------------'                 `--------------'
   */
  [FNLY] = LAYOUT_gergo(
			KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                               KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_VOLU,
			KC_TRNS, KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_MPLY, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BRIU, KC_VOLD,
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_MNXT, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BRID, KC_MUTE,
			                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
			),
};

/* Keymap template
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      |                         |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
 [SYMB] = LAYOUT_gergo(
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
 )
*/
