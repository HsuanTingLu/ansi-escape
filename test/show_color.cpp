/*
 * Copyright (C) 2019  Hsuan-Ting Lu <hsuan.ting.lu.ee05@g2.nctu.edu.tw>
 *
 * Wrap some CSI escape codes with string streams
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
#include <iostream>
#include "../aesc/csi.hpp"

using namespace std;
using namespace aesc;
int main(int argc, char** argv) {
    //cout << truecolor::RGB.foreground(200, 0, 0) << "haha" << SGR::reset << endl;
    cout << "line1" << endl << "line2" << endl << cursor::up(1) << "33" << cursor::EL(cursor::clear::entire) << "a" << endl;
    cout << SGR::bold << SGR::blink::slow << " bold" << SGR::reverse_color << " reversed" << SGR::reset_intensity << " reset bold" << SGR::cancel_blink << " reset blink" << SGR::cancel_inverse << " cancel reverse" << endl;
    cout << " pre-reset" << SGR::reset << " post-reset" << endl;

    cout << color::red << color::background::cyan << " bg_cyan, fg_red" << SGR::reset << endl;
    cout << color::bright::red << color::bright::background::cyan << " bright bg_cyan, bright fg_red" << SGR::reset << endl;

    cout << "24 level grey FOREground:" << endl << "start";
    for (int i=0; i!=24; ++i) {
        cout << color256::grey::foreground(i) << "█";
    }
    cout << SGR::reset << "done" << endl;
    cout << "24 level grey BACKground:" << endl << "start";
    for (int i=0; i!=24; ++i) {
        cout << color256::grey::background(i) << " ";
    }
    cout << SGR::reset << "done" << endl;

    cout << color256::RGB::foreground(2,3,0) << "256 color RGB test sequence" << SGR::reset << endl;

    return 0;
}
