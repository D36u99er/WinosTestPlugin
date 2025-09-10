@echo off
echo Compiling WinosTestPlugin.dll directly with cl.exe...

REM Compile with MSVC compiler directly
cl.exe /LD /Fe:WinosTestPlugin.dll WinosTestPlugin.cpp user32.lib

echo Compilation complete! WinosTestPlugin.dll should be generated.

pause