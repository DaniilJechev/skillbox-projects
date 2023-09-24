#include <iostream>
#include <sstream>

enum switchers
{
    off = 0,
    plumbingON = 1,
    lightOutsideON = 2,

};


void plumbing (int& tOut, int& total){ 
    if (!(total & plumbingON) && tOut < 0 ){
        total |= plumbingON;
        std::cout <<"plumbing ON!" <<  std::endl;
    }else if ((total & plumbingON) && tOut > 5){
        total ^= plumbingON;
        std::cout <<"plumbing OFF!" <<  std::endl;
    }
}


void lightOut (int time, std::string& movement, int& total)
{
    time = time % 24;
    if ((time > 16 || time < 5) && movement == "yes" && total & lightOutsideON ){
        std::cout << "Light in garden ON!";
    }
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
    int total, plumbingState = 0, lightOutState = 0;


    for (int i = 0; i < 48; i ++){
        timePrint(i);
        std::cout << "Please, enter the temperature inside, temperature outside, movements, lights:\n";
        getline(std::cin, inf);
        std::stringstream stream (inf);
        stream >> tIn >> tOut >> movements >> lights;
        plumbing(tOut, total);
        lightOut(i, movements, total);
    }
    std::cout << std::endl << "end!";
}