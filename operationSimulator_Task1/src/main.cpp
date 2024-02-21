#include <iostream>
#include "myLib.h"

using namespace std;

void enterPoint(pair<int, int>& point)
{
    cout << "Enter 'x' and 'y' coordinates: ";
    cin >> point.first >> point.second;
}

int main()
{
    string command = "0";
    bool is_first = true;
    pair<int, int> point1, point2;
    pair<int, int> scalP1, scalP2;

    while (true){
        if (is_first) cout << "\nEnter first command: ";
        else cout << "\nEnter next command: ";

        cin >> command;

        if (is_first && command == "scalpel"){ //change the condition, you check "is_first" twice
            enterPoint(point1);
            enterPoint(point2);
            scalpel(point1, point2);
            scalP1 = point1;
            scalP2 = point2;
            is_first = false;
            continue;
        }else if (is_first){
            cout << "\nIncorrect command, first command must be 'scalpel'\n";
            continue;
        }else if (command == "scalpel"){
            cout << "\nScalpel mustn't be used more than 1 time\n";
        }

        if (command == "hemostat"){
            enterPoint(point1);
            hemostat(point1);
        }else if (command == "tweezers"){
            enterPoint(point1);
            tweezers(point1);
        }else if (command == "suture"){
            enterPoint(point1);
            enterPoint(point2);

            if ((scalP1 == point1 && scalP2 == point2)
             || (scalP1 == point2 && scalP2 == point1)){
                suture(point1, point2);
                break;
            }else{
                cout << "\nIncorrect points, they must be coincide with cut points\n";
            }

        }else{
            cout << "\nIncorrect command\n";
        }

    }
    cout << "\nOperation done!";
}