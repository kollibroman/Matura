#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main()
{
    string imie, nazwisko;
    int telefon;
    string linia;
    int numer_linii = 1;

    // cout << "Podaj imie: ";
    //     cin >> imie;
    // cout << "Podaj nazwisko: ";
    //     cin >> nazwisko;
    // cout << "Podaj numer telefonu: ";
    //     cin >> telefon;



    fstream plik;
    //plik.open("Wizytowka.txt", ios::out | ios::app);
    plik.open("Wizytowka.txt", ios::in);

    if(!plik.good())
    {
        cout << "Nie mozna otworzyc pliku";
    }

    while (!plik.eof())     //ZAPAMIĘTAĆ!!!!!
    {
        getline(plik, linia);
        numer_linii++;
    }
    
    plik.close();

    // plik<<imie<<endl;
    // plik<<nazwisko<<endl;
    // plik<<telefon<<endl;

    cout << imie << endl;
    cout << nazwisko << endl;
    cout << telefon << endl;

    return 0;
}