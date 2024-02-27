#include "../include/cpu.h"
#include "../include/ram.h"
#include <iostream>

using namespace std;

void compute()
{
    int summ = 0;
    for (int i = 0; i < 8; i ++) summ+= buffer[i];
    cout << summ << endl;
}