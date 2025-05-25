#pragma once

class Scene {
public:
    virtual ~Scene() = default;
    virtual void init() = 0;
    virtual void handleInput(float dt) = 0;
    virtual void update(float dt) = 0;
    virtual void draw() = 0;
};
