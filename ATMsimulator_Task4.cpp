#include <iostream>
#include <fstream>
#include <vector>

void randDistribution (int& banknote, int& needCount)
{
    int buffer = banknote;                   
    banknote += (rand() % needCount);
    needCount -= banknote - buffer;
}

int main ()
{
    int count_5000, count_2000, count_1000, count_500, count_200, count_100, moneySumm;
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

    if (command == '+'){
        int needCount =  1000 - (count_5000 + count_2000 + count_1000 + count_500 + count_200 + count_100);
        randDistribution(count_5000, needCount);
        randDistribution(count_2000, needCount);
        randDistribution(count_1000, needCount);
        randDistribution(count_500, needCount);
        randDistribution(count_200, needCount);
        count_100 += needCount;
    }else{
        std::cout << "\nEnter the amount of money needed accurate to 100\n(money less than 100 will be burned from your account): ";
        std::cin >> moneySumm;
        moneySumm -= moneySumm % 100;
        while (moneySumm > count_5000 * 5000 + count_2000 * 2000 + count_1000 * 1000 + count_500 * 500 + count_200 * 200 + count_100 * 100 || moneySumm <= 0){
            std::cout << "\nThat's too a lot or less or equal to 0, enter other summ: ";
            std::cin >> moneySumm;
            moneySumm -= moneySumm % 100;
        }
        while (moneySumm >= 5000){ 
            count_5000--;
            moneySumm -= 5000;
        }
        while (moneySumm >= 2000){ 
            count_2000--;
            moneySumm -= 2000;
        }
        while (moneySumm >= 1000){ 
            count_1000--;
            moneySumm -= 1000;
        }
        while (moneySumm >= 500){ 
            count_500--;
            moneySumm -= 500;
        }
        while (moneySumm >= 200){ 
            count_200--;
            moneySumm -= 200;
        }
        while (moneySumm >= 100){ 
            count_100--;
            moneySumm -= 100;
        }
        std::cout << "\nMoney withdrawn successfully";
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