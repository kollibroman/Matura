#include<iostream>
#include<vector>
using namespace std;

void Fibonacci(int liczba_wyrazow)
{
    vector<int> ciag = { 1, 1 };

    for(int i = 2; i <= liczba_wyrazow; i++)
    {
        ciag.push_back(ciag[i - 1] + ciag[i - 2]);
    }

    for(int i = 0; i <= liczba_wyrazow; i++)
    {
        cout << " " << ciag[i] << " \n";
    }
}

int main()
{
    int wyrazy;
    cout << "Podaj liczbe poczotkowych wyrazow: ";
    cin >> wyrazy;
    Fibonacci(wyrazy);
}