#include <iostream>
#include "Treap.h"

using namespace std;

    // Test program
int main( )
{
    Treap<int> t;
    int NUMS = 200000;
    const int GAP  =   37;
    int i;

    cout << "Checking... (no more output means success)" << endl;
