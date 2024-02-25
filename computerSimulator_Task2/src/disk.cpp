#include "../include/disk.h"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

void save (const vector<int>& ram)
{
    if (ram.empty()){
        cout << "\nOperation ERROR. No data to save.\n";
        return;
    }
    ofstream file ("data.txt");
    for (int i : ram){
        file << i << " ";
    }
    file.close();
    cout << "\nData saved successfully\n";
}

void load (vector<int>& ram)
{
    ifstream file ("data.txt");
    if (file.eof()) {
        cout << "\nOperation ERROR. No data to load.\n";
        return;
    }
    ram = {};

    while (!file.eof()){
        int tmp;
        file >> tmp;
        ram.push_back(tmp);
    }

    file.close();
    cout << "\nData loaded successfully\n";
}
