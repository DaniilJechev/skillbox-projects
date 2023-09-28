#include <iostream>

bool cheking (const char* &a, const char* &b, int pos)
{
    for (int i = pos;; i++){
        if ( *(i + a) == *(b + (i - pos) ) && *(b + (i - pos)) == '\0' )  return true;
    }
    return false;
}

bool substr (const char* &a, const char* &b)
{
    for (int i = 0; *(i + a) != '\0'; i++){
        if ( *(i + a) != *b) continue;
        else if (cheking (a, b, i)) return true; 
    }
    return false;
}

int main()
{
    const char* a = "Hello world";
    const char* b = "wor";
    const char* c = "banana";
    std::cout << substr(a,b) << " " << substr(a,c);
}