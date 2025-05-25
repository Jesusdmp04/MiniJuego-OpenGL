#pragma once
#include "Scene.h"

class Escena3_Final : public Scene {
public:
    void init() override;
    void handleInput(float dt) override;
    void update(float dt) override;
    void draw() override;
private:
    bool victory;
    float survivedTime;
};
