/*
 * Copyright (C) 2019  Hsuan-Ting Lu <hsuan.ting.lu.ee05@g2.nctu.edu.tw>
 *
 * Wraps cursor control sequences
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

#ifndef AESC_CONTROL_CURSOR_HPP_
#define AESC_CONTROL_CURSOR_HPP_

#include "aesc/internal/manipulator.hpp"

namespace aesc {  // Ansi Escape Terminal

inline namespace cursor {  // Cursor controls

enum class clear : int { to_end = 0, to_beginning = 1, entire = 2 };

manipulator::smanip up(const int n = 1);
manipulator::smanip down(const int n = 1);
manipulator::smanip forward(const int n = 1);
manipulator::smanip back(const int n = 1);
// moves to beginning of next line
manipulator::smanip next_line(const int n = 1);
// moves to beginning of previous line
manipulator::smanip prev_line(const int n = 1);
// erases from cursor to EOL if 0
// clear from cursor to beginning if 1
// clears entire line if 2
manipulator::smanip EL(const clear n);
// Saves cursor position and state
std::ostream& save_pos(std::ostream& stream);
// Restores cursor position and state
std::ostream& restore_pos(std::ostream& stream);

}  // namespace cursor

}  // namespace aesc

#endif
