#include<iostream>

using namespace std;

void Sortowanie( int tab[], int size )
{
     int k;
    for( int i = 0; i < size; i++ )
     {
        k = i; 
        
        for( int j = i + 1; j < size; j++ )
        if( tab[ j ] < tab[ k ] )
        k = j;

        swap( tab[ k ], tab[ i ] );
    }
}


int main()
{

}