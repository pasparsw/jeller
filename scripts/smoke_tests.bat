@echo off

set BUILD_TYPE=%1

if [%1] == [] set BUILD_TYPE=Debug

set SCRIPTS_DIR=%~dp0
set REPO_DIR=%SCRIPTS_DIR%..
set EXAMPLE_APP_BIN_DIR=%REPO_DIR%\build\%BUILD_TYPE%

SETLOCAL EnableDelayedExpansion

echo ----- Running simplest_use_case example -----
%EXAMPLE_APP_BIN_DIR%\simplest_use_case.exe || exit /b !ERRORLEVEL!
echo ----- Running simplest_use_case example done -----

echo ----- Running custom_default_logging_callback example -----
%EXAMPLE_APP_BIN_DIR%\custom_default_logging_callback.exe || exit /b !ERRORLEVEL!
echo ----- Running custom_default_logging_callback example done -----

echo ----- Running multiple_logging_callbacks example -----
%EXAMPLE_APP_BIN_DIR%\multiple_logging_callbacks.exe || exit /b !ERRORLEVEL!
echo ----- Running multiple_logging_callbacks example done -----