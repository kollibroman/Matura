#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>

using namespace std;

int silnia(int n)
{
    int silnia = 1;

    for (int i = 1; i <= n; i++)
    {
        silnia *= i;
    }

    return silnia;
}

int suma_silnii(string str)
{
    int suma = 0;

    for (int i = 0; i < str.length(); i++)
    {
        suma += silnia(stoi(str.substr(i, 1)));
    }
    
    return suma;
}

int main()
{
    string linia;
    vector<int> liczby;
    vector<int> _odp;
    ifstream plik("liczby.txt");

    int licznik_poteg = 0;
    int temp_sil = 0;

    while (!plik.eof())
    {
        getline(plik, linia);

        if(linia != "")
        {
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
    for (int i = 0; i < liczby.size(); i++)
    {
        int temp = liczby[i];

        if (suma_silnii(to_string(temp)) == temp)
        {
            _odp.push_back(temp);
        }
    }
    
        
    cout << "4.1" << " " << licznik_poteg << endl;
    cout << "4.2" << endl;

    for (int i = 0; i < _odp.size(); i++)
    {
        cout << _odp[i] << endl;
    }
    
    return 0;
}