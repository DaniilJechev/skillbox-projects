#include <iostream>

bool allowedSwap (int size, int i)  //swap check
{
    return (i*2 + 2 <= size - 1);
}

void print (float arr[], int size){      //print function
    if (size >= 0){
        print (arr, size - 1);
        std::cout << arr[size] << "  ";
    }
}

void sort(float arr[], int size)   //swap functinon
{
    if (size == 1) return ;
    int i = size - 1;
    while (i * 2 + 1 > size - 1 ) i--;
    if (allowedSwap(size, i)){
        if (arr[i*2 + 1] >= arr[i*2 + 2] && arr[i*2 + 1] > arr[i]){
            std::swap(arr[i], arr[i*2 + 1]);
        }else if (arr[i*2 + 2] > arr[i*2 + 1] && arr[i*2 + 2] > arr[i]){
            std::swap(arr[i], arr[i*2 + 2]);
        }
    }else if (arr[i] < arr[i*2 + 1]) std::swap(arr[i], arr[i*2 + 1]);
    sort(arr, i);
}

int main()
{
    float arr[] = {1.6, 1.5, 4.4, 2.2 ,3.25, 1.7};
    int size = sizeof(arr)/sizeof(arr[0]);
    std::cout << "Sorted arrat : \n" ;
    sort (arr,size);
    print (arr, size - 1);
}