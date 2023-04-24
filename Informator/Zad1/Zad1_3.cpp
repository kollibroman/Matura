#include<iostream>
#include<fstream>
#include<vector>

int main()
{
    std::string linia;

    std::ifstream plik("dane1_3.txt");

    std::vector<int> liczby;

    while(!plik.eof())
    {
        std::getline(plik, linia);

        if(linia != "")
        {
            liczby.push_back(std::stoi(linia));
        }
    }

    

    return 0;
}