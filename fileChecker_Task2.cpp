#include <iostream>
#include <fstream>


int main()
{
    std::string puth;
    std::ifstream file;

    while (!file.is_open()){
        std::cout << "Enter a relative or direct path to your file (use double slash // if you have slash in puth): " << std::endl;
        std::cin >> puth;
        file.open(puth, std::ios::binary);
        if (!file.is_open()) std::cout << "Error puth, try again" << std::endl;
    }

    
    file.seekg(0, std::ios::end);
    int size = file.tellg();
    file.seekg(0);

    char text [size + 1];
    text [size] = 0;
    file.read(text, size);

    std::cout << text;

    file.close();
}