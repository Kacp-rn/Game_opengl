#pragma once

#include "../glad/stb_image.h"

#include "shader.h"

#include <iostream>
#include <string>
#include <vector>

class Texture
{
    private:   
   // unsigned int EBO;
    GLuint texture;
    unsigned char *data;
    std::string texture_path;
    int width;
    int height;
    int nrChannels;

    public:
    bool data_setup();
    void pre_texture_setup();
    void EBO_setup();
    void bind_texture();
    public:
    void s_Texture(std::string path);
    void main_loop();
    ~Texture();
};