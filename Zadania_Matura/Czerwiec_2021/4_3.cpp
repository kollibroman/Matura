#include<iostream>
#include<fstream>

bool czy_palindrom(std::string str)
{
   std::string rev_str = "";

   for (int i = str.length(); i >= 0; i--)
   {
        rev_str += str[i];
   }

   if(rev_str == str);
   {
        return true;
   }
   return false;
}

//do poprawki

int main()
{
    std::ofstream wyniki("wyniki.txt");
    std::ifstream plik("przyklad.txt");
    std::string s;
    while (plik >> s)
    {
        for(char c = '0'; c <= 'Z'; c++)
        {
            std::string tmp = c + s;

            if(czy_palindrom(tmp))
            {
                wyniki << tmp[s.length()/2];
                break;
            }

            tmp = s + c;

            if(czy_palindrom(tmp))
            {
                wyniki<< tmp[s.length()/2];
                break;
            }
        }
    }
    
   wyniki.close();
   plik.close();

   return 0;
}