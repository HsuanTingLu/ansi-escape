/*
 * Manipulators of general output streams that take one or three arguments
 */

#include "aesc/internal/manipulator.hpp"

namespace aesc {  // Ansi Escape Terminal

namespace manipulator {

smanip::smanip(std::ostream& (*ff)(std::ostream&, const int), const int ii)
    : f{ff}, i{ii} {}

std::ostream& operator<<(std::ostream& os, const smanip& m) {
    m.f(os, m.i);  // call m’s function with m’s stored value i
    return os;
}

smanipiii::smanipiii(std::ostream& (*ff)(std::ostream&, const int, const int,
                                         const int),
                     const int i1, const int i2, const int i3)
    : f{ff}, i1{i1}, i2{i2}, i3{i3} {}

std::ostream& operator<<(std::ostream& os, const smanipiii& m) {
    m.f(os, m.i1, m.i2, m.i3);  // call m’s function with m’s stored value i
    return os;
}

}  // namespace manipulator

}  // namespace aesc
