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
    glm::mat4 transform = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    transform = glm::translate(transform, glm::vec3(-0.25f, 0.25f, 0.0f));
    transform = glm::rotate(transform, (float)glfwGetTime()*2, glm::vec3(0.0f, 0.0f, 1.0f));

    glUseProgram(Program_ID);

    int transformLoc = glGetUniformLocation(Program_ID, "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
    
    int vertexColorLocation = glGetUniformLocation(Program_ID, "ourColor");
    glUniform4f(vertexColorLocation, 1.0f, (rand()%360)*glfwGetTime(), 0.0f, 1.0f);
}

Shader::~Shader()
{
    glDeleteProgram(Program_ID);
}

