#
# Copyright (C) 2019  Hsuan-Ting Lu <hsuan.ting.lu.ee05@g2.nctu.edu.tw>
#
# CMake configs
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

# Most widely used distributions have cmake 3.5 or greater available as of March
# 2019.

cmake_minimum_required(VERSION 3.9)
project(aesc LANGUAGES CXX)

option(BUILD_SHARED_LIBS "Build as shared library." ON)

option(ENABLE_IPO "Enable interprocedural optimization." ON)
if(ENABLE_IPO)
    include(CheckIPOSupported)
    check_ipo_supported(RESULT ipo_support OUTPUT ipo_err_info LANGUAGES CXX)
    if(ipo_support)
        message(STATUS "compiler supports interprocedural optimization")
    else()
        message(WARNING "compiler does NOT support interprocedural optimization\nreason:\n${ipo_err_info}")
    endif()
endif()

option(SKIP_CLANG_TIDY "Skip clang-tidy checks when build type is not set." OFF)

# UndefinedBehaviorSanitizer
option(ENABLE_UBSAN "Enable UndefinedBehaviorSanitizer." OFF)
option(ENABLE_UBSAN_SYMBOLIZED_OUTPUTS "Let UndefinedBehaviorSanitizer print symbolized stack trace." OFF)
if(ENABLE_UBSAN_SYMBOLIZED_OUTPUTS)
    set(ENABLE_UBSAN ON)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(aesc)
add_subdirectory(examples EXCLUDE_FROM_ALL)
