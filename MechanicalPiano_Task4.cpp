#include <iostream>
#include <vector>
#include <windows.h>

enum note
{
    DO = 1, 
    RE, 
    MI, 
    FA, 
    SOL, 
    LA, 
    SI
};

bool isAllowed (int combination)
{
    return !(combination <= 7 && combination >= 1);
}

void melodyPrint (int sound){
        if (sound == note::DO) std::cout << "Do ", Sleep(200);
        if (sound == note::RE) std::cout << "RE ", Sleep(200);
        if (sound == note::MI) std::cout << "MI ", Sleep(200);
        if (sound == note::FA) std::cout << "FA ", Sleep(200);
        if (sound == note::SOL) std::cout << "SOL ", Sleep(200);
        if (sound == note::LA) std::cout << "LA ", Sleep(200);
        if (sound == note::SI) std::cout << "SI", Sleep(200);
    std::cout << std::endl;
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


    std::cout << "Melody start!" << std:: endl ;

    for (int i = 0;; i++){
        if (i % 12 == 0) std::cout << std::endl;
        combination = i % 12;
        melodyPrint(melody[combination]);
        Sleep(300);
    }
}