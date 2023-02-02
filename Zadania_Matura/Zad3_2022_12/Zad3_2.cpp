#include<iostream>
#include<fstream>
#include<vector>

int ilosc_dzielnikow(int n)
{
    int ilosc_dzielnikow = 0;

    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0)
        {
            ilosc_dzielnikow++;
        }
    }
    return ilosc_dzielnikow;   
}

int main()
{
    std::string linia;
    std::vector<int> liczby;
    std::ifstream plik("liczby_przyklad.txt");
    int pierwsze = 0;

    while (!plik.eof())
    {
        getline(plik, linia);

        if(linia != "")
        {
            liczby.push_back(std::stoi(linia));
        }        
    }

    plik.close();

    for(int j = 0; j < liczby.size(); j++)
    {
        int liczba = liczby[j];

        if(ilosc_dzielnikow(liczba - 1) == 2)
        {
            pierwsze++;
        }
    }

    std::cout << pierwsze << std::endl;
}