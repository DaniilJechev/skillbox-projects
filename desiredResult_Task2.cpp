#include <iostream>
#include <vector>

void desResFinder (std::vector <int>& arr, int desRes)
{
    for (int i = 0; i < arr.size() - 1; i ++){
        for (int j = i; j < arr.size() - 1; j ++){
            if (arr[i] + arr[j] == desRes){
                std::cout << arr[i] << " + " << arr[j] << " = " << desRes;
                return ;
            }
        }
    }
    std::cout << "This result is missed!";
}

int main ()
{
    std::vector <int> arr {2, 7, 11, 15};
    int desRes;
    std::cout << "Please, enter the desire result: ";
    std::cin >> desRes;

    desResFinder(arr, desRes);
}