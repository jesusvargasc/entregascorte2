cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(SistemaGestionAcademica VERSION 1.0 LANGUAGES CXX)

# Estándar de C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Directorio de archivos de cabecera
include_directories(${PROJECT_SOURCE_DIR}/include)

# Archivos fuente
set(SOURCES
    src/Estudiante.cpp
    src/main.cpp
)

# Crear el ejecutable
add_executable(gestion_academica ${SOURCES})

# Configuración para exportar comandos de compilación (útil para IDEs)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Opciones de compilación (warnings)
if(MSVC)
    target_compile_options(gestion_academica PRIVATE /W4)
else()
    target_compile_options(gestion_academica PRIVATE -Wall -Wextra -pedantic)
endif()

# Mensaje de información
message(STATUS "Configurando proyecto: ${PROJECT_NAME} v${PROJECT_VERSION}")
message(STATUS "Compilador: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Estándar C++: ${CMAKE_CXX_STANDARD}")