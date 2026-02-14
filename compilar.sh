#!/bin/bash

# Script de compilación para Lily58 Custom Right
# Ejecuta este archivo desde QMK MSYS

echo "========================================"
echo "Compilando Lily58 Custom Right Keymap"
echo "========================================"
echo ""

# Cambiar al directorio raíz de QMK
cd /c/Users/Catalina/qmk_firmware || cd /mnt/c/Users/Catalina/qmk_firmware

echo "Compilando firmware..."
echo ""

# Compilar usando qmk
qmk compile -kb lily58/rev1 -km custom_right

if [ $? -eq 0 ]; then
    echo ""
    echo "========================================"
    echo "¡Compilación exitosa!"
    echo "========================================"
    echo ""
    echo "El archivo .hex se encuentra en:"
    echo ".build/lily58_rev1_custom_right.hex"
    echo ""
    echo "Ahora puedes flashear este archivo usando QMK Toolbox."
    echo ""
else
    echo ""
    echo "ERROR: La compilación falló."
    echo "Verifica que todas las dependencias estén instaladas."
    echo ""
    echo "Si no tienes QMK instalado, ejecuta:"
    echo "  qmk setup"
    echo ""
    exit 1
fi
