#include <iostream>
#include "RedBlackTree.h"
using namespace std;

    // Test program
int main( )
{
    const int NEG_INF = -9999;
    RedBlackTree<int> t{ NEG_INF };
    int NUMS = 400000;
    const int GAP  =   37;
    int i;

    cout << "Checking... (no more output means success)" << endl;

    for( i = GAP; i != 0; i = ( i + GAP ) % NUMS )
        t.insert( i );
