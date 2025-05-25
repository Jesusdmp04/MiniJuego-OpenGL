#pragma once
#include "Scene.h"

class Escena1_Presentacion : public Scene {
public:
    void init() override;
    void handleInput(float dt) override;
    void update(float dt) override;
    void draw() override;
private:
    unsigned int VAO, VBO;
    unsigned int textureShip;
};
