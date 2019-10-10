/*
 * Copyright (C) 2019  Hsuan-Ting Lu <hsuan.ting.lu.ee05@g2.nctu.edu.tw>
 *
 * Wrap 24-bit true color codes within general output streams
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope tha it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#ifndef AESC_COLOR_TRUECOLOR_HPP_
#define AESC_COLOR_TRUECOLOR_HPP_

#include <iostream>
#include "../aesc.hpp"
#include "../manipulator.hpp"

namespace aesc {  // Ansi Escape Terminal

namespace truecolor {

namespace RGB {
manipulator::smanipiii foreground(const int r = 0, const int g = 0,
                                  const int b = 0);
manipulator::smanipiii background(const int r = 0, const int g = 0,
                                  const int b = 0);
}  // namespace RGB

}  // namespace truecolor

}  // namespace aesc

#endif
