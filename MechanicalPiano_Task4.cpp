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

bool isAllowed (int sound)
{
    return (sound < 1 || sound > 7);
}

void melodyPrint (int sound)
{
        if (sound == note::DO) std::cout << "Do ", Sleep(200);
        if (sound == note::RE) std::cout << "RE ", Sleep(200);
        if (sound == note::MI) std::cout << "MI ", Sleep(200);
        if (sound == note::FA) std::cout << "FA ", Sleep(200);
        if (sound == note::SOL) std::cout << "SOL ", Sleep(200);
        if (sound == note::LA) std::cout << "LA ", Sleep(200);
        if (sound == note::SI) std::cout << "SI ", Sleep(200);
        std::cout << std::endl;
}

int main()
{
    int sound;
    std::vector <int> melody;
    while (melody.size() < 12){
        std::cout << std::endl << "Enter new combination: ";
        std::cin >> sound;
        if (isAllowed(sound)){
            std::cout << "Wrong combination!" << std::endl ;
            continue;
        }
        melody.push_back(1 << sound - 1);
    }


    std::cout << "Melody start!" << std:: endl ;

    for (int i = 0;; i++){
        if (i % 12 == 0) std::cout << std::endl;
        melodyPrint(melody[i % 12]);
        Sleep(300);
    }
}