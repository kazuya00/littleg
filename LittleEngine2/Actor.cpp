/* 
 * File:   Actor.cpp
 * Author: youness
 * 
 * Created on 22 mai 2010, 13:58
 */

#include "Actor.h"

Actor::Actor(std::string name, Drawable * drawable, b2BodyType bodyType): m_Drawable(drawable), m_BodyType(bodyType)
{
    b2BodyDef bodyDef;
    bodyDef.type = m_BodyType;
    bodyDef.position.Set(m_Drawable->GetX() / Little::RATIO, m_Drawable->GetY() / Little::RATIO);

    m_Body = Little::m_World->CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    b2Vec2 centre = b2Vec2((m_Drawable->GetWidth()/2) / Little::RATIO, (m_Drawable->GetHeight()/2) / Little::RATIO);
    dynamicBox.SetAsBox((m_Drawable->GetWidth()/2) / Little::RATIO, (m_Drawable->GetHeight()/2) / Little::RATIO, centre, 0);
    //dynamicBox.m_p.Set();
    //dynamicBox.m_radius = (ball->width / 2) / Little::RATIO;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 0.0f; // mass
    fixtureDef.friction = 10.0f; // frotement
    fixtureDef.restitution = 0.1f; // bounce


    m_Body->SetBullet(true);
    m_Body->SetAwake(true);
    m_Body->CreateFixture(&fixtureDef);
    m_Body->SetUserData(new std::string(name));

    std::string * t = (std::string*)m_Body->GetUserData();
    
    std::cout << "create actor : " << name << std::endl;


}

Actor::Actor(const Actor& orig) {
}

Actor::~Actor() {
}
b2Body * Actor::GetBody() const
{
    return m_Body;
}
void Actor::Update()
{
    m_Drawable->SetX(m_Body->GetPosition().x * Little::RATIO);
    m_Drawable->SetY(m_Body->GetPosition().y * Little::RATIO);
    m_Drawable->SetRotation(m_Body->GetAngle() * 180 / b2_pi);
}
