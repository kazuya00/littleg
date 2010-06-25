/* 
 * File:   Drawable.h
 * Author: youness
 *
 * Created on 21 mai 2010, 20:37
 */

#ifndef _DRAWABLE_H
#define	_DRAWABLE_H

#include "Object.h"


class Drawable : public Object
{
public:
    Drawable();
    Drawable(const Drawable& orig);
    virtual ~Drawable();
    virtual std::string GetClassName() const;
    void SetVisible(bool visiblity);
    bool IsVisible() const;
    void SetRotation(float rotation);
    float GetRotation() const;
    void SetHeight(float height);
    float GetHeight() const;
    void SetWidth(float width);
    float GetWidth() const;
    void SetY(float y);
    float GetY() const;
    void SetX(float x);
    float GetX() const;
    
private:
    float m_x;
    float m_y;
    float m_width;
    float m_height;
    float m_rotation;
    bool  m_visible;
    
};

#endif	/* _DRAWABLE_H */

