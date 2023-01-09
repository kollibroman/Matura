#include<iostream>
#include<fstream>
#include<vector>
#include<map>
using namespace std;

vector<int> rozklad_na_czynniki(int n)      //TODO: policzyc dzielniki i znalezc ich najwieksza liczbe i dodac do zmiennej
{                                           // Wrzucic w osobny plik btw
    vector<int> czynniki;                   // aby sprawdzic dzielniki rozne wystarczy poprzedni z nastepnym porownywac i do zmiennej dodawac
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
    string linie2;  //4.2
    int liczby_rozne = 0;
    vector<string> liczby;
    vector<int> liczby_int;
    vector<int> czynniki;
    vector<string> czynnikowe_liczby; 
    map<string, string> pary_liczb;

    ofstream of_plik2("liczby_z_cznnikami.txt");
    ifstream if_plik2("liczby_z_cznnikami.txt");

    //4.2
    for(int j = 0; j < liczby.size() - 1; j++) //konwersja
    {
        liczby_int.push_back(stoi(liczby[j]));
    }

    for (int i = 0; i < liczby_int.size(); i++) // zapisanie w pliku liczb razem z ich czynnikami
    {
        of_plik2 << liczby_int[i] << " ";
        czynniki = rozklad_na_czynniki(liczby_int[i]);

        for(int j = 0; j < czynniki.size(); j++)
        {
            of_plik2 << czynniki[j] << " ";
        }

        of_plik2 << "\n";
        czynniki.clear();
    }
    
    if(!if_plik2.good())
    {
        cout << "Dupa" << endl;
    }

    while (!if_plik2.eof())
    {
        getline(if_plik2, linie2);
        
        if(linie2 != "")
        {
            czynnikowe_liczby.push_back(linie2);
        }
    }
    
    for (int i = 0; i < czynnikowe_liczby.size(); i++)
    {
        string temp = czynnikowe_liczby[i];

        for(int j = i+1; j < temp.length() - 1; j++)
        {
            if (temp[i] != ' ' && temp[j] != ' ')
            {
                if(temp[i] != temp[j])
                {
                    liczby_rozne++;
                }
            }
        }

        liczby_rozne--;     // odejmujemy pierwsza kolumne
        pary_liczb[temp] = liczby_rozne;
        liczby_rozne = 0; //zerowanie aby przejsc do nastepnej
    }

    for(int i = 0; i < pary_liczb.size(); i++)  //czyszczenie pliku
    {
        of_plik2 << " ";
    }

    for (int i = 0; i < pary_liczb.size(); i++)
    {
        string temp = czynnikowe_liczby[i];
        of_plik2 << temp << pary_liczb[temp] << endl;
    }
}