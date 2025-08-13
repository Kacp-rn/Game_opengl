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

void Renderer::init()
{

}