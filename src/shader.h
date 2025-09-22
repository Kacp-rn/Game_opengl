#pragma once

#include "../glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <stdlib.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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
