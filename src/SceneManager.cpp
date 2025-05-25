#include "SceneManager.h"

void SceneManager::changeScene(std::unique_ptr<Scene> newScene) {
    current = std::move(newScene);
    current->init();
}

void SceneManager::handleInput(float dt) {
    if (current) current->handleInput(dt);
}

void SceneManager::update(float dt) {
    if (current) current->update(dt);
}

void SceneManager::draw() {
    if (current) current->draw();
}
