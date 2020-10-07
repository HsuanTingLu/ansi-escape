/*
 * Wraps cursor control sequences
 */

#ifndef AESC_CONTROL_CURSOR_HPP_
#define AESC_CONTROL_CURSOR_HPP_

#include "aesc/internal/manipulator.hpp"
#include "aesc/internal/sequences.hpp"

namespace aesc {  // Ansi Escape Terminal

inline namespace cursor {  // Cursor controls

enum class clear : int { to_end = 0, to_beginning = 1, entire = 2 };

namespace internal {

std::ostream& up(std::ostream& s, int x);

std::ostream& down(std::ostream& s, int x);

std::ostream& forward(std::ostream& s, int x);

std::ostream& back(std::ostream& s, int x);

std::ostream& next_line(std::ostream& s, int x);

std::ostream& prev_line(std::ostream& s, int x);

std::ostream& EL(std::ostream& s, int x);

}  // namespace internal

constexpr manipulator::smanip up(int n = 1) {
    return manipulator::smanip(internal::up, n);
}

constexpr manipulator::smanip down(int n = 1) {
    return manipulator::smanip(internal::down, n);
}

constexpr manipulator::smanip forward(int n = 1) {
    return manipulator::smanip(internal::forward, n);
}

constexpr manipulator::smanip back(int n = 1) {
    return manipulator::smanip(internal::back, n);
}

// moves to beginning of next line
constexpr manipulator::smanip next_line(int n = 1) {
    return manipulator::smanip(internal::next_line, n);
}

// moves to beginning of previous line
constexpr manipulator::smanip prev_line(int n = 1) {
    return manipulator::smanip(internal::prev_line, n);
}

// erases from cursor to EOL if 0
// clear from cursor to beginning if 1
// clears entire line if 2
constexpr manipulator::smanip EL(clear n) {
    /*
     * n = 0: clear from cursor to end of screen
     * n = 1: clear from cursor to beginning of the screen
     * n = 2: clear entire line
     *
     * Cursor position does NOT change
     */
    return manipulator::smanip(internal::EL, static_cast<int>(n));
}

// Saves cursor position and state
std::ostream& save_pos(std::ostream& stream);

// Restores cursor position and state
std::ostream& restore_pos(std::ostream& stream);

}  // namespace cursor

}  // namespace aesc

#endif
