/*
 * Manipulators of general output streams that take one or three arguments
 */

#include "aesc/internal/manipulator.hpp"

namespace aesc {  // Ansi Escape Terminal

namespace manipulator {

std::ostream& operator<<(std::ostream& os, const smanip& m) {
    m.f(os, m.i);  // call m’s function with m’s stored value i
    return os;
}

std::ostream& operator<<(std::ostream& os, const smanipiii& m) {
    m.f(os, m.i1, m.i2, m.i3);  // call m’s function with m’s stored value i
    return os;
}

}  // namespace manipulator

}  // namespace aesc
