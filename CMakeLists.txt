cmake_minimum_required(VERSION 3.5)
project(NarutoRush VERSION 0.0.1)
find_package(glfw3 3.3 REQUIRED)

# Include dirs
include_directories(
    ${PROJECT_SOURCE_DIR}/glad/include
    ${PROJECT_SOURCE_DIR}/include
)
include_directories("C:/Users/jesus/vcpkg/installed/x64-windows/include")

add_subdirectory(glad)

set(
    SOURCES
    src/Entity.cpp 
    src/Escena1_Presentacion.cpp 
    src/Escena2_Juego.cpp
    src/Escena3_Final.cpp
    src/main.cpp 
    src/SceneManager.cpp
    src/Shader.cpp
    src/Texto.cpp
    src/stb_image.cpp         # <=== Implementación agregada aquí
)

add_executable(NarutoRush ${SOURCES})

target_link_libraries(
    NarutoRush
    glfw
    glad
)
