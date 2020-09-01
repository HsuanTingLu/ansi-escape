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

#include "aesc/render/color256.hpp"

#include <stdexcept>

#include "aesc/internal/sequences.hpp"
#include "aesc/render/internal.hpp"

namespace aesc {  // Ansi Escape Terminal

namespace color256 {

namespace {  // 8-bit, 256 colors
constexpr const char* foreground_8bit_expr = "38;5;";
constexpr const char* background_8bit_expr = "48;5;";
}  // anonymous namespace

namespace RGB {

manipulator::smanipiii foreground(const int r, const int g, const int b) {
    if (0 > r || r > 5 || 0 > g || g > 5 || 0 > b || b > 5) {
        throw std::invalid_argument("invalid argument(s)");
    }

    auto h = [](std::ostream& s, const int r, const int g,
                const int b) -> std::ostream& {
        s << CSI_expr << foreground_8bit_expr << 16 + 36 * r + 6 * g + b
          << end_expr;
        return s;
    };
    return {h, r, g, b};
}

manipulator::smanipiii background(const int r, const int g, const int b) {
    if (0 > r || r > 5 || 0 > g || g > 5 || 0 > b || b > 5) {
        throw std::invalid_argument("invalid argument(s)");
    }

    auto h = [](std::ostream& s, const int r, const int g,
                const int b) -> std::ostream& {
        s << CSI_expr << background_8bit_expr << 16 + 36 * r + 6 * g + b
          << end_expr;
        return s;
    };
    return {h, r, g, b};
}

auto& fg = foreground;

auto& bg = background;

}  // namespace RGB

namespace grey {

manipulator::smanip foreground(const int n) {
    if (0 > n || n > 23) {
        throw std::invalid_argument("invalid argument(s)");
    }

    auto h = [](std::ostream& s, const int x) -> std::ostream& {
        s << CSI_expr << foreground_8bit_expr << 255 - x << end_expr;
        return s;
    };
    return {h, n};
}

manipulator::smanip background(const int n) {
    if (0 > n || n > 23) {
        throw std::invalid_argument("invalid argument(s)");
    }

    auto h = [](std::ostream& s, const int x) -> std::ostream& {
        s << CSI_expr << background_8bit_expr << 255 - x << end_expr;
        return s;
    };
    return {h, n};
}

auto& fg = foreground;

auto& bg = background;

}  // namespace grey

}  // namespace color256

}  // namespace aesc
