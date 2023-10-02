#include <iostream>
#include <vector>

void swapvec(std::vector<int>& a, int* b[])
{
    int x = a.size() <= sizeof(b) / sizeof( *b ) ? a.size() - 1: sizeof(b) / sizeof( *b ); // search min size of these arrays
    for (int i = 0; i < x; i ++){
        std::swap(a[i], b[i]);
    }
}


int main()
{
    std::vector<int> a = {1,2,3,4};

    int b[] = {2,4,6,8};

    swapvec(a,b);

    for(int i = 0; i < 4; ++i) std::cout << a[i];

    std::cout << std::endl;

    for(int i = 0; i < 4; ++i) std::cout << b[i];

}