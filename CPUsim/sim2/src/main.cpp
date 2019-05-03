#include "../lib/Mem8.cpp"
//#include "Mem16.cpp"
#include <iostream>

int main (int argc, char *argv[]){
	Mem8 mem8(5); //allocate 5 slots of memory

	std::cout << "Testing read..." << std::endl
		  << "Data should be 1" << std::endl
		  << "Actual data is ";

	mem8.set_MADDR(0); //set to address 0
	mem8.set_READ(true); //set to read
	mem8.tick(); //move the data

	std::cout << unsigned(mem8.get_Data()) << std::endl << std::endl;

	std::cout << "Testing write..." << std::endl;

	mem8.set_MADDR(0); //set to address 0
	mem8.set_Din(0b10000000); //set data to be written
	mem8.set_READ(false); //set to write
	mem8.tick();

	std::cout << "Newly written data should be 128" << std::endl;
	std::cout << "Newly written data actually is ";

	mem8.set_MADDR(0); //set to address 0
	mem8.set_READ(true); //set to read
	mem8.tick(); //move the data

	std::cout << unsigned(mem8.get_Data()) << std::endl;

	std::cout << "Testing read with out of bounds address of 9" << std::endl;
	mem8.set_MADDR(9);
	std::cout << "Current address should roll over to 0" << std::endl
		  << "Current address actually is " << mem8.get_MADDR() << std::endl;
}
