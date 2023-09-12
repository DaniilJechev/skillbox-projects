#include <iostream>
#include <vector>

int main ()
{
    std::vector <int> arr {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        int maxI = 0, maxJ = 0, maxSumm = arr[0], temp = 0;
    
    for (int i = 0; i < arr.size() - 1; i ++){
        for (int j = i; j < arr.size() - 1; j ++){
            temp += arr[j];
            if (maxSumm < temp){
                maxSumm = temp;
                maxI = i, maxJ = j;
            }
        }
        temp = 0;
    }
    std::cout << "i = " << maxI << " j = " << maxJ;
    std::cout << std::endl << maxSumm;
}