#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

#include "dsexceptions.h"
#include <iostream>     
using namespace std;

// SplayTree class
//
// CONSTRUCTION: with no parameters
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// bool isEmpty( )        --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class SplayTree
{
  public:
    SplayTree( )
    {
        nullNode = new BinaryNode;
        nullNode->left = nullNode->right = nullNode;
        root = nullNode;
    }

    SplayTree( const SplayTree & rhs )
    {
        nullNode = new BinaryNode;
        nullNode->left = nullNode->right = nullNode;
        root = clone( rhs.root );
    }

    SplayTree( SplayTree && rhs ) : root{ rhs.root }, nullNode{ rhs.nullNode }
    {
        rhs.root = nullptr;
        rhs.nullNode = nullptr;
    }
    
    ~SplayTree( )
    {
        makeEmpty( );
        delete nullNode;
    }
