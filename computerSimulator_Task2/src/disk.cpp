#include "../include/disk.h"
#include "../include/ram.h"
#include <fstream>
#include <iostream>

using namespace std;

void save ()
{
    ofstream file ("data.txt");

    for (int & i : buffer){
        file << " " << i;
    }
    file.close();
    cout << "\nData saved successfully\n";
}

void load ()
{
    ifstream file ("data.txt");

    if (!file.is_open()){
        cout << "\nOperation ERROR. No data to load.\n";
        return;
    }

    for (int & i : buffer){
        file >> i;
    }

    file.close();
    cout << "\nData loaded successfully\n";
}