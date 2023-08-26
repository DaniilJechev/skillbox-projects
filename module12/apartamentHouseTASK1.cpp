#include <iostream>

int main()
{
    int number;
    std::string houseResidents[] = {"SidorovA" , "IvanovA", "PetrovA", "SidorovB",
     "IvanovB", "PetrovB", "SidorovC" , "IvanovC", "PetrovC", "SidorovD"};

    std::cout << "Enter the apartament numbers 3 times: \n";
    for (int i = 0; i < 3; i++){
        std::cin >> number;
        while ( number < 1 || number > 10){
            std::cout << "Incorrect\nEnter new number: ";
            std::cin >> number;
        }
        std::cout << houseResidents[number + 1] << " is living in apartament number " << number << std::endl;
    }
}
