#include "../include/gpu.h"
#include <vector>
#include <iostream>

using namespace std;

void display(const vector<int>& cur_nums)
{
    for (int i : cur_nums) cout << i << " ";
    cout << endl;
}