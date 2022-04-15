#include <fstream>
#include <iostream>
#include <limits>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <thread>

#include "../include/game.hpp"
#include "../include/hangman_print.hpp"
#include "../include/input.hpp"
#include "../include/loader.hpp"
#include "../include/records.hpp"
#include "../include/switch.hpp"
#include "../include/sound.hpp"
#include "../include/timer.hpp"
#include "../include/about.hpp"
#include "../include/globals.hpp"

void menu(bool deleting_record, bool is_not_empty, bool sound)
{	
	const int menu_size = 6;
	short int menu_point=1;
	const int ENTER = 10;
	const int SPACE = 32;
	const int DOWN = 66;
	const int UP = 65;		
	bool menu_cycle = true;
	system("clear");
	switch_menu(menu_point,sound);
	cbreak();
	
   
	while (menu_cycle == true)
	{	  
		const int key = keypress();		 
		switch(key)
		{	
			case DOWN:
			{
				++menu_point;
				if (menu_point == menu_size + 1)
				{
					menu_point = 1;
				}
				switch_menu(menu_point, sound);
				break;
			}

			case UP:
			{
				--menu_point;
				if (menu_point == 0 || menu_point == -1)
				{
					menu_point = 6;
				}
				switch_menu(menu_point, sound);
				break;
			}

			case ENTER:
			{ 
				if (menu_point == 1)
				{ 
					hour = 0;
					min = 0;
					sec = 0; 
					if (sound == true) 
					{
						std :: cout << "\a";
					}		
					is_not_empty = true;
					if (deleting_record == true)
					{
						std :: fstream records_file;
						records_file.open("txt/records.txt", std :: ios :: out | std :: ios :: trunc);
					}		
					deleting_record = false;
					system("clear");
					game(sound);  
					break;
				}

				if (menu_point == 2)   
				{ 
					if (sound == true) 
					{
						std :: cout << "\a";
					}	   
					system("clear");			
					deleting_record == false ? records(is_not_empty) : no_records();		
					break;
				}  

				if (menu_point == 3)
				{
					if (sound == true) 
					{
						std :: cout << "\a";
					}	   
					delete_records(deleting_record, is_not_empty, sound);
					break;
				}

				if (menu_point == 4)
				{
					if (sound == true) 
					{
						std :: cout << "\a";
					}	   
					system("clear");
					print_hangman();
					if (sound == true) 
					{
						sound_off();
						sound = false;
					}
					else 
					{
						sound = true;
						sound_on();
					}
					break;
				}

				if (menu_point == 5)
				{
					if (sound == true)
					{
						std :: cout << "\a";
					}
					system("clear");
					print_about();
					about();
					break;
				}


				if (menu_point == 6) 
				{
					if (sound == true) 
					{
						std :: cout << "\a";
					}	   
					std :: fstream records_file;
					if (deleting_record == true)
					{
						records_file.open("txt/records.txt", std :: ios :: out | std :: ios :: trunc);	
					}
					return;
				}
			}
			
			case SPACE:
			{
				if (sound == true)
				{
					std :: cout << "\a";
				}
				menu_cycle = false;
				menu(deleting_record,is_not_empty,sound);
			}	
		}	
	}	
}	

int main()
{  
	std :: cout << "\033[1;41m\033[0m";	
	bool sound = false;
	bool is_not_empty = false;
	bool deleting_record = true;
	std :: string players_records;
	std :: fstream records_file;
	records_file.open("txt/records.txt");	
	while (getline(records_file, players_records))
	{ 
		deleting_record = false;  
		is_not_empty = true; 
	}

	if (is_not_empty == true)
	{
		load_time();
	}
	menu(deleting_record,is_not_empty,sound);
	system("clear");
	normal();
	return 0;
}
