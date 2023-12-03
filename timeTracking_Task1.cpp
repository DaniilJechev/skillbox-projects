#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>

#define FINISHEDTASK ""

void reset_Task (std::pair<std::string, std::time_t>& cur_task, std::time_t& start_t, std::time_t& end_t)
{
    start_t = 0;
    end_t = 0;   
    cur_task.first = "";
    cur_task.second = 0;
}

int main()
{
    std::string command, temp;
    std::pair <std::string, std::time_t> cur_task;
    std::vector<std::pair <std::string, std::time_t>> finishedTasks;
    std::time_t start_t, end_t;

    while (true)
    {
        std::cout << std::endl << "Input command: ";
        std::cin >> command;
        if (command == "begin"){
            if (cur_task.first != FINISHEDTASK){
                end_t = std::time(nullptr);
                cur_task.second = std::difftime(start_t, end_t);
                finishedTasks.push_back(cur_task);
                reset_Task(cur_task, end_t, start_t);

                std::cout << std::endl << "Your last task was replace to folder \"finished Tasks\"";
            }
            std::cout << std::endl << "Enter the name of current task: ";
            std::cin >> cur_task.first;
            start_t = std::time(nullptr);

        }else if (command == "end"){
            end_t = std::time(nullptr);
            cur_task.second = std::difftime(start_t, end_t);
            finishedTasks.push_back(cur_task);
            reset_Task(cur_task, start_t, end_t);

            std::cout << std::endl << "Your task was replace to folder \"finished Tasks\"";

        }else if (command == "status"){
            std::cout << std::endl << "Finished Task data: ";
            for (int i = 0; i < finishedTasks.size(); i++){
                std::cout << std::endl << "Name: " << finishedTasks[i].first
                                    << "\t Time: " << finishedTasks[i].second; 
            }

        }else if (command == "exit") break;

    }
}