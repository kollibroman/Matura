#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>

std::string szesnastkowe(int x)
{
    std::stringstream ss;
    ss << std::hex << x;

    return ss.str();
}

int main()
{   
    std::string linia;
    int liczby[1000];
    int i = 0;
    std::ifstream plik("liczby.txt");
    std::ofstream wynik("wynik3_4.txt");
    std::string liczby2;

    wynik.clear();

    int zero = 0;
    int jeden = 0;
    int dwa = 0;
    int trzy = 0;
    int cztery = 0;
    int piec = 0;
    int szesc = 0;
    int siedem = 0;
    int osiem = 0;
    int dziewiec = 0;
    int A = 0;
    int B = 0;
    int C = 0;
    int D = 0;
    int E = 0;
    int F = 0;

    while (!plik.eof())
    {
        plik >> liczby[i];
        i++;
    }
    
    for (int j = 0; j <= 1000; j++)
    {
        wynik << szesnastkowe(liczby[j]) << std::endl; 
        liczby2 += szesnastkowe(liczby[j]); 
    }
    
    std::sort(liczby2.begin(), liczby2.end());
    
    for (int j = 0; j < liczby2.length(); j++)
    {
        switch (liczby2[j])
        {
            case '0':
                zero++;
                break;
            case '1':
                jeden++;
                break;
            case '2':
                dwa++;
                break;
            case '3':
                trzy++;
                break;
            case '4':
                cztery++;
                break;
            case '5':
                piec++;
                break;
            case '6':
                szesc++;
                break;
            case '7':
                siedem++;
                break;
            case '8':
                osiem++;
                break;
            case '9':
                dziewiec++;
                break;
            case 'a':
                A++;
                break;
            case 'b':
                B++;
                break;
            case 'c':
                C++;
                break;
             case 'd':
                D++;
                break;
            case 'e':
                E++;
                break;
            case 'f':
                F++;
                break;
            default:
                break;
        }
    }

    plik.close();
    wynik.close();

    std::cout << "0: " << zero << std::endl;
    std::cout << "1: " << jeden << std::endl;
    std::cout << "2: " << dwa << std::endl;
    std::cout << "3: " << trzy << std::endl;
    std::cout << "4: " << cztery << std::endl;
    std::cout << "5: " << piec << std::endl;
    std::cout << "6: " << szesc << std::endl;
    std::cout << "7: " << siedem << std::endl;
    std::cout << "8: " << osiem << std::endl;
    std::cout << "9: " << dziewiec << std::endl;
    std::cout << "A: " << A << std::endl;
    std::cout << "B: " << B << std::endl;
    std::cout << "C: " << C << std::endl;
    std::cout << "D: " << D << std::endl;
    std::cout << "E: " << E << std::endl;
    std::cout << "F: " << F << std::endl;

    return 0;
}