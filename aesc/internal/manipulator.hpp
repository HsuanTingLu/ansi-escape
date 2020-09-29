/*
 * Manipulators of general output streams that take one or three arguments
 */

#ifndef AESC_INTERNAL_MANIPULATOR_HPP_
#define AESC_INTERNAL_MANIPULATOR_HPP_

#include <iostream>

namespace aesc {  // Ansi Escape Terminal

namespace manipulator {  // for stream manipulators that needs arguments

class smanip {
    // manipulator that takes a single int as argument
    friend std::ostream& operator<<(std::ostream&, const smanip&);

   public:
    explicit constexpr smanip(std::ostream& (*const ff)(std::ostream&,
                                                        const int),
                              int ii) noexcept
        : f(ff), i(ii) {}

   private:
    std::ostream& (*const f)(std::ostream&,
                             const int);  // function to be called
    const int i;                          // value to be used as argument
};

class smanipiii {  // manipulator that takes triple ints as arguments
    friend std::ostream& operator<<(std::ostream&, const smanipiii&);

   public:
    explicit constexpr smanipiii(std::ostream& (*const ff)(std::ostream&,
                                                           const int, const int,
                                                           const int),
                                 int i1, int i2, int i3) noexcept
        : f(ff), i1(i1), i2(i2), i3(i3) {}

   private:
    std::ostream& (*const f)(std::ostream&, const int, const int,
                             const int);  // function to be called
    // values to be used as argument
    const int i1;
    const int i2;
    const int i3;
};

}  // namespace manipulator

}  // namespace aesc

#endif  // AESC_INTERNAL_MANIPULATOR_HPP_
