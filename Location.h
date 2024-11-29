#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <map>
#include <vector>
#include "Character.h"
#include "Inventory.h"

using namespace std;
/**
 * @class Location: represents a location in the game with exits, 
 * characters, and an inventory.
 */
class Location 
{
    public:
        /** 
         * Location constructor: constructs a location object with the given 
         * name and description.
         * @param name - string - the name of the location.
         * @param description - string - the description of the location.
        */
        Location(const string& name, const string& description);
        /**
         * getName function: retrieves name of the location.
         * @return name - string - the name of the location.
         */
        string getName() const;
        /**
         * getDescription function: retrieves the description of the location.
         * @return description - string- the description of the location.
         */
        string getDescription() const;
        /**
         * decribe function: displays formatted string describing the location.
         */
        void describe() const;
        /**
         * aaddExit function: adds an exit to another location.
         * @param direction - string - the direction of the exit.
         * @param location - Location* - the location that the exit leads to. 
         */
        void addExit(const string& direction, Location* location);
        /**
         * getExit function: retrieves a pointer to the location for a given direction.
         * @param direction - string - the direction of the exit.
         * @return - Location* - pointer to the connected location, or nullptr if no exits exist.
         */
        Location* getExit(const string& direction);
        /**
         * getExits function: retrieves directions for all exits for this location.
         * @return allExits - vector<string> - all exits directions for this location.
         */
        vector<string> getExits();
        /**
         * addCharacter function: adds a character to the location.
         * @param character - Character* - The character to add.
         */
        void addCharacter(Character* character);
        /**
         * removeChracter function: removes a character from the location.
         * @param character - Character* - The character to remove.
         */
        void removeCharacter(Character* character);
        /**
         * getCharacters function: retrieves all characters present at the location.
         * @return characters - vector<Character*> - a vector of character pointers.
         */
        vector<Character*> getCharacters() const;
        /**
         * showCharacters function: displays all characters present at the location.
         */
        void showCharacters();
        /**
         * getInventory function: retrieves the inventory of items available at the location.
         * @return inventory - Inventory - reference to the location's inventory.
         */
        Inventory& getInventory();
        /**
         * showInventory function: displays formatted output that shows all items 
         * in the location's inventory.
         */
        void showInventory();

    private:
        string name;
        string description;
        map<string, Location*> exits;
        vector<Character*> characters;
        Inventory inventory; 
};

#endif
