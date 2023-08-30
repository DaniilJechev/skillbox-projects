#include <iostream>
#include <vector>

int main()
{
    std::vector <float> prices {2.5, 4.25, 3.0, 10.0};
    std::vector <int> items {1, 1, 0, 3};
    float summ = 0;
    
    for (int i = 0; i < items.size(); i ++){
        summ += prices[items[i]];
    }

    std::cout << "Total summ = " << summ;
}