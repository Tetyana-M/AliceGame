#include "Character.h"
#include "Location.h"
#include <iostream>

Character::Character(const string& name, Location* startingLocation)
    : name(name), currentLocation(startingLocation) {}

string Character::getName() const 
{
    return name;
}

Location* Character::getCurrentLocation() const 
{
    return currentLocation;
}

void Character::setCurrentLocation(Location* location) 
{
    currentLocation = location;
}

void Character::interact() const {
    cout << name << " interacts with you." << std::endl;
}
