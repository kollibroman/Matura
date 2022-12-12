#include<iostream>
using namespace std;

bool Czy_liczba_jest_Pierwsza(int n)
{
    for(int i = 2; i <= n - 1; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}
int main()
{
    int n;
    cout << "Podaj liczbe: ";
    cin >> n;
    cout << Czy_liczba_jest_Pierwsza(n);

    return 0;
}
