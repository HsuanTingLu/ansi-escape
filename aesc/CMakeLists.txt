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
        ${PROJECT_SOURCE_DIR}/aesc/aesc.hpp
)

include(GNUInstallDirs)
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

if(ipo_support)
    set_target_properties(aesc PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION ON  # thin LTO
    )
endif()

# Conditionally runs clang-tidy
if((NOT CMAKE_BUILD_TYPE) AND (NOT SKIP_CLANG_TIDY))
    # Only when build type is not defined
    find_program(
        clang_tidy_path
        clang-tidy
        HINTS "/usr/local/opt/llvm/bin/"
        PATHS "/usr/local/bin" "/usr/bin"
    )
    if(NOT clang_tidy_path STREQUAL "clang_tidy_path-NOTFOUND")
        message(VERBOSE "\"clang-tidy\"\t program path: ${clang_tidy_path}")
        set_target_properties(aesc PROPERTIES
            CXX_CLANG_TIDY ${clang_tidy_path}
        )
    else()
        message(WARNING "clang-tidy not found")
    endif()
elseif(SKIP_CLANG_TIDY)
    message(STATUS "skipping clang-tidy checks")
endif()

# Setup sanitizer stack trace symbolizer paths
if(ENABLE_UBSAN_SYMBOLIZED_OUTPUTS)
    find_program(
        llvm_symbolizer_path
        llvm-symbolizer
        HINTS "/usr/local/opt/llvm/bin/"
        PATHS "/usr/local/bin" "/usr/bin"
    )
    if(NOT llvm_symbolizer_path STREQUAL "llvm_symbolizer_path-NOTFOUND")
        message(VERBOSE "\"llvm-symbolizer\"\t program path: ${llvm_symbolizer_path}")
        set(ENV{UBSAN_SYMBOLIZER_PATH} "${llvm_symbolizer_path}")
        set(ENV{UBSAN_OPTIONS} "print_stacktrace=1") 
    else()
        message(WARNING "llvm-symbolizer not found")
    endif()
endif()

target_compile_options(aesc
    PRIVATE
        $<$<OR:$<NOT:$<BOOL:${CMAKE_BUILD_TYPE}>>,$<CONFIG:Debug>>:-Og;-g;-fno-omit-frame-pointer>
        $<$<CONFIG:MinSizeRel>:-Os>
        $<$<CONFIG:RelWithDebInfo>:-O3;-g>
        $<$<CONFIG:RELEASE>:-O3>

        # UndefinedBehaviorSanitizer, -O?
        $<$<BOOL:${ENABLE_UBSAN}>:-fsanitize=undefined;-g;-fno-omit-frame-pointer>
        $<$<AND:$<BOOL:${ENABLE_UBSAN}>,$<CONFIG:RelWithDebInfo>>:-fsanitize=-fsanitize-minimal-runtime>

        -march=native  # FIXME: be cautious
        -Wall
        -Wextra
        -pedantic
        -Wpedantic
        -Wc++11-compat
        -Wc++11-compat-pedantic
        -Wc++11-extensions
)

target_link_options(aesc
    PRIVATE
        # UndefinedBehaviorSanitizer
        $<$<BOOL:${ENABLE_UBSAN}>:-fsanitize=undefined>
        $<$<AND:$<BOOL:${ENABLE_UBSAN}>,$<CONFIG:RelWithDebInfo>>:-fsanitize=-fsanitize-minimal-runtime>
)

install(TARGETS aesc
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
install(
    FILES aesc.hpp
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(
    FILES control/cursor.hpp
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/aesc/control
)
install(
    FILES internal/manipulator.hpp
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/aesc/internal
)
install(
    FILES render/render.hpp
          render/color.hpp
          render/color256.hpp
          render/truecolor.hpp
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/aesc/render
)
