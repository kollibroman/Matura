#include<iostream>
#include<fstream>
#include<string>
#include<vector>

int main()
{
	std::string linia;
	std::ifstream plik("mecz.txt");
	
	int rozne = 0;
	int A = 0;
	int B = 0;
	char wygrany;

	int temp_passa = 0;
	int licznik_A = 0;
	int licznik_B = 0;
	int Max_passa = 0;
	std::string Max_passa_nazwa;


	while (!plik.eof())
	{
		std::getline(plik, linia);
	}

	//1.1
	for (int i = 1; i < linia.length(); i++)
	{
		if (linia[i] != linia[i - 1])
		{
			rozne++;
		}
	}

	//1.2
	for (int i = 0; i < linia.length(); i++)
	{
		if (linia[i] == 'A')
		{
			A++;
		}
		if (linia[i] == 'B')
		{
			B++;
		}

		if (A >= 1000 && A - B >= 3)
		{
			wygrany = 'A';
			break;
		}

		if (B >= 1000 && B - A >= 3)
		{
			wygrany = 'B';
			break;
		}
	}

	//1.3
	for (int i = 0; i < linia.length(); i++)
	{
		if (linia[i+1] == linia[i])
		{
			temp_passa++;
		}

		if(linia[i+1] != linia[i])
		{
			if (temp_passa >= 10 && linia[i] == 'A')
			{
				licznik_A++;
			}
			else if(temp_passa >= 10 && linia[i] == 'B')
			{
				licznik_B++;
			}

			if (temp_passa > Max_passa)
			{
				Max_passa = temp_passa;
				Max_passa_nazwa = linia[i];
			}

			temp_passa = 0;
		}
	}

	plik.close();
	std::cout << rozne << std::endl;
	std::cout << wygrany << " " << A << ":" << B << std::endl;
	std::cout << "A: " << licznik_A << " B: " << licznik_B << " Lacznie: " << licznik_A+licznik_B << " Maks: " << Max_passa << " " << Max_passa_nazwa << std::endl;
	return 0;
}