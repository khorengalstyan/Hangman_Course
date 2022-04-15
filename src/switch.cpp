#include <iostream>
#include "../include/hangman_print.hpp"
#include "../include/sound.hpp"
#include "../include/game_help.hpp"
#include "../include/globals.hpp"


void switch_menu(short int menu_point, bool sound)
{
	switch(menu_point)
	{
		case 1:				
		{			
			std :: cout << "\e[8;24;72t";
			if (sound == true) 
			{
				std :: cout << "\a";
			}  
			system("clear");
			print_hangman();
		   
			std :: cout << "\033[1;32m\n\n\n\n\t\t\t\t➢GAME\033[0m\n";
			std :: cout << "\033[1;35m\t\t\t\tRECORDS\n" << "\t\t\t\tRESET\n" << "\t\t\t\tSOUND\n"<< "\t\t\t\tABOUT\n" << "\t\t\t\tQUIT\n\033[0m";
			break;
		}
		

		case 2:	
		{
			std :: cout << "\e[8;24;72t";
			if (sound == true) 
			{
				std :: cout << "\a";
			}
			system("clear");
			print_hangman();
			std :: cout << "\033[1;35m\n\n\n\n\t\t\t\tGAME\n\033[0m" << "\t\t\t\t\033[1;32m➢RECORDS\033[0m\n" << "\033[1;35m\t\t\t\tRESET\033[0m\n";
			std :: cout << "\033[1;35m\t\t\t\tSOUND\n" << "\t\t\t\tABOUT\n" <<"\t\t\t\tQUIT\n\033[0m";
			break;
		}

		case 3:
		{
			std :: cout << "\e[8;24;72t";
			if (sound == true) 
			{
				std :: cout << "\a";
			}
			system("clear");
			print_hangman();
			std :: cout << "\033[1;35m\n\n\n\n\t\t\t\tGAME\n" << "\t\t\t\tRECORDS\n\033[0m" << "\t\t\t\t\033[1;32m➢RESET\033[0m\n";
			std :: cout << "\033[1;35m\t\t\t\tSOUND\n" << "\t\t\t\tABOUT\n" << "\t\t\t\tQUIT\033[0m\n";
			break;
		}

		case 4:
		{	
			std :: cout << "\e[8;24;72t";
			if (sound == true) 
			{
				std :: cout << "\a";
			}
			system("clear");
			print_hangman();
			sound == true ? sound_on() : sound_off();
			break;
		}
		case 5:
		{
			std :: cout << "\e[8;24;72t";
			if (sound == true) 
			{
				std :: cout << "\a";
			}
			system("clear");
			print_hangman();
			std :: cout << "\033[1;35m\n\n\n\n\t\t\t\tGAME\n" << "\t\t\t\tRECORDS\n" << "\t\t\t\tRESET\033[0m\n";
			std :: cout << "\033[1;35m\t\t\t\tSOUND\033[0m\n" << "\033[1;32m \t\t\t\t➢ABOUT\033[0m\n" << "\033[1;35m\t\t\t\tQUIT\033[0m\n";
			break;
		}

		case 6:		
		{
			std :: cout << "\e[8;24;72t";
			if (sound == true) 
			{
				std :: cout << "\a";
			}
			system("clear");
			print_hangman();
			std :: cout << "\033[1;35m\n\n\n\n\t\t\t\tGAME\n" << "\t\t\t\tRECORDS\n" << "\t\t\t\tRESET\033[0m\n";
			std :: cout << "\033[1;35m\t\t\t\tSOUND\n" << "\t\t\t\tABOUT\033[0m\n" << "\033[1;32m \t\t\t\t×QUIT\033[0m\n";
			break;
		}
	}
}

void switch_hangman(int x)
{

	
	switch(x)
	{	
		case 0:
		{
			//system("clear");
			gotoxy(1,1);
			print_full_life();
			break;
		}	

		case 1:
		{
			//system("clear");
			gotoxy(1,1);
			print_life_1();
			break;
		}

		case 2:
		{
			//system("clear");
			gotoxy(1,1);
			print_life_2();
			break;
		}

		case 3:
		{
			//system("clear");
			gotoxy(1,1);
			print_life_3();
			break;
		}
	}
}
