#include "../include/ram.h"

using namespace std;

int buffer[8];

void write (int* input)
{
    for (int i = 0; i < 8; i ++){
        buffer[i] = input[i];
    }
}

int* read()
{
    return buffer;
}