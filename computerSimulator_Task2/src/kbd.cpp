#include "../include/kbd.h"
#include "../include/ram.h"
#include <iostream>

using namespace std;

void input_nums()
{
    int input[8];
    cout << "\nStart enter nums:\n";
    for (int i = 0; i < 8; i ++){
        cin >> input[i];
    }
    cout << "\nEnd enter nums:\n";
    write(input);
}