#include "myLib.h"
#include <iostream>

using namespace  std;

void scalpel(const pair<double, double>& start, const pair<double, double>& end)
{
    cout << "\nCut was made\n"
            "from point: " << start.first << " " << start.second
            << "\nto point: " << end.first << " " << end.second
            << endl;
}

void hemostat (const pair<double, double>& dot)
{
    cout << "\nClamp made at the point:\n"
         << dot.first << " " << dot.second
         << endl;
}

void tweezers (const pair<double, double>& dot)
{
    cout << "\nTweezers are clamped at point:\n"
         << dot.first << " " << dot.second
         << endl;
}

void suture(const pair<double, double>& start, const pair<double, double>& end)
{
    cout << "\nSeam was made\n"
            "from point: " << start.first << " " << start.second
         << "\nto point:"  << end.first << " " << end.second
         << endl;
}