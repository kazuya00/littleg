/* 
 * File:   Clip.h
 * Author: youness
 *
 * Created on 21 mai 2010, 21:31
 */

#ifndef _CLIP_H
#define	_CLIP_H

#include "Sprite.h"
#include "AnimatedTexture.h"

class Clip : public Sprite{
public:
    Clip();
    Clip(const Clip& orig);
    virtual ~Clip();
    virtual std::string GetClassName() const;
    void SetAnim(AnimatedTexture* new_anim);
    AnimatedTexture* GetAnim();
    void SetFrame(int frame);
    int GetCurrentFrame();
    void SetFrameTime(float time);
    float GetFrameTime();
    void SetLoop(bool loop);
    bool IsLoop();
    void Pause();
    void Play();
    void Stop();
    bool IsPaused();
    bool IsStoped();
    void Anime(float elapsed_time);

private:
    float m_Time;
    float m_ElapsedTime;
    bool  m_Paused;
    bool  m_Loop;
    int   m_CurrentFrame;
    AnimatedTexture * m_Animtex;
    // map of animatedtexture (setanim(name))
    // or one animatedtexture (setanim(extern))
};

#endif	/* _CLIP_H */

