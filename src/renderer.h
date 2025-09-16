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
    
    void setupBuffers();    

    public:
    bool init();
    void render();
    //void color_change();
};