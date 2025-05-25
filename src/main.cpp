#include <glad/glad.h>
#include <GLFW/glfw3.h>
GLFWwindow* window = nullptr;

#include "SceneManager.h"
#include "Escena1_Presentacion.h"

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    window = glfwCreateWindow(800, 600, "DodgeShip", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glViewport(0, 0, 800, 600);

    SceneManager manager;
    manager.changeScene(std::make_unique<Escena1_Presentacion>());

    float last = glfwGetTime();
    while (!glfwWindowShouldClose(window)) {
        float now = glfwGetTime();
        float dt = now - last;
        last = now;

        glClear(GL_COLOR_BUFFER_BIT);
        manager.handleInput(dt);
        manager.update(dt);
        manager.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
