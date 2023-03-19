#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int suma_p(int n)
{
    if(n == 4)
    {
        return 2;
    }

    int k = 3;

    while(k <= n/2 && !(pierwsza(k) && pierwsza(n-k)))
    {
        k += 2;
    }

    return k;
}

bool pierwsza(int n)
{
    int i = 2;

    while (i*i <= n && n % i != 0)
    {
        i++;
    }

    if(i*i > n)
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
    string linia;

    vector<int> liczby;
    vector<string> litery;

    int n = 0;

    ifstream plik("przyklad.txt");

    while(!plik.eof())
    {
        plik >> liczby[n] >> litery[n];
        n++;
    }

    for (int i = 0; i < liczby.size(); i++)
    {
        if(liczby[i] % 2 == 0)
        {
            int k = suma_p(liczba[i]);
        }
    }
    

    return 0;
}