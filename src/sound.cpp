#include <iostream>

void sound_on()
{
	std :: cout << "\033[1;35m\n\n\n\n\t\t\t\tGAME\n" << "\t\t\t\tRECORDS\n" << "\t\t\t\tRESET\n\033[0m";
	std :: cout << "\033[1;32m\t\t\t\t➢SOUND OFF\033[0m \n" << "\033[1;35m\t\t\t\tABOUT\n" << "\t\t\t\tQUIT\n\033[0m";
}

void sound_off()
{
	std :: cout << "\033[1;35m\n\n\n\n\t\t\t\tGAME\n" << "\t\t\t\tRECORDS\n" << "\t\t\t\tRESET\n\033[0m";
	std :: cout << "\033[1;32m\t\t\t\t➢SOUND ON\033[0m \n" << "\033[1;35m\t\t\t\tABOUT\n" << "\t\t\t\tQUIT\n\033[0m";
}