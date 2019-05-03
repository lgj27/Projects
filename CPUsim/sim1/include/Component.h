#pragma once
#include <string>

class Component {
    public:
        Component(std::string n, int val);     // constructor
        int write(int);      // to outside
        int read(void) const;
	      std::string get_name(void) const;
    private:
        int data;
	      std::string name;
};
