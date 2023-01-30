#include<iostream>

int f(int n)
{
    if(n > 0)
    {
        std::cout << n << " ";
        f(n - 2);
        std::cout<< n << " ";
    }
    return n;
}

int main()
{
    f(5);
    return 0;  
}