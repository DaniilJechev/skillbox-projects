#include <iostream>
#include <cassert>

using namespace std;

class Branch{
private:
    string elfName;
    Branch* parent = nullptr;
    Branch** middleBranches = nullptr;
    int branches_cnt = 0;

public:
    explicit Branch(Branch* inParent):
        parent(inParent)
    {
        cout << "\nEnter elf name: ";
        cin >> elfName;

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
        delete parent;
    }
};

class Tree{
private:
    Branch** bigBranches = nullptr;
    int branches_cnt = 0;
    
public:
    Tree(){
        branches_cnt = rand() % 3 + 3; // 3-5 big branches
        bigBranches = new Branch*[branches_cnt];
        for (int i = 0; i < branches_cnt; ++i){
            bigBranches[i] = new Branch(nullptr);
        }
    }

    ~Tree(){
        for (int i = 0; i < branches_cnt; ++i){
            delete bigBranches[i];
        }
        delete[] bigBranches;
    }

};

class Village{
private:
    Tree** all_trees = new Tree*[5];

public:
    Village(){
        for (int i = 0; i < 5; ++i){
            all_trees[i] = new Tree();
        }
    }

    ~Village(){
        for (int i = 0; i < 5; ++i){
            delete all_trees[i];
        }
        delete[] all_trees;
    }
};

int main()
{
    srand(time(nullptr));
    auto* village = new Village();
    cout << "\nEnter ended";
    delete village;
}