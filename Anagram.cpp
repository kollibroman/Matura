#include<iostream>
#include<cstring>
using namespace std;
 
bool czy_anagram(char *a, char *b)
{
	//wyznaczenie liczby liter w slowie a i w slowie b
  	int dl1 = strlen(a), dl2 = strlen(b);
  	//jesli dlugosci wyrazów nie sa równe, to nie moga
  	//byc anagramy
	
    if(dl1!=dl2)
        return false;
  
  	int licz[127]={}; //zerujemy licznniki

  	for(int i=0;i<dl1;i++)
  	{
        licz[a[i]]++; //zliczamy litery pierwszego wyrazu
    }

  	for(int i=0;i<dl1;i++)
    {
  		licz[b[i]]--; //odejmowanie wystapien liter
    }
  		
  	for(int i=0;i<127;i++)
    {
  		if(licz[i]!=0) //jesli ktorys licznik sie nie wyzerowal
			return false; //to oznacza, ze słowa nie sa anagramami
    }
		
     return true; //jesli wszystkie liczniki sie wyzerowały, to mamy anagramy
} 
 
int main()
{
 
   char a[101], b[101]; //dwa słowa, maksymalnie 100 znaków
   cout<<"Podaj dwa wyrazy: ";
   cin>>a>>b;
 
   if(czy_anagram(a,b))
     cout<<"Podane wyrazy sa anagramami\n";
   else
     cout<<"Podane wyrazy nie są anagramami\n";
 