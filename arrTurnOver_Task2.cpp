#include <iostream>

void turnOver (int* point)
{
    for (int i = 0; i < 5; i ++){
        std::swap(*(point + i), *(point + 9 - i));
    }   
}

void print (int* point)
{
    for (int i = 0; i < 10; i ++){
        std::cout << *(point + i) << " ";
    }   
}


int main ()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    turnOver(arr);
    print(arr);
}