#include <iostream>
#include <stdio.h>

    
    int val = 0;
    char key = 0;
    int op;
    
void fetch();
void decode();
void execute();
void store();

    
void fetch()
{
	std::cin.get(key);
}

void decode()
{
	if(key != '\n'){
		std::cout << "processing: " << key << std::endl;
		
		//is key + or -
		if(key == '+'){
			op = 0;
	    }

		if(key == '-'){
			op = 1;
		}
}
}

void execute()
{
	if(key == 0){
			std::cout << "Display: " << val << std::endl;
		}
		//doadd or  dosub
	if(key != '\n')
	{	
		if(key != '+' && op != 1){
			val = val + (key - '0');
				key = 0;
			}
		if(key != '-' && op != 0){
			val = val - (key - '0');
			if(val <= 0) val = 0;
				key = 0;
     		}
     	}
}

void store()
{
	if(key != '\n')
	std::cout << "Display: " << val << std::endl;
}


int main ()
{
	
	
	
	while (true){

		fetch();
		
		decode();
		
		execute();
		
		store();
		
     }
		}
	
