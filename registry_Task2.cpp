#include <iostream>
#include <map>


bool is_num (std::string phoneNum)
{
    return ((int)phoneNum[0] >= 48 && (int)phoneNum[0] <= 57);
}

int main()
{
    std::string command, sameName;
    std::map <std::string, int> queue;

    while (true)
    {
        std::cout << std::endl << "Enter name or command: ";
        std::cin >> command;
        if (command == "Next"){
            if (!queue.empty()){
                std::cout << queue.begin()->first;
                queue.begin()->second --;
                if (queue.begin()->second == 0) queue.erase(queue.begin());    
            }
        }else{
            std::string& name = command;
            if (queue.count(name)){
                queue.find(name)->second ++;
            }else{
                queue[name];
                queue.find(name)->second++;
            }
        }
    }
}