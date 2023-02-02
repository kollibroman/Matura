#include <iostream>
#include <fstream>
using namespace std;

const int N=1000000;

bool czy_pierwsza(int n)
{
    int czynnik=2;
    while(czynnik*czynnik<=n)
    {
        if(n%czynnik==0) return false;
        else czynnik++;
    }
    return true;
}

void rozklad(int Dane [], int Pierwsze [])
{
    int wynik=0, ilemax=0, ilemin=10000, imax=0, imin=0, ile=0;
    for(int j=0; j<100; j++)
    {
        int liczba=Dane[j];
        wynik=0;
        ile=0;
        for(int i=0; i<liczba; i++)
        {
            wynik=liczba-Pierwsze[i];
            if(czy_pierwsza(wynik) and wynik>1 and Pierwsze[i]>=wynik) ile++;
        }
        if(ile>ilemax)
        {
            ilemax=ile;
            imax=liczba;
        }
        if(ile<ilemin)
        {
            ilemin=ile;
            imin=liczba;
        }
    }
    cout<<"ilemax"<<ilemax<<"dla liczby"<<imax<<endl;
    cout<<"ilemin"<<ilemin<<"dla liczby"<<imin<<endl;

}

int main()
{
    int *Pierwsze = new int [N];
    int Dane[100];
    for(int i=0; i<N; i++)
        if(czy_pierwsza(i))
        Pierwsze[i]=i;

    ifstream wej("liczby.txt");
    int z=0;
    while(!wej.eof())
    {
        wej>>Dane[z];
        z++;
    }
    rozklad(Dane, Pierwsze);

    return 0;
}