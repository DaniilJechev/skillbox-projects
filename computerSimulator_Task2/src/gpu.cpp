#include "../include/gpu.h"
#include <vector>
#include <iostream>

using namespace std;

void display(const vector<int>& ram)
{
    for (int i : ram) cout << i << " ";
    cout << endl;
}