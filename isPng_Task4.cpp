#include <iostream>
#include <fstream>

bool PNGcheck(char (&first3Letters)[3])
{
    std::string PNG = "PNG";
    for (int i = 0; i < 3; i ++){
        if (PNG[i] != *(first3Letters + i)) return false;
    }
    return true;
}

int main()
{
    std::ifstream file;
    std::string puth;

    char first3Letters[3], firstNum;


    while (!file.is_open()){
        std::cout << "Enter a relative or direct path to your file (use double slash // if you have slash in puth): " << std::endl;
        std::cin >> puth;
        file.open(puth, std::ios::binary);
        if (!file.is_open()) std::cout << "Error puth, try again" << std::endl;
    }

    file.read(&firstNum, sizeof(char));
    file.read((char*)&first3Letters, sizeof(char) * 3);

    if((int)firstNum == -119 && PNGcheck(first3Letters)){
        std::cout << "Thats a PNG image!";
    }else std::cout << "Thats not a PNG image";


    file.close();
}