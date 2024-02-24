#include "../include/disk.h"
#include <vector>
#include <fstream>

using namespace std;

void save (const vector<int>& ram)
{
    ofstream file ("data.txt");
    for (int i : ram){
        file << i << " ";
    }
    file.close();
}

void load (vector<int>& ram)
{
    ifstream file ("data.txt");
    ram = {};

    while (!file.eof()){
        int tmp;
        file >> tmp;
        ram.push_back(tmp);
    }

    file.close();
}
