#include<iostream>
#include<list>
using namespace std;

bool Czy_Liczba_Doskonala(int n)
{
    int dzielniki[n];
    int j = 1;

    for (int i = 1; i <= n - 1; i++)
    {
        if(n % i == 0)
        {
            dzielniki[i] = i;
            j += dzielniki[i];
        }
    }

    if(j == n)
    {
        return true;
    }
   else 
   {
        return false;
   } 
}

int main()
{
    int n;
    cout << "Podaj Liczbe: ";
    cin >>  n;
    cout << Czy_Liczba_Doskonala(n);

    return 0;
}