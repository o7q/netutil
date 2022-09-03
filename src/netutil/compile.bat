@echo off
color e
g++ *.cpp "resources\icon\icon.res" -Wall -O2 -o "netutil.exe" -static-libstdc++ -static-libgcc
echo.
pause