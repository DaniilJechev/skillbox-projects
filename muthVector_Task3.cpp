#include <iostream>
#include <vector>
#include <cmath>

struct muthVector{
    double cordX = 0;
    double cordY = 0;
};

enum commands{
    summ = 1,
    subtract,
    scale,
    length,
    normalize
};

void vec_sum(muthVector& first, muthVector& second)
{    
    std::cout << "Xcord = " << first.cordX + second.cordX << std::endl;
    std::cout << "Ycord = " << first.cordY + second.cordY;
}

void vec_subtract(muthVector& first, muthVector& second)
{    
    std::cout << "Xcord = " << first.cordX - second.cordX << std::endl;
    std::cout << "Ycord = " << first.cordY - second.cordY;
}

double vec_length(muthVector& first, muthVector& second, bool writeResult = true)
{
    double delta_X = second.cordX - first.cordX;
    double delta_Y = second.cordY - first.cordY;
    double length = sqrt(pow(delta_X, 2) + pow(delta_Y, 2));
    if (writeResult) std::cout << "Vector length = " << length;
    return length;
}

double vec_scale(double length, double multiplier, bool writeResult = true)
{
    double scaledVec = length * multiplier;
    if (writeResult) std::cout << "Result = " << scaledVec;
    return scaledVec;
}

void vec_normalize(muthVector& first, muthVector& second)
{
    double length = vec_length (first, second, false);
    std::cout << "Result = " << vec_scale(length, 1/length, false);
}

bool is_incorrect(int command){

    return (command != commands::length && command != commands::normalize &&
            command != commands::scale && command != commands::subtract &&
            command != commands::summ);
}

void coord_Input(muthVector& first, muthVector& second)
{
    std::cout << std::endl << "Input first x, y coordinates: ";
    std::cin >> first.cordX >> first.cordY;
    std::cout << std::endl << "Input second x, y coordinates: ";
    std::cin >> second.cordX >> second.cordY;
}


int main()
{
    int command;
    muthVector firstVec, secondVec;

    std::cout << "Avalibale commands:\n" 
              << "1.Vectors summ\n" 
              << "2.Vectors subtract\n"
              << "3.Vectors scale\n"
              << "4.Vectors length\n"
              << "5.Vectors normalize\n"
              << "Please, Enter the number of your command: ";
    std::cin >> command;

    while (is_incorrect(command)){
        std::cout << std::endl << "Incorrect command, enter new please: ";
        std::cin >> command;
    }
    
    if (command == commands::summ){
        coord_Input(firstVec, secondVec);
        vec_sum(firstVec, secondVec);

    }else if (command == commands::subtract){
        coord_Input(firstVec, secondVec);
        vec_subtract(firstVec, secondVec);

    }else if (command == commands::scale){
        coord_Input(firstVec, secondVec);
        int multiplier;
        std::cout << std::endl << "Enter the multiplier: ";
        std::cin >> multiplier;
        vec_scale(vec_length(firstVec, secondVec), multiplier);
    }else if (command == commands::length){
        coord_Input(firstVec, secondVec);
        vec_length(firstVec, secondVec);
    }else{
        coord_Input(firstVec, secondVec);
        vec_normalize(firstVec, secondVec);
    }
}