@echo off
color e
del "netutil.exe" /f 2> nul
rmdir "netutil" /s /q 2> nul
rmdir ".vscode" /s /q 2> nul
echo.
pause