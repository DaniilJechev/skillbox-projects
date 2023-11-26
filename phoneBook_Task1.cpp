#include <iostream>
#include <map>
#include <sstream>
#include <string>


bool is_num (std::string phoneNum)
{
    return ((int)phoneNum[0] >= 48 && (int)phoneNum[0] <= 57);
}


int main ()
{
    std::map <std::string, std::string> phoneBook;
    std::string name, phoneNum, input;

    while (true){
        std::cout << std::endl << "Enter your request: ";
        std::getline(std::cin, input);

        std::stringstream stream (input);
        stream >> phoneNum >> name;
        if (phoneNum != "" && name != ""){
            phoneBook.insert(std::pair<std::string, std::string>(phoneNum, name));

        }else if (is_num(phoneNum)){
            if (phoneBook.count(phoneNum)) std::cout << std::endl << "Surname: " << phoneBook.at(phoneNum);
                else std::cout << std::endl << "This name is not listed in your phone book.";
        }else{
            std::swap(phoneNum, name);
            bool number_listed = false;

            for (std::map <std::string, std::string>::iterator it = phoneBook.begin();
                it != phoneBook.end(); ++it){
                    if (it->second == name){
                        if (!number_listed) std::cout << std::endl << "possible number/numbers: ";
                        std::cout << it->first << ' ';
                        number_listed = true;
                    }
                }
                if (!number_listed) std::cout << std::endl << "No numbers with this surname";
        }

        phoneNum.erase(), name.erase();
    }
}