#include "Location.h"
#include <iostream>
#include <string>
#include <algorithm>

//using namespace std;

Location::Location(const string& name, const string& description) 
    : name(name), description(description) {}

void Location::describe() const {
    cout << "You are in " << name << "." << endl;
}

void Location::showInfo() const 
{
    cout << "Name: " << name << endl;
    cout << "Description" << description << endl;
    cout << "Exits: " << exits.size() << endl;
    string allExits;
    for (auto it = exits.begin(); it != exits.end(); ++it)
    {
        cout << (*it).first  << " to " << (*it).second->getName() << endl;
    }
}

void Location::addExit(const string& direction, Location* location) 
{
    exits[direction] = location;
}

Location* Location::getExit(const std::string& direction) 
{
    return exits.count(direction) ? exits[direction] : nullptr;
}

string Location::getName() 
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
