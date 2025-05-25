#include <glad/glad.h>
#include <GLFW/glfw3.h>
extern GLFWwindow* window;

#include "Escena2_Juego.h"
#include "SceneManager.h"
#include "Escena3_Final.h"
#include "Shader.h"

void Escena2_Juego::init() {
    countdown = 5.0f;
    gameTimer = 25.0f;
    gameOver = false;
    Shader sh("shaders/vertex.vs", "shaders/fragment.fs");
    ship.init(sh, 0, {400, 50}, {64, 64});
}

void Escena2_Juego::handleInput(float dt) {
    if (gameOver || countdown > 0) return;
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        ship.pos.x -= 300 * dt;
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        ship.pos.x += 300 * dt;
}

void Escena2_Juego::update(float dt) {
    if (countdown > 0) {
        countdown -= dt;
        return;
    }
    gameTimer -= dt;
    if (gameTimer <= 0.0f) gameOver = true;
    if (gameOver) {
        SceneManager mgr;
        mgr.changeScene(std::make_unique<Escena3_Final>());
    }
}

void Escena2_Juego::draw() {
    // Dibujar nave, asteroides, etc.
}
