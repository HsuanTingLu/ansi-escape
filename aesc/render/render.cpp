/*
 * Wrap the Select Graphic Rendition codes
 */

#include "aesc/render/render.hpp"

#include "aesc/internal/sequences.hpp"
#include "aesc/render/internal.hpp"

namespace aesc {  // Ansi Escape Terminal

inline namespace render {  // Select Graphic Rendition

namespace {
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
    stream << CSI_expr << reset_expr << end_expr;
    return stream;
}

std::ostream& bold(std::ostream& stream) {
    stream << CSI_expr << bold_expr << end_expr;
    return stream;
}

std::ostream& faint(std::ostream& stream) {
    stream << CSI_expr << faint_expr << end_expr;
    return stream;
}

std::ostream& italic(std::ostream& stream) {
    stream << CSI_expr << italic_expr << end_expr;
    return stream;
}

std::ostream& underline(std::ostream& stream) {
    stream << CSI_expr << underline_expr << end_expr;
    return stream;
}

namespace blink {

std::ostream& slow(std::ostream& stream) {
    stream << CSI_expr << slow_blink_expr << end_expr;
    return stream;
}

std::ostream& rapid(std::ostream& stream) {
    stream << CSI_expr << rapid_blink_expr << end_expr;
    return stream;
}

}  // namespace blink

std::ostream& reverse_color(std::ostream& stream) {
    stream << CSI_expr << reverse_expr << end_expr;
    return stream;
}

std::ostream& cross_out(std::ostream& stream) {
    stream << CSI_expr << cross_out_expr << end_expr;
    return stream;
}

std::ostream& reset_intensity(std::ostream& stream) {
    stream << CSI_expr << reset_intensity_expr << end_expr;
    return stream;
}

std::ostream& cancel_underline(std::ostream& stream) {
    stream << CSI_expr << cancel_underline_expr << end_expr;
    return stream;
}

std::ostream& cancel_blink(std::ostream& stream) {
    stream << CSI_expr << cancel_blink_expr << end_expr;
    return stream;
}

std::ostream& cancel_inverse(std::ostream& stream) {
    stream << CSI_expr << cancel_inverse_expr << end_expr;
    return stream;
}

std::ostream& cancel_cross_out(std::ostream& stream) {
    stream << CSI_expr << cancel_cross_out_expr << end_expr;
    return stream;
}

}  // namespace render

}  // namespace aesc
