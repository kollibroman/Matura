#include<iostream>
using namespace std;

int main()
{
    int w = 0;
    int n = 11111;

    while(n != 0)
    {
        w = w + (n % 10);
        n = n / 10;
        cout << w << endl;
    }
    cout << w << endl;
    return 0;
}