#include<iostream>
using namespace std;

int main()
{
    string input;
    string input_1, input_2;
    cout << "Podaj Swoje Imie i nazwisko:";
    cin >> input_1 >> input_2;

    input = input_1 + input_2;

    cout << " Twoje imie sklada sie z " << input.length() << " liter";
    return 0;
}