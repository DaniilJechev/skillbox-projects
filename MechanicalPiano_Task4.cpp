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

bool symCheck(std::string str)
{
    char comb = str[0];
    if ((comb < 49 || comb > 57) || (comb == ' ')) return true;
    return false;
}

bool isAllowed (std::string combination)
{
    char comb;
    for (int i = 0; i < combination.size(); i ++){
        comb = combination[i];
        if ((comb < 49 || comb > 57) && (comb != ' ')) return false;
    }
    return true;
}

void melodyPrint (std::string soundStr){
    std::string sound;
    for (int i = 0; i < soundStr.size(); i ++){
        sound = soundStr[i];
        if (symCheck(sound)) continue;
        if (std::stoi(sound) == note::DO) std::cout << "Do ", Sleep(200);
        if (std::stoi(sound) == note::RE) std::cout << "RE ", Sleep(200);
        if (std::stoi(sound) == note::MI) std::cout << "MI ", Sleep(200);
        if (std::stoi(sound) == note::FA) std::cout << "FA ", Sleep(200);
        if (std::stoi(sound) == note::SOL) std::cout << "SOL ", Sleep(200);
        if (std::stoi(sound) == note::LA) std::cout << "LA ", Sleep(200);
        if (std::stoi(sound) == note::SI) std::cout << "SI ", Sleep(200);
    }
    std::cout << std::endl;
}

int main()
{
    std::string combination;
    std::vector <std::string> melody;
    while (melody.size() < 12){
        std::cout << std::endl << "Enter new combination: ";
        getline(std::cin, combination);
        if (!isAllowed(combination)){
            std::cout << std::endl << "Wrong combination!";
            continue;
        }
        melody.push_back(combination);
    }


    std::cout << "Melody start!" << std:: endl ;

    for (int i = 0;; i++){
        if (i % 12 == 0) std::cout << std::endl;
        melodyPrint(melody[i % 12]);
        Sleep(300);
    }
}