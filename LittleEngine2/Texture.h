/* 
 * File:   Texture.h
 * Author: youness
 *
 * Created on 21 mai 2010, 21:25
 */

#ifndef _TEXTURE_H
#define	_TEXTURE_H

#include "Resource.h"
#include <GL/gl.h>
#include <SDL/SDL_image.h>

class Texture : public Resource{
public:
    Texture();
    Texture(const Texture& orig);
    virtual ~Texture();
    virtual std::string GetClassName() const;
    void Bind();
    void Destroy();
    void LoadFromImage(const char * filename);
//private:
    GLuint m_texture;
};

#endif	/* _TEXTURE_H */

