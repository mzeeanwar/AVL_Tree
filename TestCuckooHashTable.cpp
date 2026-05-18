#include <iostream>
#include <sstream>
#include "CuckooHashTable.h"
using namespace std;


// Pre-c++11 style; not all compilers have new to_string function
template <typename Object>
string toString( Object x )
{
    ostringstream oss;
    oss << x;
    return oss.str( );
}


    // Simple main
int main( )
{
    const int NUMS = 2000000;
    const int GAP  =   37;
    const int ATTEMPTS = 1;
    int i;

    cout << "Checking... (no more output means success)" << endl;

    for( int att = 0; att < ATTEMPTS; ++att )
