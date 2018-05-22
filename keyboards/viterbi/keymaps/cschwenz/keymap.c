/*
Copyright 2018  Calvin Schwenzfeier

This file is part of the cschwenz keymap for a Viterbi keyboard
using the QMK firmware.

This keymap is free software: you can redistribute it and/or
modify it under the terms of the GNU General Public License as
published by the Free Software Foundation, either version 3 of
the License, or (at your option) any later version.

This keymap is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this keymap.c file.
If not, see <http://www.gnu.org/licenses/>.
*/

#include "./config.h"
#include "../../viterbi.h"
#include "tmk_core/common/action_layer.h"
#include "tmk_core/common/eeconfig.h"
#include "tmk_core/common/print.h"

extern keymap_config_t keymap_config;

/* Note a given layer name has an underscore prefix while its corresponding keycode does not. */
#define _COLEMAK_DH 0
#define _QWERTY 1
#define _MEDIA 2
#define _MOUSE 3
#define _NUMPAD 4
#define _KEYBOARD_SETUP 15

enum custom_keycodes {
    LOWER = SAFE_RANGE,
    RAISE,
    COLEMAK_DH,
    QWERTY,
    MEDIA,
    MOUSE,
    NUMPAD,
    KEYBOARD_SETUP
};

typedef uint8_t cschwenz_Layer;
typedef int8_t cschwenz_SentinelLayer;
typedef uint8_t cschwenz_Index;

/* In order to have functional Raise/Lower keys, we need to forego the use of the TO() macro;
otherwise our bookkeepping in the cschwenz_current_layer variable will be inaccurate. */
#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_CDH  COLEMAK_DH
#define KC_QWER QWERTY
#define KC_MDIA MEDIA
#define KC_MVP  MOUSE
#define KC_NUM  NUMPAD
#define KC_KBSU KEYBOARD_SETUP
#define KC_SCDN KC_F14
#define KC_SCUP KC_F15
#define AG_HNK  MAGIC_HOST_NKRO
#define AG_UHNK MAGIC_UNHOST_NKRO
#define KC_RSET RESET
#define _x_x_x_ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Colemak-DH
     * ╔══════╦══════╦══════╦══════╦══════╦══════╦══════╗      ╔══════╦══════╦══════╦══════╦══════╦══════╦══════╗
     * ║ Media║   `  ║   1  ║   2  ║   3  ║   4  ║   5  ║      ║   6  ║   7  ║   8  ║   9  ║   0  ║ Bksp ║  Del ║
     * ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣      ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣
     * ║NumPad║   =  ║   Q  ║   W  ║   F  ║   P  ║   B  ║      ║   J  ║   L  ║   U  ║   Y  ║   ;  ║   [  ║   ]  ║
     * ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣      ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣
     * ║  Esc ║  Tab ║   A  ║   R  ║   S  ║   T  ║   G  ║      ║   M  ║   N  ║   E  ║   I  ║   O  ║   '  ║   ↵  ║
     * ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣      ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣
     * ║CapsLk║   :  ║   Z  ║   X  ║   C  ║   D  ║   V  ║      ║   K  ║   H  ║   ,  ║   .  ║   /  ║  Up  ║   \  ║
     * ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣      ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣
     * ║ Raise║ Lower║ Ctrl ║  Alt ║  GUI ║ Shift║   -  ║      ║ Space║ Shift║  GUI ║  Alt ║ Left ║ Down ║ Right║
     * ╚══════╩══════╩══════╩══════╩══════╩══════╩══════╝      ╚══════╩══════╩══════╩══════╩══════╩══════╩══════╝
     */
    [_COLEMAK_DH] = LAYOUT(
        KC_MDIA , KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,      KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSPC , KC_DEL  ,
        KC_NUM  , KC_EQL  , KC_Q    , KC_W    , KC_F    , KC_P    , KC_B    ,      KC_J    , KC_L    , KC_U    , KC_Y    , KC_SCLN , KC_LBRC , KC_RBRC ,
        KC_ESC  , KC_TAB  , KC_A    , KC_R    , KC_S    , KC_T    , KC_G    ,      KC_M    , KC_N    , KC_E    , KC_I    , KC_O    , KC_QUOT , KC_ENT  ,
        KC_CAPS , KC_COLN , KC_Z    , KC_X    , KC_C    , KC_D    , KC_V    ,      KC_K    , KC_H    , KC_COMM , KC_DOT  , KC_SLSH , KC_UP   , KC_BSLS ,
        KC_RASE , KC_LOWR , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT , KC_MINS ,      KC_SPC  , KC_RSFT , KC_RGUI , KC_RALT , KC_LEFT , KC_DOWN , KC_RGHT
    ),

    /* Qwerty
     * ╔══════╦══════╦══════╦══════╦══════╦══════╦══════╗      ╔══════╦══════╦══════╦══════╦══════╦══════╦══════╗
     * ║ Media║   `  ║   1  ║   2  ║   3  ║   4  ║   5  ║      ║   6  ║   7  ║   8  ║   9  ║   0  ║ Bksp ║  Del ║
     * ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣      ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣
     * ║NumPad║   =  ║   Q  ║   W  ║   E  ║   R  ║   T  ║      ║   Y  ║   U  ║   I  ║   O  ║   P  ║   [  ║   ]  ║
     * ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣      ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣
     * ║  Esc ║  Tab ║   A  ║   S  ║   D  ║   F  ║   G  ║      ║   H  ║   J  ║   K  ║   L  ║   ;  ║   '  ║   ↵  ║
     * ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣      ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣
     * ║CapsLk║   :  ║   Z  ║   X  ║   C  ║   V  ║   B  ║      ║   N  ║   M  ║   ,  ║   .  ║   /  ║  Up  ║   \  ║
     * ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣      ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣
     * ║ Raise║ Lower║ Ctrl ║  Alt ║  GUI ║ Shift║   -  ║      ║ Space║ Shift║  GUI ║  Alt ║ Left ║ Down ║ Right║
     * ╚══════╩══════╩══════╩══════╩══════╩══════╩══════╝      ╚══════╩══════╩══════╩══════╩══════╩══════╩══════╝
     */
    [_QWERTY] = LAYOUT(
        KC_MDIA , KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,      KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSPC , KC_DEL  ,
        KC_NUM  , KC_EQL  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    ,      KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_LBRC , KC_RBRC ,
        KC_ESC  , KC_TAB  , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    ,      KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT , KC_ENT  ,
        KC_CAPS , KC_COLN , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    ,      KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_UP   , KC_BSLS ,
        KC_RASE , KC_LOWR , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT , KC_MINS ,      KC_SPC  , KC_RSFT , KC_RGUI , KC_RALT , KC_LEFT , KC_DOWN , KC_RGHT
    ),

    /* Media Keys
     * ╔══════╦══════╦══════╦══════╦══════╦══════╦══════╗      ╔══════╦══════╦══════╦══════╦══════╦══════╦══════╗
     * ║ClmkDH║  F1  ║  F2  ║  F3  ║  F4  ║  F5  ║  F6  ║      ║  F7  ║  F8  ║  F9  ║  F10 ║  F11 ║  F12 ║  F13 ║
     * ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣      ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣
     * ║      ║      ║      ║      ║      ║      ║      ║      ║ Stop ║ Prev ║ Play ║ Next ║ Mute ║ Vol- ║ Vol+ ║
     * ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣      ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣
     * ║  Esc ║  Tab ║ KBSet║  MvP ║ Media║NumPad║Qwerty║      ║ Brt- ║ Brt+ ║      ║      ║ Eject║      ║   ↵  ║
     * ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣      ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣
     * ║CapsLk║      ║      ║      ║      ║      ║   M  ║      ║      ║ PgUp ║      ║      ║      ║  Up  ║      ║
     * ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣      ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣
     * ║ Raise║ Lower║ Ctrl ║  Alt ║  GUI ║ Shift║ Space║      ║ Home ║PgDown║  End ║      ║ Left ║ Down ║ Right║
     * ╚══════╩══════╩══════╩══════╩══════╩══════╩══════╝      ╚══════╩══════╩══════╩══════╩══════╩══════╩══════╝
     */
    [_MEDIA] = LAYOUT(
        KC_CDH  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   ,      KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_F13  ,
        _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ ,      KC_MSTP , KC_MRWD , KC_MPLY , KC_MFFD , KC_MUTE , KC_VOLD , KC_VOLU ,
        KC_ESC  , KC_TAB  , KC_KBSU , KC_MVP  , KC_MDIA , KC_NUM  , KC_QWER ,      KC_SCDN , KC_SCUP , _x_x_x_ , _x_x_x_ , KC_EJCT , _x_x_x_ , KC_ENT  ,
        KC_CAPS , _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ , KC_M    ,      _x_x_x_ , KC_PGUP , _x_x_x_ , _x_x_x_ , _x_x_x_ , KC_UP   , _x_x_x_ ,
        KC_RASE , KC_LOWR , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT , KC_SPC  ,      KC_HOME , KC_PGDN , KC_END  , _x_x_x_ , KC_LEFT , KC_DOWN , KC_RGHT
    ),

    /* Mouse Keys
     * ╔══════╦══════╦══════╦══════╦══════╦══════╦══════╗      ╔══════╦══════╦══════╦══════╦══════╦══════╦══════╗
     * ║ClmkDH║  F1  ║  F2  ║  F3  ║  F4  ║  F5  ║  F6  ║      ║  F7  ║  F8  ║  F9  ║  F10 ║  F11 ║  F12 ║  F13 ║
     * ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣      ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣
     * ║      ║      ║      ║      ║      ║      ║      ║      ║      ║      ║      ║      ║ mBtn5║      ║      ║
     * ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣      ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣
     * ║  Esc ║  Tab ║ KBSet║  MvP ║ Media║NumPad║Qwerty║      ║      ║      ║      ║ mAcl2║ mBtn4║ mBtn2║   ↵  ║
     * ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣      ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣
     * ║CapsLk║      ║      ║      ║      ║      ║   R  ║      ║      ║ mwUp ║      ║ mAcl1║ mBtn1║  mUp ║ mBtn3║
     * ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣      ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣
     * ║ Raise║ Lower║ Ctrl ║  Alt ║  GUI ║ Shift║ Space║      ║mwLeft║mwDown║mwRght║ mAcl0║ mLeft║ mDown║mRight║
     * ╚══════╩══════╩══════╩══════╩══════╩══════╩══════╝      ╚══════╩══════╩══════╩══════╩══════╩══════╩══════╝
     */
    [_MOUSE] = LAYOUT(
        KC_CDH  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   ,      KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_F13  ,
        _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ ,      _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ , KC_BTN5 , _x_x_x_ , _x_x_x_ ,
        KC_ESC  , KC_TAB  , KC_KBSU , KC_MVP  , KC_MDIA , KC_NUM  , KC_QWER ,      _x_x_x_ , _x_x_x_ , _x_x_x_ , KC_ACL2 , KC_BTN4 , KC_BTN2 , KC_ENT  ,
        KC_CAPS , _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ , KC_R    ,      _x_x_x_ , KC_WH_U , _x_x_x_ , KC_ACL1 , KC_BTN1 , KC_MS_U , KC_BTN3 ,
        KC_RASE , KC_LOWR , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT , KC_SPC  ,      KC_WH_L , KC_WH_D , KC_WH_R , KC_ACL0 , KC_MS_L , KC_MS_D , KC_MS_R
    ),

    /* NumPad Keys
     * ╔══════╦══════╦══════╦══════╦══════╦══════╦══════╗      ╔══════╦══════╦══════╦══════╦══════╦══════╦══════╗
     * ║ClmkDH║  F1  ║  F2  ║  F3  ║  F4  ║  F5  ║  F6  ║      ║  F7  ║  F8  ║  F9  ║  F10 ║  F11 ║ Bksp ║  Del ║
     * ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣      ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣
     * ║      ║      ║      ║      ║      ║      ║      ║      ║NumLck║   7  ║   8  ║   9  ║   /  ║      ║      ║
     * ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣      ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣
     * ║  Esc ║  Tab ║ KBSet║  MvP ║ Media║NumPad║Qwerty║      ║   ,  ║   4  ║   5  ║   6  ║   *  ║      ║   ↵  ║
     * ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣      ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣
     * ║CapsLk║      ║      ║      ║      ║      ║   N  ║      ║   =  ║   1  ║   2  ║   3  ║   +  ║      ║      ║
     * ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣      ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣
     * ║ Raise║ Lower║ Ctrl ║  Alt ║  GUI ║ Shift║ Space║      ║      ║   0  ║   .  ║ Enter║   -  ║      ║      ║
     * ╚══════╩══════╩══════╩══════╩══════╩══════╩══════╝      ╚══════╩══════╩══════╩══════╩══════╩══════╩══════╝
     */
    [_NUMPAD] = LAYOUT(
        KC_CDH  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   ,      KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_BSPC , KC_DEL  ,
        _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ ,      KC_NLCK , KC_P7   , KC_P8   , KC_P9   , KC_PSLS , _x_x_x_ , _x_x_x_ ,
        KC_ESC  , KC_TAB  , KC_KBSU , KC_MVP  , KC_MDIA , KC_NUM  , KC_QWER ,      KC_PCMM , KC_P4   , KC_P5   , KC_P6   , KC_PAST , _x_x_x_ , KC_ENT  ,
        KC_CAPS , _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ , KC_N    ,      KC_PEQL , KC_P1   , KC_P2   , KC_P3   , KC_PPLS , _x_x_x_ , _x_x_x_ ,
        KC_RASE , KC_LOWR , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT , KC_SPC  ,      _x_x_x_ , KC_P0   , KC_PDOT , KC_PENT , KC_PMNS , _x_x_x_ , _x_x_x_
    ),

    /* Keyboard Setup
     * ╔══════╦══════╦══════╦══════╦══════╦══════╦══════╗      ╔══════╦══════╦══════╦══════╦══════╦══════╦══════╗
     * ║ClmkDH║  F1  ║  F2  ║  F3  ║  F4  ║  F5  ║  F6  ║      ║  F7  ║  F8  ║  F9  ║  F10 ║  F11 ║  F12 ║  F13 ║
     * ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣      ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣
     * ║      ║      ║      ║      ║      ║      ║      ║      ║      ║      ║      ║      ║      ║ Reset║      ║
     * ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣      ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣
     * ║  Esc ║  Tab ║ KBSet║  MvP ║ Media║NumPad║Qwerty║      ║      ║ NKRO+║ NKRO-║ Swap ║Unswap║      ║   ↵  ║
     * ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣      ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣
     * ║CapsLk║      ║      ║      ║      ║      ║   K  ║      ║      ║      ║      ║      ║      ║  Up  ║      ║
     * ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣      ╠══════╬══════╬══════╬══════╬══════╬══════╬══════╣
     * ║ Raise║ Lower║ Ctrl ║  Alt ║  GUI ║ Shift║ Space║      ║      ║      ║      ║      ║ Left ║ Down ║ Right║
     * ╚══════╩══════╩══════╩══════╩══════╩══════╩══════╝      ╚══════╩══════╩══════╩══════╩══════╩══════╩══════╝
     */
    [_KEYBOARD_SETUP] = LAYOUT(
        KC_CDH  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   ,      KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_F13  ,
        _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ ,      _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ , KC_RSET , _x_x_x_ ,
        KC_ESC  , KC_TAB  , KC_KBSU , KC_MVP  , KC_MDIA , KC_NUM  , KC_QWER ,      _x_x_x_ , AG_HNK  , AG_UHNK , AG_SWAP , AG_NORM , _x_x_x_ , KC_ENT  ,
        KC_CAPS , _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ , KC_K    ,      _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ , KC_UP   , _x_x_x_ ,
        KC_RASE , KC_LOWR , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT , KC_SPC  ,      _x_x_x_ , _x_x_x_ , _x_x_x_ , _x_x_x_ , KC_LEFT , KC_DOWN , KC_RGHT
    )

};

/* Initialize the bookkeepping; _COLEMAK_DH is the default layer and -1 is the sentinel value. */
const cschwenz_SentinelLayer cschwenz_defined_layers[] = { _COLEMAK_DH , _QWERTY , _MEDIA , _MOUSE , _NUMPAD , _KEYBOARD_SETUP , -1 };
static cschwenz_Layer cschwenz_current_layer = _COLEMAK_DH;

/* Given a layer, returns its index in the cschwenz_defined_layers array. */
cschwenz_Index cschwenz_find_layer_index( cschwenz_Layer layer ) {
    cschwenz_Index idx = 0;
    cschwenz_Index n = 0;
    while ( cschwenz_defined_layers[n] >= 0 ) {
        if ( cschwenz_defined_layers[n] == layer ) {
            idx = n;
            break;
        }
        n++;
    }
    return idx;
}

/* Returns the index of the layer before the current layer stored in the cschwenz_current_layer variable. */
cschwenz_Index cschwenz_prev_layer_index( void ) {
    cschwenz_Index idx = cschwenz_find_layer_index( cschwenz_current_layer );
    if ( idx == 0 ) {
        cschwenz_Index n = 0;
        while ( cschwenz_defined_layers[n] >= 0 ) {
            n++;
        }
        idx = n - 1;
    }
    else {
        idx--;
    }
    return idx;
}

/* Returns the index of the layer after the current layer stored in the cschwenz_current_layer variable. */
cschwenz_Index cschwenz_next_layer_index( void ) {
    cschwenz_Index idx = cschwenz_find_layer_index( cschwenz_current_layer );
    idx++;
    if ( cschwenz_defined_layers[idx] < 0 ) {
        idx = 0;
    }
    return idx;
}

/* Set the given layer as the current layer. */
void cschwenz_goto_layer( cschwenz_Layer layer ) {
    cschwenz_current_layer = layer;
    layer_move( cschwenz_current_layer );
    return;
}

/* Process our custom keycodes. */
bool process_record_user( uint16_t keycode, keyrecord_t *record ) {
    switch ( keycode ) {
        case LOWER:
            if ( record->event.pressed ) {
                cschwenz_goto_layer( cschwenz_defined_layers[ cschwenz_prev_layer_index() ] );
            }
            return false;
            break;
        case RAISE:
            if ( record->event.pressed ) {
                cschwenz_goto_layer( cschwenz_defined_layers[ cschwenz_next_layer_index() ] );
            }
            return false;
            break;
        case COLEMAK_DH:
            if ( record->event.pressed ) {
                cschwenz_goto_layer( _COLEMAK_DH );
            }
            return false;
            break;
        case QWERTY:
            if ( record->event.pressed ) {
                cschwenz_goto_layer( _QWERTY );
            }
            return false;
            break;
        case MEDIA:
            if ( record->event.pressed ) {
                cschwenz_goto_layer( _MEDIA );
            }
            return false;
            break;
        case MOUSE:
            if ( record->event.pressed ) {
                cschwenz_goto_layer( _MOUSE );
            }
            return false;
            break;
        case NUMPAD:
            if ( record->event.pressed ) {
                cschwenz_goto_layer( _NUMPAD );
            }
            return false;
            break;
        case KEYBOARD_SETUP:
            if ( record->event.pressed ) {
                cschwenz_goto_layer( _KEYBOARD_SETUP );
            }
            return false;
            break;
    }
    return true;
}
