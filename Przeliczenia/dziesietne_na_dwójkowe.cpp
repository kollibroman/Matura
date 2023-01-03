#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

string dec2bin (int dziesietna)
{
    char binarna[255];
    itoa(dziesietna, binarna, 2); //funkcja itoa konwertuje liczbê na
                                  //³añcuch znaków w postaci okreœlonego systemu liczbowego.


    return (string)binarna;
}

int main()
{
    int liczba;

    cout << "Podaj liczbe dziesietna:" << endl;
    cin >> liczba;
    cout << dec2bin(liczba) << endl;

    system ("pause >nul");
    return 0;
}
