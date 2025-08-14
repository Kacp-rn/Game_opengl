#include "shader.h"

Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
{
    vert_Path = vertexShaderPath;
    frag_Path = fragmentShaderPath;
}

void Shader::compileShader()
{
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


    const char* Vert_Shader = vert_Shader.str().c_str();
    const char* Frag_Shader = frag_Shader.str().c_str();

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
    glUseProgram(Program_ID);
}

Shader::~Shader()
{
    glDeleteProgram(Program_ID);
}