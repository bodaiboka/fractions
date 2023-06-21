cmake_minimum_required(VERSION 3.10)

project(FractionalLibrary)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCES fractional_util.cpp fraction.cpp)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Check if the build is for Android
if(ANDROID)
    add_library(fractional SHARED ${SOURCES})
    # Include JNI wrapper source file
    target_sources(fractional PRIVATE MainActivity_JNI.cpp)
    # Add a post-build command to copy the library to another directory
    add_custom_command(TARGET fractional POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:fractional>
            $<$<STREQUAL:${ANDROID_ABI},arm64-v8a>:${CMAKE_CURRENT_SOURCE_DIR}/../app/android/app/src/main/jniLibs/arm64-v8a/libfractional.so>
            $<$<STREQUAL:${ANDROID_ABI},armeabi-v7a>:${CMAKE_CURRENT_SOURCE_DIR}/../app/android/app/src/main/jniLibs/armeabi-v7a/libfractional.so>
    COMMENT "Copying the library to architecture-specific destination folder"
    )
else()
    add_library(fractional STATIC ${SOURCES})
    if(NOT "$ENV{GOOGLE_TEST}" STREQUAL "")
        enable_testing()    
        add_subdirectory(tests)
    endif()
endif()

