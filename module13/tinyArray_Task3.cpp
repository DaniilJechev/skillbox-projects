#include <iostream>
#include <vector>

void numMove(std::vector <int>& vec)
{
    int num = vec[0];
     for (int i = 0 ; i < vec.size() - 1; i ++ ){
        vec[i] = vec[i + 1];
    }
    vec.back() = num;
}

void print (std::vector<int> const vec)
{
    std::cout << std::endl;
    for (int i = 0; i < vec.size(); i ++){
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int num, count = 0;
    std::vector <int> vec ;

    for (int i = 0;; i ++){
        std::cout << "\nEnter the number : " ;
        std::cin >> num;
        if (num == -1){
            print(vec);
        } else if (count < 20){
            vec.push_back(num);
            count ++;
        } else {
            numMove(vec);
            vec.back() = num;
        }
    }
}