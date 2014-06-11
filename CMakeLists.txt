cmake_minimum_required(VERSION 2.6)

project(Gest-Art_App)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

macro(FIND_GSTREAMER_COMPONENT _component_prefix _pkgconfig_name _header _library)
    pkg_check_modules(PC_${_component_prefix} QUIET ${_pkgconfig_name})

    find_path(${_component_prefix}_INCLUDE_DIRS
        NAMES ${_header}
        HINTS ${PC_${_component_prefix}_INCLUDE_DIRS} ${PC_${_component_prefix}_INCLUDEDIR}
        PATH_SUFFIXES gstreamer-1.0
    )

    find_library(${_component_prefix}_LIBRARIES
        NAMES ${_library}
        HINTS ${PC_${_component_prefix}_LIBRARY_DIRS} ${PC_${_component_prefix}_LIBDIR}
    )
endmacro()

FIND_GSTREAMER_COMPONENT(GSTREAMER gstreamer-1.0 gst/gst.h gstreamer-1.0)
FIND_GSTREAMER_COMPONENT(GSTREAMER_BASE gstreamer-base-1.0 gst/base/gstadapter.h gstbase-1.0)

if(NOT GTKMM_FOUND)
    message(FATAL_ERROR "gtkmm-3.0 not found!")
endif()

link_directories(
    ${GTKMM_LIBRARY_DIRS}
    ${GSTREAMER_LIBRARY_DIRS}
    ${OPENGL_LIBRARY_DIRS}
    ${GLUT_LIBRARY_DIRS}
    ${GLEW_LIBRARY_DIRS}
)

include_directories(
    ${GTKMM_INCLUDE_DIRS}
    ${GSTREAMER_INCLUDE_DIRS}
    ${OPENGL_INCLUDE_DIRS}
    ${GLUT_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
)

file(
    GLOB_RECURSE
    source_files
    src/*
)

add_executable(
    Gest-Art_App
    ${source_files}
)

target_link_libraries(
    Gest-Art_App
    ${GTKMM_LIBRARIES}
    ${GSTREAMER_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARY}
    ${GLEW_LIBRARY}
    -lassimp
)
