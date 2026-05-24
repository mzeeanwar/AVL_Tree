    #include <iostream>
    #include "SplayTree.h"
    using namespace std;

        // Test program
    int main( )
    {
        SplayTree<int> t;
        int NUMS = 30000;
        const int GAP  =   37;
        int i;

        cout << "Checking... (no more output means success)" << endl;

        for( i = GAP; i != 0; i = ( i + GAP ) % NUMS )
            t.insert( i );

        for( i = 1; i < NUMS; i+= 2 )
            t.remove( i );
