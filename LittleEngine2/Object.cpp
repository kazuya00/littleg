/* 
 * File:   Object.cpp
 * Author: youness
 * 
 * Created on 21 mai 2010, 20:44
 */

#include "Object.h"

Object::Object() {}

Object::Object(const Object& orig) {}

Object::~Object() {}

std::string Object::GetClassName() const
{
    return "Object";
}

