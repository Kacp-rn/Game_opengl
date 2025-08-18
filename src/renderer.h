#pragma once

#include "shader.h"
#include "window.h"
#include<vector>

struct Vertex 
{
    GLfloat x;
    GLfloat y;
    GLfloat z;
};


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

    GLfloat* genVertices();

    public:
    Renderer(Window& window, int c_rows, int cols);
    ~Renderer(){}
    float make_vertices();

    bool init();
    void render();
};