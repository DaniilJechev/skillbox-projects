#include <iostream>

int main()
{
    std::string whole, fraction;
    std::cout << "Enter the whole part: ";
    std::cin >> whole;
    whole.push_back('.');
    std::cout << "\nEnter the fraction: ";
    std::cin >> fraction;
    for (int i = 0; i < fraction.size(); i ++) whole.push_back(fraction[i]);
    std::cout << whole;
}