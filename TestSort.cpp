#include <iostream>
#include "Sort.h"
#include <vector>
#include <string>
#include "UniformRandom.h"

using namespace std;

void checkSort( const vector<string> & a )
{
    for( int i = 0; i < a.size( ); ++i )
        if( a[ i ].length( ) != i )
            cout << "Error at " << i << endl;
    cout << "Finished checksort" << endl;
}
