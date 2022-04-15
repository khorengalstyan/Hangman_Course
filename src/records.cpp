#include <iostream>
#include <fstream>
#include "../include/input.hpp"
#include "../include/hangman_print.hpp"
#include "../include/game_help.hpp"

void records_deleted()
{
	print_hangman();
	std :: cout << "\033[1;35m\n\n\n\n\t\t\t\tGAME\n" << "\t\t\t\tRECORDS\n\033[0m" << "\033[1;32m\t\t\t\t➢RESET\033[0m\n";
	std :: cout << "\033[1;35m\t\t\t\tSOUND\n" << "\t\t\t\tABOUT\n" << "\t\t\t\tQUIT\n\n\n\n\n\n\033[0m" << "\033[1;32m\t\t\t   ALL RECORDS DELETED\033[0m\n";
}

void no_records()
{	
	system("clear");
	std :: cout << "\e[8;24;72t";
	print_hangman();
	std :: cout << "\033[1;35m\n\n\n\n\t\t\t\tGAME\n\033[0m" << "\t\t\t\t\033[1;32m➢RECORDS\033[0m\n" << "\033[1;35m\t\t\t\tRESET\033[0m\n";
	std :: cout << "\033[1;35m\t\t\t\tSOUND\n" << "\t\t\t\tABOUT\n" << "\t\t\t\tQUIT\n\n\n\n\n\n\033[0m" << "\033[1;36m\t\t\t       NO RECORDS\033[0m\n";
}

void records(bool is_not_empty)
{
	std :: cout << "\e[8;23;126t";
	std :: string players_records;
	std :: fstream records_file;
	records_file.open("txt/records.txt");	 
	is_not_empty = false;
	print_records();
	std :: cout << "\n\n";
	gotoxy(1,11);
	std :: cout << "\033[1;36m______________________________________________________________________________________________________________________________\033[0m\n";
	gotoxy(1,12);
	std :: cout << "\033[1;33m		NAME		\033[0m"	<< "\033[1;36m|\tSURNAME\033[0m" << "\033[1;36m    |\033[0m" <<"\033[1;34m   SCORE    \033[0m" << "\033[1;36m|\033[0m";
	std :: cout << "\033[1;31m     UNPREDICTED WORD\033[0m";
	gotoxy(101,12);
	std :: cout <<  "\033[1;36m|   TIME\n";	
	std :: cout << "\033[1;4;36m                                                                                                                              \033[0m\n";
	
	while (getline(records_file, players_records))
	{ 
		is_not_empty = true;   
		std :: cout<<"\t\t" << players_records << "\n";
	}	 
	
	if (is_not_empty != true) 
	{
		print_hangman();
		no_records();
	} 
	records_file.close();
}

void delete_records(bool deleting_record, bool is_not_empty, bool sound)
{
	std :: string players_records;
	std :: fstream records_file;
	
	records_file.open("txt/records.txt");	
	std :: string pass;
	deleting_record = true;	
	while (getline(records_file, players_records))
	{ 
		deleting_record = false;
		is_not_empty = true;   
	}
	if (deleting_record == false)
	{
		std :: fstream password_file;
		std :: string password;
		password_file.open("txt/password.txt");
		while (getline(password_file,password))
		{
			pass = password;
		}
		
		normal();
		system("clear");
		print_hangman();
		std :: string parol;
		std :: cout << "\033[1;35m\n\n\n\n\t\t\t\tGAME\n" << "\t\t\t\tRECORDS\n\033[0m" << "\t\t\t\t\033[1;32m➢RESET\033[0m\n";
		std :: cout << "\033[1;35m\t\t\t\tSOUND\n" << "\t\t\t\tABOUT\n" << "\t\t\t\tQUIT\033[0m\n";
		std :: cout << "\n\n\n\n\033[1;36mPlease enter password`\033[0m ";
		
		std :: cout << "\033[1;36m";
		{
			std :: cin >> parol;
		}

	
		std :: cout << "\033[0m";
		if (sound == true)
		{
			std :: cout << "\a";
		}
		if (parol == pass)
		{
			remove("txt/records.txt"); 
			is_not_empty = false;
			deleting_record = true;  
			system("clear");
			records_deleted(); 
			records_file.close();
			cbreak();
		}
		else 
		{
			system("clear");
			print_hangman();
			std :: cout << "\033[1;35m\n\n\n\n\t\t\t\tGAME\n" << "\t\t\t\tRECORDS\n\033[0m" << "\t\t\t\t\033[1;32m➢RESET\033[0m\n";
			std :: cout << "\033[1;35m\t\t\t\tSOUND\n" << "\t\t\t\tABOUT\n" << "\t\t\t\tQUIT\033[0m\n";
			std :: cout << "\n\n\n\n\033[1;31mPassword is wrong.Nothing is changed\033[0m\n";
			cbreak();
		}	 
	}
	else
	{
		if (sound == true)
		{
			std :: cout << "\a";
		}
		system("clear");
		print_hangman();
		std :: cout << "\033[1;35m\n\n\n\n\t\t\t\tGAME\n" << "\t\t\t\tRECORDS\n\033[0m" << "\t\t\t\t\033[1;32m➢RESET\033[0m\n";
		std :: cout << "\033[1;35m\t\t\t\tSOUND\n" << "\t\t\t\tABOUT\n" << "\t\t\t\tQUIT\033[0m\n" << "\n\n\n\n\n\t\t\t\033[1;36m     NOTHING TO DELETE\033[0m\n";
	}
}

