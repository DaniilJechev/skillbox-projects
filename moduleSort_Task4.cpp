#include <iostream>
#include <vector>


bool allowedSwap (int size, int i)  //swap check
{
    return (i * 2 + 2 <= size);
}

void print (std::vector <int> arr){      //print function
    for (int i = 0; i < arr.size(); i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void heapSwap(std::vector <int>& arr, int size, int i)   //swap functinon
{
    if ((size < 1) || (i < 0) ) return ;
    while (i * 2 + 1 > size ) i--;
    while ( i >= 0){
        if (allowedSwap(size, i)){
            if ( abs(arr[i * 2 + 1]) >= abs(arr[i * 2 + 2]) &&  abs(arr[i * 2 + 1]) > abs(arr[i])){   
                std::swap(arr[i], arr[i * 2 + 1]);
            }else if (abs(arr[i * 2 + 2]) >=  abs(arr[i * 2 + 1]) && abs(arr[i * 2 + 2]) > abs(arr[i])){
                std::swap(arr[i], arr[i * 2 + 2]);
            }
        }else if ( abs(arr[i]) <  abs(arr[i * 2 + 1])) std::swap(arr[i],  arr[i * 2 + 1]);
        i --;
    }
    return;
}

void sort (std::vector <int>& arr, int size)
{
    int k = size;
    for (int i = 0; i < k; i ++){
        heapSwap(arr, size, size);
        std::swap (arr [0], arr [size]);
        size--;
    }
}

int main()
{
    std::vector <int> arr = {-100,-50, -5, 1, 10, 15};
    int size = arr.size() - 1;
    sort (arr, size);
    std::cout << "\nSorted array : \n" ;
    print (arr);
}