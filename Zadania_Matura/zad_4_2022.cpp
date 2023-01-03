#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    
    string linie;
    ifstream plik("./Dane_2205/przyklad.txt");

    if(!plik.good())
    {
        cout << "Dupa" << endl;
    }

    while (!plik.eof())
    {
        getline(plik, linie);
    }
    

}