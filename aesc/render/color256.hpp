/*
 * Wrap 8-bit color codes within general output streams
 */

#ifndef AESC_RENDER_COLOR256_HPP_
#define AESC_RENDER_COLOR256_HPP_

#include "aesc/internal/manipulator.hpp"

namespace aesc {  // Ansi Escape Terminal

namespace color256 {
// 8-bit, 256 colors
/* <Predefined 256 colors>
 * <n>:
 * 16- 231:  6×6×6 cube (216 colors): 16 + 36×r + 6×g + b (0≤r,g,b≤5)
 * 232-255:  grayscale from black to white in 24 steps
 */

namespace RGB {

manipulator::smanipiii foreground(int r = 0, int g = 0, int b = 0);
manipulator::smanipiii background(int r = 0, int g = 0, int b = 0);
extern decltype(foreground)& fg;
extern decltype(background)& bg;

}  // namespace RGB

namespace grey {
/*
 * 24 step grey:
 * <n> ranges from 0 to 23, from white to black
 */
manipulator::smanip foreground(int n = 1);
manipulator::smanip background(int n = 1);
extern decltype(foreground)& fg;
extern decltype(background)& bg;

}  // namespace grey

}  // namespace color256

namespace RGB = color256::RGB;

}  // namespace aesc

#endif  // AESC_RENDER_COLOR256_HPP_
