#include <bitset>
#include <cstdlib>
#include <stdint.h>

class Mem8 {
	private:
		uint8_t MADDR;
		uint8_t Din;
		uint8_t Dout;
		bool READ;
		int SIZE;
		uint8_t *MEM;
	public:
		//constructos
		Mem8(int num);
		~Mem8();
		//accessors
		uint8_t get_Data() const;
		//mutators
		void set_MADDR(uint8_t addr);
		void set_Din(uint8_t input);
		void set_READ(bool setRead);
		void load(std::string file);
		void tick();
};
