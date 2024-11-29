#ifndef ACTION_H
#define ACTION_H

#include <iostream>
#include <string>

using namespace std;

/**
 * @class Action: represents an action that a character can take.
 */
class Action 
{
    public:
        /**
         * Action constructor: constructs an Action object with the 
         * specified name and target.
         * @param name - string - The name of the action.
         * @param target - string - The target of the action.
         */
        Action(const string& newName, const string& newTarget);
        /**
         * getName function: retrieves the name of the action.
         * @return name - string - The name of the action.
         */
        string getName() const;
        /**
         * getTarget function: retrieves the target of the action.
         * @return target - string - The name of the target of the action.
         */
        string getTarget() const;
    private:
        string name;
        string target;
};

#endif
