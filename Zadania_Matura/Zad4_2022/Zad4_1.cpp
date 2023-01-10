#include<iostream>
#include<fstream>
#include<vector>
#include<map>

using namespace std;

int main()
{
    
    string linie;   //4.1
    vector<string> liczby;
    vector<string> wazne_liczby;

    vector<int> liczby_int;
    vector<int> czynniki;

    int liczba_liczb = 0;

    ifstream plik("przyklad.txt");

    //4.1
    if(!plik.good())
    {
        cout << "Dupa" << endl;
        return -1;
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

    cout << "ilosc liczb: " << liczba_liczb << endl;
    cout << "Pierwsza liczba: " << wazne_liczby[0] << endl;

    return 0;

}