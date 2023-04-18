#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main()
{
    string linia;
    vector<string> plansze;

    vector<vector<string>>  pelne_plansze;
    vector<string> temp_plansza;

    int puste_kolumny_plansze = 0;
    int puste_kolumny = 0;
    int Max_puste_kolumny = 0;

    ifstream plik("szachy_przyklad.txt");

    while(!plik.eof())
    {
        getline(plik, linia);

        plansze.push_back(linia);
    }

    plik.close();

    for(int i = 0; i < plansze.size(); i++)
    {
        string temp = plansze[i];

        temp_plansza.push_back(temp);

        if(i % 8 == 0)
        {
            pelne_plansze.push_back(temp_plansza);
            temp_plansza.clear();
        }
    }

    int i = 0;

    for(auto plansza: pelne_plansze)
    { 
        for (int i = 0; i < 8; i++)
        {
            if(plansza[i] == ".")
            {
                puste_kolumny_plansze++;
                puste_kolumny++;
            }

            if(puste_kolumny > Max_puste_kolumny)
            {
                Max_puste_kolumny = puste_kolumny;
            }

            puste_kolumny = 0;
            
        }
                
    }

    cout << "1.1" << " " << puste_kolumny_plansze << " " << Max_puste_kolumny << endl;

    return 0;
}