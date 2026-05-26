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

    /**
     * Print items satisfying
     * low[ 0 ] <= x[ 0 ] <= high[ 0 ] and
     * low[ 1 ] <= x[ 1 ] <= high[ 1 ]
     */
    void printRange( const vector<Comparable> & low, 
                        const vector<Comparable> & high ) const
    {
        printRange( low, high, root, 0 );
    }

  private:
    struct KdNode
    {
        vector<Comparable> data;
        KdNode            *left;
        KdNode            *right;

        KdNode( const vector<Comparable> & item )
          : data( item ), left( nullptr ), right( nullptr ) { }
    };
