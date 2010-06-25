/* 
 * File:   Resource.cpp
 * Author: youness
 * 
 * Created on 21 mai 2010, 21:25
 */

#include "Resource.h"

Resource::Resource() {
}

Resource::Resource(const Resource& orig) {
}

Resource::~Resource() {
}

std::string Resource::GetClassName() const
{
    return "Resource";
}
