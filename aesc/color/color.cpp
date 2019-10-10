/*
 * Copyright (C) 2019  Hsuan-Ting Lu <hsuan.ting.lu.ee05@g2.nctu.edu.tw>
 *
 * Wrap 4-bit color codes within general output streams
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

#include "color.hpp"

namespace aesc {  // Ansi Escape Terminal

namespace color {
inline namespace {  // 4-bit
// foreground colors, 30-39
constexpr const char* fg_black_expr = "30";
constexpr const char* fg_red_expr = "31";
constexpr const char* fg_green_expr = "32";
constexpr const char* fg_yellow_expr = "33";
constexpr const char* fg_blue_expr = "34";
constexpr const char* fg_magenta_expr = "35";
constexpr const char* fg_cyan_expr = "36";
constexpr const char* fg_white_expr = "37";
// background color, 40-49
constexpr const char* bg_black_expr = "40";
constexpr const char* bg_red_expr = "41";
constexpr const char* bg_green_expr = "42";
constexpr const char* bg_yellow_expr = "43";
constexpr const char* bg_blue_expr = "44";
constexpr const char* bg_magenta_expr = "45";
constexpr const char* bg_cyan_expr = "46";
constexpr const char* bg_white_expr = "47";
// bright foreground colors, 90-97
constexpr const char* b_fg_black_expr = "90";
constexpr const char* b_fg_red_expr = "91";
constexpr const char* b_fg_green_expr = "92";
constexpr const char* b_fg_yellow_expr = "93";
constexpr const char* b_fg_blue_expr = "94";
constexpr const char* b_fg_magenta_expr = "95";
constexpr const char* b_fg_cyan_expr = "96";
constexpr const char* b_fg_white_expr = "97";
// bright background colors, 100-107
constexpr const char* b_bg_black_expr = "100";
constexpr const char* b_bg_red_expr = "101";
constexpr const char* b_bg_green_expr = "102";
constexpr const char* b_bg_yellow_expr = "103";
constexpr const char* b_bg_blue_expr = "104";
constexpr const char* b_bg_magenta_expr = "105";
constexpr const char* b_bg_cyan_expr = "106";
constexpr const char* b_bg_white_expr = "107";
}  // anonymous namespace

std::ostream& black(std::ostream& stream) {
    stream << CSI_expr << fg_black_expr << color_end_expr;
    return stream;
}
std::ostream& red(std::ostream& stream) {
    stream << CSI_expr << fg_red_expr << color_end_expr;
    return stream;
}
std::ostream& green(std::ostream& stream) {
    stream << CSI_expr << fg_green_expr << color_end_expr;
    return stream;
}
std::ostream& yellow(std::ostream& stream) {
    stream << CSI_expr << fg_yellow_expr << color_end_expr;
    return stream;
}
std::ostream& blue(std::ostream& stream) {
    stream << CSI_expr << fg_blue_expr << color_end_expr;
    return stream;
}
std::ostream& magenta(std::ostream& stream) {
    stream << CSI_expr << fg_magenta_expr << color_end_expr;
    return stream;
}
std::ostream& cyan(std::ostream& stream) {
    stream << CSI_expr << fg_cyan_expr << color_end_expr;
    return stream;
}
std::ostream& white(std::ostream& stream) {
    stream << CSI_expr << fg_white_expr << color_end_expr;
    return stream;
}

namespace background {
std::ostream& black(std::ostream& stream) {
    stream << CSI_expr << bg_black_expr << color_end_expr;
    return stream;
}
std::ostream& red(std::ostream& stream) {
    stream << CSI_expr << bg_red_expr << color_end_expr;
    return stream;
}
std::ostream& green(std::ostream& stream) {
    stream << CSI_expr << bg_green_expr << color_end_expr;
    return stream;
}
std::ostream& yellow(std::ostream& stream) {
    stream << CSI_expr << bg_yellow_expr << color_end_expr;
    return stream;
}
std::ostream& blue(std::ostream& stream) {
    stream << CSI_expr << bg_blue_expr << color_end_expr;
    return stream;
}
std::ostream& magenta(std::ostream& stream) {
    stream << CSI_expr << bg_magenta_expr << color_end_expr;
    return stream;
}
std::ostream& cyan(std::ostream& stream) {
    stream << CSI_expr << bg_cyan_expr << color_end_expr;
    return stream;
}
std::ostream& white(std::ostream& stream) {
    stream << CSI_expr << bg_white_expr << color_end_expr;
    return stream;
}
}  // namespace background
namespace bright {
std::ostream& black(std::ostream& stream) {
    stream << CSI_expr << b_fg_black_expr << color_end_expr;
    return stream;
}
std::ostream& red(std::ostream& stream) {
    stream << CSI_expr << b_fg_red_expr << color_end_expr;
    return stream;
}
std::ostream& green(std::ostream& stream) {
    stream << CSI_expr << b_fg_green_expr << color_end_expr;
    return stream;
}
std::ostream& yellow(std::ostream& stream) {
    stream << CSI_expr << b_fg_yellow_expr << color_end_expr;
    return stream;
}
std::ostream& blue(std::ostream& stream) {
    stream << CSI_expr << b_fg_blue_expr << color_end_expr;
    return stream;
}
std::ostream& magenta(std::ostream& stream) {
    stream << CSI_expr << b_fg_magenta_expr << color_end_expr;
    return stream;
}
std::ostream& cyan(std::ostream& stream) {
    stream << CSI_expr << b_fg_cyan_expr << color_end_expr;
    return stream;
}
std::ostream& white(std::ostream& stream) {
    stream << CSI_expr << b_fg_white_expr << color_end_expr;
    return stream;
}

namespace background {
std::ostream& black(std::ostream& stream) {
    stream << CSI_expr << b_bg_black_expr << color_end_expr;
    return stream;
}
std::ostream& red(std::ostream& stream) {
    stream << CSI_expr << b_bg_red_expr << color_end_expr;
    return stream;
}
std::ostream& green(std::ostream& stream) {
    stream << CSI_expr << b_bg_green_expr << color_end_expr;
    return stream;
}
std::ostream& yellow(std::ostream& stream) {
    stream << CSI_expr << b_bg_yellow_expr << color_end_expr;
    return stream;
}
std::ostream& blue(std::ostream& stream) {
    stream << CSI_expr << b_bg_blue_expr << color_end_expr;
    return stream;
}
std::ostream& magenta(std::ostream& stream) {
    stream << CSI_expr << b_bg_magenta_expr << color_end_expr;
    return stream;
}
std::ostream& cyan(std::ostream& stream) {
    stream << CSI_expr << b_bg_cyan_expr << color_end_expr;
    return stream;
}
std::ostream& white(std::ostream& stream) {
    stream << CSI_expr << b_bg_white_expr << color_end_expr;
    return stream;
}
}  // namespace background

}  // namespace bright

}  // namespace color

}  // namespace aesc
