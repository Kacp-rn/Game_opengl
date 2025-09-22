#include "renderer.h"

void Renderer::setupBuffers()
{
    float timeValue = glfwGetTime()*(rand()%360);
    float greenValue = (sin(timeValue)/2.0f) + 0.5f;
    float redValue = (sin(timeValue) / 2.0f) + 0.5f;
    float blueValue = (sin(timeValue) / 4.0f) + 0.6f;

    float vertices[] = {
        // positions         // colors
         -0.5f, 0.5f, 0.0f,  redValue, 0.0f, 0.0f,   // bottom right
          0.5f,  0.5f, 0.0f,  0.0f, greenValue, 0.0f,   // bottom left
          0.0f, -0.5f, 0.0f,  0.0f, 0.0f, blueValue    // top 
    };  

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

   // position attribute
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
glEnableVertexAttribArray(0);
// color attribute
glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

bool Renderer::init()
{
    
    shader.compileShader("/home/kacp_r/Dokumenty/Game/src/shaders/vertex.glsl", "/home/kacp_r/Dokumenty/Game/src/shaders/fragment.glsl");
    shader.createProgram();

    setupBuffers();

    return true;
}



void Renderer::render()
{
    shader.use();
    
    glBindVertexArray(VAO);
   
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glBindVertexArray(0);
}

// void Renderer::color_change()
// {
//     float timeValue = glfwGetTime();
//     float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
//     int vertexColorLocation = glGetUniformLocation(shader.getProgramID(), "ourColor");
//     glUniform4f(vertexColorLocation, 0.7f, greenValue, 0.3f, 1.0f);
// }