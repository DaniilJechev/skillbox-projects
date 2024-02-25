#include "../include/kbd.h"
#include <iostream>
#include <vector>

using namespace std;

void input_nums(vector<int>& ram)
{
    ram = {};
    cout << "\nStart enter nums:\n";
    for (int i = 0; i < 8; i ++){
        int tmp;
        cin >> tmp;
        ram.push_back(tmp);
    }
    cout << "\nEnd enter nums\n";
}