#include <iostream>
#include "QuadraticProbing.h"
using namespace std;

    // Simple main
int main( )
{
    HashTable<int> h1;
    HashTable<int> h2;

    const int NUMS = 4000;
    const int GAP  =   37;
    int i;

    cout << "Checking... (no more output means success)" << endl;

    for( i = GAP; i != 0; i = ( i + GAP ) % NUMS )
        h1.insert( i );
    
    h2 = h1;
