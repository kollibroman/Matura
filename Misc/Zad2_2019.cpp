#include<iostream>

using namespace std;
int wywolania = 0;
void pisz(string s, int n, int k)
{
    wywolania++;
    string napis[] = {"0", "1", "2", "3", "4"};

    if(s.length() == n)
    {
        cout << s << endl;
    }

    else
    {
        for(int i = 0; i <= k - 1; i++)
        {
            pisz(s + napis[i], n, k);
        }
    }
}


int main()
{
    pisz("", 2, 3);
    cout << wywolania << endl;
}