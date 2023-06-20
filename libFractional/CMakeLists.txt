cmake_minimum_required(VERSION 3.10)

project(FractionalLibrary)

set(SOURCES fractional_util.cpp fraction.cpp)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(fractional STATIC ${SOURCES})
