#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
using namespace std;

const int N = 1000;

bool czy_pierwsza(int n)
{
    for (int i = 2; i < n; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    
    return true;
}

int NWD(int a, int b)
{
    while (a != b)
    {
        if(a > b)
        {
            a -= b;
        }

        if(a < b)
        {
            b -= a;
        }
    }
    return a;
}

int main()
{
    string linia;

    ifstream plik("liczby.txt");

    int M[N];
    int a[N];
    int b[N];
    int z = 0;

    int pierwsze = 0;
    int jedynki = 0;
    int trojki = 0;

	int m, A, B;

    while (!plik.eof())
    {
        plik >> M[z] >> a[z] >> b[z];
	    z++;	
    }
	
    
    for(int i = 0; i < 1000; i++)
    {
       if(czy_pierwsza(M[i]))
       {
            pierwsze++;
       }

       if(NWD(M[i], a[i]) == 1)
       {
            jedynki++;
       }        
    }
    
    cout << "3.3 "<< pierwsze << endl;
    cout << "3.4 "<< jedynki << endl;  
    cout << "3.5 "<< trojki << endl;   

    plik.close();

    return 0;
}