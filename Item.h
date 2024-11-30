#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

/**
 * @class Item: represents an item with a specific name that can be held in 
 * an inventory.
 */
class Item 
{
    public:
        /**
         * Item constructor: constructs an item with a specific name.
         * @param name - string - the name of the item.
         */
        Item(const string& name);
        /**
         * getName function: retrieves the name of the item.
         * @return name - string - the item's name.
         */
        string getName() const;

    private:
        string name;
};

#endif
