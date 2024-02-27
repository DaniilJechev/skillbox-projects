#include "../include/disk.h"
#include "../include/ram.h"
#include <fstream>
#include <iostream>

using namespace std;

void save ()
{
    if (sizeof(buffer) == 0){
        cout << "\nOperation ERROR. No data to save.\n";
        return;
    }
    ofstream file ("data.txt");

    for (int i = 0; i < 8; i ++){
        file << " " << buffer[i];
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

    for (int i = 0; i < 8; i ++){
        file >> buffer[i];
    }

    file.close();
    cout << "\nData loaded successfully\n";
}
