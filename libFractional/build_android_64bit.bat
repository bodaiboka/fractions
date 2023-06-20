cmake --build build/android-64bit --target clean

cmake -S . -B build/android-64bit ^
    -G Ninja ^
    -DCMAKE_TOOLCHAIN_FILE=%ANDROID_NDK%\build\cmake\android.toolchain.cmake ^
    -DANDROID_ABI=arm64-v8a ^
    -DANDROID_NATIVE_API_LEVEL=21 ^
    -DCMAKE_BUILD_TYPE=Release

cmake --build build/android-64bit