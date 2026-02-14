# Configuración de Windows para el Teclado Lily58

## ⚠️ IMPORTANTE: Cambio de Layout Requerido

Debido a limitaciones técnicas de QMK con Windows Español, el firmware usa **keycodes US** y requiere que Windows esté configurado en **US-International**.

## ¿Por qué US-International?

✅ **Ventajas:**
- Todos los símbolos de programación funcionan: `@`, `#`, `[`, `]`, `{`, `}`, etc.
- Soporta acentos españoles: á, é, í, ó, ú, ñ
- Es el estándar usado por programadores hispanos
- Compatible con QMK sin problemas de AltGr

❌ **Problema con Español de España:**
- QMK no puede enviar correctamente AltGr en muchos Pro Micros
- Los símbolos `@`, `#`, `[`, `]`, `{`, `}` no funcionan

## 🔧 Cómo Cambiar Windows a US-International

### Paso 1: Abrir Configuración de Idioma

1. Presiona **Windows + I** (Configuración)
2. Ve a **Hora e idioma** → **Idioma y región**

### Paso 2: Agregar Teclado US-International

1. En la sección **Idiomas**, busca **Español** (o tu idioma)
2. Haz clic en los **tres puntos** (⋯) → **Opciones de idioma**
3. En **Teclados**, haz clic en **Agregar un teclado**
4. Busca y selecciona: **Estados Unidos-Internacional**

### Paso 3: Eliminar el Teclado Español (Opcional pero Recomendado)

1. En la misma pantalla de **Teclados**
2. Haz clic en **Español (España)** o el layout español que tengas
3. Haz clic en **Quitar**

### Paso 4: Configurar US-International como Predeterminado

1. Cierra la ventana de opciones
2. En la barra de tareas (abajo a la derecha), verás el indicador de idioma (ESP o ENG)
3. Haz clic y selecciona **US** o **ENG**

## 🎯 Verificación

Abre un editor de texto y prueba:

### Símbolos Básicos (funcionan inmediatamente):
- `@` → Shift + 2
- `#` → Shift + 3  
- `[` → Tecla [ (al lado de P)
- `]` → Tecla ]
- `;` → Tecla ; (al lado de L)

### Acentos y Ñ (Dead Keys):

**Para acentos agudos (á, é, í, ó, ú):**
1. Presiona `'` (tecla Quote, al lado de ;)
2. Suelta
3. Presiona la vocal → `á`, `é`, `í`, `ó`, `ú`

**Para diéresis (ä, ë, ï, ö, ü):**
1. Presiona `"` (Shift + ')
2. Suelta
3. Presiona la vocal → `ä`, `ë`, `ï`, `ö`, `ü`

**Para Ñ:**
1. Presiona `~` (Shift + ` - tecla grave, arriba del Tab)
2. Suelta
3. Presiona `n` → `ñ`
4. O presiona `N` → `Ñ`

**Para grave (à, è, ì, ò, ù):**
1. Presiona `` ` `` (tecla grave, arriba del Tab)
2. Suelta
3. Presiona la vocal → `à`, `è`, `ì`, `ò`, `ù`

## 📋 Mapa del Teclado con US-International

### CAPA BASE:
```
┌─────┬─────┬─────┬─────┬─────┬─────┐                ┌─────┬─────┬─────┬─────┬─────┬──────┐
│ ESC │  1! │  2@ │  3# │  4$ │  5% │                │  6^ │  7& │  8* │  9( │  0) │ Bksp │
├─────┼─────┼─────┼─────┼─────┼─────┤                ├─────┼─────┼─────┼─────┼─────┼──────┤
│ Tab │  Q  │  W  │  E  │  R  │  T  │                │  Y  │  U  │  I  │  O  │  P  │  [{  │
├─────┼─────┼─────┼─────┼─────┼─────┤                ├─────┼─────┼─────┼─────┼─────┼──────┤
│Shift│  A  │  S  │  D  │  F  │  G  ├─────┐    ┌─────┤  H  │  J  │  K  │  L  │  ;: │  '"  │
├─────┼─────┼─────┼─────┼─────┼─────┤ GUI │    │ Del ├─────┼─────┼─────┼─────┼─────┼──────┤
│Ctrl │  Z  │  X  │  C  │  V  │  B  ├─────┤    ├─────┤  N  │  M  │  ,< │  .> │  /? │Shift │
└─────┴─────┴─────┴──┬──┴──┬──┴──┬──┴──┬──┘    └──┬──┴──┬──┴──┬──┴──┬──┴─────┴─────┴──────┘
                     │ Alt │ GUI │LOWER│            │HIGHR│Bksp │ADJST│
                     └─────┴─────┴─────┘            └─────┴─────┴─────┘
                            │Space│                  │Enter│
                            └─────┘                  └─────┘
```

### CAPA LOWER (Símbolos + Numpad):
```
┌─────┬─────┬─────┬─────┬─────┬─────┐                ┌─────┬─────┬─────┬─────┬─────┬──────┐
│ ESC │ F1  │ F2  │ F3  │ F4  │ F5  │                │ F6  │ F7  │ F8  │ F9  │ F10 │ Bksp │
├─────┼─────┼─────┼─────┼─────┼─────┤                ├─────┼─────┼─────┼─────┼─────┼──────┤
│ Tab │  !  │  @  │  #  │  $  │  %  │                │  7  │  8  │  9  │  /  │  *  │ Vol+ │
├─────┼─────┼─────┼─────┼─────┼─────┤                ├─────┼─────┼─────┼─────┼─────┼──────┤
│Shift│  [  │  ]  │  {  │  }  │  &  ├─────┐    ┌─────┤  4  │  5  │  6  │  -  │  +  │ Mute │
├─────┼─────┼─────┼─────┼─────┼─────┤  \  │    │  =  ├─────┼─────┼─────┼─────┼─────┼──────┤
│Ctrl │  <  │  >  │  (  │  )  │  \  ├─────┤    ├─────┤  1  │  2  │  3  │  .  │  ,  │ Vol- │
└─────┴─────┴─────┴──┬──┴──┬──┴──┬──┴──┬──┘    └──┬──┴──┬──┴──┬──┴──┬──┴─────┴─────┴──────┘
                     │ Alt │ GUI │▓▓▓▓▓│            │  0  │  =  │ Play │
                     └─────┴─────┴─────┘            └─────┴─────┴─────┘
```

### CAPA HIGHER (Navegación + Símbolos Especiales):
```
┌─────┬─────┬─────┬─────┬─────┬─────┐                ┌─────┬─────┬─────┬─────┬─────┬──────┐
│ ESC │ F11 │ F12 │ F13 │ F14 │ F15 │                │  ^  │  ~  │  `  │  _  │  -  │ Bksp │
├─────┼─────┼─────┼─────┼─────┼─────┤                ├─────┼─────┼─────┼─────┼─────┼──────┤
│ Tab │ F1  │ F2  │ F3  │ F4  │ F5  │                │PgUp │     │  ↑  │  ?  │Home │ Ins  │
├─────┼─────┼─────┼─────┼─────┼─────┤                ├─────┼─────┼─────┼─────┼─────┼──────┤
│Shift│ F6  │ F7  │ F8  │ F9  │ F10 ├─────┐    ┌─────┤PgDn │  ←  │  ↓  │  →  │ End │PrtSc │
├─────┼─────┼─────┼─────┼─────┼─────┤  ?  │    │Caps ├─────┼─────┼─────┼─────┼─────┼──────┤
│Ctrl │Undo │ Cut │Copy │Paste│Redo ├─────┤    ├─────┤BkWrd│ Del │DlWrd│     │Menu │Pause │
└─────┴─────┴─────┴──┬──┴──┬──┴──┬──┴──┬──┘    └──┬──┴──┬──┴──┬──┴──┬──┴─────┴─────┴──────┘
                     │ Alt │ GUI │LOWER│            │▓▓▓▓▓│Bksp │ GUI │
                     └─────┴─────┴─────┘            └─────┴─────┴─────┘
```

## 🔄 ¿Cómo Volver a Español?

Si en algún momento necesitas volver al teclado español de Windows:

1. Haz clic en el indicador de idioma (barra de tareas)
2. Selecciona **ESP** o **Español (España)**

**Nota:** El teclado NO funcionará correctamente con layout español, solo con US-International.

## 💡 Tips para Adaptarte

1. **@ y #** ahora están con Shift+2 y Shift+3 (más fácil que AltGr)
2. **[ y ]** tienen su propia tecla (al lado de P)
3. **Ñ** se hace con `~` + `n` (dead key)
4. **Acentos** con `'` + vocal (dead key)
5. La tecla `;` está donde antes estaba `ñ`

## 🆘 Problemas Comunes

**Problema:** No aparecen los acentos
**Solución:** Recuerda que son "dead keys". Presiona `'`, suelta, luego presiona la vocal.

**Problema:** Aparece `'` en lugar de acento
**Solución:** Si presionas `'` + espacio, aparece el apóstrofe literal. Para el acento, presiona `'` + vocal directamente.

**Problema:** No sé dónde está la Ñ
**Solución:** Presiona `~` (Shift + tecla grave arriba del Tab), suelta, presiona `n`.

## ✅ Resumen

1. Cambia Windows a **US-International**
2. Compila y flashea el firmware
3. Usa dead keys para acentos: `'` + vocal = á
4. Usa `~` + `n` = ñ
5. Todos los símbolos de programación funcionan perfectamente

---

**¿Dudas?** Revisa `LAYOUT_ESPANOL.txt` para el mapa visual completo.
