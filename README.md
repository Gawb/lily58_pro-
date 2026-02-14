# Lily58 Custom Right - Keymap Personalizado

Para que todo quede igual que en el esquema, debes dejar el teclado Español(España) Latinoamerica, como en la siguiente imagen:
<img width="362" height="110" alt="image" src="https://github.com/user-attachments/assets/13881ed7-6d93-420c-9b2e-be30c023ad98" />


Este keymap está configurado para permitir conectar el USB-C en cualquier lado del teclado Lily58 (izquierdo o derecho) usando la función EE_HANDS.

## Características

- **4 capas**: BASE, LOWER, HIGHER, ADJUST
- **EE_HANDS activado**: Permite usar el USB en cualquier lado
- **OLED habilitado**: Muestra información del teclado
- **RGB Underglow**: Control de LEDs RGB

## Compilación

Para compilar el firmware:

```bash
qmk compile -kb lily58/rev1 -km custom_right
```

O usando make:

```bash
make lily58/rev1:custom_right
```

## Flasheo

### Paso 1: Flashear el firmware

Conecta cada mitad del teclado por separado y flashea:

```bash
qmk flash -kb lily58/rev1 -km custom_right
```

O con make:

```bash
make lily58/rev1:custom_right:flash
```

### Paso 2: Configurar EE_HANDS

Después de flashear el firmware en ambas mitades, necesitas configurar la EEPROM para que cada mitad sepa si es izquierda o derecha.

**Para el lado IZQUIERDO:**
1. Conecta solo el lado izquierdo via USB
2. Activa la capa ADJUST (presiona LOWER + HIGHER juntos)
3. Ejecuta este comando mientras el teclado está conectado:

```bash
qmk console
```

**Para el lado DERECHO:**
1. Conecta solo el lado derecho via USB
2. Activa la capa ADJUST (presiona LOWER + HIGHER juntos)
3. Ejecuta el mismo comando

Alternativamente, puedes usar estos comandos para configurar cada lado:

```bash
# Para el lado IZQUIERDO:
make lily58/rev1:custom_right:dfu-split-left

# Para el lado DERECHO:
make lily58/rev1:custom_right:dfu-split-right
```

## Uso

Una vez configurado, puedes conectar el USB-C en cualquier lado y funcionará como master. El otro lado se conectará automáticamente via el cable TRRS.

## Capas

### BASE
Capa principal con layout personalizado

### LOWER
Capa con números, símbolos y controles multimedia

### HIGHER
Capa con teclas de función y navegación

### ADJUST
Capa con controles RGB y reset (se activa presionando LOWER + HIGHER)
