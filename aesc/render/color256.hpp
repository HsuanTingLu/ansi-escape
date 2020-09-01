/*
 * Copyright (C) 2019  Hsuan-Ting Lu <hsuan.ting.lu.ee05@g2.nctu.edu.tw>
 *
 * Wrap 8-bit color codes within general output streams
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

#ifndef AESC_RENDER_COLOR256_HPP_
#define AESC_RENDER_COLOR256_HPP_

#include "aesc/internal/manipulator.hpp"

namespace aesc {  // Ansi Escape Terminal

namespace color256 {
// 8-bit, 256 colors
/* <Predefined 256 colors>
 * <n>:
 * 16- 231:  6×6×6 cube (216 colors): 16 + 36×r + 6×g + b (0≤r,g,b≤5)
 * 232-255:  grayscale from black to white in 24 steps
 */

namespace RGB {

manipulator::smanipiii foreground(int r = 0, int g = 0, int b = 0);
manipulator::smanipiii background(int r = 0, int g = 0, int b = 0);
auto& fg = foreground;
auto& bg = background;

}  // namespace RGB

namespace grey {
/*
 * 24 step grey:
 * <n> ranges from 0 to 23, from white to black
 */
manipulator::smanip foreground(int n = 1);
manipulator::smanip background(int n = 1);
auto& fg = foreground;
auto& bg = background;

}  // namespace grey

}  // namespace color256

namespace RGB = color256::RGB;

}  // namespace aesc

#endif  // AESC_RENDER_COLOR256_HPP_
