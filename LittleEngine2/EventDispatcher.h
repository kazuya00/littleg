/* 
 * File:   EventDispatcher.h
 * Author: youness
 *
 * Created on 22 mai 2010, 15:02
 */

#ifndef _EVENTDISPATCHER_H
#define	_EVENTDISPATCHER_H

#include <map>
#include <list>
#include <string>
#include <stdio.h>
#include "Event.h"

// Event function callback pointer type
typedef void (*eventFunctionPtr)(const Event &);

class EventDispatcher
{
public:
    EventDispatcher();
    EventDispatcher(const EventDispatcher& orig);
    virtual ~EventDispatcher(){}

    void addEventListener(const std::string &type, eventFunctionPtr listener, bool useCapture, int priority, bool useWeakReference);
    void removeEventListener(const std::string &type, eventFunctionPtr listener, bool useCapture);
    bool hasEventListener(const std::string &type);
    void dispatchEvent(const Event &event);

private:
    std::map<const std::string, std::map<int, std::list<eventFunctionPtr> > > eventHandlerList;
};

#endif	/* _EVENTDISPATCHER_H */

