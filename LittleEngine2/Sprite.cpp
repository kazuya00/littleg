/* 
 * File:   Sprite.cpp
 * Author: youness
 * 
 * Created on 21 mai 2010, 20:43
 */

#include "Sprite.h"

Sprite::Sprite() : Drawable(), m_tex(0){}

Sprite::Sprite(const Sprite& orig) : Drawable(orig)
{
   /* delete m_tex;
    m_tex = new Texture(*orig.m_tex);*/
}

std::string Sprite::GetClassName() const
{
    return "Sprite";
}

Sprite::~Sprite()
{
    m_tex == NULL;
}

void Sprite::BindTexture()
{
    m_tex->Bind();
}

void Sprite::SetTexture(Texture* tex)
{
    // wa9ila make a copy
    m_tex = tex;
}