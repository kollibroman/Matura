#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main()          //Czystosc tego kodu nie istanieje
{
    string linia;
    int x, y, z, u, w;
    int trojki = 0;
    int piotki = 0;
    vector<int> liczby;

    ifstream if_plik("przyklad.txt");
    ofstream of_plik("trojki.txt");

    if(!if_plik.good())
    {
        cout << "Not good" << endl;
        return -1;
    }

    while (!if_plik.eof())
    {
        getline(if_plik, linia);

        if(linia != "")
        {
            liczby.push_back(stoi(linia));
        }
    }

    for (int i = 0; i < liczby.size(); i++) //szukanie trojek
    {
        x = liczby[i];
       
        for (int j = 0; j < liczby.size(); j++)
        {
            if(liczby[j] != x && liczby[j] % x == 0)
            {
                y = liczby[j];
              
                for (int k = 0; k < liczby.size(); k++)
                {
                    if(liczby[k] != x && liczby[k] != y && liczby[k] % y == 0)
                    {
                        z = liczby[k];

                        of_plik << x << " " << y << " " << z << endl;
                        trojki++;

                        for(int l = 0; l < liczby.size(); l++)
                        {
                            if(liczby[l] != x && liczby[l] != y && liczby[l] != z && liczby[l] % z == 0)
                            {
                                u = liczby[l];

                                for(int m = 0; m < liczby.size(); m++)
                                {
                                    if (liczby[m] != x && liczby[m] != y && liczby[m] != z && liczby[m] != u && liczby[m] % u == 0)
                                    {
                                        w = liczby[m];

                                        piotki++;
                                    }
                                    
                                }
                            }
                        }
                    }
                }
            }
        }
            x = 0;
            y = 0;
            z = 0;
            u = 0;
            w = 0;
    }

    cout << trojki << endl;
    cout << piotki << endl;

    return 0;
}