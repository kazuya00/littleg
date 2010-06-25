/* 
 * File:   Little.cpp
 * Author: youness
 * 
 * Created on 22 mai 2010, 10:21
 */

#include "Little.h"
#include "Drawable.h"
#include "Sprite.h"
#include "Stage.h"
#include "Clip.h"
#include "ActorContactListener.h"

b2World * Little::m_World = NULL;
bool Little::m_Touched = false;
bool Little::game_is_running = true;
bool Little::can_jump = true;

void Little::Init()
{
    if( SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
        printf("SDL Init Error: %s\n", SDL_GetError());
        return;
    }
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
    SDL_GL_SetAttribute (SDL_GL_DEPTH_SIZE, 0);
    SDL_GL_SetAttribute (SDL_GL_STENCIL_SIZE, 0);
    SDL_GL_SetAttribute (SDL_GL_ACCUM_RED_SIZE, 0);
    SDL_GL_SetAttribute (SDL_GL_ACCUM_GREEN_SIZE, 0);
    SDL_GL_SetAttribute (SDL_GL_ACCUM_BLUE_SIZE, 0);
    SDL_GL_SetAttribute (SDL_GL_ACCUM_ALPHA_SIZE, 0);
    SDL_WM_SetCaption("Little Engine", "Little Engine");

    b2Vec2 gravity(0.0f, 9.8f);
    bool doSleep = true;

    m_World = new b2World(gravity, doSleep);
    m_World->SetContactListener(new ActorContactListener());
}
void Little::Loop(const int fps)
{
    const int FRAMES_PER_SECOND = fps;
    const int SKIP_TICKS = 1000 / FRAMES_PER_SECOND;
    int next_game_tick = 0;
    int sleep_time = 0;
    next_game_tick = SDL_GetTicks();
    Stage * stage = Stage::GetInstance();
    Sprite * sprite = NULL;
    Clip * clip = NULL;
    while( game_is_running )
    {
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        glMatrixMode( GL_MODELVIEW );
        glLoadIdentity();
        
        stage->dispatchEvent(Event(Event::ENTER_FRAME, false, false));

        for (int i=0; i < stage->Count(); i++)
        {
            sprite = dynamic_cast<Sprite*>(stage->At(i));

            if(sprite->GetClassName().compare("Clip") == 0)
            {
                clip = dynamic_cast<Clip*>(sprite);
                clip->Anime(clip->GetAnim()->Count());
            }
            glPushMatrix();
            glTranslatef(sprite->GetX(), sprite->GetY(), 0.0f);
            glRotatef(sprite->GetRotation(), 0.0f, 0.0f, 1.0f);
            glScalef(sprite->GetWidth(), sprite->GetHeight(), 0.0f);

            sprite->BindTexture();

            glBegin( GL_QUADS );
                glTexCoord2i( 0, 0 );
                glVertex2f(0.0f, 1.0f);

                glTexCoord2i( 1, 0 );
                glVertex2f( 1.0f, 1.0f );

                glTexCoord2i( 1, 1 );
                glVertex2f( 1.0f, 0.0f );

                glTexCoord2i( 0, 1 );
                glVertex2f( 0.0f, 0.0f );
            glEnd();
            glPopMatrix();
        }
        SDL_GL_SwapBuffers();
        //stage->dispatchEvent(Event(Event::END_FRAME, false, false));
        next_game_tick += SKIP_TICKS;
        sleep_time = next_game_tick - SDL_GetTicks();

        if( sleep_time >= 0 )
        {
            SDL_Delay( sleep_time );
        }
    }
}