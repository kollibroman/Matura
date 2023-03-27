#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

bool czy_podzielne_17(int n)
{
    if(n % 17 == 0)
    {
        return true;
    }

    return false;
}

string Odwrocona_liczba(string str)
{
    string reverse_str = "";

    for(int i = str.length() - 1; i >= 0; i--)
    {
        reverse_str += str[i];
    }

    return reverse_str;
}

bool czy_pierwsza(int n)
{
    for (int i = 2; i < n; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string linia;
    vector<string> liczby;

    ifstream plik("liczby.txt");
    ofstream plik2("wyniki4.txt");

    vector<int> podzielne_odbicia;

    int Max_roznica = 0;
    int Max_liczba;

    vector<int> liczba;
    vector<int> odbicie;

    int rozne = 0;
    int podwojne = 0;
    int potrojne = 0;

    while(!plik.eof())
    {
        getline(plik, linia);

        if(linia != "")
        {
            liczby.push_back(linia);
        }
    }

    plik.close();

    for(int i = 0; i < liczby.size(); i++)
    {
       if(czy_podzielne_17(stoi(Odwrocona_liczba(liczby[i]))))
       {
            podzielne_odbicia.push_back(stoi(Odwrocona_liczba(liczby[i])));
       }
    }

    for (int i = 0; i < liczby.size(); i++)
    {
        int a = stoi(liczby[i]);
        int b = stoi(Odwrocona_liczba(liczby[i]));

        int roznica = abs(a - b);

        if(roznica > Max_roznica)
        {
            Max_roznica = roznica;
            Max_liczba = a;
        }
    }
    
    for(int i = 0; i < liczby.size(); i++)
    {
        int temp = stoi(liczby[i]);
        int temp1 = stoi(Odwrocona_liczba(liczby[i]));

        if(czy_pierwsza(temp) && czy_pierwsza(temp1))
        {
            liczba.push_back(temp);
            odbicie.push_back(temp1);
        }
    }

    sort(liczby.begin(), liczby.end());

    for(int i = 0; i < liczby.size(); i++)
    {
        if(liczby[i] != liczby[i + 1])
        {
            rozne++;
        }

        else if(i != 0 && liczby[i] == liczby[i - 1])
        {
            podwojne++;
        }

        else if(liczby[i] == liczby[i + 1] && liczby[i] == liczby[i + 2])
        {
            potrojne++;
        }
       
    }

    plik2 << "4.1" << endl;

    for (int i = 0; i < podzielne_odbicia.size(); i++)
    {
        plik2 << podzielne_odbicia[i] << endl;
    }

    plik2 << "4.2" << " " << Max_liczba << " " << Max_roznica << endl;

    plik2 << "4.3" << endl;

    for(int i = 0; i < liczba.size(); i++)
    {
        plik2 << liczba[i] << " " << odbicie[i] << endl;
    }

    plik2 << "4.4" << " " << rozne << " " << podwojne << " " << potrojne << endl;
    plik2.close();
    return 0;
}