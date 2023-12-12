#include <iostream>
#include <ctime>
#include <windows.h>
#include <iomanip>


int main()
{
    tm timer;
    std::cout << "Enter the count of minutes and seconds: ";
    std::cin >> std::get_time(&timer, "%M:%S");

    for (;(timer.tm_min * 60 + timer.tm_sec) != 0;){
        std::cout << std::endl << std::put_time(&timer, "%M:%S");
        Sleep(1000);
        if (timer.tm_sec != 0) timer.tm_sec--;
            else{
                timer.tm_sec = 59;
                timer.tm_min-= 1;
            }
    }
    std::cout << std::endl << "DING! DING! DING!";
}