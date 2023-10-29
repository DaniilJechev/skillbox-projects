#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

void randDistribution (int& banknote, int& needCount)
{
    srand(time(NULL));
    int buffer = banknote;                   
    banknote += (rand() % needCount);
    needCount -= banknote - buffer;
}

void payment (int& summ, int& money_count, int moneySize){
    while (summ >= moneySize && money_count > 0){
        summ -= moneySize;
        money_count --;
    }
}

int main ()
{
    int count_5000 = 0, count_2000 = 0, count_1000 = 0, count_500 = 0, count_200 = 0, count_100 = 0, moneySumm = 0;
    char command;

    std::ifstream save_read ("save.bin", std::ios::binary);

    save_read.read((char*)&count_5000, sizeof(int));
    save_read.read((char*)&count_2000, sizeof(int));
    save_read.read((char*)&count_1000, sizeof(int));
    save_read.read((char*)&count_500, sizeof(int));
    save_read.read((char*)&count_200, sizeof(int));
    save_read.read((char*)&count_100, sizeof(int));

    save_read.close();

    std::cout << "Input the command: ";
    std::cin >> command;
    
    if (count_5000 + count_2000 + count_1000 + count_500 + count_200 + count_100 == 0){
        while (command != '+'){
            std::cout << std::endl << "ATM is empty! Enter other command: ";
            std::cin >> command;
            if (command != '+') std::cout << std::endl << "Wrong choice:)";
                else if (command == '+') std::cout << std::endl << "It was only your opinion, u are always have a choice!";
        }
    }   

    if (command == '+'){
        int needCount =  1000 - (count_5000 + count_2000 + count_1000 + count_500 + count_200 + count_100);

        if (needCount != 0){
            randDistribution(count_5000, needCount);
            randDistribution(count_2000, needCount);
            randDistribution(count_1000, needCount);
            randDistribution(count_500, needCount);
            randDistribution(count_200, needCount);
            count_100 += needCount;
            std::cout << std::endl << "Operation was successfully completed";
        }else{
            std::cout << std::endl << "There is enough money in ATM";
        }
    }else{
        command = '.';
        std::cout << "\nEnter the amount of money needed accurate to 100\n(money less than 100 will be burned from your account): ";
        std::cin >> moneySumm;
        moneySumm -= moneySumm % 100;

        while (moneySumm > count_5000 * 5000 + count_2000 * 2000 
            + count_1000 * 1000 + count_500 * 500 
            + count_200 * 200 + count_100 * 100 
            || moneySumm <= 0){
            
            std::cout << "\nThat's too a lot or less or equal to 0.\n(if u want to enter other summ, please enter ""*"")\n(if u want to stop this, please enter ""!""): ";
            std::cin >> command;
            if (command == '!') break;

            std::cout << "\nEnter other summ: ";
            std::cin >> moneySumm;
            moneySumm -= moneySumm % 100;
        }
        if (command != '!'){

        payment(moneySumm, count_5000, 5000);
        payment(moneySumm, count_2000, 2000);
        payment(moneySumm, count_1000, 1000);
        payment(moneySumm, count_500, 500);
        payment(moneySumm, count_200, 200);
        payment(moneySumm, count_100, 100);

        if (moneySumm == 0){
            std::cout << "\nMoney withdrawn successfully";
        }else std::cout << "Some of your money is missing, we are terribly sorry :(" << std::endl << "goodbye!";
        }else std::cout << std::endl << "goodbye!";
    }

    std::ofstream save_write ("save.bin", std::ios::binary); //write the result of work

    save_write.write((char*)&count_5000, sizeof(int));
    save_write.write((char*)&count_2000, sizeof(int));
    save_write.write((char*)&count_1000, sizeof(int));
    save_write.write((char*)&count_500, sizeof(int));
    save_write.write((char*)&count_200, sizeof(int));
    save_write.write((char*)&count_100, sizeof(int));

    save_write.close();
}