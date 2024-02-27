#include "../include/disk.h"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

void save (const vector<int>& buffer)
{
    if (buffer.empty()){
        cout << "\nOperation ERROR. No data to save.\n";
        return;
    }
    ofstream file ("data.txt");
    for (int i : buffer){
        file << i << " ";
    }
    file.close();
    cout << "\nData saved successfully\n";
}

void load (vector<int>& cur_nums)
{
    ifstream file ("data.txt");

    if (!file.is_open()){
        cout << "\nOperation ERROR. No data to load.\n";
        return;
    }
    cur_nums.erase(cur_nums.begin(), cur_nums.end());

    file.seekg(0);

    for (int i = 0; i < 8; i ++){
        int tmp;
        file >> tmp;
        cur_nums.push_back(tmp);
    }

    file.close();
    cout << "\nData loaded successfully\n";
}
