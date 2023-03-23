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

int NWD(int x, int y)
{
    while(x != y)
    {
        if(x > y)
        {
            x -= y;
        }
        else 
        {
            y -= x;
        }
    }

    return x;
}

int NWD_ciag(vector<int> vec)
{
    for (int i = 1; i < vec.size(); i++)
    {
        while(vec[i] != vec[i - 1])
        {
            if(vec[i] > vec[i - 1])
            {
                vec[i] -= vec[i - 1];
            }

            else
            {
                vec[i - 1] -= vec[i];
            }
        }
    }   
}

int main()
{
    string linia;
    vector<int> liczby;
    vector<int> _odp;
    ifstream plik("przyklad.txt");

    int licznik_poteg = 0;
    int ciag = 0;

    int Max_ciag;
    int Max_dziel;

    int dzielnik;

    vector<int> ciag_l;

    while (!plik.eof())
    {
        getline(plik, linia);

        if(linia != "")
        {
            liczby.push_back(stoi(linia));
        }
    }

    plik.close();
    
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

    for(int i = 1; i < liczby.size(); i++)
    {   
        

        if(ciag > Max_ciag)
        {
            Max_ciag = ciag;
        }

        ciag = 0;
    }
    
        
    cout << "4.1" << " " << licznik_poteg << endl;
    cout << "4.2" << endl;

    for (int i = 0; i < _odp.size(); i++)
    {
        cout << _odp[i] << endl;
    }

    cout << "4.3" << " " << Max_ciag << " " << Max_dziel << endl;
    
    return 0;
}