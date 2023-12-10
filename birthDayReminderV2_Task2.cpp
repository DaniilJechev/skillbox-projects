#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>

struct inf
{
    std::string name;
    tm date;
};

bool correctDate (tm date)
{
    time_t t = std::time(nullptr);
    std::tm* cur_time = std::localtime(&t);
    if (date.tm_year > cur_time->tm_year) return false;
        else if (date.tm_year == cur_time->tm_year){
                if (date.tm_mon > cur_time->tm_mon) return false;
                    else if (date.tm_mon == cur_time->tm_mon){
                        if (date.tm_mday > cur_time->tm_mday) return false;
                    }
        }
    return true;
}

bool isCloser (tm date, tm candidate) //return true mean that candidate is closer to current date than current nearest date
{
    time_t t = std::time(nullptr);
    std::tm* cur_time = std::localtime(&t);

    int daysTo_date = 365 - (cur_time->tm_yday - date.tm_yday);
    if (daysTo_date >= 365) daysTo_date -= 365;
    int daysTo_candidate = 365 - (cur_time->tm_yday - candidate.tm_yday);
    if (daysTo_candidate >= 365) daysTo_candidate -= 365;
    
    return (daysTo_candidate <= daysTo_date);
}

tm nearestDate(std::vector <inf>& friends)
{
    tm date = friends[0].date;
    tm candidate;
    for (int i = 0; i < friends.size(); i ++){
        candidate = friends[i].date;
        if (correctDate(candidate) && isCloser(date, candidate)){
            date = candidate;
        }
    }
    return date;
}

void showResult(std::vector <inf> friends)
{
    tm closerDate = nearestDate(friends);
    for (int i = 0; i < friends.size(); i ++){
        if (closerDate.tm_mon == friends[i].date.tm_mon &&
            closerDate.tm_mday == friends[i].date.tm_mday){
                std::cout << std::endl << "Person: " << friends[i].name <<
                             std::endl << "Date: " << friends[i].date.tm_mon + 1 << ':' << friends[i].date.tm_mday;
            }
    }
}


int main()
{
    std::string name;
    std::vector <inf> friends;

    while (true)
    {
        inf cur_friend;
        std::cout << std::endl << "Enter the name: ";
        std::cin >> name;
        if (name != "end"){
            cur_friend.name = name;
            std::cout << std::endl << "Enter the date: ";
            std::cin >> std::get_time(&cur_friend.date, "%Y:%m:%d");
            friends.push_back(cur_friend);
        }else{
            showResult(friends);
            break;
        }
    }
}