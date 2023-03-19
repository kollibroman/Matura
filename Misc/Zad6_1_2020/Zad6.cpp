#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main()
{
    string linia;
    vector<int> liczby;

    ifstream plik("dane.txt");
    
    int suma = 0;

    while (!plik.eof())
    {
        getline(plik, linia);

        if(linia != "" && linia != "0")
        {
            liczby.push_back(stoi(linia));
        }
    }

    for (int i = 0; i < liczby.size(); i++)
    {
        suma += liczby[i];   
    }

    cout << suma << endl;

    return 0;
}