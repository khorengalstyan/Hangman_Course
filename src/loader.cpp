#include <iostream>
#include <unistd.h>


void loading()
{
    system("clear");
    //std::cout<<"\n\n\n";
    std :: cout << "\033[1;36mLL       OOOOO    AAA   DDDDD   IIIII NN   NN   GGGG\033[0m\n";  
    std :: cout << "\033[1;36mLL      OO   OO  AAAAA  DD  DD   III  NNN  NN  GG  GG\033[0m\n";   
    std :: cout << "\033[1;36mLL      OO   OO AA   AA DD   DD  III  NN N NN GG\033[0m\n";        
    std :: cout << "\033[1;36mLL      OO   OO AAAAAAA DD   DD  III  NN  NNN GG   GG\033[0m\n";   
    std :: cout << "\033[1;36mLLLLLLL  OOOO0  AA   AA DDDDDD  IIIII NN   NN  GGGGGG      \033[0m"; 
}

void load_time()
{
	system("mode 650");

    //std :: cout << "\e[8;6;82t";
    loading();
    std :: cout.flush();
    int load_times = 0;
    int how_many_times = 1;
    while (load_times != how_many_times) 
    {
        ++load_times;
        for (int i = 0; i < 3; ++i) 
        {  
            std :: cout << "\033[1;33mO\033[0m";
            std :: cout.flush();
            sleep(1);
        }
        std :: cout << "\b\b\b   \b\b\b";
    }
}
