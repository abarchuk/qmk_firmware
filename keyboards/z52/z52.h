/* Copyright 2017 REPLACE_WITH_YOUR_NAME
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
#ifndef Z52_H
#define Z52_H

#include "quantum.h"

// This a shortcut to help you visually see your layout.
// The following is an example using the Planck MIT layout
// The first section contains all of the arguments
// The second converts the arguments into a two-dimensional array
#define KEYMAP( \
  k00, k01, k02, k03, k04,           k05, k06, k07, k08, k09, \
  k10, k11, k12, k13, k14,           k15, k16, k17, k18, k19, \
  k20, k21, k22, k23, k24,           k25, k26, k27, k28, k29, \
  k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b,\
       k40, k41, k42, k43, k44, k45, k46, k47, k48, k49 \
) \
{ \
    { k00,   k01, k02, k03, k04, KC_NO, k05, k06, k07, k08, k09   }, \
    { k10,   k11, k12, k13, k14, k35,   k15, k16, k17, k18, k19   }, \
    { k20,   k21, k22, k23, k24, k44,   k25, k26, k27, k28, k29   }, \
    { k30,   k31, k32, k33, k34, k36,   k37, k38, k39, k3a, k3b   } \
    { KC_NO, k40, k41, k42, k43, k45,   k46, k47, k48, k49, KC_NO } \
}

#endif