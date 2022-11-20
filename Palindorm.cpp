#include <iostream>
using namespace std;

int main()
{
    string input;
    string reverse_input;

    cout << "Podaj slowo: ";
    cin >> input;
    int j = 0;

    for(int i = input.length() - 1; i >= 0; i--)
    {
       reverse_input += input[i];
    }
    cout << reverse_input;

    if(reverse_input == input)
        cout << "slowo jest palindromem";
    
    else
        cout << "slowo nie jest palindromem";
    
    return 0;
}