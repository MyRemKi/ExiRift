@echo off
setlocal enabledelayedexpansion
cd /d "%~dp0"

rem --- MinGW64 de MSYS2 (g++ + SFML)
set "MINGW=C:\msys64\mingw64"
set "PATH=%MINGW%\bin;%PATH%"

set SOURCES=
for /r %%f in (*.cpp) do set SOURCES=!SOURCES! "%%f"

echo Compilation des fichiers :
for /r %%f in (*.cpp) do echo %%f

g++ -std=c++17 -I. -Wall -o game.exe !SOURCES! -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

if errorlevel 1 (
    echo Echec de la compilation.
    exit /b 1
)

rem --- DLL SFML a cote de l'exe (pour le lancer hors MSYS2)
xcopy /y /d /q "%MINGW%\bin\sfml-*.dll" . >nul 2>nul

echo Build termine : game.exe