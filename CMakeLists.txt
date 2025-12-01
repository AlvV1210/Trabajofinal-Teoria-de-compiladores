cmake_minimum_required(VERSION 3.16)
project(recipeLang LANGUAGES C CXX)

# =============================
# C++ Standard
# =============================
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# =============================
# Paths
# =============================
set(GENERATED_DIR ${CMAKE_SOURCE_DIR}/frontend/generated)
set(BACKEND_DIR   ${CMAKE_SOURCE_DIR}/backend)

# =============================
# LLVM
# =============================
find_package(LLVM REQUIRED CONFIG)

message(STATUS "Encontrado LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "LLVM dir: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

llvm_map_components_to_libnames(
    LLVM_LIBS
    core
    support
    irreader
)

# =============================
# ANTLR4 Runtime (del sistema)
# =============================
find_library(ANTLR4_RUNTIME antlr4-runtime REQUIRED)
include_directories(/usr/include/antlr4-runtime)

# =============================
# Fuentes del proyecto
# =============================
set(SOURCES
    ${BACKEND_DIR}/main.cpp
    ${BACKEND_DIR}/RecipeVisitorImpl.cpp

    ${GENERATED_DIR}/RecipeLangLexer.cpp
    ${GENERATED_DIR}/RecipeLangParser.cpp
    ${GENERATED_DIR}/RecipeLangBaseListener.cpp
    ${GENERATED_DIR}/RecipeLangListener.cpp
    ${GENERATED_DIR}/RecipeLangBaseVisitor.cpp
    ${GENERATED_DIR}/RecipeLangVisitor.cpp
)

# =============================
# Ejecutable
# =============================
add_executable(recipec ${SOURCES})

# =============================
# Enlace de librerías
# =============================
target_link_libraries(recipec
    ${ANTLR4_RUNTIME}
    ${LLVM_LIBS}
    pthread
)
