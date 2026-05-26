@echo off

pushd %~dp0\..\
Premake\premake5.exe vs2022
popd

pause