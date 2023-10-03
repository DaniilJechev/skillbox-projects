#include <iostream>

void evenDigit(long long& num, int& ans)
{
    std::string strNum = std::to_string(num);

    for (int i = 0; i < strNum.size(); i ++){
        if ( (int) (strNum[i]) % 2 == 0) ans++;
    } 

}

int main ()
{
    int ans;
    long long k = 22312;

    evenDigit(k, ans);
    std::cout << "Even digits are equal to " << ans;
}