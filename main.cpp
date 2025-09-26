#include"src/shader.h"
#include"src/window.h"
#include"src/renderer.h"
#include"src/texture.h"
int main()
{
    // Texture texture;
    // texture.is_exist();
    
    Window window("Colorful Turning Triangle", 800, 600);
    Shader shader;
    window.init();
    Renderer renderer;
    window.create();
    
   renderer.init();
    
    shader.compileShader("/home/kacp_r/Dokumenty/Game/src/shaders/vertex.glsl", "/home/kacp_r/Dokumenty/Game/src/shaders/fragment.glsl");
    shader.createProgram();
    shader.use();


    while (!window.ShouldClose())
    {
        // Obsługa zdarzeń
        window.pollEvents();

        // Aktualizacja stanu gry (np. pozycja gracza, logika gry)
        window.update();

        // Renderowanie sceny
        
        renderer.render();

        // Zamiana buforów
        window.swapBuffers();
    }

    return 0;
}
