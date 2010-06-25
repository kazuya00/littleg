/* 
 * File:   Event.h
 * Author: youness
 *
 * Created on 22 mai 2010, 15:05
 */

#ifndef _EVENT_H
#define	_EVENT_H
#include <string>

class Event
{
public:
    static const std::string QUIT;
    static const std::string ENTER_FRAME;
    static const std::string END_FRAME;

    Event(const std::string &type, bool bubble, bool cancelable);
    Event(const Event& orig){}
    virtual ~Event(){}

    std::string type;
    bool bubbles;
    bool cancelable;
    //Object * target;

};

#endif	/* _EVENT_H */

