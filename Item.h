#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    Item(const std::string& name);
    std::string getName() const;

private:
    std::string name;
};

#endif
