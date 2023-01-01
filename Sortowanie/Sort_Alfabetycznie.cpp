#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	string wyrazy[5];
	
	cout<<"Podaj pięć wyrazów:\n";
	
	//BASIA KASIA DARIA ANNA KAMILA
	for(int i=0; i<5; i++)
	{
		cin>>wyrazy[i];
	}
	
	sort(wyrazy, wyrazy+5);
	
	cout<<"Elementy posortowane:\n";

	for(int i=0; i<5; i++)
	{
		cout<<wyrazy[i]<<endl;
	}
	
	return 0;
}