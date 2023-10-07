#include <iostream>
#include <fstream>

int main()
{
    std::fstream file;
    std::string rightWord, currentWord;
    int count;
    
    std::cout << "Еnter a word to count the number of its repetitions in the text: ";
    std::cin >> rightWord;

    file.open("words_Task1.txt");

    while( !file.eof() ){
        file >> currentWord;
        if (currentWord == rightWord) count ++;
    }

    file.close();

    std::cout << std::endl << "Count of repetitions = " << count;


}
