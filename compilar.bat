@echo off
REM Script de compilación para Lily58 Custom Right
REM Ejecuta este archivo desde QMK MSYS o PowerShell con QMK instalado

echo ========================================
echo Compilando Lily58 Custom Right Keymap
echo ========================================
echo.

REM Cambiar al directorio raíz de QMK
cd C:\Users\Catalina\qmk_firmware

echo Compilando firmware...
echo.

REM Intentar compilar con qmk
qmk compile -kb lily58/rev1 -km custom_right

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo ERROR: La compilación falló.
    echo Asegúrate de tener QMK MSYS instalado y las herramientas configuradas.
    echo.
    echo Descarga QMK MSYS desde: https://msys.qmk.fm/
    echo.
    pause
    exit /b 1
)

echo.
echo ========================================
echo Compilación exitosa!
echo ========================================
echo.
echo El archivo .hex se encuentra en:
echo C:\Users\Catalina\qmk_firmware\.build\lily58_rev1_custom_right.hex
echo.
echo Ahora puedes flashear este archivo usando QMK Toolbox.
echo.
pause
