#pragma once
#include "Shader.h"

// Representa nave o asteroide
struct Vec2 { float x, y; };

class Entity {
public:
    Vec2 pos;
    Vec2 size;
    Vec2 vel;
    unsigned int texture;
    unsigned int VAO;
    bool active;

    Entity();
    void init(Shader &shader, unsigned int tex, Vec2 initialPos, Vec2 size);
    void update(float dt);
    void draw(const float* proj);
    bool checkCollision(const Entity &other) const;
};
