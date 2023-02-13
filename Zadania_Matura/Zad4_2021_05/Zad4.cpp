#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    string slowo = "";
    string linia;
    ifstream plik("instrukcje.txt");
    vector<string> instrukcje;

    vector<char> alfabet = {'A','B','C','D','E','F',
		'G','H','I','J','K','L','M','N','O','P',
		'Q','R','S','T','U','V','W','X','Y','Z'};

    vector<string> ciagi_instrukcji;
    string slowo_ciagu;
    int dlugosc_ciagu = 0;
    int Max_dlugosc = 0;

    vector<char> litery;
    char najcz_litera;
    int ilosc_powtorek = 0;
    int Max_powtorek = 0;

    vector<string> komendy = {"DOPISZ", "ZMIEN", "USUN", "PRZESUN"};

    while (!plik.eof())
    {
        getline(plik, linia);

        if (linia != " ")
        {
            instrukcje.push_back(linia);
        }
    }

    plik.close();

    //4_1

    for(int i = 0; i < instrukcje.size(); i++)
    {
        string temp = instrukcje[i];

        for(int j = 0; j < komendy.size(); j++)
        {
            if(temp.find(komendy[j]) != string::npos)
            {
               if(j == 0)
               {
                    slowo.push_back(temp.back());

                    ciagi_instrukcji.push_back(komendy[j]);

                    litery.push_back(temp.back());
               }
               else if(j == 1)
               {
                    slowo.pop_back();
                    slowo.push_back(temp.back());
                    ciagi_instrukcji.push_back(komendy[j]);
               }
               else if(j == 2)
               {
                    slowo.pop_back();
                    ciagi_instrukcji.push_back(komendy[j]);
               }
               else if(j == 3)
               {
                    int l = slowo.find(temp.back());

                    if(slowo.find(temp.back()) != string::npos)
                    {
                        for(int k = 0; k < alfabet.size(); k++)
                        {
                            if(temp.back() == 'Z')
                            {
                                slowo[l] = 'A';
                            }

                            else if(temp.back() == alfabet[k])
                            {
                                slowo[l] = alfabet[k + 1];
                            }
                        }
                    }

                    ciagi_instrukcji.push_back(komendy[j]);
               }
               else
               {
                    cout << "nie ma nic do zrobienia" << endl;
               }
            }
        }
    }

    //4_2

    for(int i = 0; i < ciagi_instrukcji.size(); i++)
    {
        if (ciagi_instrukcji[i] == ciagi_instrukcji[i + 1])
        {
            dlugosc_ciagu++;
        }

        else
        {
            if(dlugosc_ciagu > Max_dlugosc)
            {
                slowo_ciagu = ciagi_instrukcji[i];
                Max_dlugosc = dlugosc_ciagu;
            }

            dlugosc_ciagu = 0;
        }   
    }

    //4_3
    sort(litery.begin(), litery.end());

    for(int i = 0; i < litery.size(); i++)
    {
        if(litery[i] == litery[i + 1])
        {
            ilosc_powtorek++;
        }

        else
        {
            if(ilosc_powtorek > Max_powtorek)
            {
                najcz_litera = litery[i];
                Max_powtorek = ilosc_powtorek;
            }

            ilosc_powtorek = 0;
        }
        
    }


    cout << "4_1: " << slowo.length() << endl;
    cout << "4_2:" << slowo_ciagu << " " << Max_dlugosc + 1 << endl;
    cout << "4_3:" << najcz_litera << " " << Max_powtorek + 1 << endl;
    cout << "4_4: "<< slowo << endl;

    return 0;
}