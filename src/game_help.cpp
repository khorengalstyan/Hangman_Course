#include <iostream>


void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

void wrong_array(int wrong_index, char * wrong_letter)
{
	std :: cout << "\033[1;31mWrong letters` \033[0m";
	for (int i = 0; i < wrong_index; ++i)
	{
		std :: cout << " " << "\033[1;31m" << wrong_letter[i] << "\033[0m";
	}
}

