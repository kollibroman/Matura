#include<iostream>
#include<fstream>

int RSA(int M, int a, int x)
{
   int wynik = 1;

   while(x > 0)
   {
		if(x % 2 == 1)
		{
			wynik = (wynik * a) % M;
		}

		a = (a*a) % M;
		x /= 2;
   }

   return wynik;
}

int main()
{
    int a, b, M;
    int trojki = 0;

    std::ifstream plik("liczby.txt");

    while (plik >> M >> a >> b)
	{
		bool znaleziono =  false;

		for (int i = 0; i < M; i++)
		{
			if(RSA(M,i,a) == b)
			{
				znaleziono = true;
				break;
			}
		}

		if(znaleziono)
		{
			trojki++;
		}
	}

    std::cout<<trojki<<std::endl;
}