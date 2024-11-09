#include "Inventory.h"
#include <iostream>

void Inventory::addItem(Item* item) {
    items.push_back(item);
}

void Inventory::showInventory() const {
    std::cout << "Inventory: ";
    for (const auto& item : items) {
        std::cout << item->getName() << " ";
    }
    std::cout << std::endl;
}
