#include <iostream>
#include <vector>

void numMove(std::vector <int>& vec, int const pos)
{
    int num = vec[pos];
     for (int i = pos ; i < vec.size() - 1; i ++ ){
        vec[i] = vec[i + 1];
    }
    vec.back() = num;
}

void deleteNum (std::vector <int>& vec, int const numToDel, int const startPos)
{
    for (int i = startPos; i < vec.size(); i ++ ){
        if (vec[i] == numToDel){
            numMove(vec, i);
            vec.pop_back();
            deleteNum(vec, numToDel, i);
        }
    }
}

void resultPrint (std::vector<int> const vec)
{
    std::cout << "Result: ";
    for (int i = 0; i < vec.size(); i ++){
        std::cout << vec[i] << " ";
    }

}

int main()
{
    int size, numToDel;
    std::cout << "Input vector size: ";
    std::cin >> size;
    std::vector <int> vec (size);

    for (int i = 0; i < size; i ++){
        std::cout << "Enter the number " << i + 1 << ": " ;
        std::cin >> vec[i];
    }

    std::cout << "Input number to delete: ";
    std::cin >> numToDel;

    deleteNum(vec, numToDel, 0);

    resultPrint(vec);
}