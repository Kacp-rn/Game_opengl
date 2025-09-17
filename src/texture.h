#include<GLFW/glfw3.h>
#include<../glad/glad.h>
#include<iostream>
#include<string>

class Texture
{
    private:
    void set_texture_vertices();
    void set_borderColor(float r, float g, float b, float a);
    public:
    Texture(const std::string& texture_path);
    void init();


};

