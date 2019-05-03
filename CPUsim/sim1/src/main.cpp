#include <iostream>
#include "Component.h"

int main( int argc, char *argv[] ) {
    std::cout << "attiny85sim (v0.4.0)" << std::endl;
    std::cout << "running ..." << std::endl;

    // create required components
    Component c1("X",5), c2("Y",0);

    // make the data move
    int data = c2.write(c1.read());

    std::cout << c1.get_name() << "->(" << data <<
    ")->" << c2.get_name() << std::endl;

    std::cout << "done!" << std::endl;
}
