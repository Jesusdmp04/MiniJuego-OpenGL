#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include "Shader.h"

class GameObject {
public:
    glm::vec2 pos;
    glm::vec2 size;
    glm::vec2 velocity;
    unsigned int texture;
    Shader* shader;
    unsigned int VAO;
    bool active;

    GameObject();
    void init(Shader &sh, unsigned int tex);
    void draw(const float* projection);
    bool checkCollision(const GameObject &other) const;
};
