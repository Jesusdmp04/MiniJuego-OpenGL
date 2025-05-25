#pragma once
#include "Scene.h"
#include "Entity.h"
#include <vector>

class Escena2_Juego : public Scene {
public:
    void init() override;
    void handleInput(float dt) override;
    void update(float dt) override;
    void draw() override;
private:
    float countdown;
    float gameTimer;
    Entity ship;
    std::vector<Entity> asteroids;
    unsigned int explosionTex;
    bool gameOver;
};
