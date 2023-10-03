#include <iostream>

int optionCount;


void rabbitJump(const int stairsCount, const int jumpLength, int start = 0)
{
    if (start == stairsCount){
        optionCount ++;
        return;
    }else if (start > stairsCount) return;

    for (int i = 1; i <= jumpLength; i++){
        if (start + i <= stairsCount) rabbitJump(stairsCount, jumpLength, start + i);
    }
}

int main()
{
    int stairsCount, jumpLenght;
    std::cout << "Enter the stairs count and max jump length: ";
    std::cin >> stairsCount >> jumpLenght;

    rabbitJump(stairsCount, jumpLenght);

    std::cout << "Option of counts are equal to " << optionCount;
}