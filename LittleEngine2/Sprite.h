/* 
 * File:   Sprite.h
 * Author: youness
 *
 * Created on 21 mai 2010, 20:43
 */

#ifndef _SPRITE_H
#define	_SPRITE_H

#include "Drawable.h"
#include "Texture.h"
#include <iostream>

class Sprite : public Drawable{
public:
    Sprite();
    Sprite(const Sprite& orig);
    virtual std::string GetClassName() const;
    virtual ~Sprite();
    void SetTexture(Texture * tex);
    void BindTexture();
private:
    Texture * m_tex;
};

#endif	/* _SPRITE_H */

