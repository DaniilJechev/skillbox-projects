#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

std::string writeAns (std::string& line)
{   
    int i = 1;
    std::string answer;
    while (line [i - 1] != '(') i++;
    while (line [i] != ')') answer.push_back(line[i]), i ++;
    return answer;
}

std::string writeQ (std::string& line)
{
    int i = 1;
    while (line[i - 1] != ' ') i ++;  //start with first letter of question
    std::string resultQ;
    for (; line[i] != '?' && line[i] != '.'; i++){
        resultQ.push_back(line[i]);
    }
    resultQ.push_back(line[i]);
    return resultQ;
}

bool is_Qwas(std::vector <int>& answeredQ, int sector)
{
    for (int i = 0; i < answeredQ.size(); i ++){
        if (answeredQ[i] == sector) return true;
    }
    return false;
}


void addOffset (int& sector, int offset = 1)
{
    if (abs(offset) > 13) offset %= 13;
        sector += offset;
    if (sector <= 0) sector = 13 + sector;
        else if (sector > 13) sector = sector - 13;
}

void showPoints (int playerP, int spectatorP)
{
    Sleep(560);
    std::cout << std::endl << "Player points = " << playerP << std::endl;
    std::cout << "Spectator points = " << spectatorP << std::endl;
}

void pleaseSomeDram (std::string& drama)
{
    if (drama != "yes") return ;
    std::string dramaText = "Your answer is ";
    for (int i = 0; i < dramaText.size(); i ++){
        Sleep(200);
        std::cout << dramaText[i];
    }
    for (int i = 0; i < 3; i++){
        Sleep(900);
        std::cout << ". ";
    }
    Sleep(900);

}

int main ()
{
    std::vector <int> answeredQ;
    std::ifstream quetionsList;
    std::string line, question, answer, drama;
    int spectatorP = 0, playerP = 0, offset;

    std::cout << "When answering, use only lowercase letters!!!" << std::endl;
    std::cout << "SETTINGS\nDo you want to turn on the drama mode? (yes or no): ";
    std::getline(std::cin, drama);
    if (drama == "yes") std::cout << "Good choice :)";
        else std::cout << "You can be kinder in your life :(";
    Sleep(1300);
    std::cout << std::string (5, '\n') << "We can start!\n";
    

    quetionsList.open("gameQuetions_Task5.txt");

    for (int sector = 1; spectatorP != 6 && playerP != 6;){
        Sleep(400);
        std::cout << std::endl << "Input offset: ";
        std::cin >> offset;
        Sleep(400);

        addOffset(sector, offset);                              // sector definition
        while (is_Qwas(answeredQ, sector)) addOffset(sector);
        answeredQ.push_back(sector);

        for (int i = 0; i != sector; i ++) std::getline(quetionsList, line); //find need question in txt

        std::cout << std::endl << "Question:\n" << writeQ(line) << std::endl << "Your answer: ";
        std::cin >> answer;
        Sleep(500);
        pleaseSomeDram(drama);
        if (answer == writeAns(line)){
            std::cout << std::endl << "You are right!!!";
            Sleep(400);
            playerP++;
        }else{
            std::cout << std::endl << "Wrong :(";
            std::cout << std::endl << "Right answer is " << writeAns(line);
            Sleep(400);
            spectatorP++;
        }

        showPoints(playerP, spectatorP);

        quetionsList.seekg(0);
    }
    Sleep(1200);

    std::cout << std::string (4,'\n'); 
    if (spectatorP == 6) std::cout << std::endl << "Spectators won!";
        else std::cout << std::endl << "Player won!";

    std::cout << std::endl << "Thank you for playing!";


    quetionsList.close();
}