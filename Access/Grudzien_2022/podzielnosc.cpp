#include<iostream>

int podzielnosc(int n)
{
	for (int i = 2; i < n-1; i++)
	{
		if (n % i == 0)
		{
			return i;
		}
	}

	return 1;
}

int main()
{
	std::cout << podzielnosc(2047) << std::endl;
}