#include "../include/kbd.h"
#include <iostream>
#include <vector>

using namespace std;

void input(vector<int>& ram)
{
    ram = {};
    for (int i = 0; i < 8; i ++){
        int tmp;
        cin >> tmp;
        ram.push_back(tmp);
    }
}