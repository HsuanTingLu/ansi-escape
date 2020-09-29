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
    smanip(std::ostream& (*ff)(std::ostream&, const int), const int ii);

   private:
    std::ostream& (*f)(std::ostream&, const int);  // function to be called
    const int i;  // value to be used as argument
};

class smanipiii {  // manipulator that takes triple ints as arguments
    friend std::ostream& operator<<(std::ostream&, const smanipiii&);

   public:
    smanipiii(std::ostream& (*ff)(std::ostream&, const int, const int,
                                  const int),
              const int i1, const int i2, const int i3);

   private:
    std::ostream& (*f)(std::ostream&, const int, const int,
                       const int);  // function to be called
    // values to be used as argument
    const int i1;
    const int i2;
    const int i3;
};

}  // namespace manipulator

}  // namespace aesc

#endif  // AESC_INTERNAL_MANIPULATOR_HPP_
