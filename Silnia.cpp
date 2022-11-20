#include <iostream>
using namespace std;

/* Rekurencyjnie
 static int Silnia_z_Liczby(int liczba)
    {
        if(liczba == 0)
        {
            return 1;
        }
        return liczba * Silnia_z_Liczby(liczba - 1);
    }
    int main()
    {
        int liczba;
        cout << "Podaj Liczbe: ";
        cin >> liczba;
        cout << Silnia_z_Liczby(liczba);
        return 0;
    }
*/

int main()
{
    int liczba, tymczasowa_liczba, wynik;
    cout << "podaj Liczbe: ";
    cin >> liczba;

    for(int i = liczba; i >= 0; i--)
    {
        tymczasowa_liczba = liczba - 1;
        wynik = liczba * tymczasowa_liczba;
    }
    cout << wynik;
    return 0;
}
   

