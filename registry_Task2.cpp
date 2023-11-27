#include <iostream>
#include <map>

bool is_nameInMap (std::string& name, std::map<std::string, int>& queue)
{   queue[name];
    for (std::map <std::string, int>::iterator it = queue.begin();
    it != queue.end(); it++){
        if (it->first == name){
                it->second++;
                return true;
                break;
        }
    }
    return false;
}

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
            if (!is_nameInMap(name, queue)){
                queue[name];
            }
        }
    }
}