#include "Location.h"
#include <iostream>
#include <string>
#include <algorithm>

Location::Location(const string& name, const string& description) 
    : name(name), description(description) {}

void Location::describe() const 
{
    cout << "You are in " << name << "." << endl;
}

string Location::getDescription()const
{
    return description;
}

void Location::addExit(const string& direction, Location* location) 
{
    exits[direction] = location;
}

Location* Location::getExit(const std::string& direction) 
{
    return exits.count(direction) ? exits[direction] : nullptr;
}

string Location::getName() const
{
    return name;
}

void Location::addCharacter(Character* character) 
{
    characters.push_back(character);
}

void Location::removeCharacter(Character* character) 
{
    characters.erase(remove(characters.begin(), characters.end(), character), 
                     characters.end());
}

vector<Character*> Location::getCharacters() const 
{
    return characters;
}

Inventory& Location::getInventory()
{
    return inventory;
}

void Location::showInventory()
{
    cout << name << " ";
    inventory.showInventory();
}

vector<string> Location::getExits()
{
    vector<string> allExits;
    for (auto it = exits.begin(); it != exits.end(); ++it)
    {
        allExits.push_back((*it).first);
    } 
    return allExits;
}

void Location::showCharacters()
{
    for (auto it = characters.begin(); it != characters.end(); ++it)
    {
        cout << (*it)->getName() << endl;
    } 
}
