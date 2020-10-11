/*
 * Wrap 24-bit true color codes within general output streams
 */

#ifndef AESC_RENDER_TRUECOLOR_HPP_
#define AESC_RENDER_TRUECOLOR_HPP_

#include <iostream>

#include "../internal/manipulator.hpp"

namespace aesc {  // Ansi Escape Terminal

namespace truecolor {

inline namespace RGB {

manipulator::smanipiii foreground(int r = 0, int g = 0, int b = 0);

manipulator::smanipiii background(int r = 0, int g = 0, int b = 0);

extern decltype(foreground)& fg;

extern decltype(background)& bg;

}  // namespace RGB

}  // namespace truecolor

}  // namespace aesc

#endif  // AESC_RENDER_TRUECOLOR_HPP_
