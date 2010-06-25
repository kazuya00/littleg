/* 
 * File:   Texture.cpp
 * Author: youness
 * 
 * Created on 21 mai 2010, 21:25
 */

#include "Texture.h"
#include <iostream>

Texture::Texture() : m_texture(0)
{
    std::cout << "Constractor : " << GetClassName() << std::endl;
}

Texture::Texture(const Texture& orig)
{
   // m_texture = orig.m_texture;
    std::cout << "Copy : " << GetClassName() << std::endl;
}

Texture::~Texture()
{
    Destroy();
    m_texture = 0;
    std::cout << "Destractor : " << GetClassName() << std::endl;
}

void Texture::Bind()
{
    glBindTexture(GL_TEXTURE_2D, m_texture);
}

void Texture::Destroy()
{
    glDeleteTextures(1, &m_texture);
}

void Texture::LoadFromImage(const char* filename)
{
    SDL_Surface * surface;
    GLenum texture_format;
    GLint  nOfColors;

    surface = IMG_Load(filename);
    if ( (surface->w & (surface->w - 1)) != 0 ) {
        printf("warning: image.bmp's width is not a power of 2\n");
    }
    if ( (surface->h & (surface->h - 1)) != 0 ) {
        printf("warning: image.bmp's height is not a power of 2\n");
    }
    nOfColors = surface->format->BytesPerPixel;
    if (nOfColors == 4)     // contains an alpha channel
    {
        if (surface->format->Rmask == 0x000000ff)
            texture_format = GL_RGBA;
        else
            texture_format = GL_BGRA;
    }
    else if (nOfColors == 3)     // no alpha channel
    {
        if (surface->format->Rmask == 0x000000ff)
            texture_format = GL_RGB;
        else
            texture_format = GL_BGR;
        } else {
            printf("warning: the image is not truecolor..  this will probably break\n");
    }

    // Have OpenGL generate a texture object handle for us
    glGenTextures( 1, &m_texture );
    // Bind the texture object
    glBindTexture( GL_TEXTURE_2D, m_texture );
    // Set the texture's stretching properties
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT);
    glTexParameteri (GL_TEXTURE_2D, GL_GENERATE_MIPMAP_SGIS, GL_TRUE);
    // Edit the texture object's image data using the information SDL_Surface gives us
    glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, surface->w, surface->h, 0, texture_format, GL_UNSIGNED_BYTE, surface->pixels );

    SDL_FreeSurface(surface);
    //glBindTexture( GL_TEXTURE_2D, 0 );
}

std::string Texture::GetClassName() const
{
    return "Texture";
}