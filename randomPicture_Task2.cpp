#include <iostream>
#include <fstream>
#include <stdlib.h>


int main ()
{
    std::ofstream picture ("randomPicture.txt");
    int width, length;

    std::cout << "Enter width and length of your picture: ";
    std::cin >> width >> length;

    srand(time(NULL));
    for (int i = 0; i < length; i ++){
        for (int j = 0; j < width; j ++){
            picture << rand() % 2;
        }
        picture << std::endl;
    }

    picture.close();
}