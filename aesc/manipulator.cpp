/*
 * Copyright (C) 2019  Hsuan-Ting Lu <hsuan.ting.lu.ee05@g2.nctu.edu.tw>
 *
 * Manipulators of general output streams that take one or three arguments
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

#include "manipulator.hpp"

namespace aesc {  // Ansi Escape Terminal

namespace manipulator {
smanip::smanip(std::ostream& (*ff)(std::ostream&, const int), const int ii)
    : f{ff}, i{ii} {}

smanipiii::smanipiii(std::ostream& (*ff)(std::ostream&, const int, const int,
                                         const int),
                     const int i1, const int i2, const int i3)
    : f{ff}, i1{i1}, i2{i2}, i3{i3} {}

}  // namespace manipulator

}  // namespace aesc