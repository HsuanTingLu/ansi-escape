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

#include "control/cursor.hpp"

#include "internal/sequences.hpp"

namespace aesc {  // Ansi Escape Terminal

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

}  // namespace aesc
