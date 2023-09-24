#include <iostream>
#include <sstream>

enum switchers
{
    plumbingON = 1,
    lightOutsideON = 2,
    heatersON = 4,
    conditionerON = 8,
};

int total;



void plumbing (int& tOut){ 
    if (!(total & plumbingON) && tOut < 0 ){
        total |= plumbingON;
        std::cout <<"plumbing ON!" <<  std::endl;
    }else if ((total & plumbingON) && tOut > 5){
        total ^= plumbingON;
        std::cout <<"plumbing OFF!" <<  std::endl;
    }
}


void lightOut (int time, std::string& movement)
{
    time = time % 24;
    if (time > 16 || time < 5){
        if (movement == "yes" && !(total & lightOutsideON )){
            total |= lightOutsideON;
            std::cout << "light in garden ON!" << std::endl;
        }else if (movement == "no" && (total & lightOutsideON)){
            total ^= lightOutsideON;
            std::cout << "light in garden OFF" << std::endl;
        }
    }
}

void heaters (int& tIn)
{
    if (!(total & heatersON) && tIn < 22 ){
        total |= heatersON;
        std::cout <<"heaters ON!" <<  std::endl;
    }else if ((total & heatersON) && tIn >= 25){
        total ^= heatersON;
        std::cout <<"heaters OFF!" <<  std::endl;
    }
}

void conditioner (int& tIn)
{
    if (!(total & conditionerON) && tIn >= 30 ){
        total |= conditionerON;
        std::cout <<"conditioner ON!" <<  std::endl;
    }else if ((total & conditionerON) && tIn <= 25){
        total ^= conditionerON;
        std::cout <<"conditioner OFF!" <<  std::endl;
    }
}

void lightIn (int time, std::string& light)
{
    time = time % 24;
    if (time >= 16 && time <= 20){
        if (light == "on") std::cout << "Color temperature: " << 5000 - 575 * (time - 16 ) << 'K' << std::endl;
    }else if (light == "on" && (time < 24 && time > 20)) std::cout << "Color temperature: 2700K" << std::endl;
    else if (light == "on") std::cout << "Color temperature: 5000K" << std::endl;
    
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


    for (int i = 0; i < 48; i ++){
        timePrint(i);
        std::cout << "Please, enter the temperature inside, temperature outside, movements, lights:\n";
        getline(std::cin, inf);
        std::stringstream stream (inf);
        stream >> tIn >> tOut >> movements >> lights;
        std::cout << std::endl;
        plumbing(tOut);
        lightOut(i, movements);
        heaters (tIn);
        conditioner(tIn);
        lightIn(i, lights);
    }

    std::cout << std::string (80, '-') << std::endl << "end!";
}