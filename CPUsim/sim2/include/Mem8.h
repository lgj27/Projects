#include <bitset>
#include <cstdlib>
#include <stdint.h>

class Mem8 {
	private:
		int MADDR;
		uint8_t Din;
		uint8_t Dout;
		bool READ;
		int SIZE;
		uint8_t *MEM;
	public:
		//constructors
		Mem8(int num);
		~Mem8();
		//accessors
		uint8_t get_Data() const;
		int get_MADDR() const;
		//mutatos
		void set_MADDR(int addr);
		void set_Din(uint8_t input);
		void set_READ(bool setRead);
		void tick();
};
