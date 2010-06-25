/* 
 * File:   Actor.h
 * Author: youness
 *
 * Created on 22 mai 2010, 13:58
 */

#ifndef _ACTOR_H
#define	_ACTOR_H

#include "Drawable.h"
#include <Box2D/Box2D.h>
#include "Little.h"

class Actor {
public:
    Actor(std::string name, Drawable * drawable, b2BodyType bodyType);
    Actor(const Actor& orig);

    void Update();
    b2Body * GetBody() const;

    virtual ~Actor();
private:
    b2Body * m_Body;
    Drawable * m_Drawable;
    b2BodyType m_BodyType;
};

#endif	/* _ACTOR_H */

