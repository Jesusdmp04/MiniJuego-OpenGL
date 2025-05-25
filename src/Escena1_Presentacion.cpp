#include <glad/glad.h>
#include <GLFW/glfw3.h>
extern GLFWwindow* window;

#include "Escena1_Presentacion.h"
#include "SceneManager.h"
#include "Escena2_Juego.h"
#include "Shader.h"

void Escena1_Presentacion::init() {
    // Inicializar recursos (VAO, textura, etc.)
}

void Escena1_Presentacion::handleInput(float dt) {
    if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS) {
        SceneManager mgr;
        mgr.changeScene(std::make_unique<Escena2_Juego>());
    }
}

void Escena1_Presentacion::update(float dt) {}

void Escena1_Presentacion::draw() {
    // Dibujar nave, fondo, texto, etc.
}
