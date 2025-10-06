#pragma once

#include "shader.h"
#include"texture.h"
#include "window.h"
#include<vector>

class Renderer
{
    private:
    Shader shader;
    Texture texture; 
    GLuint EBO;
    GLuint VAO;
    GLuint VBO;
    
    void setupBuffers();    

    public:
    ~Renderer();
    bool init();
    void render();
    //void color_change();
};