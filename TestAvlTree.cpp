#include <iostream>
#include "AvlTree.h"
using namespace std;

    // Test program
int main( )
{
    AvlTree<int> t;
    int NUMS = 2000000;
    const int GAP  =   37;
    int i;

    cout << "Checking... (no more output means success)" << endl;

    for( i = GAP; i != 0; i = ( i + GAP ) % NUMS )
        t.insert( i );
    t.remove( 0 );
    for( i = 1; i < NUMS; i += 2 )
        t.remove( i );
