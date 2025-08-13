#include "renderer.h"

Renderer::Renderer(Window& window, int c_rows, int cols)
: shader("/home/kacp_r/Dokumenty/Game/src/shaders/vertex.glsl", "/home/kacp_r/Dokumenty/Game/src/shaders/fragment.glsl"),
      window(window),
      rows(c_rows),
      columns(cols)
{
    cell_size = 40;

    init();
}

void Renderer::setupBuffers()
{
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    
}

void Renderer::init()
{
    window.init();
    shader.compileShader();
    shader.createProgram();
    glEnable(GL_DEPTH_TEST);

    setupBuffers();
}