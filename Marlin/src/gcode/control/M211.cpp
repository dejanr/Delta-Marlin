/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "../gcode.h"
#include "../../module/motion.h"

/**
 * M211: Enable, Disable, and/or Report software endstops
 *
 * Usage: M211 S1 to enable, M211 S0 to disable, M211 alone for report
 */
void GcodeSuite::M211() {
  SERIAL_ECHO_START();
  #if HAS_SOFTWARE_ENDSTOPS
    if (parser.seen('S')) soft_endstops_enabled = parser.value_bool();
    SERIAL_ECHOPGM(MSG_SOFT_ENDSTOPS);
    serialprintPGM(soft_endstops_enabled ? PSTR(MSG_ON) : PSTR(MSG_OFF));
  #else
    SERIAL_ECHOPGM(MSG_SOFT_ENDSTOPS);
    SERIAL_ECHOPGM(MSG_OFF);
  #endif
  SERIAL_ECHOPGM(MSG_SOFT_MIN);
  SERIAL_ECHOPAIR(    MSG_X, LOGICAL_X_POSITION(soft_endstop_min[X_AXIS]));
  SERIAL_ECHOPAIR(" " MSG_Y, LOGICAL_Y_POSITION(soft_endstop_min[Y_AXIS]));
  SERIAL_ECHOPAIR(" " MSG_Z, LOGICAL_Z_POSITION(soft_endstop_min[Z_AXIS]));
  SERIAL_ECHOPGM(MSG_SOFT_MAX);
  SERIAL_ECHOPAIR(    MSG_X, LOGICAL_X_POSITION(soft_endstop_max[X_AXIS]));
  SERIAL_ECHOPAIR(" " MSG_Y, LOGICAL_Y_POSITION(soft_endstop_max[Y_AXIS]));
  SERIAL_ECHOLNPAIR(" " MSG_Z, LOGICAL_Z_POSITION(soft_endstop_max[Z_AXIS]));
}
