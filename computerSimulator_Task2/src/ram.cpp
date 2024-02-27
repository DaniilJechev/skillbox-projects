#include "../include/ram.h"
#include <vector>

using namespace std;

int buffer[8];

void write (vector<int>& input)
{
    for (int i = 0; i < 8; i ++){
        buffer[i] = input[i];
    }
}

void read (vector<int>& output)
{
    for (int i = 0; i < 8; i ++){
        output[i] = buffer[i];
    }
}