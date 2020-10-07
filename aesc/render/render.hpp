/*
 * Wrap the Select Graphic Rendition codes
 */

#ifndef AESC_RENDER_RENDER_HPP_
#define AESC_RENDER_RENDER_HPP_

#include <iostream>

namespace aesc {  // Ansi Escape Terminal

inline namespace render {  // Select Graphic Rendition

std::ostream& reset(std::ostream& stream);

std::ostream& bold(std::ostream& stream);  // with increased intensity

std::ostream& faint(std::ostream& stream);  // with decreased intensity

std::ostream& italic(std::ostream& stream);

std::ostream& underline(std::ostream& stream);

namespace blink {

std::ostream& slow(std::ostream& stream);

std::ostream& rapid(std::ostream& stream);

}  // namespace blink

std::ostream& reverse_color(
    std::ostream& stream);  // swap fore/back-ground colors

std::ostream& cross_out(std::ostream& stream);

std::ostream& reset_intensity(std::ostream& stream);

std::ostream& cancel_underline(std::ostream& stream);

std::ostream& cancel_blink(std::ostream& stream);

std::ostream& cancel_inverse(std::ostream& stream);

std::ostream& cancel_cross_out(std::ostream& stream);

}  // namespace render

}  // namespace aesc

#endif  // AESC_RENDER_RENDER_HPP_
