/*
 * Wraps cursor control sequences
 */

#include "cursor.hpp"

namespace aesc {  // Ansi Escape Terminal

inline namespace cursor {

namespace internal {

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

auto up(std::ostream& s, const int x) -> std::ostream& {
    s << CSI_expr << x << up_expr;
    return s;
}

auto down(std::ostream& s, const int x) -> std::ostream& {
    s << CSI_expr << x << down_expr;
    return s;
};

auto forward(std::ostream& s, const int x) -> std::ostream& {
    s << CSI_expr << x << forward_expr;
    return s;
};

auto back(std::ostream& s, const int x) -> std::ostream& {
    s << CSI_expr << x << back_expr;
    return s;
};

auto next_line(std::ostream& s, const int x) -> std::ostream& {
    s << CSI_expr << x << next_line_expr;
    return s;
};

auto prev_line(std::ostream& s, const int x) -> std::ostream& {
    s << CSI_expr << x << prev_line_expr;
    return s;
};

auto EL(std::ostream& s, const int x) -> std::ostream& {
    s << CSI_expr << x << erase_in_line_expr;
    return s;
};

}  // namespace internal

std::ostream& save_pos(std::ostream& stream) {
    stream << CSI_expr << internal::save_cursor_expr;
    return stream;
}

std::ostream& restore_pos(std::ostream& stream) {
    stream << CSI_expr << internal::restore_cursor_expr;
    return stream;
}

}  // namespace cursor

}  // namespace aesc
