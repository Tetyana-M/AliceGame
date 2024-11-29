#include "Action.h"
#include <iostream>

Action::Action(const string& newName, const string& newTarget)
{
    name = newName;
    target = newTarget;        
}
string Action::getName() const 
{ 
    return name; 
}
string Action::getTarget() const 
{ 
    return target; 
}