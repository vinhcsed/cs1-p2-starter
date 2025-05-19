@echo off
setlocal

set "build_dir=build"
set "executable_name=myprogram.exe"
set "compiler=cl.exe"
set "srcfiles=*.cpp"

echo Cleaning...
if exist "%build_dir%" (
    rmdir /s /q "%build_dir%"
    echo "Build directory cleaned."
) else (
    echo "Build directory not found, nothing to clean."
)

echo Creating build directory...
mkdir "%build_dir%"
if errorlevel 1 (
    echo "Failed to create build directory."
    exit /b 1
)
echo %source_dir%\*.cpp
echo Compiling...
pushd "%build_dir%"
"%compiler%" /EHsc /Fe"%executable_name%" "..\%srcfiles%"
if errorlevel 1 (
    echo "Compilation failed."
    popd
    exit /b 1
)
popd

%build_dir%\%executable_name%

endlocal