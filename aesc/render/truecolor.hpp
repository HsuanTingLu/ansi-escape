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

#ifndef AESC_RENDER_TRUECOLOR_HPP_
#define AESC_RENDER_TRUECOLOR_HPP_

#include <iostream>

#include "aesc/internal/manipulator.hpp"

namespace aesc {  // Ansi Escape Terminal

namespace truecolor {

inline namespace RGB {

manipulator::smanipiii foreground(int r = 0, int g = 0, int b = 0);
manipulator::smanipiii background(int r = 0, int g = 0, int b = 0);
extern decltype(foreground)& fg;
extern decltype(background)& bg;

}  // namespace RGB

}  // namespace truecolor

}  // namespace aesc

#endif  // AESC_RENDER_TRUECOLOR_HPP_
