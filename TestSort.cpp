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
template <typename AnyType>
void permute( vector<AnyType> & a )
{
    static UniformRandom r;

    for( int j = 1; j < a.size( ); ++j )
        swap( a[ j ], a[ r.nextInt( 0, j ) ] );
}
