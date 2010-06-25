/* 
 * File:   AnimatedTexture.h
 * Author: youness
 *
 * Created on 21 mai 2010, 21:33
 */

#ifndef _ANIMATEDTEXTURE_H
#define	_ANIMATEDTEXTURE_H

#include "Object.h"
#include "Texture.h"
#include <vector>


class AnimatedTexture : public Object{
public:
    AnimatedTexture();
    AnimatedTexture(const AnimatedTexture& orig);
    virtual ~AnimatedTexture();
    virtual std::string GetClassName() const;
    void PushTexture(Texture* tex);
    int Count();
    Texture * GetTextureAt(int index);
    //Texture& operator [] (size_t N);

private:
    std::vector< Texture * > m_textures;
};

#endif	/* _ANIMATEDTEXTURE_H */

