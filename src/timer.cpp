#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <unistd.h>
#include "../include/game_help.hpp"
#include "../include/globals.hpp"



void print_timer() 
{ 	 
    gotoxy(40,28);
	
	std :: cout << "\033[1;36m      TIMER\n\033[0m";	 
	gotoxy(40,29);
	std :: cout << "\033[1;31m" << hour << " hrs \033[0m" << "\033[1;34m" << min << " min \033[0m" << "\033[1;33m" << sec << " sec \033[0m\n";
	
}

void timer() 
{  
	while (play == true) 
    { 
		print_timer(); 
		sleep(1);
		++sec; 

		if (sec == 60) 
        { 
			++min; 			
			if (min == 60) 
            { 		
				++hour; 
				min = 0; 
			} 
			sec = 0; 
		} 
	} 
} 


