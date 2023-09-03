#include <iostream>
#include <vector>
#include <iomanip>

void popPrint(int const& count)
{
    for (int i = 0; i < count; i ++) std::cout << "Pop! "; 
}

void resultPrint (std::vector<std::vector<bool>> const& vec)
{
    std::cout << std::endl;
    for (int i = 0; i < vec.size(); i ++){
        for (int j = 0; j < vec[0].size(); j ++){
            std::cout << std::setw(2);
            if (vec[i][j]){
                std::cout << 'O';
            } else std::cout << 'X';
        }
        std::cout << std::endl;
    }
}

bool isWhole (std::vector<std::vector<bool>> const& film)
{
    for (int i = 0; i < film.size(); i ++){
        for (int j = 0; j < film[0].size(); j ++){
            if (film[i][j]) return false;
        }
    }
    return true;
}

bool isValid (int const& x, int const& y)
{
    return (x < 0 || x > 11 || y < 0 || y > 11);
}

int  burst (int const& x1, int const& y1, int const& x2, int const& y2, std::vector<std::vector<bool>>& film )     //burst bubles and return their count
{
    int count = 0;
    for (int y = y1; y < y2 + 1; y ++){
        for (int x = x1; x < x2 + 1; x++ ){
            if (film[y][x]){
                count++;
                film[y][x] = false;
            }
        }
    }
    return count;
}

int main()
{
    std::vector <std::vector<bool>>film (12, std::vector<bool>(12,true));
    int x1 = -1, y1, x2 = -1, y2;

    for (;;){
        while (isValid (x1, y1)) {
        std::cout << "\nPlease, enter first coardinates (more then or equal 0 and less then 12): ";
        std::cin >> x1 >> y1;
        }

        while (isValid (x2, y2)) {
        std::cout << "\nPlease, enter second coardinates (more then or equal 0 and less then 12): ";
        std::cin >> x2 >> y2;
        }
        if (x1 > x2) std::swap(x1, x2);
        if (y1 > y2) std::swap(y1, y2);

        popPrint(burst(x1, y1, x2, y2, film));
        resultPrint(film);
        if(isWhole(film)) break;
        x1 = x2 = -1;
    }
    std::cout << "\nEnd!";
}