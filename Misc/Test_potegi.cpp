#include<iostream>

int potega(int x, int n)
{
	unsigned long long wynik = 1;

	for (int i = 1; i <= n; i++)
	{
		wynik *= x;
	}
	return wynik;
}

int main()
{
	std::cout << potega(3, 10) << std::endl;

	return 0;
}