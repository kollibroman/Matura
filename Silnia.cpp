#include <iostream>
using namespace std;

 static unsigned long long int Silnia_z_Liczby(int liczba)
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


   

