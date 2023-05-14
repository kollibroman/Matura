#include<iostream>

int petla(int n)
{
    int p = 1;
    int q = n;
    int s;

    while (p < q)
    {
        s = (p+q) / 2;

        if(s*s*s < n)
        {
            p = s + 1;
        }
        else
        {
            q = s;
        }
        std::cout<< q << " " << s << " " << p << std::endl;
    }
    
    return p;
}

int main()
{
    std::cout << petla(80);
    return 0;
}