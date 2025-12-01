

# RECIPELANG – Intérprete DSL para Lenguaje de Recetas

Este proyecto implementa un **lenguaje específico de dominio (DSL)** llamado **RecipeLang**, diseñado para describir recetas culinarias y calcular información como **costo total**, **calorías**, etc.
El compilador está construido con **ANTLR4**, **C++** y **LLVM IR**, y genera código intermedio ejecutable mediante `lli`.

---

## 📁 Estructura del Proyecto

```
backend/
  main.cpp                  → Punto de entrada
  RecipeVisitorImpl.cpp     → Implementación del visitor
  RecipeVisitorImpl.h

frontend/generated/         → Archivos generados por ANTLR
  RecipeLangLexer.cpp/.h
  RecipeLangParser.cpp/.h
  ...

grammar/
  RecipeLang.g4             → Gramática del lenguaje (ANTLR4)

tests/
  paella.recipe
  brownie.recipe
  sopa.recipe               → Ejemplos de entrada del DSL

dist/                       → Librerías LLVM / ANTLR compiladas
  libantlr4-runtime.so
  libantlr4-runtime.a

CMakeLists.txt
README.md
```

---

# 🚀 **Cómo compilar el proyecto**

El proyecto usa **CMake**.

### 1. Crear carpeta de build

```bash
mkdir build
cd build
```

### 2. Generar configuración con CMake

```bash
cmake ..
```

### 3. Compilar

```bash
make
```

Esto generará un ejecutable, por ejemplo:

```
./recipec
```

---

# ▶️ **Cómo ejecutar un archivo `.recipe`**

Ejemplo:

```bash
./recipec ../tests/paella.recipe
```

Salida esperada (ejemplo):

```
Costo total: 4.70
Calorías totales: 1000
```

---

# 🔄 **Cómo recompilar la gramática (si editas RecipeLang.g4)**

### 1. Instalar ANTLR4 (si no lo tienes)

```bash
sudo apt install default-jre
curl -O https://www.antlr.org/download/antlr-4.13.2-complete.jar
```

### 2. Generar archivos C++

Desde la raíz del proyecto:

```bash
antlr4 -Dlanguage=Cpp -visitor -o frontend/generated grammar/RecipeLang.g4
```

Regenerará:

* Lexer
* Parser
* Visitors
* Tokens

Luego recompila el proyecto con CMake:

```bash
cd build
make
```

---

# 🐳 **Usar el proyecto dentro de un contenedor (Recomendado)**

Este repositorio está preparado para funcionar dentro de un container con:

✔ LLVM instalado
✔ ANTLR4 runtime
✔ CMake + g++
✔ Entorno limpio y reproducible

---

## ✔ Añadir la carpeta del proyecto al container

(Esto aplica tanto a Docker como a Dev Containers de VSCode)

Tu `devcontainer.json` / `Dockerfile` deberá contener:

### **Ejemplo de Dockerfile recomendado**

```dockerfile
FROM ubuntu:22.04

# Dependencias
RUN apt update && apt install -y \
    build-essential cmake wget curl git \
    openjdk-11-jre-headless python3 \
    llvm clang

# Instalar ANTLR
RUN curl -O https://www.antlr.org/download/antlr-4.13.2-complete.jar \
  && mv antlr-4.13.2-complete.jar /usr/local/lib/

ENV CLASSPATH=".:/usr/local/lib/antlr-4.13.2-complete.jar:$CLASSPATH"

# Alias útil
RUN echo 'alias antlr4="java -jar /usr/local/lib/antlr-4.13.2-complete.jar"' >> ~/.bashrc
RUN echo 'alias grun="java org.antlr.v4.gui.TestRig"' >> ~/.bashrc

WORKDIR /workspace
```

Luego:

```bash
docker build -t recipelang .
docker run -it -v $(pwd):/workspace recipelang
```

---

# ✔ VSCode Dev Containers

Si usas VSCode, solo abre el repositorio y ejecuta:

```
Dev Containers: Reopen in Container
```

Asegúrate de que en `.devcontainer/devcontainer.json` esté:

```json
"mounts": [
  "source=${localWorkspaceFolder},target=/workspace,type=bind"
]
```

---

# 🧪 Tests

Puedes ejecutar cualquiera de los archivos de ejemplo:

```bash
./recipec tests/paella.recipe
./recipec tests/brownie.recipe
./recipec tests/sopa.recipe
```

---

# 📌 Notas finales

* Si agregas nuevos tokens o reglas en `RecipeLang.g4`, siempre vuelve a generar el lexer/parser.
* El proyecto requiere LLVM instalado, ya que produce código intermedio.
* `dist/` contiene la librería ANTLR4 precompilada usada por CMake.

---

