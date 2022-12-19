#include <iostream> 
#include<vector>
using namespace std;

void sito(int zakres) // na ten moment zle
{
    vector<bool> Is_prime;

    for (int i = 0; i < zakres; i++)
    {
        Is_prime[i] = true;        
    }

    int j = 2;
    do
    {
        for (int i = 0; i < zakres; i++)
        {
            Is_prime[j*i] = false;
        }
        
        j++;
    } while (j*j <= zakres);
    
    for(int i = 0; i < Is_prime.size(); i++)
    {
        cout << Is_prime.at(i);
    }
}   

int main()
{
    int zakres;
    cout << "Podaj zakres liczb: ";
    cin >> zakres;
    sito(zakres);
}