#include "../include/Mem8.h"
#include <fstream>
#include <iostream>
#include <sstream>

//constructors
Mem8::Mem8(int num) : MADDR(0), Din(0b00000000), Dout(0b00000000), READ(true), SIZE(num) { //constructor initializes everything
	MEM = new uint8_t[SIZE];
	for (int i = 0; i < SIZE; i ++){
		MEM[0] = 0b00000000;
	}
}

Mem8::~Mem8(){ //deconstructor
	delete[] MEM; //free up memory used by array
}

//accessors
uint8_t Mem8::get_Data() const {
	return Dout; //retrieve data sitting on out pin
}

//mutators
void Mem8::set_MADDR(uint8_t addr){
	MADDR = addr; //set address to be used
}

void Mem8::set_Din(uint8_t input){
	Din = input; //place the input data on the in pin
}

void Mem8::set_READ(bool setRead){
	READ = setRead; //set to read or write
}

void Mem8::tick(){
	if (READ == true){
		Dout = MEM[MADDR]; //send data to out pin from specified address
	}
	else{
		MEM[MADDR] = Din; //take data from in pin and write to specified address
	}
}

void Mem8::load(std::string file){
	std::string line;
	std::ifstream fin;
	fin.open(file, std::ios::in);

	if(fin.is_open()) {
		set_READ(false);

       	 	while(!fin.eof()) {
            		fin >> line;
			int len = line.size();
			std::cout << line << std::endl;
			std::string bytes = line.substr(1,2);
			std::cout << "Byte count: " << bytes << std::endl;

			std::string offset = line.substr(3,4);
			std::cout << "Offset: " << offset << std::endl;

			std::string record = line.substr(7,2);
			std::cout << "Record Type: " << record << std::endl;

			std::string data = line.substr(9, len-11);
			std::cout << "Record data: " << data << std::endl;

			std::string check = line.substr(len-2,2);
			std::cout << "Checksum: " << check << std::endl;
			
			std::string addr = "0x" + offset; //here the only way to load the data is to convert it
			int iaddr = std::stoi (addr,nullptr,16);
			set_MADDR(iaddr);

			std::string datastr = "0x" + data;
			int idatastr = std::stoi (datastr,nullptr,16);
			set_Din(idatastr);
			
			tick();
		}
	}
	else
		std::cout << "error reading file" << std::endl;
}
