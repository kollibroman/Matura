#include<iostream>
#include<fstream>
#include<string>

int main()
{   //do naprawienia
    std::ifstream plik("przyklad.txt");
    std::ofstream wynik("wynik.txt");
    std::string slowo = "";

    bool szukaj_hasla = true;

    int ilosc_X = 0;
    char haslo[4] = {'X', 'X', 'X', '\0'};
    char znak;

    while (plik.get(znak))
    {
        if(isdigit(znak))
        {
            slowo += znak;

            if(slowo.length() == 2)
            {
                int liczba = stoi(slowo);

                if(liczba >= 65 && liczba <= 90)
                {
                    char litera = char(liczba);

                    if(szukaj_hasla)
                    {
                        wynik << litera;

                        if(litera == haslo[ilosc_X])
                        {
                            ilosc_X++;
                            if(ilosc_X == 3)
                            {
                                szukaj_hasla = false;
                            }
                            else
                            {
                                ilosc_X = 0;
                            }
                        }
                    }
                    slowo = " ";
                }
            }
            else
            {
                slowo = " ";
            }
        }
    }

    wynik.close();
    plik.close();

    return 0;
}