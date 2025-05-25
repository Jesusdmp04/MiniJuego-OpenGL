#pragma once
#include "Scene.h"

class Escena1_Presentacion : public Scene {
public:
    void init() override;
    void handleInput(float dt) override;
    void update(float dt) override;
    void draw() override;
private:
    unsigned int shipTex;
    unsigned int titleTex;
    unsigned int nameTex;
    unsigned int promptTex;
    unsigned int VAO, VBO;
    float rotation;
};
