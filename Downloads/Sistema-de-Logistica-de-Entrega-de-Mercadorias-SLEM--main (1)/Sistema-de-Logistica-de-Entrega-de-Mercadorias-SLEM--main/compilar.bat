@echo off
echo Compilando Sistema de Logistica de Entrega de Mercadorias...

REM Tentar diferentes compiladores
if exist "C:\MinGW\bin\g++.exe" (
    echo Usando MinGW...
    "C:\MinGW\bin\g++.exe" -o executavel main.cpp local.cpp veiculo.cpp pedido.cpp
    goto :success
)

if exist "C:\mingw64\bin\g++.exe" (
    echo Usando MinGW64...
    "C:\mingw64\bin\g++.exe" -o executavel main.cpp local.cpp veiculo.cpp pedido.cpp
    goto :success
)

REM Tentar g++ no PATH
g++ --version >nul 2>&1
if %errorlevel% == 0 (
    echo Usando g++ do PATH...
    g++ -o executavel main.cpp local.cpp veiculo.cpp pedido.cpp
    goto :success
)

REM Tentar gcc
gcc --version >nul 2>&1
if %errorlevel% == 0 (
    echo Usando gcc do PATH...
    gcc -lstdc++ -o executavel main.cpp local.cpp veiculo.cpp pedido.cpp
    goto :success
)

echo ERRO: Nenhum compilador C++ encontrado!
echo.
echo Por favor, instale um dos seguintes:
echo 1. MinGW-w64: https://www.mingw-w64.org/
echo 2. TDM-GCC: https://jmeubank.github.io/tdm-gcc/
echo 3. Visual Studio Build Tools
echo 4. Code::Blocks com MinGW
echo.
pause
exit /b 1

:success
echo.
echo Compilacao concluida com sucesso!
echo Execute: executavel.exe
pause
