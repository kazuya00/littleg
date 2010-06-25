/* 
 * File:   Stage.h
 * Author: youness
 *
 * Created on 21 mai 2010, 17:49
 */

#ifndef _STAGE_H
#define	_STAGE_H

#include "Object.h"
#include "Drawable.h"
#include "AnimatedTexture.h"
#include "Sprite.h"
#include "EventDispatcher.h"
#include <SDL/SDL.h>
#include <vector>

class Stage : public Object, public EventDispatcher
{
public:
    static Stage * GetInstance();
    void SetProperties(unsigned int width, unsigned int height, unsigned int bpp);
    void Attach(Drawable * drawable);
    int Count();
    Drawable * At(int index);
    void Destroy(Drawable * drawable);
    void DestroyAll();
    void Show();
    virtual std::string GetClassName() const;
    virtual ~Stage();
private:
    void SetupGL();
    static Stage * m_Instance;
    SDL_Surface * m_Screen;
    SDL_Color m_Color;
    unsigned int m_Height, m_Width, m_Bpp;
    std::vector< Drawable * > m_Drawables;
    Stage();
    Stage(const Stage& orig);
};

#endif	/* _STAGE_H */

