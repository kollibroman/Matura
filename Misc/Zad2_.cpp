#include<iostream>
#include<vector>

void modyfikuj(int s, int k)
{
    std::vector<int> T = {4, 2, 6, 2, 9, 3, 5, 2, 7, 4, 3, 2, 3};

    if(s+k < T.size())
    {
        modyfikuj(s+k, k);
    }

    int i = s+1;
    while (i < T.size() && i <= s+k)
    {
        T[s] = T[s] + T[i];
        i++;
    }

    for (int i = 0; i < T.size(); i++)
    {
        std::cout << T[i] << " ";
    }
    std::cout<< " " << std::endl;
}

int main()
{
    modyfikuj(4,4);

    return 0;
}