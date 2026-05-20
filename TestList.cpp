#include "dsexceptions.h"
#include "List.h"
#include "Vector.h"

#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

static const int NUMS_PER_LINE = 14;


template <typename Object>
class Stack 
{
  public:
    bool isEmpty( ) const
      { return theList.empty( ); }
    const Object & top( ) const
      { return theList.front( ); }
    void push( const Object & x )
      { theList.push_front( x ); }
    void pop( Object & x )
      { x = theList.front( ); theList.pop_front( ); }
  private:
    List<Object> theList;
};
template <typename Object>
class Queue
{
  public:
    bool isEmpty( ) const
      { return theList.empty( ); }
    const Object & getFront( ) const
      { return theList.front( ); }
    void enqueue( const Object & x )
      { theList.push_back( x ); }
    void dequeue( Object & x )
      { x = theList.front( ); theList.pop_front( ); }
  private:
    List<Object> theList;
};
