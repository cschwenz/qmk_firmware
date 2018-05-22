
# Copyright 2018  Calvin Schwenzfeier
#
# This file is part of the cschwenz keymap for a Viterbi keyboard
# using the QMK firmware.
#
# This keymap is free software: you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation, either version 3 of
# the License, or (at your option) any later version.
#
# This keymap is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this rules.mk file.
# If not, see <http://www.gnu.org/licenses/>.

BOOTMAGIC_ENABLE = yes
NKRO_ENABLE = yes
UNICODE_ENABLE = yes
USE_I2C = no

STENO_ENABLE = no
MOUSEKEY_ENABLE = yes

EXTRAKEY_ENABLE = yes
COMMAND_ENABLE = yes
CONSOLE_ENABLE = no
BACKLIGHT_ENABLE = no
MIDI_ENABLE = no
AUDIO_ENABLE = no
BLUETOOTH_ENABLE = no
RGBLIGHT_ENABLE = no
SLEEP_LED_ENABLE = no

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
