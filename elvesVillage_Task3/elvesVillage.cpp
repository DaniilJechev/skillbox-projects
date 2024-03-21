#include <iostream>
#include <cassert>

using namespace std;

string randomName()
{
    string name;
    for (int i = 0; i < 5; i ++){
        name.push_back((char)(97 + rand() % 26));
    }
    return name;
}

bool rand_decide(){return rand() % 2;}

class Branch{
private:
    string elfName = "None";
    Branch* parent = nullptr;
    Branch** middleBranches = nullptr;
    int branches_cnt = 0;

public:
    explicit Branch(Branch* inParent):
        parent(inParent)
    {
        if(rand_decide()){
            elfName = randomName();
            cout << "\nname: " << elfName;
        }

        if (this->parent == nullptr){
            branches_cnt = rand() % 2 + 2;
            middleBranches = new Branch*[branches_cnt];
            for (int i = 0; i < branches_cnt; ++i){
                middleBranches[i] = new Branch(this);
            }
        }
    }
    
    ~Branch(){
        for (int i = 0; i < branches_cnt; ++i){
            delete middleBranches[i];
        }
        delete[] middleBranches;
    }

    [[nodiscard]]
    bool checkName(const string& needFind) const{
        if (this->elfName == needFind){
            return true;
        }else{
            for (int i = 0; i < branches_cnt; ++i){
                if (middleBranches[i]->checkName(needFind)) return true;
            }
        }
        return false;
    }

    [[nodiscard]]
    string getName() const{
        return elfName;
    }

    [[nodiscard]]
    int getBranchCnt() const{
        return branches_cnt;
    }

    [[nodiscard]]
    static int countCitizens(const Branch* branch){
        int cnt = 0;
        if (branch->getName() != "None") cnt++;
        for (int i = 0; i < branch->getBranchCnt(); ++i){
            cnt += countCitizens(branch->middleBranches[i]);
        }
        return cnt;
    }
};

class Village{
private:
    Branch** all_BigBranches = nullptr;
    int branches_cnt = 0;

public:
    Village(){
        branches_cnt = 15 + rand() % 11;
        all_BigBranches = new Branch*[branches_cnt];
        for (int i = 0; i < branches_cnt; ++i){
            all_BigBranches[i] = new Branch(nullptr);
        }
    }

    ~Village(){
        for (int i = 0; i < 5; ++i){
            delete all_BigBranches[i];
        }
        delete[] all_BigBranches;
    }
    
    [[nodiscard]]
    Branch* checkElf(const string& needFind) const{
        for (int i = 0; i < branches_cnt; ++i){
            if (all_BigBranches[i]->checkName(needFind)){
                return all_BigBranches[i];
            }
        }
        return nullptr;
    }

};

int main()
{
    string needFind;
    srand(time(nullptr));

    auto* village = new Village();
    cout << "\nDistribution ended";
    cout << "\nEnter need elf name: ";
    cin >> needFind;
    Branch* elfPoint = village->checkElf(needFind);
    
    if (elfPoint == nullptr){
        cout << "\nNo elf in village";
    }else{
        cout << "\nNeighbours count: " << Branch::countCitizens(elfPoint);
    }

    delete village;
}