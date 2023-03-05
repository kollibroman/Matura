#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

bool czy_przysta(int x)
{
    if(x % 2 == 0)
    {
        return true;
    }
    return false;
}

void sito(bool *tab, unsigned int n)
{
    for (int i = 0; i*i <= n; i++)
    {
        if (!tab[i])
        {
            for(int j = i*i; j <= n; j += i)
            {
                tab[j] = 1;
            }
        }
    }
}

int main()
{
    string linia;
    vector<string> liczby;

    vector<int> liczby1;
    vector<int> liczby2;

    vector<string> liczby3;
    vector<string> liczby4;

    int Max_1 = 0;
    int Max_2 = 0;
    int Max_r = 0;

    bool *tab;
    vector<int> pierwsze;

    tab = new bool[101];

    for (int i = 0; i <= 100; i++)
    {
        tab[i] = 0;
    }

    sito(tab, 100);

    for(int i = 2; i <= 100; i++)
    {
        if(!tab[i])
        {
            pierwsze.push_back(i);
        }
    }

    delete []tab;

    ifstream plik("przyklad.txt");

    while(!plik.eof())
    {
        getline(plik, linia);

        if(linia != "")
        {
            liczby.push_back(linia);
        }
    }
    
    for (int i = 0; i < liczby.size(); i++)
    {
        string temp = liczby[i];

        string liczba = temp.substr(0, 1);
        if(temp.substr(1, 1) != "")
        {
            liczba += temp[1];
        }
        
        int int_liczba = stoi(liczba);

        if(int_liczba > 4)
        {
            for(int j = 0; j < pierwsze.size(); j++)
            {
                int temp1 = pierwsze[j];

                for(int k = 0; k < pierwsze.size(); k++)
                {
                    int temp2 = pierwsze[k];

                    if(temp1 + temp2 == int_liczba)
                    {
                       liczby1.push_back(temp1);
                       liczby2.push_back(temp2); 
                    }

                    for(int l = 0; l < liczby1.size(); l++)
                    {
                        if(abs(liczby1[l] - liczby2[l]) > Max_r)
                        {
                            Max_r = abs(liczby1[l] - liczby2[l]);
                            Max_1 = liczby1[l];
                            Max_2 = liczby2[l];
                        }
                    }
                }
            }
        }
    }

    return 0;

}