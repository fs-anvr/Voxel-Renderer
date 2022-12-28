cd build
cmake -D CMAKE_C_COMPILER="C:\Program Files\LLVM\bin" -D CMAKE_CXX_COMPILER="C:\Program Files\LLVM\bin" ..
cd ..
cmake --build build

.\build\bin\Debug\Editor.exe