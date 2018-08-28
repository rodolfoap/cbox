#include "solid.h"

/**
 * The function setter
 * @param[in]  aName The name as input.
 */
void Solid::setName(std::string aName) {
    this->name=aName;
}

/**
 * The function setter
 * return The object name.
 */
std::string Solid::getName(){
    return this->name;
}
