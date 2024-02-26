#include <iostream>
#include "cpu.h"
#include "disk.h"
#include "gpu.h"
#include "kbd.h"
#include "ram.h"

using namespace std;

int main() {
    vector<int> cur_nums;
    string input;

    while (true) {
        cin >> input;
        if (input == "sum") {
            compute(cur_nums);
        } else if (input == "save") {
            save(cur_nums);
        } else if (input == "load") {
            load(cur_nums);//error with load
        } else if (input == "input") {
            input_nums(cur_nums);
        } else if (input == "read"){
            read(cur_nums);
        } else if (input == "display") {
            display(cur_nums);
        }else if (input == "exit") {
            break;
        }else cout << "\nERROR incorrect input\n";
    }
}
