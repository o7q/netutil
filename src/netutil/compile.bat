@echo off
color e
g++ *.cpp -Wall -O2 -o "netutil.exe" -static-libstdc++ -static-libgcc
echo.
pause