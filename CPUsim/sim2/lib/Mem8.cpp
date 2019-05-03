#include "../include/Mem8.h"

Mem8::Mem8(int num) : MADDR(0), Din(0b00000000), Dout(0b00000000), READ(true), SIZE(num) { //constructor initializes everything
	MEM = new uint8_t[SIZE];
	for (int i = 0; i < SIZE; i++)
		MEM[i] = 0b00000001 + i;
}

Mem8::~Mem8() { //destructor
	delete[] MEM; //free up memory used by array
}

//accessors
uint8_t Mem8::get_Data() const {
	return Dout; //retrieve data sitting on out pin
}

int Mem8::get_MADDR() const {
	return MADDR;
}

//mutators
void Mem8::set_MADDR(int addr) {
	if (addr > SIZE)
		addr = 0;
	MADDR = addr; //set address to be used
}

void Mem8::set_Din(uint8_t input) {
	Din = input; //place the input data on the in pin
}

void Mem8::set_READ(bool setRead) {
	READ = setRead; //set to read or write
}

void Mem8::tick() {
	if (READ == true) {
		Dout = MEM[MADDR]; //send data to out pin from specified address
	}
	else {
		MEM[MADDR] = Din; //take data from in pin and write to specified address
	}
}
