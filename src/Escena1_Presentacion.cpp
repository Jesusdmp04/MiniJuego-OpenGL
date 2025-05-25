#include <glad/glad.h>
#include <GLFW/glfw3.h>
extern GLFWwindow* window;

#include "Escena1_Presentacion.h"
#include "SceneManager.h"
#include "Escena2_Juego.h"
#include "Shader.h"
#include "stb_image.h"
#include <cmath>

static unsigned int LoadTexture(const char* path) {
    int w, h, channels;
    unsigned char* data = stbi_load(path, &w, &h, &channels, 4);
    unsigned int tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    stbi_image_free(data);
    return tex;
}

void Escena1_Presentacion::init() {
    rotation = 0.0f;

    shipTex = LoadTexture("assets/textures/ship.png");
    titleTex = LoadTexture("assets/textures/title.png");
    nameTex = LoadTexture("assets/textures/game_name.png");
    promptTex = LoadTexture("assets/textures/press_enter.png");

    float vertices[] = {
        -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.0f, 1.0f
    };
    unsigned int indices[] = { 0, 1, 2, 2, 3, 0 };

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO, EBO;
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

void Escena1_Presentacion::handleInput(float dt) {
    if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS) {
        SceneManager mgr;
        mgr.changeScene(std::make_unique<Escena2_Juego>());
    }
}

void Escena1_Presentacion::update(float dt) {
    rotation += dt * 50.0f;
    if (rotation > 360.0f) rotation -= 360.0f;
}

static void DrawQuad(unsigned int texture, float x, float y, float scale = 1.0f, float angle = 0.0f) {
    glBindTexture(GL_TEXTURE_2D, texture);
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scale, scale, 1.0f);
    glRotatef(angle, 0, 0, 1);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glPopMatrix();
}

void Escena1_Presentacion::draw() {
    glEnable(GL_TEXTURE_2D);
    glBindVertexArray(VAO);

    DrawQuad(titleTex, 400, 500, 1.5f);
    DrawQuad(nameTex, 400, 450, 1.0f);
    DrawQuad(shipTex, 400, 300, 1.2f, rotation);
    DrawQuad(promptTex, 400, 100, 1.0f);
}
