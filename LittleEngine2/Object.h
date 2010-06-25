/* 
 * File:   Object.h
 * Author: youness
 *
 * Created on 21 mai 2010, 20:44
 */

#ifndef _OBJECT_H
#define	_OBJECT_H
#include <string>

class Object {
public:
    Object();
    Object(const Object& orig);
    virtual ~Object();
    virtual std::string GetClassName() const;
};

#endif	/* _OBJECT_H */

