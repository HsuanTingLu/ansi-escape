/*
 * Copyright (C) 2019  Hsuan-Ting Lu <hsuan.ting.lu.ee05@g2.nctu.edu.tw>
 *
 * Wrap the Select Graphic Rendition codes
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope tha it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#ifndef AESC_SGR_HPP_
#define AESC_SGR_HPP_

#include <iostream>
#include "aesc.hpp"

namespace aesc {  // Ansi Escape Terminal

namespace SGR {  // Select Graphic Rendition

std::ostream& reset(std::ostream& stream);
std::ostream& bold(std::ostream& stream);   // with increased intensity
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
}  // namespace SGR

}  // namespace aesc

#endif
