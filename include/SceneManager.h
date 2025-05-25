#pragma once
#include <memory>
#include "Scene.h"

class SceneManager {
public:
    void changeScene(std::unique_ptr<Scene> newScene);
    void handleInput(float dt);
    void update(float dt);
    void draw();
private:
    std::unique_ptr<Scene> current;
};
