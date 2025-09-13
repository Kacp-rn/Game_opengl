#include"src/shader.h"
#include"src/window.h"
#include"src/renderer.h"
int main()
{
    Window window("Game", 800, 600);
    Shader shader;
    window.init();
    Renderer renderer;
    window.create();
    
    renderer.init();
    
    // shader.compileShader();
    // shader.createProgram();
    //shader.use();

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
