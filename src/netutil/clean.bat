@echo off
color e

:: dev
del "netutil.exe" /f 2> nul
rmdir "netutil" /s /q 2> nul
rmdir ".vscode" /s /q 2> nul

:: build
del "..\..\..\PackagedBuild\netutil\netutil.exe" /f 2> nul
rmdir "..\..\..\PackagedBuild\netutil\netutil" /s /q 2> nul

echo.
PAUSE