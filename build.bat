@echo off
setlocal enabledelayedexpansion
cd /d "%~dp0"

set SOURCES=
for /r %%f in (*.cpp) do set SOURCES=!SOURCES! "%%f"

echo Compilation des fichiers :
for /r %%f in (*.cpp) do echo %%f

g++ -std=c++17 -I. -Wall -o game.exe !SOURCES!

if errorlevel 1 (
    echo Echec de la compilation.
    exit /b 1
)

echo Build termine : game.exe
