#pragma once

#include "shader.h"
#include "window.h"


class Renderer
{
    private:
    Shader shader;    
    Window& window;

    int rows;
    int columns;
    float cell_size;

    GLuint VAO;
    GLuint VBO;
    
    void setupBuffers();

    public:
    Renderer(Window& window, int c_rows, int cols);
    ~Renderer();

    void init();
    void render();
};