#include"texture.h"

void Texture::s_Texture(std::string path)
{
    texture_path = path;
    std::cout<<texture_path<<std::endl;
}

Texture::~Texture()
{
    stbi_image_free(data);
}
bool Texture::data_setup()
{
    stbi_set_flip_vertically_on_load(true); // opcjonalnie, jeśli tekstura jest do góry nogami
    data = stbi_load("/home/kacp_r/Dokumenty/Game/src/assets/container.png", &width, &height, &nrChannels, 0);
    if(data)
    {
        std::cout<<"Data loaded correctly."<<std::endl;
        return true;
    }
    else
    {
        std::cout<<"Data didn't load or loaded uncorrectly."<<std::endl;
        return false;
    }
}

void Texture::pre_texture_setup()
{
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    if(data)
    {
        GLenum format = (nrChannels == 4) ? GL_RGBA : GL_RGB;
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
}

/*
void Texture::EBO_setup()
{
     float texCoords[] = {
    1.0f, 0.0f,  // lower-left corner  
    1.0f, 1.0f,  // lower-right corner
    0.5f, 0.0f   // top-center corner
    };    
    
    glGenBuffers(1, &EBO);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(texCoords), texCoords, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)offsetof(float, texCoords));
    glEnableVertexAttribArray(0);
}*/

void Texture::bind_texture()
{
      glBindTexture(GL_TEXTURE_2D, texture);
}

void Texture::main_loop()
{
    // EBO_setup();
    // pre_texture_setup();
    // data_setup();
}