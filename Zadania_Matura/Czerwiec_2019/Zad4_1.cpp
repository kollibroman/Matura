#include<iostream>
#include<fstream>
#include<vector>

bool is_prime(long n)
{
    for (int i = 2; i < n; i++)
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
    long linia;
    std::ifstream plik("liczby.txt");
    std::ofstream wynik("wynik4_1.txt");
    std::vector<int> pierwsze;

    while (plik >> linia)
    {
        if (is_prime(linia) && linia >= 100 && linia <= 5000)
        {
            pierwsze.push_back(linia);
        }
    }
    
    for(int i = 0; i < pierwsze.size(); i++)
    {
        wynik << pierwsze[i] << std::endl;
    }

    plik.close();
    wynik.close();
    return 0;
}