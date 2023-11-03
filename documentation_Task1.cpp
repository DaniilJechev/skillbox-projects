#include <iostream>
#include <fstream>

#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>

enum mounthes{
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    Septemper,
    October,
    November,
    December
};

bool leapYear(int year)
{
    if (year % 400 == 0) return true;
        else if (year % 100 == 0) return false;
            else if (year % 4 == 0) return true;

    return false;
}

bool symbol_val(std::string date)
{
    if (date[2] != '.' && date[5] != '.'){
        std::cout << "Invalid input, enter date again: ";
        return false;
    }
    for (int i = 0; i < date.size(); i ++){
        if (i == 2 || i == 5) i ++;
        if (date[i] > 57 || date[i] < 48){
            std::cout << "Invalid input, enter date again: ";
            return false;
        }
    }
    return true;
}

bool year_val(int const year)
{
    if (year > 2050 || year < 1950){
        std::cout << "\nInvalid year, enter date again:";
        return false;
    }
    return true;
}

bool day_mounth_val(int const day, int const mounth, int const year){
    if (day < 0 || day > 31){
        std::cout << "\nInvalid day, enter date again: ";
        return false;
    } else if (mounth < 0 || mounth > 12){
        std::cout << "\nInvalid mounth, enter date again: ";
        return false;
    }

    if (mounth == mounthes::February){
        if (leapYear(year)){                                                  //leap year check
            if (day > 29){
                std::cout << "\nInvalid day, enter date again: ";
                return false;
            }
        }else{
            if (day > 28){
                std::cout << "\nInvalid day, enter date again: ";
                return false;
            }
        }                                                       //usual year;
    }

    if (mounth == mounthes::April || mounth == mounthes::June || mounth == mounthes::Septemper || mounth == mounthes::November){
            if (day > 30){
                std::cout << "\nInvalid day, enter date again: ";
                return false;
            }
        }

    return true;
}

bool date_val(std::string date)
{
    if (date.length() != 10){
        std::cout << "\nInvalid input enter date again: ";
        return false;
        }else if (!symbol_val(date)) return false;
            else if (!day_mounth_val( stoi(date.substr(0, 2)), stoi(date.substr(3, 2)), stoi(date.substr(6)) )) return false;
                else if (!year_val( stoi(date.substr(6)) )) return false;
    
    return true;
}


struct documentationData
{
    std::string name_first;
    std::string name_last;
    std::string date;
    int paymentSumm;
};



int main()
{
    std::string command;
    std::cout << "Enter the command please: ";
    std::cin >> command;

    if (command == "list"){
        std::ifstream file ("documentation.txt");
        documentationData inf;

        while(!file.eof()){
            file >> inf.name_first >> inf.name_last >>inf.date >> inf.paymentSumm;
            std::cout << inf.name_first << ' ' << inf.name_last << ' ' << inf.date << ' ' << inf.paymentSumm << std::endl;
        }

        file.close();
    }else if (command == "add"){
        std::ofstream documentation ("documentation.txt", std::ios::app);
        documentationData inf;
    
        std::cout << "Enter your first name: ";
        std::cin >> inf.name_first;

        std::cout << "Enter your last name: ";
        std::cin >> inf.name_last;

        documentation << std::endl << inf.name_first << ' ' << inf.name_last << ' ';

        std::cout << "\nEnter the date (DD.MM.YYYY): ";
        while (true){
            getline(std::cin, inf.date);
            if (date_val(inf.date)) break;
        }
        documentation << inf.date << ' ';

        std::cout << "\nEnter the summ : ";
        while (true){
            std::cin >> inf.paymentSumm;
            if (inf.paymentSumm <= 0){
                std::cout << "\nInvalid input, try again: ";
                continue;
            }
            break;
        }
        documentation << inf.paymentSumm;

        std::cout << std::endl << "Have a nice day, good luck :)";
        documentation.close();

    }else std::cout << "Error input, run documentation again";
}