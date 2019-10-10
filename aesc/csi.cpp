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
          << color_end_expr;
        return s;
    };
    return manipulator::smanipiii(h, r, g, b);
}
manipulator::smanipiii background(const int r, const int g, const int b) {
    // @todo: assert 0 <= r,g,b <= 5
    auto h = [](std::ostream& s, const int r, const int g,
                const int b) -> std::ostream& {
        s << CSI_expr << background_8bit_expr << 16 + 36 * r + 6 * g + b
          << color_end_expr;
        return s;
    };
    return manipulator::smanipiii(h, r, g, b);
}
}  // namespace RGB

namespace grey {
manipulator::smanip foreground(const int n) {
    // @todo: assert 0 <= n <= 23
    auto h = [](std::ostream& s, const int x) -> std::ostream& {
        s << CSI_expr << foreground_8bit_expr << 255 - x << color_end_expr;
        return s;
    };
    return manipulator::smanip(h, n);
}
manipulator::smanip background(const int n) {
    // @todo: assert 0 <= n <= 23
    auto h = [](std::ostream& s, const int x) -> std::ostream& {
        s << CSI_expr << background_8bit_expr << 255 - x << color_end_expr;
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
          << color_end_expr;
        return s;
    };
    return manipulator::smanipiii(h, r, g, b);
}
manipulator::smanipiii background(const int r, const int g, const int b) {
    // @todo: assert 0 <= r,g,b <= 255
    auto h = [](std::ostream& s, const int r, const int g,
                const int b) -> std::ostream& {
        s << CSI_expr << background_24bit_expr << r << ";" << g << ";" << b
          << color_end_expr;
        return s;
    };
    return manipulator::smanipiii(h, r, g, b);
}
}  // namespace RGB

}  // namespace truecolor

}  // namespace aesc
