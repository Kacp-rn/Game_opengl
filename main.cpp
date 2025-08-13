#include"src/renderer.h"
#include"src/window.h"
#include"src/shader.h"

int main()
{
    Window window("Game", 800, 600);
    Renderer renderer(window, 18, 32);

    renderer.init();
    window.create();

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
