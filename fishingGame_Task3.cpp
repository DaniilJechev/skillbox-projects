#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void rewrite (){

}

int main()
{
    std::ifstream river ("fishRiver_Task3.txt");
    std::string fish_Name, fish_Now, str;
    int fish_CountToday, fish_TotalCount, needFish_line = 0;     
        //value to count how many in basket are saving

    std::cout << "Enter the fish name please: ";
    std::cin >> fish_Name;

    while(!river.eof()){
        std::getline(river, fish_Now);
        if (fish_Now == fish_Name) fish_CountToday ++;
    }
    river.close();

    std::ifstream basket_read ("basketFish_Task3.txt");
    basket_read.seekg(0);
    fish_Now = ""; // reset the variable, yes. I will look for this fish in the basket

    std::vector <std::string> text;
    while (!basket_read.eof()){        //copy basket
        std::getline(basket_read, str);
        str.push_back('\n');
        text.push_back(str);
    }

    basket_read.seekg(0);
    while (!basket_read.eof()){            //find a pos of fish in file and check how many fish in
        std::getline(basket_read, str);
        std::stringstream string_stream (str);
        string_stream >> fish_Now;
        if (fish_Now == fish_Name){
            basket_read.close();

            string_stream.ignore(16, '|');
            string_stream >> fish_TotalCount;
            fish_TotalCount += fish_CountToday;    

            while (str[str.size() - 1] != ' '){
                str.pop_back();
            }

            std::string stringCountFish = std::to_string(fish_TotalCount);
            str += stringCountFish;
            str.push_back('\n');
            text[needFish_line] = str;

            str = text[text.size() - 1];  //delete last '\n'
            str.pop_back();
            text[text.size() - 1] = str;


            std::ofstream basket_write ("basketFish_Task3.txt");
            for (int i = 0; i < text.size(); i ++){
                basket_write << text[i];
            }
            basket_write.close();

            break;
        }
        needFish_line ++;
    }

}