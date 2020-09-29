/*
 * Wraps cursor control sequences
 */

#include "aesc/control/cursor.hpp"

#include "aesc/internal/sequences.hpp"

namespace aesc {  // Ansi Escape Terminal

inline namespace cursor {

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
     * n = 2: clear entire line
     *
     * Cursor position does NOT change
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
