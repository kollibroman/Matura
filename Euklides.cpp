#include<iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Podaj a i b: ";
    cin >> a >> b;

    if (a == b)
    {
        cout << a;
    }

    if(a > b)
    {
        do
        {
            a -= b;
        }
        while(a > b);
        if(a == b)
        {
            cout << a;
        }
    }
    else if(b > a)
    {
        do
        {
            b -= a;
        }
        while(b > a);
        if(a == b)
        {
            cout << b;
        }
    }
    return 0; 
}