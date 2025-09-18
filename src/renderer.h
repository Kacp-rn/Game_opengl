#pragma once

#include "shader.h"
#include "window.h"
#include<vector>

class Renderer
{
    private:
    Shader shader;    
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
    unsigned char *data;
    
    void setupBuffers();    

    public:
    bool init();
    void render();
    void data_setup();
    //void color_change();
};