/* 
 * File:   Clip.cpp
 * Author: youness
 * 
 * Created on 21 mai 2010, 21:31
 */

#include <iostream>

#include "Clip.h"

Clip::Clip() : Sprite(), m_Animtex(0), m_CurrentFrame(0), m_ElapsedTime(0),
                m_Loop(0), m_Paused(0), m_Time(0)
{
    std::cout << "Constractor : " << GetClassName() << std::endl;
}

Clip::Clip(const Clip& orig) : Sprite(orig)
{
    m_CurrentFrame = orig.m_CurrentFrame;
    m_ElapsedTime = orig.m_ElapsedTime;
    m_Loop = orig.m_Loop;
    m_Paused = orig.m_Paused;
    m_Time = orig.m_Time;
    /*delete m_Animtex;
    m_Animtex = new AnimatedTexture();*/
    std::cout << "Copy : " << GetClassName() << std::endl;
}

Clip::~Clip()
{
    if(m_Animtex != NULL)
    {
        delete m_Animtex;
        m_Animtex = NULL;
    }
    std::cout << "Destractor : " << GetClassName() << std::endl;
}


// Comme 'SetImage', sauf qu'on lui fournit l'Anim
void Clip::SetAnim(AnimatedTexture* new_anim)
{
    m_Animtex = new_anim;
    SetFrame(0);
}

std::string Clip::GetClassName() const
{
    return "Clip";
}

AnimatedTexture* Clip::GetAnim()
{
    return m_Animtex;
}

void Clip::SetFrame(int frame)
{
    if ( m_Animtex != NULL)
    {
        if (m_Animtex->Count() > 0)
        {
            if (m_Animtex->GetTextureAt(frame) != NULL)
                SetTexture(m_Animtex->GetTextureAt(frame));

            m_CurrentFrame = frame;
        }
    }
}

int Clip::GetCurrentFrame()
{
    return m_CurrentFrame;
}

void Clip::SetFrameTime(float time)
{
    m_Time = time;
}

float Clip::GetFrameTime()
{
    return m_Time;
}

void Clip::SetLoop(bool loop)
{
    m_Loop = loop;
}

bool Clip::IsLoop()
{
    return m_Loop;
}

void Clip::Pause()
{
    m_Paused = true;
}

void Clip::Play()
{
    m_Paused = false;
}

void Clip::Stop()
{
    SetFrame(0);
    m_ElapsedTime = m_Time;
    m_Paused = true;
}

bool Clip::IsPaused()
{
    return m_Paused;
}

bool Clip::IsStoped()
{
    return (m_Paused && (m_CurrentFrame == 0) && (m_ElapsedTime == m_Time));
}

// Fonction à appeler à chaque tours de boucle, prend le temps
// écoulé depuis le dernier appel à la fonction en paramètre
void Clip::Anime(float elapsed_time)
{
    // Si il n'est pas en pause et que l'animation est valide
    if (!m_Paused && m_Animtex != NULL)
    {
        // on retranche le temps écoulé a notre compteur
        m_ElapsedTime -= elapsed_time;

        // Si Le temps entre chaque frame est atteint
        if (m_ElapsedTime <= 0.f)
        {
            // On réinitialise notre compteur
            m_ElapsedTime = m_Time;

            // On passe a la frame suivante
            if (m_CurrentFrame + 1 < m_Animtex->Count())
                m_CurrentFrame++;
            else
            {
                // Ou on a la premiere
                if (m_Loop)
                    m_CurrentFrame = 0;
                else
                {
                    // Si le mode Loop est désactivé, on stop l'animation
                    Stop();
                }
            }
            // On change la frame
            SetFrame(m_CurrentFrame);
        }
    }
}