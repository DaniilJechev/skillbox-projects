#include <iostream>

int main (){
    float deltaF;
    char del[4], speed[4];
    do{
        std::cout << "\nEnter yout delta: ";
        std::cin >> deltaF;
        std::sprintf(del, "%.2f", deltaF);
        std::sprintf(speed, "%.1f", atof(speed) + atof(del));
        std::cout << std::endl << "Your speed = " << speed;
    } while (atof(speed) >= 0 && atof(speed) <= 150);
   
    if (atoi(speed) > 150) std::cout << std::endl << "You crashed";
    else std::cout << std::endl << "You stalled";
}