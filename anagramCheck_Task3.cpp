#include <iostream>
#include <map>

bool is_Anagram(std::string first_str, std::string second_str)
{
    if (first_str.length() != second_str.length()) return false;

    std::map <char, int> firstWord_letters;
    std::map <char, int> secondWord_letters;
    for (int i = 0; i < first_str.length(); i ++){
        firstWord_letters[first_str[i]]++;
        secondWord_letters[second_str[i]]++;
    }
    if (firstWord_letters.size() != secondWord_letters.size()) return false;
        else{
            std::map <char, int>::iterator it_1 = firstWord_letters.begin();
            std::map <char, int>::iterator it_2 = secondWord_letters.begin();
            while (it_1 != firstWord_letters.end() && it_2 != secondWord_letters.end()){
                if (it_1 != it_2) return false;
                ++it_1, ++it_2;
            }
        }
    return true;
}

int main()
{
    std::string first_str, second_str;
    std::cout << "Enter first string please: ";
    std::cin >> first_str;
    std::cout << std::endl << "Enter second string please: ";
    std::cin >> second_str;
    
    if (is_Anagram(first_str, second_str)) std::cout << std::endl << "This is anagram";
        else std::cout << std::endl << "This is not anagram";
}