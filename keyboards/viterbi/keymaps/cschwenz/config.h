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
along with this config.h file.
If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#ifndef NO_PRINT
#define NO_PRINT
#endif
#ifndef NO_DEBUG
#define NO_DEBUG
#endif
#ifndef FORCE_NKRO
#define FORCE_NKRO
#endif
#ifndef PREVENT_STUCK_MODIFIERS
#define PREVENT_STUCK_MODIFIERS
#endif

#ifdef USE_I2C
#undef USE_I2C
#endif
#define USE_SERIAL

#ifdef MASTER_LEFT
#undef MASTER_LEFT
#endif
#ifdef EE_HANDS
#undef EE_HANDS
#endif
#define MASTER_RIGHT

#ifdef DEBOUNCING_DELAY
#undef DEBOUNCING_DELAY
#endif
#ifdef QMK_KEYS_PER_SCAN
#undef QMK_KEYS_PER_SCAN
#endif
#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif
#define DEBOUNCING_DELAY 3
#define QMK_KEYS_PER_SCAN 4
#define TAPPING_TERM 149

#ifdef MOUSEKEY_DELAY
#undef MOUSEKEY_DELAY
#endif
#ifdef MOUSEKEY_MOVE_DELTA
#undef MOUSEKEY_MOVE_DELTA
#endif
#ifdef MOUSEKEY_MOVE_MAX
#undef MOUSEKEY_MOVE_MAX
#endif
#ifdef MOUSEKEY_INTERVAL
#undef MOUSEKEY_INTERVAL
#endif
#ifdef MOUSEKEY_MAX_SPEED
#undef MOUSEKEY_MAX_SPEED
#endif
#ifdef MOUSEKEY_TIME_TO_MAX
#undef MOUSEKEY_TIME_TO_MAX
#endif
#ifdef MOUSEKEY_WHEEL_DELAY
#undef MOUSEKEY_WHEEL_DELAY
#endif
#ifdef MOUSEKEY_WHEEL_DELTA
#undef MOUSEKEY_WHEEL_DELTA
#endif
#ifdef MOUSEKEY_WHEEL_MAX
#undef MOUSEKEY_WHEEL_MAX
#endif
#ifdef MOUSEKEY_WHEEL_MAX_SPEED
#undef MOUSEKEY_WHEEL_MAX_SPEED
#endif
#ifdef MOUSEKEY_WHEEL_TIME_TO_MAX
#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#endif

#define MOUSEKEY_DELAY 7
#define MOUSEKEY_MOVE_DELTA 3
#define MOUSEKEY_MOVE_MAX 29
#define MOUSEKEY_INTERVAL 19
#define MOUSEKEY_MAX_SPEED 23
#define MOUSEKEY_TIME_TO_MAX 255
#define MOUSEKEY_WHEEL_DELAY 17
#define MOUSEKEY_WHEEL_DELTA 1
#define MOUSEKEY_WHEEL_MAX 1
#define MOUSEKEY_WHEEL_MAX_SPEED 1
#define MOUSEKEY_WHEEL_TIME_TO_MAX 255

#include "quantum/config_common.h"

#endif
