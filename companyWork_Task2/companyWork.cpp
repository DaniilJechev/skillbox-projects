#include <iostream>
#include <ctime>
#include <cassert>
#include <cstring>

using namespace std;

char* getRandName()
{
    char* name = new char[6];
    for (int i = 0; i < 5; i ++){
        char randLetter = (char)('a' + rand() % 26);
        name[i] = randLetter;
    }
    name[5] = '\0';
    return name;
}

class People{
protected:
    char* name = nullptr;

public:
    explicit People(char* inName):
            name(inName) {}

    ~People(){
        delete[] name;
    }

};

class Worker: public People{
private:
    char task = '-';

public:
    explicit Worker(char* inName): People(inName) {}

    [[nodiscard]]
    char getTask() const{
        return task;
    }

    void setTask(char inTask){
        this->task = inTask;
        cout << name;
        cout << " got a task " << task << endl;
    }

};


class Manager: public People{
private:
    Worker** team = nullptr;
    int teamSize = 0;
    int availableWorkers = 0;

private:
    static char getRandTask(){
        return (char)('A' + rand() % 3);
    }

public:
    explicit Manager(char* inName, int inTeamSize):
        teamSize(inTeamSize), People(inName)
    {
        availableWorkers += teamSize;
        assert(teamSize >= 0);
        team = new Worker*[teamSize];
        for (int i = 0; i < teamSize; ++i){
            team[i] = new Worker(getRandName());
        }
    }

    ~Manager(){
        for (int i = 0; i < teamSize; ++i){
            delete team[i];
        }
        delete[] team;
    }

    [[nodiscard]]
    int getAvailableWorkers() const
    {
        return availableWorkers;
    }

    void acceptCommand(int command, int managerNum){
        srand(command + managerNum);
        int needGiveCommand = (rand() % availableWorkers) + 1;
        availableWorkers -= needGiveCommand;

        for (int i = 0; i < teamSize; i ++){
            if (team[i]->getTask() == '-'){
                team[i]->setTask(getRandTask());
                --needGiveCommand;
                if (needGiveCommand == 0) break;
            }
        }
    }

};


class Boss: public People{
private:
    Manager** all_managers = nullptr;
    int managersCnt = 0;

public:
    explicit Boss(char* inName):
            People(inName)
    {
        cout << "\nEnter the number of teams (managers): ";
        cin >> managersCnt;
        assert(managersCnt > 0);
        all_managers = new Manager*[managersCnt];

        for (int i = 0; i < managersCnt; ++i){
            int teamSize = 0;
            cout << "\nEnter team size for "
                 << i + 1 << " team: ";
            cin >> teamSize;
            assert(teamSize > 0);

            all_managers[i] = new Manager(getRandName(), teamSize);
        }
    }

    ~Boss(){
        assert(all_managers != nullptr);
        for (int i = 0; i < managersCnt; ++i){
            delete all_managers[i];
        }
        delete[] all_managers;
    }

    void startCommand(){
        int command;
        for (int i = 0; i < managersCnt; ++i){
            while (all_managers[i]->getAvailableWorkers() != 0){
                cout << "\nEnter command for "
                     << i + 1 << " team: ";
                cin >> command;
                all_managers[i]->acceptCommand(command, i + 1);
            }
        }
        cout << "\nAl workers are doing something!";
    }
};


int main()
{
    srand(time(nullptr));
    string bossName;

    cout << "\nEnter boss name: ";
    cin >> bossName;
    char* p_bossName = new char[bossName.size() + 1];
    strcpy(p_bossName, bossName.c_str());

    Boss* boss = new Boss(p_bossName);
    boss->startCommand();
    delete boss;
}