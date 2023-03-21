#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main()
{
    string linia;
    vector<string> litery;

    int powtorki = 0;
    string str_ciag = "";

    int Max_Ciag = 0;
    string Max_litera;

    ifstream if_plik("pary.txt");
    ofstream of_plik("odpowiedzi.txt");

    of_plik.clear();

    while (!if_plik.eof())
    {
        getline(if_plik, linia);

        if(linia != "")
        {
            litery.push_back(linia);
        }
    }

    for(int i = 0; i < litery.size(); i++)
    {
        string temp = litery[i];

        for (int j = 1; j < temp.length(); j++)
        {
            if(temp[j] == temp[j - 1])
            {
                str_ciag += temp[j];
                powtorki++;
            }

            else if(temp[j] == temp[j + 1])
            {
                str_ciag += temp[j];
                powtorki++;
            }

            if(temp[j] != temp[j + 1])
            {
                if(powtorki > Max_Ciag)
                {   
                    Max_Ciag = powtorki;
                    Max_litera = str_ciag;
                }

                str_ciag.clear();
                powtorki = 0;
            }
        }

        if(Max_Ciag == 0)
        {
            if(temp.substr(1, 1) == " ")
            {
                of_plik << temp[2] << " " << 1 << endl;
            }

            else if(temp.substr(2, 1) == " ")
            {
                of_plik << temp[3] << " " << 1 << endl;
            }
        }

        else
        {
            of_plik << Max_litera << " " << Max_Ciag << endl;
        }
        powtorki = 0;
        str_ciag.clear();
        Max_Ciag = 0;
        Max_litera.clear();
    }

    if_plik.close();
    of_plik.close();
    return 0;
        
}