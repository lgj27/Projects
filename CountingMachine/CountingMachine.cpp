#include <iostream>
#include <stdio.h>

    
    int val = 0;
    char key = 0;
    int op;
    
    
void add(char k)
{
	val = val + (k - '0');
	printf("Display: %d\n", val);
}

void sub(char k)
{
	val = val - (k - '0');
	printf("Display: %d\n", val);
}


int main ()
{
	
	
	
	while (true){

	    
		std::cin.get(key);
		
		if(key != '\n'){
		std::cout << "processing: " << key << std::endl;
		
		//is key + or -
		if(key == '+'){
			op = 0;
		std::cout << "Display: " << val << std::endl;
	    }

		if(key == '-'){
			op = 1;
		std::cout << "Display: " << val << std::endl;
		}
		
		//test for zero
		if(key == 0){
			std::cout << "Display: " << val << std::endl;
		}
		//doadd or  dosub
		
		if(key != '+' && op != 1){
				add(key);
				key = 0;
			}
		if(key != '-' && op != 0){
				sub(key);
				key = 0;
     		}
     	//key = 0;
     	
     }
		}

	
}
	
		
