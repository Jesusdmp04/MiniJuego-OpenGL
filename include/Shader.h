#pragma once
#include <string>
#include <glad/glad.h>

class Shader {
public:
    unsigned int ID;
    Shader(const char* vsPath, const char* fsPath);
    void use() const;
    void setMat4(const std::string &name, const float* value) const;
};
