/*
 * Copyright (C) 2019  Hsuan-Ting Lu <hsuan.ting.lu.ee05@g2.nctu.edu.tw>
 *
 * Wrap some CSI escape codes with string streams
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

#ifndef AESC_CSI_HPP_
#define AESC_CSI_HPP_

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

namespace {
// Control Sequence Introducer
constexpr const char* CSI_expr = "\033[";
/*
 * sequence of parameters are seperated with semicolons ';'
 */
}  // anonymous namespace

namespace cursor {
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
manipulator::smanip EL(clear n);
// Saves cursor position and state
std::ostream& save_pos(std::ostream& stream);
// Restores cursor position and state
std::ostream& restore_pos(std::ostream& stream);
}  // namespace cursor

namespace SGR {  // Select Graphic Rendition

namespace {
constexpr const char* color_end_expr = "m";
}  // anonymous namespace

std::ostream& reset(std::ostream& stream);
std::ostream& bold(std::ostream& stream);   // with increased intensity
std::ostream& faint(std::ostream& stream);  // with decreased intensity
std::ostream& italic(std::ostream& stream);
std::ostream& underline(std::ostream& stream);

namespace blink {
std::ostream& slow(std::ostream& stream);
std::ostream& rapid(std::ostream& stream);
}  // namespace blink

std::ostream& reverse_color(
    std::ostream& stream);  // swap fore/back-ground colors
std::ostream& cross_out(std::ostream& stream);
std::ostream& reset_intensity(std::ostream& stream);
std::ostream& cancel_underline(std::ostream& stream);
std::ostream& cancel_blink(std::ostream& stream);
std::ostream& cancel_inverse(std::ostream& stream);
std::ostream& cancel_cross_out(std::ostream& stream);
}  // namespace SGR

namespace color {
std::ostream& black(std::ostream& stream);
std::ostream& red(std::ostream& stream);
std::ostream& green(std::ostream& stream);
std::ostream& yellow(std::ostream& stream);
std::ostream& blue(std::ostream& stream);
std::ostream& magenta(std::ostream& stream);
std::ostream& cyan(std::ostream& stream);
std::ostream& white(std::ostream& stream);

namespace background {
std::ostream& black(std::ostream& stream);
std::ostream& red(std::ostream& stream);
std::ostream& green(std::ostream& stream);
std::ostream& yellow(std::ostream& stream);
std::ostream& blue(std::ostream& stream);
std::ostream& magenta(std::ostream& stream);
std::ostream& cyan(std::ostream& stream);
std::ostream& white(std::ostream& stream);
}  // namespace background

namespace bright {
std::ostream& black(std::ostream& stream);
std::ostream& red(std::ostream& stream);
std::ostream& green(std::ostream& stream);
std::ostream& yellow(std::ostream& stream);
std::ostream& blue(std::ostream& stream);
std::ostream& magenta(std::ostream& stream);
std::ostream& cyan(std::ostream& stream);
std::ostream& white(std::ostream& stream);

namespace background {
std::ostream& black(std::ostream& stream);
std::ostream& red(std::ostream& stream);
std::ostream& green(std::ostream& stream);
std::ostream& yellow(std::ostream& stream);
std::ostream& blue(std::ostream& stream);
std::ostream& magenta(std::ostream& stream);
std::ostream& cyan(std::ostream& stream);
std::ostream& white(std::ostream& stream);
}  // namespace background

}  // namespace bright

}  // namespace color

namespace color256 {
// 8-bit, 256 colors
/* <Predefined 256 colors>
 * <n>:
 * 16- 231:  6×6×6 cube (216 colors): 16 + 36×r + 6×g + b (0≤r,g,b≤5)
 * 232-255:  grayscale from black to white in 24 steps
 */
namespace RGB {
manipulator::smanipiii foreground(const int r = 0, const int g = 0,
                                  const int b = 0);
manipulator::smanipiii background(const int r = 0, const int g = 0,
                                  const int b = 0);
}  // namespace RGB

namespace grey {
/*
 * 24 step grey:
 * <n> ranges from 0 to 23, from white to black
 */
manipulator::smanip foreground(const int n = 1);
manipulator::smanip background(const int n = 1);
}  // namespace grey

}  // namespace color256

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
