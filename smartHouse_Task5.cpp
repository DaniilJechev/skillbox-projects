#include <iostream>
#include <sstream>

enum switchers
{
    off = 0,
    plumbingON = 1

};


void plumbing (int& tOut, int& total, int& plumbingState){        //printing all values in one F, with inversion
    if (plumbingState == 0 && tOut <= 5 ){
        plumbingState = plumbingON, total |= plumbingState;
    }else if (plumbingState == 1 && tOut > 5){
        plumbingState = off, total &= ~plumbingState; 
    }
    std::cout << total;
}



void timePrint (int& i)
{
    std::cout << std::string (80, '-') << std::endl;
    if (i % 24 < 10) std::cout << '0' << i % 24 << ":00" << std::endl;
    else std::cout << i % 24 << ":00" << std::endl;
}

int main ()
{
    int tOut, tIn;
    std::string movements, lights, inf;   // movements - yes / no       // lights - on / off
    int total, plumbingState = 0;

    for (int i = 0; i < 48; i ++){
        timePrint(i);
        std::cout << "Please, enter the temperature inside, temperature outside, movements, lights:\n";
        getline(std::cin, inf);
        std::stringstream stream (inf);
        stream >> tIn >> tOut >> movements >> lights;
        plumbing(tOut,total, plumbingState);
    }
    std::cout << std::endl << "end!";
}