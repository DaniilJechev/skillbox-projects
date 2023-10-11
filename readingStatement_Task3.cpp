#include <iostream>
#include <fstream>
#include <sstream>


int main ()
{
    std::string str, firstN, secondN;
    unsigned long long summ = 0, maxBill = 0, billNow = 0;
    std::ifstream statement;

    statement.open("statement.txt");

    while (!statement.eof()){
        std::getline(statement, str);
        std::stringstream personData (str);
        if (str != ""){
            for (int i = 0; i < 2; i ++) personData.ignore(10,' ');
            personData >> billNow;
            summ += billNow;
            if (billNow > maxBill){
                maxBill = billNow;
                personData.seekg(0);
                personData >> firstN >> secondN;
                firstN.push_back(' ');
            }
        }

    }
    std::cout << "Sum of all paid bills = " << summ << std::endl;
    std::cout << "Human with max paid bill is " << firstN << secondN << ". He paid " << maxBill;

    
    statement.close();
}