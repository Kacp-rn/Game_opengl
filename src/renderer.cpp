#include "renderer.h"

void Renderer::setupBuffers()
{

float vertices[] = {-0.5f, -0.5f, 0.0f, // left  
         0.5f, -0.5f, 0.0f, // right 
         0.0f,  0.5f, 0.0f  // top  
         }; 
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    //delete[] vertices;
}

bool Renderer::init()
{
    
    shader.compileShader("/home/kacp_r/Dokumenty/Game/src/shaders/vertex.glsl", "/home/kacp_r/Dokumenty/Game/src/shaders/fragment.glsl");
    shader.createProgram();

    setupBuffers();

    return true;
}



void Renderer::render()
{
    // Używamy naszego shadera
    shader.use();

    // Powiązujemy VAO, który zawiera nasze wierzchołki
    
    glBindVertexArray(VAO);

    // Renderujemy siatkę kwadratów za pomocą funkcji glDrawArrays
    // GL_LINES - oznacza, że będziemy rysować linie między wierzchołkami
    // W naszym przypadku każdy kwadrat składa się z 4 lini (linia od A do B, B do C, C do D, D do A)
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // Odbindowujemy VAO
    glBindVertexArray(0);
}
