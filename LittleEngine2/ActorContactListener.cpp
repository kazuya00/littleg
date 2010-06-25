/* 
 * File:   ActorContactListener.cpp
 * Author: youness
 * 
 * Created on 23 mai 2010, 11:41
 */

#include <iostream>

#include "ActorContactListener.h"

ActorContactListener::ActorContactListener() {
}

ActorContactListener::ActorContactListener(const ActorContactListener& orig) {
}

ActorContactListener::~ActorContactListener() {
}

void ActorContactListener::BeginContact(b2Contact* contacts)
{

}

void ActorContactListener::EndContact(b2Contact* contacts)
{
    std::string * shape1 = (std::string*)contacts->GetFixtureA()->GetBody()->GetUserData();
    std::string * shape2 = (std::string*)contacts->GetFixtureB()->GetBody()->GetUserData();

    if (strcmp(shape2->c_str(), "ground")==0 || strcmp(shape2->c_str(), "box")==0)
    {
            std::cout << "cannnot jump" << std::endl;
            Little::can_jump = false;
    }
}

void ActorContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
    b2Fixture* character = contact->GetFixtureA();
    b2Fixture* others = contact->GetFixtureB();

    std::string * shape2 = (std::string*)contact->GetFixtureB()->GetBody()->GetUserData();


   /*if(strcmp(shape1->c_str(), "jill")==0 && strcmp(shape2->c_str(), "ground")==0 )
   {
       character = contact->GetFixtureA();
       floor = contact->GetFixtureB();

   }else if (strcmp(shape1->c_str(), "ground")==0 && strcmp(shape2->c_str(), "jill")==0)
   {
       floor = contact->GetFixtureA();
       character = contact->GetFixtureB();
   }*/
   if(strcmp(shape2->c_str(), "ground") ==0 )
   {
        if (character->GetBody()->GetPosition().y + 32 / Little::RATIO > others->GetBody()->GetPosition().y )
        {    contact->SetEnabled(false);
        //std::cout << "enable true" << std::endl;
        }else
        {   contact->SetEnabled(true);
        //std::cout << "enable false" << std::endl;

        }
    }
}
void ActorContactListener::PostSolve(b2Contact* contacts, const b2ContactImpulse* impulse)
{
    b2Fixture* character = contacts->GetFixtureA();
    b2Fixture* others = contacts->GetFixtureB();

    std::string * shape1 = (std::string*)contacts->GetFixtureA()->GetBody()->GetUserData();
    std::string * shape2 = (std::string*)contacts->GetFixtureB()->GetBody()->GetUserData();

    std::cout << "shape1 " << shape1->c_str()<< std::endl << "shape2 " << shape2->c_str() << std::endl;


    if (strcmp(shape2->c_str(), "ground")==0 || strcmp(shape2->c_str(), "box")==0)
    {
        if (character->GetBody()->GetPosition().y + 32 / Little::RATIO < others->GetBody()->GetPosition().y )
        {
            std::cout << "can jump" << std::endl;
            Little::can_jump = true;
        }
    }
}