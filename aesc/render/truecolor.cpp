/*
 * Wrap 24-bit true color codes within general output streams
 */

#include "truecolor.hpp"

#include <stdexcept>

#include "../internal/sequences.hpp"
#include "internal.hpp"

namespace aesc {  // Ansi Escape Terminal

namespace truecolor {

namespace {  // 24-bit, true color
constexpr const char* foreground_24bit_expr = "38;2;";
constexpr const char* background_24bit_expr = "48;2;";
}  // anonymous namespace

inline namespace RGB {

manipulator::smanipiii foreground(const int r, const int g, const int b) {
    if (0 > r || r > 255 || 0 > g || g > 255 || 0 > b || b > 255) {
        throw std::invalid_argument("invalid argument(s)");
    }

    auto h = [](std::ostream& s, const int r, const int g,
                const int b) -> std::ostream& {
        s << CSI_expr << foreground_24bit_expr << r << ";" << g << ";" << b
          << end_expr;
        return s;
    };
    return manipulator::smanipiii(h, r, g, b);
}

manipulator::smanipiii background(const int r, const int g, const int b) {
    if (0 > r || r > 255 || 0 > g || g > 255 || 0 > b || b > 255) {
        throw std::invalid_argument("invalid argument(s)");
    }

    auto h = [](std::ostream& s, const int r, const int g,
                const int b) -> std::ostream& {
        s << CSI_expr << background_24bit_expr << r << ";" << g << ";" << b
          << end_expr;
        return s;
    };
    return manipulator::smanipiii(h, r, g, b);
}

auto& fg = foreground;

auto& bg = background;

}  // namespace RGB

}  // namespace truecolor

}  // namespace aesc
