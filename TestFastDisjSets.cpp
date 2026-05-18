#include <iostream>
#include "DisjSets.h"
using namespace std;

// Test main; all finds on same output line should be identical
int main( )
{
    int numElements = 128;
    int numInSameSet = 16;

    DisjSets ds{ numElements };
    int set1, set2;
