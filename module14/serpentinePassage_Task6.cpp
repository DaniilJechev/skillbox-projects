#include <iostream>
#include <vector>
#include <iomanip>

void resultPrint (std::vector<std::vector<int>> const& vec)
{
    for (int i = 0; i < vec.size(); i ++){
        for (int j = 0; j < vec[0].size(); j ++){
            std::cout << std::setw(3) << vec[i][j] ;
        }
        std::cout << std::endl;
    }
}

int main ()
{
    std::vector <std::vector<int>> vec (5, std::vector <int>(5));
    int number = 0, multiplayer = 1;

    for (int i = 0; i < 5; i ++){
        for (int j = (multiplayer == 1) ?  0 : 4; j != ((multiplayer == 1) ?  5 : -1); j += multiplayer){
            vec[i][j] = number;
            number++;
        }
        multiplayer *= -1;
    }

    resultPrint(vec);
}