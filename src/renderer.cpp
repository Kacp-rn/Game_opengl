#include "renderer.h"

Renderer::Renderer(Window& window, int c_rows, int cols)
: shader("src/shaders/vertex.glsl", "src/shaders/fragment.glsl"),
      window(window),
      rows(c_rows),
      columns(cols)
{
    vertices = genVertices();
    cell_size = 0.0625;
}

void Renderer::setupBuffers()
{
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    unsigned int size = window.getWidth() * window.getHeight() * 3 * sizeof(float);

    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    delete[] vertices;
}

bool Renderer::init()
{
    shader.compileShader();
    shader.createProgram();
    glEnable(GL_DEPTH_TEST);

    setupBuffers();

    return true;
}

GLfloat* Renderer::genVertices()
{
    // unsigned int width = window.getWidth();
    // unsigned int height = window.getHeight();
    
    // Obliczenie liczby wierzchołków
    unsigned int numVertices = (columns + 1) * (rows + 1);

    // Tworzenie dynamicznej tablicy dla wierzchołków
    GLfloat* vertices = new GLfloat[numVertices * 3];

    // Generowanie siatki kwadratów
    for (unsigned int y = 0; y <= rows; ++y) 
    {
        for (unsigned int x = 0; x <= columns; ++x) 
        {
            unsigned int index = (y * (columns + 1) + x) * 3;
            vertices[index] = (x * cell_size)-columns;
            vertices[index + 1] = rows - (y * cell_size);
            vertices[index + 2] = 0.0f; // Wszystkie wierzchołki mają z = 0
        }
    }

     return vertices;
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
    glDrawArrays(GL_LINES, 0, rows * columns * 4);

    // Odbindowujemy VAO
    glBindVertexArray(0);
}
