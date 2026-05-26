#include <iostream>
#include <vector>
using namespace std;

/**
 * Quick illustration of a two-dimensional tree.
 * No abstraction here.
 */
template <typename Comparable>
class KdTree
{
  public:
    KdTree( ) : root( nullptr ) { }

    void insert( const vector<Comparable> & x )
    {
        insert( x, root, 0 );
    }
