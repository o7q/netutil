@echo off
color e
windres "icon.rc" -O coff -o "icon.res"
echo.
pause