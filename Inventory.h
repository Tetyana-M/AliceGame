#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>
#include "Item.h"

using namespace std;

/**
 * @class Inventory: manages a collection of items, allowing addition, demoval,
 * and display of items.
 */
class Inventory 
{
    public:
        /**
         * addItem function: adds an item to the inventory.
         * @param item - Item* - the item to add.
         */
        void addItem(Item* item);
        /**
         * removeItem function: removes an item from the inventory.
         * @param item - Item* - the item to remove.
         */
        void removeItem(Item* item);
        /**
         * getItem funciton:  retrieves an item by name from the inventory, if present.
         * @param itemName - string - the name of the item to retrieve.
         * @return item - Item* - pointer to the item if found, nullptr otherwise.
         */
        Item* getItem(const string& itemName) const;
        /**
         * showInventory function: displays all items currently in the inventory.
         */
        void showInventory() const;
        /**
         * getInventoryItems function: retrieves items stored in the inventory.
         * @return items - vector<Item*> - items stored in the inventory.
         */
        vector<Item*> getInventoryItems() const;

    private:
        vector<Item*> items;
};

#endif
