#include <iostream>
#include <map>

int main()
{
    std::string string;
    std::map <std::string, int> queue;

    while (true)
    {
        std::cout << std::endl << "Enter string: ";
        std::cin >> string;
        if (string == "Next"){
            if (!queue.empty()){
                std::cout << queue.begin()->first;
                queue.erase(queue.begin());
            }
        }else queue[string];
    }
}