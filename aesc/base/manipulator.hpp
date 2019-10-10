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

#ifndef AESC_BASE_MANIPULATOR_HPP_
#define AESC_BASE_MANIPULATOR_HPP_

#include <iostream>

namespace aesc {  // Ansi Escape Terminal

namespace manipulator {  // for stream manipulators that needs arguments

class smanip {
    // manipulator that takes a single int as argument
    template <typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(
        std::basic_ostream<CharT, Traits>&, const smanip&);

   public:
    smanip(std::ostream& (*ff)(std::ostream&, const int), const int ii);

   private:
    std::ostream& (*f)(std::ostream&, const int);  // function to be called
    const int i;  // value to be used as argument
};
template <typename CharT, typename Traits>
std::basic_ostream<CharT, Traits>& operator<<(
    std::basic_ostream<CharT, Traits>& os, const smanip& m) {
    m.f(os, m.i);  // call m’s function with m’s stored value i
    return os;
}

class smanipiii {  // manipulator that takes triple ints as arguments
    template <typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(
        std::basic_ostream<CharT, Traits>&, const smanipiii&);

   public:
    smanipiii(std::ostream& (*ff)(std::ostream&, const int, const int,
                                  const int),
              const int i1, const int i2, const int i3);

   private:
    std::ostream& (*f)(std::ostream&, const int, const int,
                       const int);  // function to be called
    // values to be used as argument
    const int i1;
    const int i2;
    const int i3;
};
template <typename CharT, typename Traits>
std::basic_ostream<CharT, Traits>& operator<<(
    std::basic_ostream<CharT, Traits>& os, const smanipiii& m) {
    m.f(os, m.i1, m.i2, m.i3);  // call m’s function with m’s stored value i
    return os;
}

}  // namespace manipulator

}  // namespace aesc

#endif
