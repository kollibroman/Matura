#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int liczba, n;
	
	//cout<<"Ile liczb będziesz chciał posortować? ";
	cin>>n;
	
	int p = 2000000000/n;  //zakres jednego kubełka 
	//przedziały dla kolejnych kubełkow: 
	//[0, p), [p, 2p), [2p, 3p), ..., [(n-1)p, n*p)
	
	vector<int>  kubelki[n]; //tworzymy kubełki
	
	//wczytanie liczb i wrzucenie ich do odpowiednich kubełków
	for(int i=0;i<n;i++)
	{
		cin>>liczba; 
		//wrzucam liczbę do odpowiedniego kubełka
		kubelki[liczba/p].push_back(liczba);
	}
	//sortowanie elementów w poszczególnych kubełkach
	for(int i=0;i<n;i++)
	{
		//sortujemy tylko, jesli kubełek ma co najmniej dwie liczby
		if(kubelki[i].size()>1)
		{
			sort(kubelki[i].begin(), kubelki[i].end());
		}
	}
	//wypisanie posortowanych liczb
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<kubelki[i].size();j++)
		{
			cout<<kubelki[i][j]<<' ';
		}
	}
	
	return 0;
}