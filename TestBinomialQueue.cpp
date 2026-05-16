#include "BinomialQueue.h"
#include <iostream>
using namespace std;

int main( )
{
    int numItems = 100000;
    BinomialQueue<int> h;
    BinomialQueue<int> h1;
    BinomialQueue<int> h2;
    int i = 37;

    cout << "Begin test..." << endl;
    for( i = 37; i != 0; i = ( i + 37 ) % numItems )
        if( i % 2 == 0 )
            h1.insert( i );
        else
            h.insert( i );
