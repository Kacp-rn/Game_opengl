#include "shader.h"

void Shader::compileShader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
{
    vert_Path = vertexShaderPath;
    frag_Path = fragmentShaderPath;
    
    std::ifstream vertex(vert_Path);
    std::ifstream fragment(frag_Path);

    if(!vertex.is_open()||!fragment.is_open())
    {
        std::cerr<<"Failed to open Shader-file"<<std::endl;
    }
    std::stringstream vert_Shader;
    std::stringstream frag_Shader;

    vert_Shader << vertex.rdbuf();
    frag_Shader << fragment.rdbuf();

    vertex.close();
    fragment.close();


    std::string vertShaderStr = vert_Shader.str();
    std::string fragShaderStr = frag_Shader.str();

    const char* Vert_Shader = vertShaderStr.c_str();
    const char* Frag_Shader = fragShaderStr.c_str();

    VertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(VertexShader, 1, &Vert_Shader, nullptr);
    glCompileShader(VertexShader);
    
    FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(FragmentShader, 1, &Frag_Shader, nullptr);
    glCompileShader(FragmentShader);

    
}

void Shader::createProgram()
{
    Program_ID = glCreateProgram();
    glAttachShader(Program_ID, VertexShader);
    glAttachShader(Program_ID, FragmentShader);
    glLinkProgram(Program_ID);
    glDeleteShader(FragmentShader);
    glDeleteShader(VertexShader);
}

void Shader::use()
{
    float timeValue = glfwGetTime();
    float greenValue = (sin(timeValue)/2.0f) + 0.5f;
    float redValue = (cos(timeValue) / 2.0f) + 0.5f;
    float blueValue = (cos(timeValue) / 4.0f) + 0.6f;
    int vertexColorLocation = glGetUniformLocation(Program_ID, "ourColor");
    glUseProgram(Program_ID);
    glUniform4f(vertexColorLocation, redValue, greenValue, blueValue, 1.0f);
}

Shader::~Shader()
{
    glDeleteProgram(Program_ID);
}

