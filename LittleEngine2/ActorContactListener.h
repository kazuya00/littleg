/* 
 * File:   ActorContactListener.h
 * Author: youness
 *
 * Created on 23 mai 2010, 11:41
 */

#ifndef _ACTORCONTACTLISTENER_H
#define	_ACTORCONTACTLISTENER_H
#include <Box2D/Box2D.h>
#include <string>
#include "Little.h"

class ActorContactListener : public b2ContactListener{
public:
    ActorContactListener();
    ActorContactListener(const ActorContactListener& orig);
    virtual ~ActorContactListener();
    void BeginContact(b2Contact* contacts);
    void EndContact(b2Contact* contacts);
    void PreSolve(b2Contact * contacts, const b2Manifold* oldManifold);
    void PostSolve(b2Contact* contacts, const b2ContactImpulse* impulse);
private:

};

#endif	/* _ACTORCONTACTLISTENER_H */

