#include "cpu.h" // возникает ошибка, т.к. указан не абсолютный путь к данному файлу
#include <iostream>
#include "vector"

using namespace std;

void compute(const vector<int>& buffer)
{
    int summ = 0;
    for (int i = 0; i < buffer.size(); i ++) summ+= buffer[i];
    cout << summ << endl;
}