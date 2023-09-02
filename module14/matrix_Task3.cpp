#include <iostream>
#include <vector>
#include <iomanip>

int maxSizeInArr (std::vector<std::vector<int>> const& vec)
{
    int maxN = vec[0][0];
    for (int i = 0; i < vec.size(); i ++){
        for (int j = 0; j < vec[0].size(); j ++){
            if (vec[i][j] > maxN) maxN = vec[i][j];
        }
    }
    return std::to_string(maxN).size() + 1;
}

void resultPrint (std::vector<std::vector<int>> const& vec)
{
    for (int i = 0; i < vec.size(); i ++){
        for (int j = 0; j < vec[0].size(); j ++){
            std::cout << std::setw(maxSizeInArr(vec)) << vec[i][j] ;
        }
        std::cout << std::endl;
    }
}

bool isEqual (std::vector<std::vector<int>> const& firstM, std::vector<std::vector<int>> const& secondM )
{
    for (int i = 0; i < firstM.size(); i ++){
        for (int j = 0; j < firstM[0].size(); j ++){
            if (firstM[i][j] != secondM[i][j]) return false;
        }
    }
    return true;
}

void matInput (std::vector <std::vector<int>>& mat)
{
    for (int i = 0; i < mat.size(); i ++){
        for (int j = 0; j < mat[0].size(); j ++ ){
            std::cout << "\nPlease, enter the number ( " << i << " " << j << " ): ";
            std::cin >> mat[i][j];
        }
    }
}

void toDiagonal (std::vector<std::vector<int>>& firstM){
    for (int i = 0; i < firstM.size(); i ++){
        for (int j = 0; j < firstM[0].size(); j ++){
            if (i != j) firstM[i][j] = 0;
        }
    }
}

int main()
{
    std::vector <std::vector<int>> firstM (4, std::vector<int>(4));
    std::vector <std::vector<int>> secondM (4, std::vector<int>(4));

    std::cout << "Input first matrix\n";
    matInput(firstM);
    resultPrint(firstM);

    std::cout << "Input second matrix\n";
    matInput(secondM);
    resultPrint(secondM);

    if (isEqual(firstM, secondM)){
        std::cout << "Matrix are equal\nDiagonal matrix:\n";
        toDiagonal(firstM);

        resultPrint(firstM);
    } else std::cout << "Matrices are not equal";
}