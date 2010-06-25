/* 
 * File:   Stage.cpp
 * Author: youness
 * 
 * Created on 21 mai 2010, 17:49
 */

#include "Stage.h"


Stage * Stage::m_Instance = NULL;

Stage::Stage() : m_Width(800), m_Height(600), m_Bpp(32), m_Screen(0){}

Stage::Stage(const Stage& orig){}

Stage::~Stage()
{
    DestroyAll();
}

void Stage::Attach(Drawable* drawable)
{
    // test for multiple attach
    m_Drawables.push_back(drawable);
}
int Stage::Count()
{
    return m_Drawables.size();
}
Drawable * Stage::At(int index)
{
    return m_Drawables.at(index);
}

void Stage::SetProperties(unsigned int width, unsigned int height, unsigned int bpp)
{
    m_Bpp = bpp;
    m_Height = height;
    m_Width = width;
}
void Stage::Show()
{
    SetupGL();
}
void Stage::SetupGL()
{
    if(!( m_Screen = SDL_SetVideoMode( m_Width, m_Height, m_Bpp, SDL_OPENGL | SDL_DOUBLEBUF | SDL_HWPALETTE )))
    {
        printf("Screen Init Error : %s\n", SDL_GetError());
        return;
    }
    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL);
    glEnable( GL_TEXTURE_2D );
    //glEnable(GL_DEPTH_TEST); // z order
    glEnable( GL_BLEND ) ;
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    //glEnable (GL_CULL_FACE); // hide back vertex
    glClear( GL_COLOR_BUFFER_BIT );
    glClearColor( 0.4f, 0.2f, 0.4f, 0.0f );
    glViewport( 0, 0, m_Width, m_Height );
    glShadeModel (GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glMatrixMode( GL_PROJECTION );
        glLoadIdentity();
        glOrtho(0.0f, m_Width, m_Height, 0.0f, -1.0f, 1.0f);
}
Stage * Stage::GetInstance()
{
    if (NULL == m_Instance)
    {
        m_Instance =  new Stage;
    }
    return m_Instance;
}
void Stage::DestroyAll()
{
    if(m_Drawables.size() > 0)
    {
        m_Drawables.clear();
    }
}

std::string Stage::GetClassName() const
{
    return "Stage";
}