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

void heapSwap(float arr[], int size, int i)   //swap functinon
{
    if ((size < 1) || (i < 0) ) return ;
    while (i * 2 + 1 > size - 1 ) i--;
    if (allowedSwap(size, i)){
        if (arr[i*2 + 1] >= arr[i*2 + 2] && arr[i*2 + 1] > arr[i]){
            std::swap(arr[i], arr[i*2 + 1]);
        }else if (arr[i*2 + 2] > arr[i*2 + 1] && arr[i*2 + 2] > arr[i]){
            std::swap(arr[i], arr[i*2 + 2]);
        }
    }else if (arr[i] < arr[i*2 + 1]) std::swap(arr[i], arr[i*2 + 1]);
    
    heapSwap(arr, size - 1, i - 1 );
}

void sort (float arr[], int size)
{
    int k = size;
    for (int i = 0; i < k - 1; i ++){
        heapSwap(arr,size, size);
        size--;
    }
}

int main()
{
    float arr[] = {1.6, 1.5, 4.4, 2.2 ,3.25, 1.7};
    int size = sizeof(arr)/sizeof(arr[0]);
    sort (arr, size);
    std::cout << "\nSorted array : \n" ;
    print (arr, size - 1);
}