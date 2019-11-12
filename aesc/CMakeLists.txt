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

add_library(aesc SHARED)

target_sources(aesc
    INTERFACE
        aesc.hpp
)

add_subdirectory(internal)
add_subdirectory(control)
add_subdirectory(render)

target_include_directories(aesc
    PUBLIC
        ${PROJECT_SOURCE_DIR}
)

target_compile_features(aesc
    PUBLIC
        cxx_std_11
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

install(TARGETS aesc DESTINATION lib)
install(
    FILES aesc.hpp
    DESTINATION include
)
install(
    FILES control/cursor.hpp
    DESTINATION include/aesc/control
)
install(
    FILES internal/manipulator.hpp
    DESTINATION include/aesc/internal
)
install(
    FILES render/render.hpp
          render/color.hpp
          render/color256.hpp
          render/truecolor.hpp
    DESTINATION include/aesc/render
)

#TODO: include(GenerateExportHeader)
#TODO: generate_export_header(aesc)
