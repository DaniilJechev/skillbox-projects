#include <iostream>
#include <vector>
#include <windows.h>

enum note
{
    DO = 1, 
    RE = 2, 
    MI = 4, 
    FA = 8, 
    SOL = 16, 
    LA = 32, 
    SI = 64
};

bool isAllowed (int combination)
{
    return !(combination <= 127 && combination >= 0);
}

int main()
{
    int combination;
    std::vector <int> melody;
    while (melody.size() < 12){
        std::cout << std::endl << "Enter new combination: ";
        std::cin >> combination;
        if (isAllowed(combination)){
            std::cout << std::endl << "Wrong combination!";
            continue;
        }
        melody.push_back(combination);
    }


    std::cout << "Melody start!";

    for (int i = 0;; i++){
        std::cout << std::endl; // add the melody print with sleep. Array is ready.
        Sleep(1200);
    }
}