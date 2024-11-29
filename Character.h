#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "Inventory.h"

using namespace std;

class Location;

/**
 * @class Character: represents a character with a name, location, and 
 * inventory of items.
 */
class Character 
{
    public:
        /**
         * Character constructor: constructs an a character with the specified name and 
         * starting location.
         * @param name - string - The name of the character.
         * @param startingLocation - Location - The initial location of the character.
         */
        Character(const string& name, Location* currentLocation, const string& description);
        /**
         * getName function: retrieves the name of the character.
         * @return name - string - The name of the character.
         */
        string getName() const;
        /**
         * getCurrentLocation function: retrieves the character's current location.
         * @return currentLocation - Location* - A pointer to the current location 
         * of the character.
         */
        Location* getCurrentLocation() const;
        /**
         * setCurrentLocation function: updates the character's current location.
         * @param location - Location* - A pointer to the new location for the character.
         */
        void setCurrentLocation(Location* location);
        /**
         * takeItem function: allows the character to take an item from a 
         * location's inventory.
         * @param itemName - string - The name of the item to take.
         * @param location - Location* - A pointer to the location from which 
         * to take the item.
         */
        void takeItem(const string& itemName, Location* location);
        /**
         * dropItem function: allows the character to drop an item into a 
         * location's inventory.
         * @param itemName - string - The name of the item to drop.
         * @param location - Location* - A pointer to the location into which 
         * to drop the item.
         */
        void dropItem(const string& itemName, Location* location);
        /**
         * showInventory function: displays all items currently in the 
         * character's inventory.
         */
        void showInventory() const;
        /**
         * getInventory function: retrieves items in character's inventory.
         * @return vector<Item*> - a collection of pointers to Item objects in 
         * character's inventory.
         */
        vector<Item*> getInventory() const;
        /**
         * @respondToGreeting function: responds with "Hello" if another character says "Hi".
         * @param greeting - string - the greeting received from another character.
         * @return string - the response from this character.
         */
        string respondToGreeting(const string& greeting) const;
        /**
         * describeSelf function: provides a description of the character.
         * @return description - string - a self-description string.
         */
        string describeSelf() const;
    private:
        string name;
        string description;
        Location* currentLocation;
        Inventory inventory;
};

#endif
