#include<iostream>
#include<fstream>
#include<vector>

using namespace std;


int main()
{
    
    string linie;
    vector<string> liczby;
    vector<string> wazne_liczby;
    vector<int> liczby_int;
    vector<int> czynniki;
    int liczba_liczb = 0;
    ifstream plik("przyklad.txt");
    ofstream plik2("liczby_z_cznnikami.txt");

    if(!plik.good())
    {
        cout << "Dupa" << endl;
    }

    while (!plik.eof())
    {
        getline(plik, linie);
        liczby.push_back(linie);
    }

    for(int i = 0; i < liczby.size() - 1; i++)  //szukanie liczby ktorej pierwsza cyfra jest taka sama jak ostatnia
    {
        string temp = liczby[i];

        if(temp[0] ==  temp[temp.length() - 2])
        {
            wazne_liczby.push_back(temp);
            liczba_liczb++;
        }
    }

    for(int j = 0; j < liczby.size() - 1; j++) //konwersja
    {
        liczby_int.push_back(stoi(liczby[j]));
    }

    for(int i = 0; i < liczby_int.size(); i++)
    {
        for(int j = 2; j <= 9; j++)
        {
            if(liczby_int[i] % j == 0)
            {
                czynniki.push_back(j);
                j--;
            }
        }

        plik2 << liczby[i];

        for (int i = 0; i < czynniki.size(); i++)
        {
            plik2 << czynniki[i];

            if(czynniki[i] == czynniki.back() - 1)
            {
                plik2 << " \n";
                break;
            }
        }
    }

    cout << "ilosc liczb: " << liczba_liczb << endl;
    cout << "Pierwsza liczba: " << wazne_liczby[0] << endl;

    return 0;

}