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

add_library(aesc SHARED aesc.hpp)

add_subdirectory(base)
add_subdirectory(controls)
add_subdirectory(graphics)

target_compile_features(aesc
    PUBLIC
        cxx_std_11
        cxx_auto_type
        cxx_constexpr
        cxx_delegating_constructors
        cxx_inline_namespaces
        cxx_lambdas
)
set_target_properties(aesc PROPERTIES
    CXX_EXTENSIONS OFF
)

target_compile_options(aesc
    PRIVATE
        -Wall
        -Wextra
        -pedantic
        -Werror
)
