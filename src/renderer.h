#pragma once

#include "shader.h"
#include "window.h"
#include <filesystem>
#include<vector>

class Renderer
{
    private:
    Shader shader;    
    GLuint VAO, VBO, EBO;
    //GLuint VBO;
    //GLuint EBO;
    unsigned char *data;
    unsigned int texture;
    int width, height, nrChannels;
    
    void setupBuffers();    

    public:
    bool init();
    void render();
    void data_setup();
    void text_setup();
};