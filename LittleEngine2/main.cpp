

/* 
 * File:   main.cpp
 * Author: youness
 *
 * Created on 21 mai 2010, 17:06
 */

#include "Sprite.h"
#include "AnimatedTexture.h"
#include "Clip.h"
#include "Little.h"
#include "Stage.h"
#include "Actor.h"
#include <iostream>
std::vector< Actor * > m_ListActors;
Uint8 *keystate = NULL;
Clip * clip = NULL;
AnimatedTexture * animex = NULL;
AnimatedTexture * animex2 = NULL;
Actor * actor = NULL;
bool keydown = false;
SDL_Event events;
void Update(const Event& event)
{
    Little::m_World->Step(1.0f/60.0f, 6, 2);
    Little::m_World->ClearForces();
    for(int i=0; i< m_ListActors.size(); i++)
    {
        m_ListActors.at(i)->Update();
    }
    
    SDL_PollEvent(&events);

    if(events.type == SDL_KEYDOWN && events.key.keysym.sym == SDLK_LEFT)
    {
        if(clip->GetAnim() != animex2)
            clip->SetAnim(animex2);
        
        clip->Play();
        actor->GetBody()->SetLinearVelocity(b2Vec2(-100/Little::RATIO, actor->GetBody()->GetLinearVelocity().y));
    }else if(events.type == SDL_KEYUP && events.key.keysym.sym == SDLK_LEFT)
        clip->Stop();

    if(events.type == SDL_KEYDOWN && events.key.keysym.sym == SDLK_RIGHT)
    {
        if(clip->GetAnim() != animex)
            clip->SetAnim(animex);
        
        clip->Play();
        actor->GetBody()->SetLinearVelocity(b2Vec2(100/Little::RATIO, actor->GetBody()->GetLinearVelocity().y));
    }else if(events.type == SDL_KEYUP && events.key.keysym.sym == SDLK_RIGHT)
        clip->Stop();

    if(events.type == SDL_KEYDOWN && events.key.keysym.sym == SDLK_SPACE)
    {
        if(Little::can_jump == true)
        {
            actor->GetBody()->SetAwake(true);
            actor->GetBody()->ApplyLinearImpulse(b2Vec2(0, -120/Little::RATIO), actor->GetBody()->GetWorldCenter());
        }
    }
}
// FIXME : jumping, one side platform, ground, boxes,
// HELP  : objet ramassable are sensors; or setcontact(false)
// TODO : Camera
int main(int argc, char** argv)
{
    Little::Init();
    
    Stage * stage = Stage::GetInstance();
    stage->SetProperties(800, 600, 32);
    stage->Show();
    keystate = SDL_GetKeyState(NULL);
    
    Texture * tex = new Texture();
    tex->LoadFromImage("/home/youness/NetBeansProjects/LittleEngine2/jill1.png");
    Texture * tex2 = new Texture();
    tex2->LoadFromImage("/home/youness/NetBeansProjects/LittleEngine2/jill2.png");
    Texture * tex3 = new Texture();
    tex3->LoadFromImage("/home/youness/NetBeansProjects/LittleEngine2/jill3.png");

    Texture * tex4 = new Texture();
    tex4->LoadFromImage("/home/youness/NetBeansProjects/LittleEngine2/jill4.png");
    Texture * tex5 = new Texture();
    tex5->LoadFromImage("/home/youness/NetBeansProjects/LittleEngine2/jill5.png");
    Texture * tex6 = new Texture();
    tex6->LoadFromImage("/home/youness/NetBeansProjects/LittleEngine2/jill6.png");


    Texture * tex44 = new Texture();
    tex44->LoadFromImage("/home/youness/NetBeansProjects/LittleEngine2/ground.png");


    Texture * boxtex = new Texture();
    boxtex->LoadFromImage("/home/youness/NetBeansProjects/LittleEngine2/gnd4.png");


    Sprite* box = new Sprite();
    box->SetX(100);
    box->SetY(20);
    box->SetWidth(16);
    box->SetHeight(16);
    box->SetTexture(boxtex);
    stage->Attach(box);

    Sprite* sprite = new Sprite();
    sprite->SetX(0);
    sprite->SetY(100);
    sprite->SetWidth(160);
    sprite->SetHeight(48);
    sprite->SetTexture(tex44);
    stage->Attach(sprite);

    Sprite* ground = new Sprite();
    ground->SetX(80);
    ground->SetY(180);
    ground->SetWidth(160);
    ground->SetHeight(48);
    ground->SetTexture(tex44);
    stage->Attach(ground);


    animex = new AnimatedTexture();
    animex->PushTexture(tex);
    animex->PushTexture(tex2);
    animex->PushTexture(tex3);

    animex2 = new AnimatedTexture();
    animex2->PushTexture(tex4);
    animex2->PushTexture(tex5);
    animex2->PushTexture(tex6);

    clip = new Clip();
    clip->SetX(0);
    clip->SetY(0);
    clip->SetWidth(32);
    clip->SetHeight(32);
    clip->SetAnim(animex);
    clip->SetLoop(true);
    clip->SetFrameTime(30);
    clip->Pause();
    stage->Attach(clip);

    actor = new Actor("jill", clip, b2_dynamicBody);
    m_ListActors.push_back(actor);

    Actor * actor2 = new Actor("ground", sprite, b2_staticBody);
    m_ListActors.push_back(actor2);

    Actor * grounda = new Actor("ground", ground, b2_staticBody);
    m_ListActors.push_back(grounda);

    Actor * boxa = new Actor("box", box, b2_staticBody);
    m_ListActors.push_back(boxa);

    stage->addEventListener(Event::ENTER_FRAME, Update, false, 0, false);

    Little::Loop(60);

    delete tex;
    delete tex2;
    delete tex3;
    Little::m_World->ClearForces();
    delete Little::m_World;
    SDL_Quit();
    exit(0);
    return 0;
}

