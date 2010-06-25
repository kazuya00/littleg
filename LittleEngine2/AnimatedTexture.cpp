 /* 
 * File:   AnimatedTexture.cpp
 * Author: youness
 * 
 * Created on 21 mai 2010, 21:33
 */
#include <iostream>
#include "AnimatedTexture.h"

AnimatedTexture::AnimatedTexture()
{
    std::cout << "Constractor : " << GetClassName() << std::endl;
}

AnimatedTexture::AnimatedTexture(const AnimatedTexture& orig)
{
    //m_textures = orig.m_textures;
    std::cout << "Copy : " << GetClassName() << std::endl;
}

AnimatedTexture::~AnimatedTexture()
{
    m_textures.clear();
    std::cout << "Destractor : " << GetClassName() << std::endl;
}

std::string AnimatedTexture::GetClassName() const
{
    return "AnimatedTexture";
}
void AnimatedTexture::PushTexture(Texture* tex)
{
    // test if tex is null
    m_textures.push_back(tex);
}

int AnimatedTexture::Count()
{
    return m_textures.size();
}

Texture * AnimatedTexture::GetTextureAt(int index)
{
    return m_textures.at(index);
}