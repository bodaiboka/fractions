cmake -S . -B build/windows-release -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build build/windows-release
