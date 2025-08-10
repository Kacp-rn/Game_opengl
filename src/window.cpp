#include"window.h"

Window::Window(std::string w_title, int w_width, int w_height)
{
    title = w_title;
    width = w_width;
    height = w_height;
}

bool Window::init()
{
    if(!glfwInit())
    {
        std::cerr<<"Failed to initialize GLFW/GLAD"<<std::endl;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Window::create()
{
    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if(window = nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
}