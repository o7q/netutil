@echo off
color e
g++ *.cpp -o "..\..\..\PackagedBuild\netutil\netutil.exe" -static-libstdc++ -static-libgcc
echo.
pause