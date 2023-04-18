#include<iostream>
#include<fstream>
#include<vector>

bool czy_palindrom(std::string str)
{
    std::string add_first = str[0] + str;
    std::string add_last = str[49] + str;

    std::string reverse1;
    std::string reverse2;

    for (int i = add_first.length() - 1; i >= 0; i--)
    {
        reverse1 += add_first[i];
        reverse2 += add_last[i];
    }
    
    if(reverse1 == add_first)
    {
        return true;
    }

    if(reverse2 == add_last)
    {
        return true;
    }

    // std::cout << add_first << std::endl;
    // std::cout << add_last << std::endl;

    return false;
}

std::vector<int> pogrupowane_cyfry(std::vector<std::string> vec_str)
{
    std::vector<int> grupy;

    std::string temp_str = "";

    int licznik_cyfr = 0;

    for(int i = 0; i < vec_str.size(); i++)
    {
       std::string temp = vec_str[i];
       
            for(int j = 0; j < temp.length(); j++)
            {
                if(temp[j] >= '0' && temp[j] <= '9')
                {
                    licznik_cyfr++;

                    temp_str += temp[j];
                }

                if(temp_str.length() == 2)
                {
                    int temp_int = stoi(temp_str);
                    
                    if(temp_int >= 65 && temp_int <= 90)
                    {
                        grupy.push_back(stoi(temp_str));
                    }
                    temp_str.clear();
                }
            }
    }
    std::cout << "dupa" << std::endl;
    return grupy;
}

int main()
{
    std::string linia;
    std::vector<std::string> napisy;

    std::ifstream plik("napisy.txt");

    int cyferki = 0;
    int dwudziestki = 0;

    int wielokrotnosc = 1;

    std::string haslo = "";
    std::string haslo2 = "";
    std::string haslo3 = "";

    std::vector<int> grupy;

    while(!plik.eof())
    {
        std::getline(plik, linia);

        if(linia != "")
        {
            napisy.push_back(linia);
        }
    }

    for(int i = 0; i < napisy.size(); i++)
    {
        std::string temp = napisy[i];

        for(int j = 0; j < temp.length(); j++)
        {
            if(temp[j] >= '0' && temp[j] <= '9')
            {
                cyferki++;
            }
        }
    }

    for(int p = 0; p < napisy.size(); p++)
    {
        std::string temp1 = napisy[p];

        if (p != 0 && p == (20 * wielokrotnosc)-1)
        {
            haslo += temp1[dwudziestki];
            dwudziestki++;
            wielokrotnosc++;
        }
    }

    for (int i = 0; i < napisy.size(); i++)
    {
        std::string temp2 = napisy[i];

        if(czy_palindrom(temp2))
        {
           haslo2 += temp2[25];
        }
    }

    grupy = pogrupowane_cyfry(napisy);
    
    for(int i = 0; i < grupy.size(); i++)
    {
        std::cout<<grupy[i]<<std::endl;
        if(char(grupy[i]) == char(grupy[i +1]) && char(grupy[i]) == 'X')
        {
            break;
        }
        else
        {
            haslo3 += char(grupy[i]);
        }
    }

    std::cout << "4.1:" << " " << cyferki << std::endl;
    std::cout << "4.2:" << " " << haslo << std::endl;
    std::cout<< "4.3:" << " " << haslo2 << std::endl;
    std::cout<< "4.4:" << " " << haslo3 << std::endl;

    return 0;
}