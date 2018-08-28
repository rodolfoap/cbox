#include <iostream>

#ifndef SOLID_H_INCLUDED
#define SOLID_H_INCLUDED

/**
 * A simple solid class
 */
class Solid{

protected:
/*@{*/
    std::string name; /**< the name of the object */
/*@}*/
public:
/*@{*/
    void setName(std::string aName);    /**< the setter */
    std::string getName();              /**< the getter */
/*@}*/
};

#endif
