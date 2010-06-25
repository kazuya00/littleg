/* 
 * File:   Event.cpp
 * Author: youness
 * 
 * Created on 22 mai 2010, 15:05
 */

#include "Event.h"
const std::string Event::ENTER_FRAME = "enterFrame";
const std::string Event::QUIT = "quit";
Event::Event(const std::string &type, bool bubbles, bool cancelable):
            type(type), bubbles(bubbles), cancelable(cancelable){}

