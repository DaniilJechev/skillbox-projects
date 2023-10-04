#include <iostream>

void evenDigit(long long& num, int& ans)
{
    if (num == 0) return;
    if ( num % 2 == 0) ans++;
    num /= 10;
    evenDigit(num, ans);
}

int main ()
{
    int ans;
    long long k = 22312;

    evenDigit(k, ans);
    std::cout << "Even digits are equal to " << ans;
}