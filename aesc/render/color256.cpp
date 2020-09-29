/*
 * Wrap 8-bit color codes within general output streams
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
