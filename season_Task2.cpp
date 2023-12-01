#include <iostream>

#define CURRENTSEASON 0

#define WINTER 0
#define SPRING 1
#define SUMMER 2
#define AUTUMN 3

int main()
{

#if CURRENTSEASON == WINTER
    std::cout << "Winter";
#elif CURRENTSEASON == SPRING
    std::cout << "Spring";
#elif CURRENTSEASON == SUMMER
    std::cout << "Summer";
#elif CURRENTSEASON == AUTUMN
    std::cout << "Autumn";
#endif

}