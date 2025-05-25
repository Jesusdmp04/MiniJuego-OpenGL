#pragma once
#include <string>
#include "Shader.h"

// Texto sencillo sin dependencia externa
class Texto {
public:
    virtual ~Texto() = default;
    void init(Shader &shader);
    void render(const std::string &text, float x, float y, float scale);
};
