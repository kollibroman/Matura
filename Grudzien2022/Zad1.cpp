#include<iostream>
#include<fstream>
#include<vector>

int main()
{
    std::string linia;
    std::ifstream plik("mecz.txt");

    int rozne = 0;
    int A = 0;
    int B = 0;

    int licznik = 0;
    int licznik_pass = 0;
    int Max_passa;
    std::string Max_passa_l;

    std::string passa = "";

    std::string wynik;
    std::string druzyna;

    getline(plik, linia);
    
    for(int i = 0; i < linia.length() - 1; i++)
    {
        if(linia[i] != linia[i+1])
        {
            rozne++;
        }
    }

    for (int i = 0; i < linia.length(); i++)
    {
        if(linia[i] == 'A')
        {
            A++;
        }

        if(linia[i] == 'B')
        {
            B++;
        }

        if(A >= 1000 && A - B >= 3)
        {
            druzyna = "A";
            wynik = std::to_string(A) + ":" + std::to_string(B);
            break;
        }

        if(B >= 1000 && B - A >= 3)
        {
            druzyna = "B";
            wynik = std::to_string(B) + ":" + std::to_string(A);
            break;
        }
    }
    
    for (int i = 1; i < linia.length(); i++)
    {
        if(linia[i] == linia[i-1])
        {
            licznik++;
        }

        else if(licznik >= 10)
        {
            licznik_pass++;

            if(licznik > Max_passa)
            {
                Max_passa = licznik;
                Max_passa_l = linia[i - 1];
            }
            licznik = 0;
        }
        else 
        {
            licznik = 0;
        }
    }
    
    plik.close();

    std::cout << "1.1: " << rozne << std::endl;
    std::cout << "1.2: " << druzyna << " " << wynik << std::endl;
    std::cout << "1.3: " << licznik_pass << " " << Max_passa_l << " " << Max_passa + 1 << std::endl;
    return 0;
}