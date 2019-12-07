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

target_sources(aesc
    PRIVATE
        ${PROJECT_SOURCE_DIR}/aesc/render/render.hpp
        ${PROJECT_SOURCE_DIR}/aesc/render/color.hpp
        ${PROJECT_SOURCE_DIR}/aesc/render/color256.hpp
        ${PROJECT_SOURCE_DIR}/aesc/render/truecolor.hpp
        ${PROJECT_SOURCE_DIR}/aesc/render/internal.hpp
        ${PROJECT_SOURCE_DIR}/aesc/render/render.cpp
        ${PROJECT_SOURCE_DIR}/aesc/render/color.cpp
        ${PROJECT_SOURCE_DIR}/aesc/render/color256.cpp
        ${PROJECT_SOURCE_DIR}/aesc/render/truecolor.cpp
)
