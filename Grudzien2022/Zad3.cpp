#include<iostream>
#include<fstream>
#include<vector>

bool czy_pierwsza(int n)
{
    n--;
    
    for(int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int liczby[100];
    std::ifstream plik("liczby_przyklad.txt");

    int i = 0;
    int licznik_pierwszych = 0;

    while (!plik.eof())
    {
        plik >> liczby[i];
        i++;
    }
    
    for(int j = 0; j <= 100; j++)
    {
        if(czy_pierwsza(liczby[j]))
        {
            licznik_pierwszych++;
        }
    }
    plik.close();

    std::cout << "3.2 " << licznik_pierwszych << std::endl; 

    return 0;
}