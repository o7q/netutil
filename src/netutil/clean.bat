@echo off
color E
rmdir ..\..\..\PackagedBuild\netutil\netutil /s /q
rmdir .vscode /s /q
del ..\..\..\PackagedBuild\netutil\netutil.exe /f
pause