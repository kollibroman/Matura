#include<iostream>
using namespace std;

static int Pole_prostokata(int a, int b)
{
    return a * b;
}

int main()
{
    int a,b;
    cout << "Podaj dwie wartosci dlugosci bokow prostokata: ";
    cin >>  a >> b;

    cout << "Pole tego prostokata to: " << Pole_prostokata(a, b);

    return 0;
}

