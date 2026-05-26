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
