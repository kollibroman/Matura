#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>

bool czy_pierwsza(int n)
{
	int x = n - 1;

	for (int i = 2; i < x; i++)
	{
		if (x % i == 0) 
		{
			return false;
		}
	}

	return true;
}

bool czy_pierwsza1(int n)
{
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}

	return true;
}

std::vector<int> sito(int n)
{
	std::vector<int> pierwsze;

	for (int i = 1; i < n; i++)
	{
		if (czy_pierwsza1(i)) {
			pierwsze.push_back(i);
		}
	}

	return pierwsze;
}

int hipoteza(int n)
{
	int licznik_rozkladow;
	std::vector<int> pierwsze = sito(n);
	std::vector<int> czynniki;

	for (int i = 0; i < pierwsze.size(); i++)
	{
		for (int j = 0; j < pierwsze.size(); j++)
		{
			if (pierwsze[i] + pierwsze[j] == n) 
			{
				licznik_rozkladow++;
				czynniki.push_back(pierwsze[i]);
				czynniki.push_back(pierwsze[j]);

				for (int k = 0; k < czynniki.size(); k++)
				{
					if (pierwsze[i] == czynniki[k] || pierwsze[j] == czynniki[k])
					{
						licznik_rozkladow--;
					}
				}
			}
		}
	}
	return licznik_rozkladow;
}

std::string szesnastkowe(std::string str)
{
	std::stringstream ss;
	ss << std::hex << str;
	return ss.str();
}

int main()
{
	std::string linia;
	std::ifstream plik("liczby_przyklad.txt");
	std::vector<int> liczby;
	std::vector<std::string> szesnastki;
	std::vector<int> ilosci;

	char symbole[16] = { '1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };

	int liczby_pierwsze = 0;
	int Max_rozklad = 0;
	int Min_rozklad = 100;
	int Max_rozklad_liczba;
	int Min_rozklad_liczba;

	while (!plik.eof())
	{
		std::getline(plik, linia);
		if (linia != "")
		{
			liczby.push_back(std::stoi(linia));
		}
	}

	for (int i = 0; i < liczby.size(); i++)
	{
		if (czy_pierwsza(liczby[i]))
		{
			liczby_pierwsze++;
		}
	}

	for (int i = 0; i < liczby.size(); i++)
	{
		int temp = hipoteza(liczby[i]);

		if (temp > Max_rozklad)
		{
			Max_rozklad = temp;
			Max_rozklad_liczba = liczby[i];
		}
		if (temp < Min_rozklad)
		{
			Min_rozklad = temp;
			Min_rozklad_liczba = liczby[i];
		}
	}

	for (int i = 0; i < liczby.size(); i++)
	{
		szesnastki.push_back(szesnastkowe(std::to_string(liczby[i])));
	}

	for (int i = 0; i < szesnastki.size(); i++)
	{
		for(int j = 0; j <= 16; j++)
		{
			ilosci.push_back(std::count(szesnastki.begin(), szesnastki.end(), symbole[j]));
		}
	}

	plik.close();

	std::cout << liczby_pierwsze << std::endl;
	std::cout << Max_rozklad_liczba << " " << Max_rozklad << Min_rozklad_liczba << " " << Min_rozklad << std::endl;

	for (int i = 0; i <= 16; i++)
	{
		std::cout << symbole[i] << ": " << ilosci[i] << std::endl;
	}

	return 0;
}