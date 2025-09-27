#pragma once

#include "../glad/stb_image.h"

#include "shader.h"

#include <iostream>
#include <string>
#include <vector>

class Texture
{
    private:   
    unsigned int EBO;
    unsigned int texture;
    unsigned char *data;
    std::string texture_path;
    int width;
    int height;
    int nrChannels;
    public:
    Texture(std::string path);
    ~Texture();
};