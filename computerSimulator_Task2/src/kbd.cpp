#include "../include/kbd.h"
#include "../include/ram.h"
#include <iostream>
#include <vector>

using namespace std;

void input_nums(vector<int>& buffer)
{
    buffer.erase(buffer.begin(), buffer.end());
    cout << "\nStart enter nums:\n";
    for (int i = 0; i < 8; i ++){
        int tmp;
        cin >> tmp;
        buffer.push_back(tmp);
    }
    cout << "\nEnd enter nums:\n";
    write(buffer);
}