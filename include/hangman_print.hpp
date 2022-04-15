#ifndef HANGMAN_PRINT_HPP
#define HANGMAN_PRINT_HPP


void print_about();
void print_records();

/*
*    Brief: prints big "HANGMAN" with *
*/
void print_hangman();

/*
*   Brief: prints green win with *,if you guess all words for that level
*/
void print_win();

/*
*    Brief: prints red lose with *,if you cant guess the word
*/
void print_lose();

/*
*   Brief:  you did 0 mistakes yet
*/
void print_full_life();

/*
*   Brief: You did 1 mistake,your head and neck are hanging
*/
void print_life_1();

/*
*   Brief: You did 2 mistakes,your head,neck and body are hanging   
*/
void print_life_2();

/*
*   Brief: You did 3 mistakes, hands are hanging too
*/
void print_life_3();

/*
*   Brief: You did 4 mistakes,game over!!  
*/
void print_dead();

#endif //HANGMAN_PRINT_HPP