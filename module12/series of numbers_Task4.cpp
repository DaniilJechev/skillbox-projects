#include <iostream>

int DublicatFind(int const numbers[], int x, int size)
{
    int arrSumm = 0, usualSumm = 0;
    for (int i = 0; i < size - 1; i ++){
        arrSumm += numbers[i];
    }
    for (int i = 0; i < size - 2; i ++){
        usualSumm += x;
        x++;
    }
    return (arrSumm - usualSumm);
}
 
int main()
{
    int numbers[15] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
    int x = 105;
    int size = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << DublicatFind(numbers, x, size);
    
}