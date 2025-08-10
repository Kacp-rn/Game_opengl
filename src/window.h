#pragma once

#include"../glad/glad.h"
#include"GLFW/glfw3.h"
#include "string"
#include<iostream>

class Window
{
    private:
    std::string title;
    int width;
    int height;
    GLFWwindow* window;
    public:
    Window(std::string w_title, int w_width, int w_height);
    ~Window();
    bool init();
    bool create();
    void pollEvents();
    bool ShouldClose();
    void swapBuffers();//for now empty;
    void update();
    int getWidth(){return width;}
    int getHeight(){return height;}
    GLFWwindow* getGLFWWindow(){return window;}

};