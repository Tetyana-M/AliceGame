#ifndef ACTION_H
#define ACTION_H

#include <iostream>
#include <string>

using namespace std;

class Action 
{
    public:
        Action(const string& newName, const string& newTarget)
        {
            name = newName;
            target = newTarget;        
        }

        string getName() const { return name; }
        string getTarget() const { return target; }
        void showInfo()
        {
            cout << "name: " << name << endl;
            cout << "target: " << target << endl;
        }

        void execute();
        

    private:
        string name;
        string target;
};

#endif
