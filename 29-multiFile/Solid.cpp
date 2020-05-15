#include<iostream>
#include "Solid.h"

std::string Solid::getName() const {
	return this->name;
}

void Solid::setName(std::string name) {
	this->name=name;
}
