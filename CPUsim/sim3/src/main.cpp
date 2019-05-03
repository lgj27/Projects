#include "../lib/Mem8.cpp"

int main (int argc, char *argv[]){
	Mem8 mem8(8); //allocate 8 slots of memory
	
	mem8.load("file.hex");
	
	std::cout << "Memory has been loaded with data..." << std::endl
		  << "Testing read to verify written data..." << std::endl;
	
	for (int i = 0; i < 8; i++){
		std::cout << "Memory Address d" << i << " contains d";
		mem8.set_MADDR(i); 
		mem8.set_READ(true);
		mem8.tick();
		std::cout << unsigned(mem8.get_Data()) << std::endl;
	}
}
