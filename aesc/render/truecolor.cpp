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

#include "aesc/render/truecolor.hpp"

#include "aesc/internal/sequences.hpp"
#include "aesc/render/internal.hpp"

namespace aesc {  // Ansi Escape Terminal

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
          << end_expr;
        return s;
    };
    return {h, r, g, b};
}

manipulator::smanipiii background(const int r, const int g, const int b) {
    // @todo: assert 0 <= r,g,b <= 255
    auto h = [](std::ostream& s, const int r, const int g,
                const int b) -> std::ostream& {
        s << CSI_expr << background_24bit_expr << r << ";" << g << ";" << b
          << end_expr;
        return s;
    };
    return {h, r, g, b};
}

}  // namespace RGB

}  // namespace truecolor

}  // namespace aesc
