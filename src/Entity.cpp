#include "Entity.h"

Entity::Entity() : pos{0,0}, size{0,0}, vel{0,0}, texture(0), VAO(0), active(false){}

void Entity::init(Shader &shader, unsigned int tex, Vec2 initialPos, Vec2 sz) {
    texture = tex;
    pos = initialPos;
    size = sz;
    active = true;
    // crear VAO/VBO aquí...
}

void Entity::update(float dt) {
    if (!active) return;
    pos.x += vel.x * dt;
    pos.y += vel.y * dt;
}

void Entity::draw(const float* proj) {
    if (!active) return;
    // bind texture, usar shader y dibujar VAO
}

bool Entity::checkCollision(const Entity &other) const {
    return active && other.active &&
           pos.x < other.pos.x + other.size.x &&
           pos.x + size.x > other.pos.x &&
           pos.y < other.pos.y + other.size.y &&
           pos.y + size.y > other.pos.y;
}
