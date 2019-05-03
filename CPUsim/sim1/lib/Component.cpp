#include <iostream>
#include "Component.h"

//constructor
Component::Component(std::string n, int val) : data(val), name(n) {}

//accessors
int Component::read(void) const {
    return data;
}

std::string Component::get_name( void ) const {
	return name;
}

//mutators
int Component::write(int val) {
    data = val;
    return data;
}
