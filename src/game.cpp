#include <cstring>
#include <fstream>
#include <iostream>
#include <limits>
#include <thread>

#include "../include/hangman_print.hpp"
#include "../include/input.hpp"
#include "../include/switch.hpp"
#include "../include/game_help.hpp"
#include "../include/globals.hpp"
#include "../include/timer.hpp"




void game(bool sound)
{
	char wrong_letter[30];
	short int wrong_index = 0;
	std :: cout << "\e[8;30;59t";
	std :: cout << "\033[1;35mREGISTRATION\n";
	score = 0;
	normal();
	std :: cout << "\033[1;36m";
	std :: cout << "Name:";
	std :: cin >> name;
	std :: cout << "\033[0m";
	if (sound == true)
	{
		std :: cout << "\a";
	}
	system("clear");
	std :: cout << "\033[1;35mREGISTRATION\n";
	std :: cout << "\033[1;34m";
	std :: cout << "Surname:";
	std :: cin >> surname;
	std :: cout << "\033[0m";
	if (sound == true)
	{
		std :: cout << "\a";
	} 
	std :: fstream records_file;
	std :: string players_records;
	records_file.open("txt/records.txt", std :: ios :: app);
	
	if (strlen(name) <= 5)
	{
		records_file  << "\033[1;33m" << name << "\033[0m" << "\033[1;36m  \t\t|  \033[0m";
	}
	else 
	{
		records_file  << "\033[1;33m" << name << "\033[0m" << "\033[1;36m  \t|  \033[0m";
	}

	if (strlen(surname) == 1)
	{
		records_file <<  "\033[1;36m " << surname << "\033[0m" << "\033[1;36m     \t   |\033[0m";
	}

	else if (strlen(surname) <= 5 && strlen(surname) != 1)	
	{
		records_file <<  "\033[1;36m " << surname << "\033[0m" << "\033[1;36m  \t   |\033[0m";
	}

	else if (strlen(surname) > 5 && strlen(surname) < 9)
	{
		records_file <<  "\033[1;36m " << surname << "\033[0m " << "\033[1;36m      |\033[0m";
	}
	else 
	{
		records_file <<  "\033[1;36m " << surname << "\033[0m " << "\033[1;36m     |\033[0m";
	}
	
	char letter; 
	std :: string game_words;
	std :: fstream words_file;
	play = true;
	short int random;
	cbreak();	
	std :: thread timer_game(timer);
	timer_game.detach();
	int nice_view = 0;	
	while (play == true)
	{	
		srand(time(NULL));
		words_file.open("txt/words.txt");	
		system("clear");
		short int wrong_count = 0;
		char help[30];
		print_full_life();	
		random = rand() % 78 + 1;
		for (int i = 0; i < random; ++i)
		{
			getline(words_file, game_words);
		}

		if (random < 14) 
		{
			strcpy(help, "sport");
		}

		else if (random >= 14 && random <= 25)
		{
			strcpy(help, "programming language");
		}
		
		else if (random >= 26 && random <= 43)
		{
			strcpy(help, "country");
		}
		else if (random >= 44 && random <= 59)
		{
			strcpy(help, "animal");
		}
		else 
		{
			strcpy(help, "model of car");
		}

		std :: string word = game_words;
		for (int i = 0; i < game_words.length(); ++i)
		{
		   word[i] = '_';
		}
		words_file.close();

		while (wrong_count < 4)
		{
			gotoxy(1,1);
			bool isTrue = false;
			switch_hangman(wrong_count);
			std :: cout << "\033[1;36mIt is  \033[0m" << "\033[1;34m" << help << "\033[0m" << "\n";
			for (int i = 0; i < word.length(); ++i)
			{
				if (word[i] == '_')
				{
					std :: cout << "\033[1;35m" << word[i] << "\033[0m" << " ";
				}
				else 
				{
					std :: cout << "\033[1;32m" << word[i] << "\033[0m" << " ";
				}
			}
			std :: cout << "\n";
			wrong_array(wrong_index, wrong_letter);
			std :: cout << "\n";
			std :: cout << "\033[1;33mguess a letter	\033[0m";
			std :: cin	>> letter;
			if (sound == true)
			{
				std :: cout << "\a";
			}
		   
			for (int i = 0; i < game_words.length(); ++i)
			{
				if (letter == game_words[i])
				{	
					isTrue = true;
					word[i] = letter;	
				}		 
			}

		if (word == game_words)   
		{
			if (sound == true)
			{
				std :: cout << "\a";
			}
			wrong_index = 0; 
			++score;
			break;
			return;
		}

			if (isTrue == false)
			{
				wrong_letter[wrong_index] = letter;
				++wrong_index;
				++wrong_count; 
				switch(wrong_count)
				{	 
					case 1: case 2: case 3: 
					{  
						switch_hangman(wrong_count);
						break;
					}

					case 4:
					{		
 						gotoxy(30,29);
 					    std :: cout << "\033[1;5;35m Tap ENTER to PLAY AGAIN \033[0m" << "\n";                                                                                                                  
					}
							 
						nice_view += game_words.length();

						records_file << "\033[1;34m     " << score << "\033[0m" << "\033[1;36m  \t|\033[0m"; 
						records_file << "\033[1;31m  " << game_words  << "\033[0m";

						if (nice_view <=3)
						{
							records_file << "\033[1;36m \t\t\t\t    |" << " hour " << hour << " min " << min << " sec " << sec << "\n";
						}	
						if (nice_view > 3 && nice_view <= 12)
						{
							records_file << "\033[1;36m \t\t\t    |" << " hour " << hour << " min " << min << " sec " << sec << "\n";
						}
						if (nice_view > 12 && nice_view <= 20)
						{
							records_file << "\033[1;36m \t\t|" << " hour " << hour << " min " << min << " sec " << sec << "\n";
						}   
						if (nice_view > 20)
						{
							records_file << "\033[1;36m \t|" << " hour " << hour << " min " << min << " sec " << sec << "\n";
						}   
						
						if (sound == true)
						{
							std :: cout << "\a";
						}
						play = false;
						system("clear");
						print_dead();
						print_lose();				  	
						break;
					}			
				}  				
			}	
		}
	}
