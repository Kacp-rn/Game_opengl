#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Shader
{
    private:
    GLuint VertexShader;
    GLuint FragmentShader;
    GLuint Program_ID;

    std::string frag_Path;
    std::string vert_Path;

    public:
    Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
    ~Shader();
    void compileShader();
    void createProgram();
    void use();

    GLuint getProgramID() const;
};
