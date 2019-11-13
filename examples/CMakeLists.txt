#
# Copyright (C) 2019  Hsuan-Ting Lu <hsuan.ting.lu.ee05@g2.nctu.edu.tw>
#
# Wrap some CSI escape codes with string streams
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope tha it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
#

add_executable(showcolor EXCLUDE_FROM_ALL show_color.cpp)

target_include_directories(showcolor
    PUBLIC
        ${PROJECT_SOURCE_DIR}/aesc
)

target_compile_features(showcolor
    PUBLIC
        cxx_std_11
)
set_target_properties(showcolor PROPERTIES
    CXX_EXTENSIONS OFF
)

target_compile_options(showcolor
    PRIVATE
        -Wall
        -Wextra
        -pedantic
        -Werror
)

# TODO: @todo: if CMAKE version at least 3.9
# Linker optimizations
#TODO: include(CheckIPOSupported)
#TODO: check_ipo_supported(RESULT ipo_support OUTPUT ipo_out LANGUAGES CXX)

#TODO: if(ipo_support)
#TODO:     set_property(TARGET showcolor PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
#TODO: else()
#TODO:     message(WARNING "IPO is not supported: ${ipo_out}")
#TODO: endif()

target_link_libraries(showcolor PRIVATE aesc)
