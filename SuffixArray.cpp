#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <iterator>
#include <stdexcept>
using std::cout;
using std::vector;
using std::string;
using std::endl;
using std::invalid_argument;
using std::sort;
  
void makeLCPArray( vector<int> & s, const vector<int> & sa, vector<int> & LCP );
void createSuffixArray( const string & str, vector<int> & sa, vector<int> & LCP );
void makeSuffixArray( const vector<int> & s, vector<int> & SA, int n, int K );
int assignNames( const vector<int> & s, vector<int> & s12, vector<int> & SA12,
                                int n0, int n12, int K );
void radixPass( const vector<int> & in, vector<int> & out,
                const vector<int> & s, int offset, int n, int K );
void radixPass( const vector<int> & in, vector<int> & out,
                const vector<int> & s, int n, int K );
void computeS12( vector<int> & s12, vector<int> & SA12, int n12, int K12 );
void computeS0( const vector<int> & s, vector<int> & s0,
                vector<int> & SA0, const vector<int> & SA12,
                            int n0, int n12, int K );
void merge( const vector<int> & s, const vector<int> & s12,
            vector<int> & SA, const vector<int> & SA0, const vector<int> & SA12,
                            int n, int n0, int n12, int t );
int getIndexIntoS( const vector<int> & SA12, int t, int n0 );
bool leq( int a1, int a2, int b1, int b2 );
bool leq( int a1, int a2, int a3, int b1, int b2, int b3 );
bool suffix12IsSmaller( const vector<int> & s, const vector<int> & s12,
                        const vector<int> & SA12, int n0, int i, int j, int t );
void printV( const vector<int> & a, const string & comment);
bool isPermutation( const vector<int> & SA, int n );
bool sleq( const vector<int> & s1, int start1, const vector<int> & s2, int start2 );
bool isSorted( const vector<int> & SA, const vector<int> & s, int n );
void assert0( bool cond );
int computeLCP( const string & s1, const string & s2 );
void createSuffixArraySlow( const string & str, vector<int> & SA, vector<int> & LCP );

/*
 * Create the LCP array from the suffix array
 * s is the input array populated from 0..N-1, with available pos N
 * sa is an already-computed suffix array 0..N-1
 * LCP is the resulting LCP array 0..N-1
 */
void makeLCPArray( vector<int> & s, const vector<int> & sa, vector<int> & LCP )
{
    int N = sa.size( );
    vector<int> rank( N );

    s[ N ] = -1;
    for( int i = 0; i < N; ++i )
        rank[ sa[ i ] ] = i;

    int h = 0;
    for( int i = 0; i < N; ++i )
        if( rank[ i ] > 0 )
        {
            int j = sa[ rank[ i ] - 1 ];

            while( s[ i + h ] == s[ j + h ] )
                ++h;

            LCP[ rank[ i ] ] = h;
            if( h > 0 )
                --h;
        }
}

/*
 * Fill in the suffix array information for String str
 * str is the input String
 * sa is an existing array to place the suffix array
 * LCP is an existing array to place the LCP information
 */
void createSuffixArray( const string & str, vector<int> & sa, vector<int> & LCP )
{
    if( sa.size( ) != str.length( ) || LCP.size( ) != str.length( ) )
        throw invalid_argument{ "Mismatched vector sizes" };
    
    int N = str.length( );

    vector<int> s( N + 3 );
    vector<int> SA( N + 3 );

    for( int i = 0; i < N; ++i )
        s[ i ] = str[ i ];

    makeSuffixArray( s, SA, N, 256 );

    for( int i = 0; i < N; ++i )
        sa[ i ] = SA[ i ];

    makeLCPArray( s, sa, LCP );
}
// find the suffix array SA of s[0..n-1] in {1..K}^n
// require s[n]=s[n+1]=s[n+2]=0, n>=2
void makeSuffixArray( const vector<int> & s, vector<int> & SA, int n, int K )
{
    int n0 = ( n + 2 ) / 3;
    int n1 = ( n + 1 ) / 3;
    int n2 = n / 3;
    int t = n0 - n1;  // 1 iff n%3 == 1
    int n12 = n1 + n2 + t;

    vector<int> s12( n12 + 3 );
    vector<int> SA12( n12 + 3 );
    vector<int> s0( n0 );
    vector<int> SA0( n0 );

    // generate positions in s for items in s12
    // the "+t" adds a dummy mod 1 suffix if n%3 == 1
    // at that point, the size of s12 is n12
    for( int i = 0, j = 0; i < n + t; ++i )
        if( i % 3 != 0 )
            s12[ j++ ] = i;

    int K12 = assignNames( s, s12, SA12, n0, n12, K );

    computeS12( s12, SA12, n12, K12 );
    computeS0( s, s0, SA0, SA12, n0, n12, K );
    merge( s, s12, SA, SA0, SA12, n, n0, n12, t );
}
