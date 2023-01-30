#include<iostream>
#include<fstream>

const int N = 1000;

int main()
{
	std::ifstream plik("pary.txt");
	int A[N], B[N], z = 0;

	while (!plik.eof())
	{
		plik >> A[z] >> B[z];
		z++;
	}

	for (int i = 0; i < N; i++)
	{
		int temp = B[i];
		int temp1 = A[i];

		while (temp > temp1)
		{
			if ((temp % 2 == 0))
			{
				temp /= 2;
			}

			else
			{
				temp -= 1;
			}
		}

		if (temp == temp1)
		{
			std::cout << temp1 << ":" << temp << std::endl;
		}
	}
}