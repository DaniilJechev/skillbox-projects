#include <iostream>

#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define SUNDAY 7

int main()
{
    int weekDay;
    std::cout << "Enter the num of week day: ";
    std::cin >> weekDay;

    if (weekDay == MONDAY){
        std::cout << std::endl << "Monday";
    }else if (weekDay == TUESDAY){
        std::cout << std::endl << "Tuesday";
    }else if (weekDay == WEDNESDAY){
        std::cout << std::endl << "Wednesday";
    }else if (weekDay == THURSDAY){
        std::cout << std::endl << "Thursday";
    }else if (weekDay == FRIDAY){
        std::cout << std::endl << "Friday";
    }else if (weekDay == SATURDAY){
        std::cout << std::endl << "Saturday";
    }else if (weekDay == SUNDAY){
        std::cout << std::endl << "Sunday";
    }else std::cout << std::endl << "Error input";
}