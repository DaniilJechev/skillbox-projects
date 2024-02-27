#include "../include/gpu.h"
#include "../include/ram.h"
#include <iostream>

using namespace std;

void display()
{
    for (int i = 0; i < 8; i ++){
        cout << buffer[i] << " ";
    }
    cout << endl;
}