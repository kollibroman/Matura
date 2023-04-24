#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

bool czy_rownowaga(vector<string> &plansza)
{
    int liczba_bialych = 0;
    int liczba_czarnych = 0;

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            char figura = plansza[i][j];

            if(figura >= 'a' &&  figura <= 'z')
            {
                liczba_czarnych++;
            }

            else if(figura >= 'A' &&  figura <= 'Z')
            {
                liczba_bialych++;
            }
        }
    }

    return liczba_bialych == liczba_czarnych;
}

int main()
{
    ifstream plik("szachy_przyklad.txt");

    int plansze_w_rownowadze = 0;
    int najm_liczba_bierek = 32;

    while(!plik.eof())
    {
        vector<string> plansza(8);

        for(int i = 0; i < 8; i++)
        {
            getline(plik, plansza[i]);
        }

        plik.ignore();

        if(czy_rownowaga(plansza))
        {
            plansze_w_rownowadze++;

            int liczba_bierek = 0;

           for (int i = 0; i < 8; i++)
           {
                for(int j = 0; j < 8; j++)
                {
                    char figura = plansza[i][j];

                    if(figura != '.')
                    {
                        liczba_bierek++;
                    }
                }
           }
           
            najm_liczba_bierek = min(najm_liczba_bierek, liczba_bierek);
        }
    }

    cout << plansze_w_rownowadze << " " << najm_liczba_bierek << endl;

    return 0;
}