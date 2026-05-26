#include <list>
#include <vector>
#include <iostream>
#include <ctime>
using namespace std;

template <typename Container>
void removeEveryOtherItem( Container & lst )
{
    auto itr = lst.begin( );
    while( itr != lst.end( ) )
    {
        itr = lst.erase( itr );
        if( itr != lst.end( ) )
            ++itr;
    }
}
template <typename Container>
void print( const Container & c, ostream & out = cout )
{
    if( c.empty( ) )
        out << "(empty)";
    else
    {
        auto itr = begin( c );
        out << "[ " << *itr++;   // Print first item

        while( itr != end( c ) )
            out << ", " << *itr++;
        out << " ]" << endl;
    }
}
int main( )
{
    list<int> lst;
    for( int i = 0; i < 9; ++i )
        lst.push_back( i );

    removeEveryOtherItem( lst );
    print( lst, cout );

   

    

    return 0;
}
