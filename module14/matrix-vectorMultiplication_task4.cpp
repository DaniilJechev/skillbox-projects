#include <iostream>
#include <vector>
#include <iomanip>

int maxSizeInArr (std::vector<float> const& vec)
{
    int maxN = vec[0];
    for (int i = 0; i < vec.size(); i ++){
            if (vec[i] > maxN) maxN = vec[i];
    }
    return std::to_string(maxN).size() + 1;
}

void resultPrint (std::vector<float> const& vec)
{
    for (int i = 0; i < vec.size(); i ++){
        std::cout << std::setw(maxSizeInArr(vec)) << vec[i];
        std::cout << std::endl;
    }
}

void matInput (std::vector <std::vector<float>>& mat)
{
    for (int i = 0; i < mat.size(); i ++){
        for (int j = 0; j < mat[0].size(); j ++ ){
            std::cout << "\nPlease, enter the number ( " << i << " " << j << " ): ";
            std::cin >> mat[i][j];
        }
    }
}

void vecInput (std::vector <float>& vec)
{
    for (int i = 0; i < vec.size(); i ++){
        std::cout << "\nPlease, enter the number ( " << i << " ): ";
        std::cin >> vec[i];
    }
}

int main()
{
    std::vector <std::vector<float>> mat (4, std::vector<float>(4));
    std::vector <float> vec (4);
    std::vector <float> result (4);
    int summ = 0;

    std::cout << "Enter matrix:";
    matInput(mat);
    std::cout << "Enter vector:";
    vecInput(vec);

    for (int i = 0; i < mat.size(); i ++){
        for (int j = 0; j < mat[0].size(); j ++ ){
            summ += mat [i][j] * vec[j];
        }
        result[i] = summ;
        summ = 0;
    }

    resultPrint(result);
}