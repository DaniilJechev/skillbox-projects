#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>


void getBirthday_data (const std::string& name, std::vector<std::pair <std::string, tm*>>& friendsDates)
{
    std::pair <std::string, tm*> friend_NameBirhday;
    friend_NameBirhday.first = name;

    time_t cur_time = std::time(nullptr);
    tm* birthday = std::localtime(&cur_time);
    std::cout << std::endl << "Enter the date, formate Year:Month:Day" << std::endl;
    std::cin >> std::get_time(birthday, "%Y:%m:%d");
    friend_NameBirhday.second = birthday;
    if (cur_time < (std::time_t)birthday){
        std::cout << std::endl << "Error data input";
        getBirthday_data(name, friendsDates);
    } friendsDates.push_back(friend_NameBirhday);
}

bool isCloser (const tm* candidateDate, const tm* cur_nearestDate, const tm* cur_date)
{
    int candidate_toNearest = candidateDate->tm_yday - cur_date->tm_yday;
    if (candidate_toNearest < 0){
        candidate_toNearest+= 365;
    }
    int cur_nearestDiff = cur_nearestDate->tm_mday - cur_date->tm_yday;
    if (cur_nearestDiff < 0){
        cur_nearestDiff+= 365;
    }

    if (candidate_toNearest < cur_nearestDiff) return true;
        else return false;
}

tm* nearestDate (const std::vector<std::pair <std::string, tm*>>& friendsDates)
{
    time_t const curTime = std::time(nullptr);
    tm* cur_date = std::localtime(&curTime);
    tm* nearestDate = friendsDates[0].second;

    for (int i = 1; i < friendsDates.size(); i++)
    {
        if (isCloser(friendsDates[i].second, nearestDate, cur_date)){
            nearestDate = friendsDates[i].second;
        }

    }
    return nearestDate;
}

int main()
{
    std::vector<std::pair <std::string, tm*>> friendsDates;
    std::string userInput;
    
    while (true)
    {
        std::cout << std::endl << "Enter the name of your friend: ";
        std::cin >> userInput;
        if (userInput == "end") break;
            else getBirthday_data(userInput, friendsDates);
    }
    
    std::cout << std::endl << "The nearest birhday/birhdays:" << std::endl;
    tm* nearest_BirthDay = nearestDate(friendsDates);

    for (int i = 0; i < friendsDates.size(); i ++){
        if (friendsDates[i].second->tm_mon == nearest_BirthDay->tm_mon
            && friendsDates[i].second->tm_mday == nearest_BirthDay->tm_mday){
                std::cout << friendsDates[i].first << " Date: " << 
                std::put_time(friendsDates[i].second, "%m:%d") << std::endl;
            }
    }
}