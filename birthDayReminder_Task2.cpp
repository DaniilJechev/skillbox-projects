#include <iostream>
#include <ctime>
#include <vector>

void getBirthday_data (std::string& name, std::vector<std::pair <std::string, tm*>>& friendsInf)
{
    std::pair <std::string, tm*> date_Name;
    date_Name.first = name;
    time_t cur_time = std::time(nullptr);
    tm* birthdayDate = std::localtime(&cur_time);
    std::cout << std::endl << "Enter the day: ";
    std::cin >> birthdayDate->tm_mday;
    std::cout << std::endl << "Enter number of mounth: ";
    std::cin >> birthdayDate->tm_mon;
    std::cout << std::endl << "Enter ther Year: ";
    std::cin >> birthdayDate->tm_year;
    

    date_Name.second = birthdayDate;
    friendsInf.push_back(date_Name);
}

int main()
{
    std::vector<std::pair <std::string, tm*>> friendsInf;
    std::string userInput;
    time_t cur_time = std::time(nullptr);
    tm* cur_date = std::localtime(&cur_time);
    
    while (true)
    {
        std::cout << std::endl << "Enter the name of your friend: ";
        std::cin >> userInput;
        if (userInput == "end") break;
            else getBirthday_data(userInput, friendsInf);
    }
    
}