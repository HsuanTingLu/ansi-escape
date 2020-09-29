/*
 * Wrap some CSI escape codes with string streams
 */
#include <iostream>

#include "aesc.hpp"

int main() {
    std::cout << "line1" << std::endl
              << "line2" << std::endl
              << aesc::up(1) << "33"
              << aesc::cursor::EL(aesc::cursor::clear::entire) << "a"
              << std::endl;
    std::cout << aesc::render::bold << aesc::render::blink::slow << " bold"
              << aesc::render::reverse_color << " reversed"
              << aesc::render::reset_intensity << " reset bold"
              << aesc::render::cancel_blink << " reset blink"
              << aesc::render::cancel_inverse << " cancel reverse" << std::endl;
    std::cout << " pre-reset" << aesc::render::reset << " post-reset"
              << std::endl;

    std::cout << aesc::color::red << aesc::color::background::cyan
              << " bg_cyan, fg_red" << aesc::render::reset << std::endl;
    std::cout << aesc::color::bright::red
              << aesc::color::bright::background::cyan
              << " bright bg_cyan, bright fg_red" << aesc::render::reset
              << std::endl;

    std::cout << "24 level grey FOREground:" << std::endl << "start";
    for (int i = 0; i != 24; ++i) {
        std::cout << aesc::color256::grey::fg(i) << "█";
    }
    std::cout << aesc::render::reset << "done" << std::endl;
    std::cout << "24 level grey BACKground:" << std::endl << "start";
    for (int i = 0; i != 24; ++i) {
        std::cout << aesc::color256::grey::background(i) << " ";
    }
    std::cout << aesc::render::reset << "done" << std::endl;

    std::cout << aesc::color256::RGB::foreground(2, 3, 0)
              << "256 color RGB test sequence" << aesc::render::reset
              << std::endl;
    std::cout << aesc::RGB::fg(2, 3, 0) << "256 color RGB alias"
              << aesc::render::reset << std::endl;

    std::cout << aesc::truecolor::RGB::foreground(130, 250, 0)
              << "24-bit true color RGB test sequence" << aesc::render::reset
              << std::endl;

    std::cout << "aaaa\nbbbb\n"
              << aesc::cursor::up(2) << "cccc" << std::endl
              << aesc::cursor::down(3) << "down" << std::endl;

    return 0;
}
