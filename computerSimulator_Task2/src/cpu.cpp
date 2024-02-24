#include "../include/cpu.h"
#include "vector"

using namespace std;

int compute(const vector<int>& buffer)
{
    int summ = 0;
    for (int i = 0; i < buffer.size(); i ++) summ+= buffer[i];
    return summ;
}