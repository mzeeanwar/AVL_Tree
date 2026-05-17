#include <iostream>
#include <vector>
using namespace std;

/**
 * Print container from start up to but not including end.
 */
template <typename Iterator>
void print( Iterator start, Iterator end, ostream & out = cout )
{
    if( start == end )
        return;

    out << *start++ << endl;   // Print and advance start
    print( start, end, out );
}

/**
 * Print container from start up to but not including end.
 */
template <typename Iterator>
void print2( Iterator start, Iterator end, ostream & out = cout )
{
    while( true )
    {
        if( start == end )
            return;

        out << *start++ << endl;   // Print and advance start
    }
}
