#include<iostream>
#include<fstream>
#include<vector>

int liczba_segmetow(std::vector<int> vec)
{
    return (vec.back() * (vec.back() + 1)) / 2;
}

int main()
{
    std::string linia;

    std::ifstream plik("dane1_3.txt");

    std::vector<int> liczby;

    int suma = 0;

    while(!plik.eof())
    {
        std::getline(plik, linia);

        if(linia != "")
        {
            liczby.push_back(std::stoi(linia));
        }
    }

    for(int i = 0; i < liczby.size(); i++)
    {
        
    }

    std::cout << suma << std::endl;

    return 0;
}