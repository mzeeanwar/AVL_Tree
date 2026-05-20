#include <iostream>
#include <vector>
#include "PairingHeap.h"
using namespace std;

    // Test program
int main( )
{
    PairingHeap<int> h;

    int numItems = 4000;
    int i = 37;
    int j;

    cout << "Checking; no bad output is good" << endl;
    for( i = 37; i != 0; i = ( i + 37 ) % numItems )
        h.insert( i );
    for( i = 1; i < numItems; ++i )
    {
        int x;
        h.deleteMin( x );
        if( x != i )
            cout << "Oops! " << i << endl;
    }
