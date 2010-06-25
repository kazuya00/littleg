/* 
 * File:   Resource.h
 * Author: youness
 *
 * Created on 21 mai 2010, 21:25
 */

#ifndef _RESOURCE_H
#define	_RESOURCE_H

#include "Object.h"

class Resource : public Object
{
public:
    Resource();
    Resource(const Resource& orig);
    virtual ~Resource();
    virtual std::string GetClassName() const;
private:

};

#endif	/* _RESOURCE_H */

