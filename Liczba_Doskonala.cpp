#include<iostream>
#include<list>
using namespace std;

bool Czy_Liczba_Doskonala(int n)
{
   // int dzielniki[n];
    list<int> dzielniki;
    int suma = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        if(n % i == 0)
        {
            dzielniki.push_back(i);
        }
    }

    auto dzielniki_front = dzielniki.begin();

    for(int j = 0; j < dzielniki.size(); j++)
    {
        advance(dzielniki_front, j);    //znaleziony sposob na znalezienie dowolnej liczby w liscie, implementacja sumy wlasnoreczna
        suma += *dzielniki_front;       //to tez ze znalezienia, sam sposob, uzycie tutaj pointera w miare zrozumialem 
    }


    cout << suma << endl; //maly debug zeby zobaczyc ile ta suma wynosi
    if(suma == n)
    {
        return true;
    }
    else
    {
        return false;
    }    
}

int main()
{
    int n;
    cout << "Podaj Liczbe: ";
    cin >>  n;
    cout << Czy_Liczba_Doskonala(n) << endl;

    return 0;
}