#include "../include/ram.h"
#include <vector>

using namespace std;

void write (vector<int>& ram, const vector<int>& input)
{
    ram = {};
    for (int i : input) ram.push_back(i);
}

void read (const vector<int>& ram, vector<int>& output)
{
    output = {};
    for (int i : ram) output.push_back(i);
}