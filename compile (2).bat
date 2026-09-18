@echo off
setlocal EnableDelayedExpansion
cd /d "%~dp0"

rem ============================================================
rem  CONFIGURATION (a adapter)
rem ============================================================
rem  Dossier MinGW64 de MSYS2 (SFML installee via pacman)
set "MINGW=C:\msys64\mingw64"
set "OUT=game.exe"
set "BUILD=build"
set "STD=c++17"
rem  Mettre -mwindows pour masquer la console, sinon laisser vide
set "EXTRA="
rem ============================================================

set "PATH=%MINGW%\bin;%PATH%"

where g++ >nul 2>nul
if errorlevel 1 (
    echo [ERREUR] g++ introuvable dans "%MINGW%\bin".
    echo Installez-le avec : pacman -S mingw-w64-x86_64-gcc
    pause
    exit /b 1
)

if not exist "%MINGW%\include\SFML" (
    echo [ERREUR] SFML introuvable dans "%MINGW%\include\SFML".
    echo Installez-la avec : pacman -S mingw-w64-x86_64-sfml
    pause
    exit /b 1
)

if not exist "%BUILD%" mkdir "%BUILD%"
set "RSP=%BUILD%\args.rsp"
type nul > "%RSP%"

rem --- Dossier racine comme dossier d'includes
>> "%RSP%" echo -I.

rem --- Tous les dossiers contenant des .h / .hpp (sauf build)
set "last="
for /f "delims=" %%f in ('dir /s /b /a-d *.h *.hpp 2^>nul ^| findstr /v /i /l /c:"\%BUILD%\"') do (
    set "d=%%~dpf"
    if not "!d!"=="!last!" (
        set "last=!d!"
        set "p=!d:\=/!"
        >> "%RSP%" echo "-I!p!"
    )
)

rem --- Tous les .cpp du projet, peu importe le sous-dossier
set COUNT=0
for /f "delims=" %%f in ('dir /s /b /a-d *.cpp 2^>nul ^| findstr /v /i /l /c:"\%BUILD%\"') do (
    set "p=%%f"
    set "p=!p:\=/!"
    >> "%RSP%" echo "!p!"
    set /a COUNT+=1
)

if %COUNT%==0 (
    echo [ERREUR] Aucun fichier .cpp trouve.
    pause
    exit /b 1
)

echo %COUNT% fichier(s) .cpp trouve(s). Compilation...

rem  SFML est dans le chemin par defaut de MinGW : pas besoin de -I / -L pour elle
g++ @%RSP% -std=%STD% -Wall -o "%OUT%" ^
    -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network ^
    -static-libgcc -static-libstdc++ %EXTRA%

if errorlevel 1 (
    echo.
    echo [ECHEC] La compilation a echoue.
    pause
    exit /b 1
)

rem --- Copie des DLL SFML a cote de l'executable (pour le lancer hors MSYS2)
xcopy /y /d /q "%MINGW%\bin\sfml-*.dll" . >nul 2>nul

echo.
echo [OK] Compilation reussie : %OUT%
choice /m "Lancer le programme"
if errorlevel 2 exit /b 0
"%OUT%"
pause
