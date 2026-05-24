#include "Vector.h"
#include <iostream>
#include <algorithm>
using namespace std;

void print( const Vector<Vector<int>> arr )
{
    int N = arr.size( );
    
    for( int i = 0; i < N; ++i )
    {
        cout << "arr[" << i << "]:";
        
        for( int j = 0; j < arr[ i ].size( ); ++j )
            cout << " " << arr[ i ][ j ];
        
        cout << endl;
    }
}
