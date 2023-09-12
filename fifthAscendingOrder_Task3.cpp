#include <iostream>
#include <vector>

void print (std::vector <int> arr){      //print function
    std::cout << std::endl;
    for (int i = 0; i < arr.size(); i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << "Thats your array.\n";
}

int partOfSort (std::vector <int>& arr, int l, int r)
{
    int u = arr[(l + r) / 2];
    while (l <= r){
        while ( arr[l] < u) l ++;
        while (arr[r] > u) r --;
        if (l <= r){
            std::swap(arr[l], arr[r ]);
            l ++;
            r --;
        }
    }
    return l;
}

void quickSort (std::vector <int>& arr, int start, int end)
{
    if (start >= end) return;
    int rightStart = partOfSort (arr, start, end);
    quickSort (arr, start, rightStart - 1);
    quickSort (arr, rightStart, end);
}


int main ()
{
    std::vector <int> arr;
    int num;
    for (int i = 0; i < 5; i ++){
        std::cout << std::endl << "Enter the number for array: ";
        std::cin >> num;
        while (num == -1 || num == -2){
            std::cout << std::endl << "This number is one of the future commands, please, enter other num: ";
            std::cin >> num;
        } 
        arr.push_back(num);
    }

    print(arr);

    std::cout << "\nComands: \n-1 means that you need fifth number in ascending order.\n-2 means that u need to stop working.\n";

    while (true){
        quickSort(arr, 0, arr.size() - 1);
        std::cout << "\n\nEnter the next num or comand: ";
        std::cin >> num;

        if (num == -2){
            std::cout << std::endl << "Goodbye!";
            break;
        }else if (num == -1){
            std::cout << std::endl << "Thats the fifth number in ascending order " << arr[4];
        }else arr.push_back(num);
    }
}