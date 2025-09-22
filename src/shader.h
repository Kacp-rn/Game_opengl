#pragma once

#include "../glad/glad.h"
#include "GLFW/glfw3.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "../glad/stb_image.h"

class Shader
{
    private:
    unsigned int VertexShader;
    unsigned int FragmentShader;
    GLuint Program_ID;

    std::string frag_Path;
    std::string vert_Path;

    public:
    ~Shader();
    void compileShader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
    void createProgram();
    void use();

    GLuint getProgramID() const;
};
