#pragma once

//#include <GLFW/glfw3.h>
//#include "../glad/glad.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../glad/stb_image.h"

//#include "shader.h"

#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

class Texture
{
    private:
    // Shader shader;    
    unsigned int EBO;
    unsigned int texture;
    unsigned char *data;
    int width;
    int height;
    int nrChannels;
    public:
    void is_exist();
};