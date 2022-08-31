@echo off
color e
g++ *.cpp -o "netutil.exe" -static-libstdc++ -static-libgcc
echo.
pause