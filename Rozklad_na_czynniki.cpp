#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    int liczba, pierwsza;

    cout << "Podaj liczbe: ";
    cin >> liczba;

    pierwsza = 2;
    while(liczba>1)
    {
        // sprawdz czy liczba dzieli sie bez reszty
        while(liczba % pierwsza == 0)
        {
            cout << pierwsza << " ";
            liczba = liczba / pierwsza; // podziel liczbe
        }
        pierwsza++; // sprawdz kolejna liczbe
    }
    
    return 0;
}