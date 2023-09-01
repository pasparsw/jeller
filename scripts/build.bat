@echo off

set BUILD_TYPE=%1

if [%1] == [] set BUILD_TYPE=Debug

set SCRIPTS_DIR=%~dp0
set REPO_DIR=%SCRIPTS_DIR%..
set JELLER_BUILD_DIR=%REPO_DIR%\build

SETLOCAL EnableDelayedExpansion

echo ----- Build type: %BUILD_TYPE% -----

echo ----- Configuring CMake for Jeller for sources in %REPO_DIR% and build in %JELLER_BUILD_DIR% -----
cmake -S %REPO_DIR% -B %JELLER_BUILD_DIR% -DCMAKE_BUILD_TYPE=%BUILD_TYPE% -DBUILD_EXAMPLES=1 || exit /b !ERRORLEVEL!
echo ----- Jeller CMake configuration done -----

echo ----- Building Jeller in %JELLER_BUILD_DIR% -----
cmake --build %JELLER_BUILD_DIR% --config %BUILD_TYPE% || exit /b !ERRORLEVEL!
echo ----- Jeller build done -----

echo ----- Installing Jeller in %JELLER_BUILD_DIR% -----
cmake --install %JELLER_BUILD_DIR% --config %BUILD_TYPE% || exit /b !ERRORLEVEL!
echo ----- Jeller installation done -----