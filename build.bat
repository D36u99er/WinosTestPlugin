@echo off
echo Building WinosTestPlugin.dll...

REM Create build directory
if not exist build mkdir build
cd build

REM Configure with CMake
cmake .. -G "Visual Studio 16 2019" -A x64

REM Build the project
cmake --build . --config Release

echo Build complete! Check build/Release/ for WinosTestPlugin.dll

pause