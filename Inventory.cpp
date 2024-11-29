#include "Inventory.h"
#include <iostream>
#include <algorithm>

void Inventory::addItem(Item* item) 
{
    items.push_back(item);
}

void Inventory::removeItem(Item* item) 
{
    items.erase(remove(items.begin(), items.end(), item), items.end());
}

Item* Inventory::getItem(const string& itemName) const 
{
    for (Item* item : items) 
    {
        if (item->getName() == itemName) 
        {
            return item;
        }
    }
    return nullptr;
}

void Inventory::showInventory() const 
{
    cout << "inventory: ";
    for (auto it = items.begin(); it != items.end(); ++it) 
    {
        cout << (*it)->getName();
        if (std::next(it) != items.end()) 
        {
            cout << ", ";
        }
    }
    cout << "." << endl;
}

vector<Item*> Inventory::getInventoryItems() const
{
    return items;
}