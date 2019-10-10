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

#include "csi.hpp"

namespace aesc {

namespace manipulator {
smanip::smanip(std::ostream& (*ff)(std::ostream&, const int), const int ii)
    : f{ff}, i{ii} {}

smanipiii::smanipiii(std::ostream& (*ff)(std::ostream&, const int, const int,
                                         const int),
                     const int i1, const int i2, const int i3)
    : f{ff}, i1{i1}, i2{i2}, i3{i3} {}
}  // namespace manipulator

namespace cursor {
namespace {
constexpr const char* up_expr = "A";
constexpr const char* down_expr = "B";
constexpr const char* forward_expr = "C";
constexpr const char* back_expr = "D";
constexpr const char* next_line_expr = "E";
constexpr const char* prev_line_expr = "F";
constexpr const char* erase_in_line_expr = "K";
constexpr const char* save_cursor_expr = "s";
constexpr const char* restore_cursor_expr = "u";
}  // anonymous namespace

manipulator::smanip up(const int n) {
    auto h = [](std::ostream& s, const int x) -> std::ostream& {
        s << CSI_expr << x << up_expr;
        return s;
    };
    return manipulator::smanip(h, n);
}
manipulator::smanip down(const int n) {
    auto h = [](std::ostream& s, const int x) -> std::ostream& {
        s << CSI_expr << x << down_expr;
        return s;
    };
    return manipulator::smanip(h, n);
}
manipulator::smanip forward(const int n) {
    auto h = [](std::ostream& s, const int x) -> std::ostream& {
        s << CSI_expr << x << forward_expr;
        return s;
    };
    return manipulator::smanip(h, n);
}
manipulator::smanip back(const int n) {
    auto h = [](std::ostream& s, const int x) -> std::ostream& {
        s << CSI_expr << x << back_expr;
        return s;
    };
    return manipulator::smanip(h, n);
}
manipulator::smanip next_line(const int n) {
    auto h = [](std::ostream& s, const int x) -> std::ostream& {
        s << CSI_expr << x << next_line_expr;
        return s;
    };
    return manipulator::smanip(h, n);
}
manipulator::smanip prev_line(const int n) {
    auto h = [](std::ostream& s, const int x) -> std::ostream& {
        s << CSI_expr << x << prev_line_expr;
        return s;
    };
    return manipulator::smanip(h, n);
}
manipulator::smanip EL(clear n) {
    /*
     * n = 0: clear from cursor to end of screen
     * n = 1: clear from cursor to beginning of the screen
     * n = 2: clear entire screen, and moves cursor to upper left
     */
    auto h = [](std::ostream& s, const int x) -> std::ostream& {
        s << CSI_expr << x << erase_in_line_expr;
        return s;
    };
    return manipulator::smanip(h, static_cast<int>(n));
}
std::ostream& save_pos(std::ostream& stream) {
    stream << CSI_expr << save_cursor_expr;
    return stream;
}
std::ostream& restore_pos(std::ostream& stream) {
    stream << CSI_expr << restore_cursor_expr;
    return stream;
}

}  // namespace cursor

namespace SGR {
namespace {
// HACK: constexpr const char* color_end_expr = "m";
constexpr const char* reset_expr = "0";
constexpr const char* bold_expr = "1";
constexpr const char* faint_expr = "2";
constexpr const char* italic_expr = "3";
constexpr const char* underline_expr = "4";
constexpr const char* slow_blink_expr = "5";
constexpr const char* rapid_blink_expr = "6";
constexpr const char* reverse_expr = "7";
constexpr const char* cross_out_expr = "9";
constexpr const char* reset_intensity_expr = "22";
constexpr const char* cancel_underline_expr = "24";
constexpr const char* cancel_blink_expr = "25";
constexpr const char* cancel_inverse_expr = "27";
constexpr const char* cancel_cross_out_expr = "29";
}  // anonymous namespace

std::ostream& reset(std::ostream& stream) {
    stream << CSI_expr << reset_expr << color_end_expr;
    return stream;
}
std::ostream& bold(std::ostream& stream) {
    stream << CSI_expr << bold_expr << color_end_expr;
    return stream;
}
std::ostream& faint(std::ostream& stream) {
    stream << CSI_expr << faint_expr << color_end_expr;
    return stream;
}
std::ostream& italic(std::ostream& stream) {
    stream << CSI_expr << italic_expr << color_end_expr;
    return stream;
}
std::ostream& underline(std::ostream& stream) {
    stream << CSI_expr << underline_expr << color_end_expr;
    return stream;
}

namespace blink {
std::ostream& slow(std::ostream& stream) {
    stream << CSI_expr << slow_blink_expr << color_end_expr;
    return stream;
}
std::ostream& rapid(std::ostream& stream) {
    stream << CSI_expr << rapid_blink_expr << color_end_expr;
    return stream;
}
}  // namespace blink

std::ostream& reverse_color(std::ostream& stream) {
    stream << CSI_expr << reverse_expr << color_end_expr;
    return stream;
}
std::ostream& cross_out(std::ostream& stream) {
    stream << CSI_expr << cross_out_expr << color_end_expr;
    return stream;
}
std::ostream& reset_intensity(std::ostream& stream) {
    stream << CSI_expr << reset_intensity_expr << color_end_expr;
    return stream;
}
std::ostream& cancel_underline(std::ostream& stream) {
    stream << CSI_expr << cancel_underline_expr << color_end_expr;
    return stream;
}
std::ostream& cancel_blink(std::ostream& stream) {
    stream << CSI_expr << cancel_blink_expr << color_end_expr;
    return stream;
}
std::ostream& cancel_inverse(std::ostream& stream) {
    stream << CSI_expr << cancel_inverse_expr << color_end_expr;
    return stream;
}
std::ostream& cancel_cross_out(std::ostream& stream) {
    stream << CSI_expr << cancel_cross_out_expr << color_end_expr;
    return stream;
}

}  // namespace SGR

namespace color {
inline namespace {  // 4-bit
// foreground colors, 30-39
constexpr const char* fg_black_expr = "30";
constexpr const char* fg_red_expr = "31";
constexpr const char* fg_green_expr = "32";
constexpr const char* fg_yellow_expr = "33";
constexpr const char* fg_blue_expr = "34";
constexpr const char* fg_magenta_expr = "35";
constexpr const char* fg_cyan_expr = "36";
constexpr const char* fg_white_expr = "37";
// background color, 40-49
constexpr const char* bg_black_expr = "40";
constexpr const char* bg_red_expr = "41";
constexpr const char* bg_green_expr = "42";
constexpr const char* bg_yellow_expr = "43";
constexpr const char* bg_blue_expr = "44";
constexpr const char* bg_magenta_expr = "45";
constexpr const char* bg_cyan_expr = "46";
constexpr const char* bg_white_expr = "47";
// bright foreground colors, 90-97
constexpr const char* b_fg_black_expr = "90";
constexpr const char* b_fg_red_expr = "91";
constexpr const char* b_fg_green_expr = "92";
constexpr const char* b_fg_yellow_expr = "93";
constexpr const char* b_fg_blue_expr = "94";
constexpr const char* b_fg_magenta_expr = "95";
constexpr const char* b_fg_cyan_expr = "96";
constexpr const char* b_fg_white_expr = "97";
// bright background colors, 100-107
constexpr const char* b_bg_black_expr = "100";
constexpr const char* b_bg_red_expr = "101";
constexpr const char* b_bg_green_expr = "102";
constexpr const char* b_bg_yellow_expr = "103";
constexpr const char* b_bg_blue_expr = "104";
constexpr const char* b_bg_magenta_expr = "105";
constexpr const char* b_bg_cyan_expr = "106";
constexpr const char* b_bg_white_expr = "107";
}  // anonymous namespace

std::ostream& black(std::ostream& stream) {
    stream << CSI_expr << fg_black_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& red(std::ostream& stream) {
    stream << CSI_expr << fg_red_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& green(std::ostream& stream) {
    stream << CSI_expr << fg_green_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& yellow(std::ostream& stream) {
    stream << CSI_expr << fg_yellow_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& blue(std::ostream& stream) {
    stream << CSI_expr << fg_blue_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& magenta(std::ostream& stream) {
    stream << CSI_expr << fg_magenta_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& cyan(std::ostream& stream) {
    stream << CSI_expr << fg_cyan_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& white(std::ostream& stream) {
    stream << CSI_expr << fg_white_expr << SGR::color_end_expr;
    return stream;
}

namespace background {
std::ostream& black(std::ostream& stream) {
    stream << CSI_expr << bg_black_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& red(std::ostream& stream) {
    stream << CSI_expr << bg_red_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& green(std::ostream& stream) {
    stream << CSI_expr << bg_green_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& yellow(std::ostream& stream) {
    stream << CSI_expr << bg_yellow_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& blue(std::ostream& stream) {
    stream << CSI_expr << bg_blue_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& magenta(std::ostream& stream) {
    stream << CSI_expr << bg_magenta_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& cyan(std::ostream& stream) {
    stream << CSI_expr << bg_cyan_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& white(std::ostream& stream) {
    stream << CSI_expr << bg_white_expr << SGR::color_end_expr;
    return stream;
}
}  // namespace background
namespace bright {
std::ostream& black(std::ostream& stream) {
    stream << CSI_expr << b_fg_black_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& red(std::ostream& stream) {
    stream << CSI_expr << b_fg_red_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& green(std::ostream& stream) {
    stream << CSI_expr << b_fg_green_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& yellow(std::ostream& stream) {
    stream << CSI_expr << b_fg_yellow_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& blue(std::ostream& stream) {
    stream << CSI_expr << b_fg_blue_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& magenta(std::ostream& stream) {
    stream << CSI_expr << b_fg_magenta_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& cyan(std::ostream& stream) {
    stream << CSI_expr << b_fg_cyan_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& white(std::ostream& stream) {
    stream << CSI_expr << b_fg_white_expr << SGR::color_end_expr;
    return stream;
}

namespace background {
std::ostream& black(std::ostream& stream) {
    stream << CSI_expr << b_bg_black_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& red(std::ostream& stream) {
    stream << CSI_expr << b_bg_red_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& green(std::ostream& stream) {
    stream << CSI_expr << b_bg_green_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& yellow(std::ostream& stream) {
    stream << CSI_expr << b_bg_yellow_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& blue(std::ostream& stream) {
    stream << CSI_expr << b_bg_blue_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& magenta(std::ostream& stream) {
    stream << CSI_expr << b_bg_magenta_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& cyan(std::ostream& stream) {
    stream << CSI_expr << b_bg_cyan_expr << SGR::color_end_expr;
    return stream;
}
std::ostream& white(std::ostream& stream) {
    stream << CSI_expr << b_bg_white_expr << SGR::color_end_expr;
    return stream;
}
}  // namespace background

}  // namespace bright

}  // namespace color

namespace color256 {
namespace {  // 8-bit, 256 colors
constexpr const char* foreground_8bit_expr = "38;5;";
constexpr const char* background_8bit_expr = "48;5;";
}  // anonymous namespace
namespace RGB {
manipulator::smanipiii foreground(const int r, const int g, const int b) {
    // @todo: assert 0 <= r,g,b <= 5
    auto h = [](std::ostream& s, const int r, const int g,
                const int b) -> std::ostream& {
        s << CSI_expr << foreground_8bit_expr << 16 + 36 * r + 6 * g + b
          << SGR::color_end_expr;
        return s;
    };
    return manipulator::smanipiii(h, r, g, b);
}
manipulator::smanipiii background(const int r, const int g, const int b) {
    // @todo: assert 0 <= r,g,b <= 5
    auto h = [](std::ostream& s, const int r, const int g,
                const int b) -> std::ostream& {
        s << CSI_expr << background_8bit_expr << 16 + 36 * r + 6 * g + b
          << SGR::color_end_expr;
        return s;
    };
    return manipulator::smanipiii(h, r, g, b);
}
}  // namespace RGB

namespace grey {
manipulator::smanip foreground(const int n) {
    // @todo: assert 0 <= n <= 23
    auto h = [](std::ostream& s, const int x) -> std::ostream& {
        s << CSI_expr << foreground_8bit_expr << 255 - x << SGR::color_end_expr;
        return s;
    };
    return manipulator::smanip(h, n);
}
manipulator::smanip background(const int n) {
    // @todo: assert 0 <= n <= 23
    auto h = [](std::ostream& s, const int x) -> std::ostream& {
        s << CSI_expr << background_8bit_expr << 255 - x << SGR::color_end_expr;
        return s;
    };
    return manipulator::smanip(h, n);
}
}  // namespace grey

}  // namespace color256

namespace truecolor {
namespace {  // 24-bit, true color
constexpr const char* foreground_24bit_expr = "38;2;";
constexpr const char* background_24bit_expr = "48;2;";
}  // anonymous namespace

namespace RGB {
manipulator::smanipiii foreground(const int r, const int g, const int b) {
    // @todo: assert 0 <= r,g,b <= 255
    auto h = [](std::ostream& s, const int r, const int g,
                const int b) -> std::ostream& {
        s << CSI_expr << foreground_24bit_expr << r << ";" << g << ";" << b
          << SGR::color_end_expr;
        return s;
    };
    return manipulator::smanipiii(h, r, g, b);
}
manipulator::smanipiii background(const int r, const int g, const int b) {
    // @todo: assert 0 <= r,g,b <= 255
    auto h = [](std::ostream& s, const int r, const int g,
                const int b) -> std::ostream& {
        s << CSI_expr << background_24bit_expr << r << ";" << g << ";" << b
          << SGR::color_end_expr;
        return s;
    };
    return manipulator::smanipiii(h, r, g, b);
}
}  // namespace RGB

}  // namespace truecolor

}  // namespace aesc
