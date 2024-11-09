#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"

class Inventory {
public:
    void addItem(Item* item);
    void showInventory() const;

private:
    std::vector<Item*> items;
};

#endif
