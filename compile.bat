@echo off
setlocal EnableDelayedExpansion
cd /d "%~dp0"

rem ============================================================
rem  CONFIGURATION (a adapter)
rem ============================================================
set "SFML=C:\msys64\mingw64\include\SFML"
set "OUT=game.exe"
set "BUILD=build"
set "STD=c++17"
rem  Mettre -mwindows pour masquer la console, sinon laisser vide
set "EXTRA="
rem ============================================================

where g++ >nul 2>nul
if errorlevel 1 (
    echo [ERREUR] g++ introuvable. Ajoutez MinGW\bin au PATH.
    pause
    exit /b 1
)

if not exist "%SFML%\include\SFML" (
    echo [ERREUR] SFML introuvable dans "%SFML%". Modifiez la variable SFML.
    pause
    exit /b 1
)

if not exist "%BUILD%" mkdir "%BUILD%"
set "RSP=%BUILD%\args.rsp"
type nul > "%RSP%"

rem --- Dossier racine comme dossier d'includes
>> "%RSP%" echo -I.

rem --- Tous les dossiers contenant des .h / .hpp (sauf build et SFML)
set "last="
for /f "delims=" %%f in ('dir /s /b /a-d *.h *.hpp 2^>nul ^| findstr /v /i /l /c:"\%BUILD%\" /c:"\SFML\"') do (
    set "d=%%~dpf"
    if not "!d!"=="!last!" (
        set "last=!d!"
        set "p=!d:\=/!"
        >> "%RSP%" echo "-I!p!"
    )
)

rem --- Tous les .cpp du projet, peu importe le sous-dossier
set COUNT=0
for /f "delims=" %%f in ('dir /s /b /a-d *.cpp 2^>nul ^| findstr /v /i /l /c:"\%BUILD%\" /c:"\SFML\"') do (
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

g++ @%RSP% -std=%STD% -Wall -I"%SFML%/include" -L"%SFML%/lib" -o "%OUT%" ^
    -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network %EXTRA%

if errorlevel 1 (
    echo.
    echo [ECHEC] La compilation a echoue.
    pause
    exit /b 1
)

rem --- Copie des DLL SFML a cote de l'executable si besoin
xcopy /y /d /q "%SFML%\bin\*.dll" . >nul 2>nul

echo.
echo [OK] Compilation reussie : %OUT%
choice /m "Lancer le programme"
if errorlevel 2 exit /b 0
"%OUT%"
pause
