#include<iostream>
#include<fstream>
#include<vector>

int main()
{
    int A[1000];
    int B[1000];

    int i = 0;

    std::ifstream plik("pary.txt");

    while (!plik.eof())
    {
        plik >> A[i] >> B[i];

        i++;
    }
    

}