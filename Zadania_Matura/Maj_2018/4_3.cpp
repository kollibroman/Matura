#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

bool odleglosc(char x, char y)
{
    if(abs(x - y) <= 10)
    {
        return true;
    }

    return false;
}

int main()
{
    std::string linia;
    std::ifstream plik("przyklad.txt");

    std::vector<std::string> sygnaly;
    std::vector<bool> logika;
    std::vector<std::string> prawdziwe;

    while (!plik.eof())
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

        for (int i = 1; i < temp.length(); i++)
        {
            if(odleglosc(temp[i], temp[i - 1]))
            {
                logika.push_back(true);
            }
            else
            {
                logika.push_back(false);
            }
        }
        
        if(std::all_of(logika.begin(), logika.end(), [](bool v){ return v; }))
        {
            prawdziwe.push_back(temp);
        }

        logika.clear();
    }
    
    
    plik.close();

    for (int i = 0; i < prawdziwe.size(); i++)
    {
        std::cout << prawdziwe[i] << std::endl;
    }
    

    return 0;
}