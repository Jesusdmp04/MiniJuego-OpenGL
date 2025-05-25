#include "Shader.h"
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const char* vsPath, const char* fsPath) {
    std::ifstream vFile(vsPath), fFile(fsPath);
    std::stringstream vSS, fSS;
    vSS << vFile.rdbuf(); fSS << fFile.rdbuf();
    std::string vsCode = vSS.str(), fsCode = fSS.str();
    const char* vsrc = vsCode.c_str();
    const char* fsrc = fsCode.c_str();

    unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vsrc, nullptr);
    glCompileShader(vs);

    unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fsrc, nullptr);
    glCompileShader(fs);

    ID = glCreateProgram();
    glAttachShader(ID, vs);
    glAttachShader(ID, fs);
    glLinkProgram(ID);
    glDeleteShader(vs);
    glDeleteShader(fs);
}

void Shader::use() const {
    glUseProgram(ID);
}

void Shader::setMat4(const std::string &name, const float* value) const {
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, value);
}
