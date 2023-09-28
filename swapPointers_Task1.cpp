#include <iostream>

void swap(int* a, int* b)
{
    std::swap(*a, *b);
}

int main()
{
    int a = 10;
    int b = 20;

    swap (&a, &b);
    std::cout << a << " " << b;
}