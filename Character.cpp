#include "Character.h"
#include "Location.h"
#include "Inventory.h"
#include <iostream>

Character::Character(const string& name, 
                     Location* currentLocation, 
                     const string& description)
    : name(name), currentLocation(currentLocation), description(description) 
{}

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

void Character::takeItem(const string& itemName, Location* location) 
{
    Item* item = location->getInventory().getItem(itemName);
    if (item) 
    {
        location->getInventory().removeItem(item);
        inventory.addItem(item);
        cout << name << " took the " << item->getName() << "." << endl;
    } 
    else 
    {
        cout << "Item not found in location." << endl;
    }
}

void Character::dropItem(const string& itemName, Location* location) 
{
    Item* item = inventory.getItem(itemName);
    if (item) 
    {
        inventory.removeItem(item);
        location->getInventory().addItem(item);
        cout << name << " dropped the " << item->getName() << "." << endl;
    } 
    else 
    {
        std::cout << "Item not found in inventory." << endl;
    }
}

void Character::showInventory() const 
{
    cout << name << " ";
    inventory.showInventory();
}

vector<Item*> Character::getInventory() const
{
    return inventory.getInventoryItems();
}

string Character::respondToGreeting(const string& greeting) const 
{
    if (greeting == "Hi") 
    {
        return "Hello!";
    }
    if (greeting == "Hello") 
    {
        return "Hi!";
    }
    return "Nah"; 
}

string Character::describeSelf() const 
{
    return description;
}

