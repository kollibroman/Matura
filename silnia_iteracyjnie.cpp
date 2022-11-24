#include <iostream>

using namespace std;

int main()
{
    int liczba, silnia=1;
    cout << "Silnia z liczby: ";
    cin>>liczba;
    for(int i=1; i<=liczba; i++){
        silnia *= i;
    }
    cout<<liczba<<"! = "<<silnia;
    return 0;
}
