#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

//Poprawione i dzialajoce :)))

vector<int> rozklad_na_czynniki(int n)      
{                                           
    vector<int> czynniki;                  
    int prime = 2;
    while (n > 1)
    {
        while (n % prime == 0)
        {
            czynniki.push_back(prime);
            n /= prime;
        }
        prime++;
    }
    return czynniki;
}

int main()
{
    string linia;  
    int liczby_rozne = 0;
    int MAXczynniki = 0;
    int MAX_ilosc = 0;
    int ilosc_czynnikow = 0;
    int liczba_z_czynnikami;
    int liczba_z_czynnikami2;

    vector<int> liczby;
    
    ifstream plik("przyklad.txt");

    if(!plik.good())
    {
        cout << "plik nie dziala" << endl;
        return -1;
    }

    while (!plik.eof())
    {
        getline(plik, linia);

        if(linia != "")
        {
            liczby.push_back(stoi(linia));
        }
    }


    for(int i = 0; i <= 200; i++)
    {
        vector<int> liczba = rozklad_na_czynniki(liczby[i]);
        
        for(int j = 0; j < liczba.size(); j++)
        {
            ilosc_czynnikow++;
        }

        if(ilosc_czynnikow > MAX_ilosc)
        {
            liczba_z_czynnikami = liczby[i];
            MAX_ilosc = ilosc_czynnikow;
        }

        ilosc_czynnikow = 0;
    }


    for(int i = 0; i <= 200; i++)                                  //Maksymalna ilosc roznych liczb w rozkladzie
    {
        vector<int> liczba2 = rozklad_na_czynniki(liczby[i]);

        for(int j = 0; j < liczba2.size(); j++)
        {
            if(liczba2[j] != liczba2[j - 1])
            {
                liczby_rozne++;
            }
        }

        if(liczby_rozne > MAXczynniki)
        {
            liczba_z_czynnikami2 = liczby[i];
            MAXczynniki = liczby_rozne;
        }

        liczby_rozne = 0;
    }   


    cout << liczba_z_czynnikami << " " << MAX_ilosc << endl;
    cout << liczba_z_czynnikami2 << " " << MAXczynniki << endl;

    return 0;
}