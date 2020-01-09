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

#include "aesc/internal/manipulator.hpp"

namespace aesc {  // Ansi Escape Terminal

namespace manipulator {

smanip::smanip(std::ostream& (*ff)(std::ostream&, const int), const int ii)
    : f{ff}, i{ii} {}

std::ostream& operator<<(std::ostream& os, const smanip& m) {
    m.f(os, m.i);  // call m’s function with m’s stored value i
    return os;
}

smanipiii::smanipiii(std::ostream& (*ff)(std::ostream&, const int, const int,
                                         const int),
                     const int i1, const int i2, const int i3)
    : f{ff}, i1{i1}, i2{i2}, i3{i3} {}

std::ostream& operator<<(std::ostream& os, const smanipiii& m) {
    m.f(os, m.i1, m.i2, m.i3);  // call m’s function with m’s stored value i
    return os;
}

}  // namespace manipulator

}  // namespace aesc
