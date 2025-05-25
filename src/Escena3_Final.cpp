#include <glad/glad.h>
#include <GLFW/glfw3.h>
extern GLFWwindow* window;

#include "Escena3_Final.h"
#include "SceneManager.h"
#include "Escena1_Presentacion.h"

void Escena3_Final::init() {
    victory = true;
    survivedTime = 25.0f;
}

void Escena3_Final::handleInput(float dt) {
    if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS) {
        SceneManager mgr;
        mgr.changeScene(std::make_unique<Escena1_Presentacion>());
    }
}

void Escena3_Final::update(float dt) {}

void Escena3_Final::draw() {
    // Dibujar mensaje de final y reinicio
}
