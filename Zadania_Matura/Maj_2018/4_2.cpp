#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>

int main()
{
    std::string linia;
    std::ifstream plik("sygnaly.txt");

    std::vector<std::string> sygnaly;
    std::vector<std::string> sorted;

    int licznik = 0;
    int Max_rozne = 0;
    std::string Max_rozne_nazwa;

    while(!plik.eof())
    {
        getline(plik, linia);

        if(linia != "")
        {
            sygnaly.push_back(linia);
        }
    }

    for (int i = 0; i < sygnaly.size(); i++)
    {
        auto temp = sygnaly[i];
        std::sort(temp.begin(), temp.end());
        sorted.push_back(temp);
    }
    
    for(int i = 0; i < sorted.size(); i++)
    {
        auto temp1 = sorted[i];
        auto temp2 = sygnaly[i];

        for (int j = 1; j < temp1.length(); j++)
        {
            if(temp1[j] != temp1[j - 1])
            {
                licznik++;
            }
        }
        
        if(licznik > Max_rozne)
        {
            Max_rozne = licznik;
            Max_rozne_nazwa = temp2;
        }

        licznik = 0;
    }

    plik.close();

    std::cout << Max_rozne << " " << Max_rozne_nazwa << std::endl;

    return 0;
}