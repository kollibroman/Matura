#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

bool pusta_kolumna(vector<string> &plansza, int kolumna)
{
    for (int wiersz = 0; wiersz < 8; wiersz++)
    {
        if(plansza[wiersz][kolumna] != '.')
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ifstream plik("szachy_przyklad.txt");

    int plansza_pusta_kolumna = 0;
    int maks_puste_kolumny = 0;

    while (!plik.eof())
    {
        vector<string> plansza(8);

        for (int i = 0; i < 8; i++)
        {
            getline(plik, plansza[i]);
        }
        plik.ignore();

        int puste_kolumny = 0;

        for (int j = 0; j < 8; j++)
        {
            if(pusta_kolumna(plansza, j))
            {
                puste_kolumny++;
            }
        }

        if(puste_kolumny > 0)
        {
            plansza_pusta_kolumna++;
        }
        maks_puste_kolumny = max(maks_puste_kolumny, puste_kolumny);
    }
    
    plik.close();

    cout << "1.1 " << plansza_pusta_kolumna << " " << maks_puste_kolumny << endl;

    return 0;
}