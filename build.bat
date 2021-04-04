cmake -G Ninja -Bbuild -DCMAKE_CXX_COMPILER="D:/msys64/mingw64/bin/g++.exe" -DCMAKE_BUILD_TYPE=Debug
cmake --build ./build/ --target SGEyes test_circle_map2 --VERBOSE=1
REM cmake --install ./build/ --prefix .
"./build/saigonlib/test_circle_map2.exe"