#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>

bool odleglosc(char x, char y)
{
    if(abs(int(x) - int(y)) <= 10)
    {
        return true;
    }

    return false;
}

bool allEqual(std::vector<bool> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[0] != v[i]) {
            return false;
        }
    }
    return true;
}

int main()
{
    std::string linia;
    std::ifstream plik("sygnaly.txt");

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

        for (int j = 0; j < temp.length(); j++)
        {
            for (int k = 0; k < temp.length(); k++)
            {
                if (odleglosc(temp[j], temp[k])) {
                    logika.push_back(odleglosc(temp[j], temp[k]));
                }
                else
                {
                    logika.push_back(false);
                }
            }
        }
        
        if(allEqual(logika))
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