cmake_minimum_required(VERSION 2.6)

project(Gest-Art_App)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

if(NOT GTKMM_FOUND)
    message(FATAL_ERROR "gtkmm-3.0 not found!")
endif()

link_directories(
    ${GTKMM_LIBRARY_DIRS}
    ${OPENGL_LIBRARY_DIRS}
    ${GLUT_LIBRARY_DIRS}
    ${GLEW_LIBRARY_DIRS}
)

include_directories(
    ${GTKMM_INCLUDE_DIRS}
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
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARY}
    ${GLEW_LIBRARY}
)
