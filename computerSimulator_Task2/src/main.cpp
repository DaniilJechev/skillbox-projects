#include <iostream>
#include "cpu.h"
#include "disk.h"
#include "gpu.h"
#include "kbd.h"
#include "ram.h"

using namespace std;

int main() {
    string input;

    while (true) {
        cin >> input;
        if (input == "sum") {
            compute();
        } else if (input == "save") {
            save();
        } else if (input == "load") {
            load();//error with load
        } else if (input == "input") {
            input_nums();
        } else if (input == "read"){
            read();
        } else if (input == "display") {
            display();
        }else if (input == "exit") {
            break;
        }else cout << "\nERROR incorrect input\n";
    }
}
