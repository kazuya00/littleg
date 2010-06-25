/* 
 * File:   Drawable.cpp
 * Author: youness
 * 
 * Created on 21 mai 2010, 20:37
 */

#include "Drawable.h"

Drawable::Drawable(): m_height(0), m_width(0), m_rotation(0), m_x(0), m_y(0){}

Drawable::Drawable(const Drawable& orig)
{
    m_height = orig.m_height;
    m_width = orig.m_width;
    m_rotation = orig.  m_rotation;
    m_x = orig.m_x;
    m_y = orig.m_y;
    m_visible = orig.m_visible;
}

Drawable::~Drawable() {}

std::string Drawable::GetClassName() const
{
    return "Drawable";
}

void Drawable::SetVisible(bool visiblity)
{
    this->m_visible = visiblity;
}
bool Drawable::IsVisible() const
{
    return m_visible;
}
void Drawable::SetRotation(float rotation)
{
    this->m_rotation = rotation;
}
float Drawable::GetRotation() const
{
    return m_rotation;
}
void Drawable::SetHeight(float height)
{
    this->m_height = height;
}
float Drawable::GetHeight() const
{
    return m_height;
}
void Drawable::SetWidth(float width)
{
    this->m_width = width;
}
float Drawable::GetWidth() const
{
    return m_width;
}
void Drawable::SetY(float y)
{
    this->m_y = y;
}
float Drawable::GetY() const
{
    return m_y;
}
void Drawable::SetX(float x)
{
    this->m_x = x;
}
float Drawable::GetX() const
{
    return m_x;
}

