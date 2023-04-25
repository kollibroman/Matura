#include<iostream>
#include<fstream>
#include<vector>

int rev_int(std::string str)
{
    std::string rev_str = "";

    for(int i = str.length() - 1; i >= 0; i--)
    {
        rev_str += str[i];
    }

    return stol(rev_str);
}

bool is_prime(long n)
{
    for (int i = 2; i < n; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::string linia;

    std::ifstream plik("pierwsze_przyklad.txt");
    std::ofstream wynik("wynik4_2.txt");
    
    std::vector<int> liczby;

    while (plik >> linia && linia != "")
    {
        if(is_prime(rev_int(linia)))
        {
            liczby.push_back(stoi(linia));
        }
    }
    
    for (int i = 0; i < liczby.size(); i++)
    {
        wynik << liczby[i] << std::endl;
    }
    
    wynik.close();
    plik.close();
    return 0;
}