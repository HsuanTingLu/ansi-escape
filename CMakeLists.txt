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
cmake_minimum_required(VERSION 3.15)

# Compiler id for Apple Clang is now AppleClang.
#cmake_policy(SET CMP0025 NEW)
#cmake_policy(SET CMP0069 NEW)
#cmake_policy(SET CMP0079 NEW)

project(aesc LANGUAGES CXX)

# when aesc is included as subproject (i.e. using add_subdirectory(aesc))
# in the source tree of a project that uses it, install rules are disabled.
if(NOT "^${CMAKE_SOURCE_DIR}$" STREQUAL "^${PROJECT_SOURCE_DIR}$")
    set(AESC_ENABLE_INSTALL FALSE)
else()
    set(AESC_ENABLE_INSTALL TRUE)
endif()

#include(CMakeDependentOption)
#include(CMakePrintHelpers)


##
## using aesc targets
## all public aesc targets are exported
## with the aesc:: prefix
##
## DO NOT rely on the internal targets outside of the prefi

# include current path
#list(APPEND AESC_COMMON_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})

# find dependencies
# find_package(xxx REQUIRED)

add_subdirectory(aesc)
add_subdirectory(examples EXCLUDE_FROM_ALL)

if(AESC_ENABLE_INSTALL)

endif()  # AESC_ENABLE_INSTALL

