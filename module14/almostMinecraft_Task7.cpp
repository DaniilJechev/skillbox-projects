#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
    std::vector <std::vector < std::vector <int>>> field (5, std::vector <std::vector<int>> ( 5 , std::vector<int> (0)));
    int num, maxsize = 0;
    for (int i = 0; i < 5; i ++){
        for (int j = 0; j < 5; j ++){
            std::cout << "Enter the number: ";
            std::cin >> num;
            if (maxsize < num) maxsize = num;
            for (int k = 0; k < num ; k++){
                field[i][j].push_back(1);
            }
        }
    }

    for (int count = 1; count <= maxsize; count ++ ){
        std::cout << "\n Slice " << count <<":\n";
        for (int i = 0; i < 5; i ++){
            for (int j = 0; j < 5; j ++){
                if (count <= field[i][j].size() ){
                    std::cout << " " << 1;
                }else std::cout << " " << 0;
            }
            std::cout << "\n";
        }
    }

    std::cout << "end!";
    
}