#include "../include/cpu.h"
#include <iostream>
#include "vector"

using namespace std;

void compute(const vector<int>& cur_nums)
{
    int summ = 0;
    for (int i = 0; i < cur_nums.size(); i ++) summ+= cur_nums[i];
    cout << summ << endl;
}