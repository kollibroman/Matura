#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>

using namespace std;

int silnia(int n)
{
    int silnia = 1;
    for (int i = 0; i <= n; i++)
    {
        silnia *= i;
    }

    return silnia;
}

int main()
{
    string linia;
    vector<int> liczby;
    vector<string> silniowe_l;
    vector<int> _odp;
    ifstream plik("przyklad.txt");

    int licznik_poteg = 0;
    int temp_sil = 0;

    while (!plik.eof())
    {
        getline(plik, linia);

        if(linia != "")
        {
            silniowe_l.push_back(linia);
            liczby.push_back(stoi(linia));
        }
    }

    //4.1
    for (int i = 0; i <= liczby.size(); i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            if(pow(3, j) == liczby[i])
            {
                licznik_poteg++;
            }
        }
    }

    //4.2
    for (int i = 0; i < silniowe_l.size(); i++)
    {
        string temp = silniowe_l[i];

        for(int j = 0; j < temp.length(); j++)
        {
            temp_sil += silnia(temp[i]);

            if(temp_sil == stoi(temp))
            {
                _odp.push_back(temp_sil);
            }
        }

        temp_sil = 0;
    }
    
        
    cout << "4.1" << " " << licznik_poteg << endl;
    cout << "4.2" << endl;
    for (int i = 0; i < _odp.size(); i++)
    {
        cout << _odp[i] << endl;
    }
    
    return 0;
}