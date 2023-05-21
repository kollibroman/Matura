#include<iostream>
#include<vector>
#include<cmath>

const int MAX = 10000;

std::vector<int> primes;

void sieveSundaram()
{
    // In general Sieve of Sundaram, produces primes smaller
    // than (2*x + 2) for a number given number x. Since
    // we want primes smaller than MAX, we reduce MAX to half
    // This array is used to separate numbers of the form
    // i + j + 2*i*j from others where 1 <= i <= j
    bool marked[MAX/2 + 100] = {0};
 
    // Main logic of Sundaram. Mark all numbers which
    // do not generate prime number by doing 2*i+1
    for (int i=1; i<=(sqrt(MAX)-1)/2; i++)
    {
        for (int j=(i*(i+1))<<1; j<=MAX/2; j=j+2*i+1)
        {
            marked[j] = true;
        }
    }
        
    // Since 2 is a prime number
    primes.push_back(2);
 
    // Print other primes. Remaining primes are of the
    // form 2*i + 1 such that marked[i] is false.
    for (int i=1; i<=MAX/2; i++)
    {
        if (marked[i] == false)
        {
            primes.push_back(2*i + 1);
        }
    }
}

