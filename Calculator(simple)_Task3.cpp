#include <iostream>
#include <sstream>

double result (double double1, double double2, char operation)
{
    if (operation == '+') return double1 + double2;
    else if (operation == '-') return double1 - double2;
    else if (operation == '*') return double1 * double2;
    else if (operation == '/') return double1 / double2;
    else std::cout << "Wrong operation\n";
    return 0;
}


int main ()
{
    std::string example;
    char operation;
    double  double1, double2;
    std::cout << "input the example: ";
    std::cin >> example;
    std::stringstream stream(example);

    stream >> double1 >> operation >> double2;

    std::cout << "Result = " << result(double1, double2, operation);
}