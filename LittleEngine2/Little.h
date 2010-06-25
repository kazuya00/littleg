/* 
 * File:   Little.h
 * Author: youness
 *
 * Created on 22 mai 2010, 10:21
 */

#ifndef _LITTLE_H
#define	_LITTLE_H

#include <iostream>
#include <SDL/SDL.h>
#include <Box2D/Box2D.h>
#include <SDL/SDL_opengl.h>

class Little {
public:
    static void Init();
    static void Loop(const int fps);
    static b2World * m_World;
    static const int RATIO = 30;
    static bool m_Touched;
    static bool game_is_running;
    static bool can_jump;
};

#endif	/* _LITTLE_H */

