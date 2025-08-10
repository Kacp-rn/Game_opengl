#include <iostream>
#include "src/window.h"


int main()
{
    /* --------------------------
       1) Utworzenie obiektu okna
    -------------------------- */
    Window win("Mój Prosty Game", 1280, 720);

    /* --------------------------
       2) Inicjalizacja GLFW / GLAD
    -------------------------- */
    if (!win.init())
        return EXIT_FAILURE;          // Błąd przy inicjalizacji

    /* --------------------------
       3) Utworzenie okna (i kontekstu OpenGL)
    -------------------------- */
    if (!win.create())
        return EXIT_FAILURE;          // Błąd przy tworzeniu okna

    /* --------------------------
       4) Konfiguracja viewportu
    -------------------------- */
    glViewport(0, 0, win.getWidth(), win.getHeight());   // metoda getWidth() i getHeight()
    glfwSetFramebufferSizeCallback(
        win.getGLFWWindow(),
        [](GLFWwindow*, int w, int h)
        {
            glViewport(0, 0, w, h);
        });

    /* --------------------------
       5) Główny loop gry
    -------------------------- */
    while (!win.ShouldClose())
    {
        // ---- Input ----------------------------------------------------
        win.pollEvents();          // obsługa zdarzeń (klawisze, mysz itp.)

        // ---- Renderowanie -------------------------------------------
        win.update();

        /* Tu wstawisz swoje renderowanie – np. wywołania draw() */

        // ---- Swap buffers --------------------------------------------
        win.swapBuffers();         // <-- powinno wywoływać glfwSwapBuffers
    }

    /* --------------------------
       6) Czyszczenie (destruktor Window zajmuje się GLFW)
    -------------------------- */
    return EXIT_SUCCESS;
}
