#include "Item.h"

Item::Item(const string& name) : name(name) {}

string Item::getName() const 
{
    return name;
}
