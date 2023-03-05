#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
    string linia;
    vector<string> pary;

    ifstream if_plik("przyklad.txt");

    string liczba;
    string litery;

    struct para
    {
        int liczba;
        string litery;
    };

    vector<para> rowne;

    para najmn_para
    {
        0,
        ""
    };

    while (!if_plik.eof())
    {
        getline(if_plik, linia);

        if(linia != "")
        {
            pary.push_back(linia);
        }
    }

    for(int i = 0; i < pary.size(); i++)
    {
        string temp = pary[i];

        if(temp.substr(1,1) == " ")
        {
            liczba = temp.substr(0,1);
            litery = temp.substr(2, temp.length() - 1);

            if(stoi(liczba) == litery.length())
            {
                rowne.push_back(para 
                {
                    stoi(liczba),
                    litery
                });
            }

            liczba.clear();
            litery.clear();
        }

        else if(temp.substr(2,1) == " ")
        {
            liczba = temp.substr(0,2);
            litery = temp.substr(3, temp.length() - 1);

           if(stoi(liczba) == litery.length())
            {
                rowne.push_back(para 
                {
                    stoi(liczba),
                    litery
                });
            }

            liczba.clear();
            litery.clear();
        }
    }

    for(int j = 0; j < rowne.size(); j++)
    {
        para para1 = rowne[j];

        for(int k = 0; k < rowne.size(); k++)
        {
            para para2 = rowne[k];

            sort(para1.litery.begin(), para1.litery.end());
            sort(para2.litery.begin(), para2.litery.end());
            
            if(-para1.liczba < para2.liczba)
            {
                najmn_para = para1;
            }

            else if(-para1.liczba == para2.liczba && para1.litery < para2.litery)
            {
                najmn_para = para1;
            }
        }
    }

    if_plik.close();
    cout << najmn_para.liczba << " " << najmn_para.litery << endl;

    return 0;
}