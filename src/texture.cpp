#include"texture.h"

Texture::Texture(std::string path)
{
    texture_path = path.c_str();
    std::cout<<texture_path<<std::endl;
}

Texture::~Texture()
{
    //stbi_image_free(data);
}