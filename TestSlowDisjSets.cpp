// DisjSets class
//
// CONSTRUCTION: with int representing initial number of sets
//
// ******************PUBLIC OPERATIONS*********************
// void union( root1, root2 ) --> Merge two sets
// int find( x )              --> Return set containing x
// ******************ERRORS********************************
// No error checking is performed

#include <iostream>
#include <vector>
using namespace std;

/**
 * Disjoint set class.
 * Does not use union heuristics or path compression.
 * Elements in the set are numbered starting at 0.
 */
class DisjSets
{
    public:
        DisjSets( int numElements );
    
        int find( int x ) const;
        void setUnion( int root1, int root2 );

    private:
        vector<int> s;
};
