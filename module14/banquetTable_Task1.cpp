#include <iostream>
#include <vector>
//12th and 11th places - VIP

//Below are all available signs that store specific cutlery for guests.
//0 - chairs
//1 - forks
//2 - spoons
//3 - knifes
//4 - plates 

void resultPrint (std::vector<std::vector<int>> const vec)
{
    for (int i = 0; i < vec.size(); i ++){
        std::cout << i + 1 << " place ";
        for (int j = 0; j < vec[0].size(); j ++){
            std::cout << vec[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::vector <std::vector <int>> cutleries (12, std::vector(5, 1));

    for (int i = 0; i < 12; i ++){
        for (int j = 0; j < 5; j ++){
            if (j == 4 && i < 10){
                cutleries[i][j] = 2;
            }else if (j == 4) {
                cutleries[i][j] = 3;
            }else if (j == 2 && i >= 10){
                cutleries[i][j] = 2;
            }
        }
    }
    cutleries[4][0] = 2;
    cutleries[11][2] = 1;
    cutleries[11][4] = 2;
    
    resultPrint(cutleries);
}