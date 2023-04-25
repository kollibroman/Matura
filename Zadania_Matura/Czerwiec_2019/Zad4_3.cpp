#include<iostream>
#include<fstream>
#include<vector>
#include<string>

int waga_int(std::string str)
{
    int waga = 0;

    for(int i = 0; i < str.length(); i++)
    {
        waga += std::stoi(str.substr(i,1));
    }

    if(waga <= 9)
    {
        return waga;
    }
    else
    {
        return waga_int(std::to_string(waga));
    }
}

int main()
{
    std::string linia;

    std::ifstream plik("pierwsze.txt");
    std::ofstream wynik("wynik4_3.txt");

    std::vector<int> liczby;

    int waga = 0;

    while (plik >> linia)
    {
        if(linia != " " && waga_int(linia) == 1)
        {
            liczby.push_back(stoi(linia));
        }
    }
    
    for(int i = 0; i < liczby.size(); i++)
    {
        waga++;
        wynik << liczby[i] << std::endl;
    }

    plik.close();
    wynik.close();

    std::cout << "4.3 " << waga << std::endl;

    return 0;
}