#include<iostream>
#include<vector>
using namespace std;

vector<int> liczby;

int sym(int a, int b)
{
	if(a != 0)
	{
		sym(a - 1, b + 1);
		cout << a * b << " ";
		liczby.push_back(a * b);
		sym(a - 1, b + 1);
	}
	return 0;
}

int main()
{
	sym(10 , 2020);
	cout << " " << liczby.size();
	return 0;
}