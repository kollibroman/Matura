#include<iostream>
using namespace std;

int main()
{
    string input;
    cout << "Podaj Swoje Imie i nazwisko:";
    getline(cin, input);

    cout << " Twoje imie sklada sie z " << input.length() - 1 << " liter";
    return 0;
}