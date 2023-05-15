#include<iostream>
#include<fstream>
#include<vector>
#include<string>

int main()
{
    std::string linia;
    std::ifstream plik("sygnaly.txt");
    std::vector<std::string> sygnaly;

    std::string haslo = ""; 

    while (!plik.eof())
    {
        getline(plik, linia);

        if (linia != "")
        {
            sygnaly.push_back(linia);
        }
    }
    
    for (int i = 39; i < sygnaly.size(); i += 40)
    {
        haslo += sygnaly[i][9];
    }
    

    plik.close();

    std::cout << haslo << std::endl;

    return 0;
}