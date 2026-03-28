//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x (unimplemented)
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// bool isEmpty( )        --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class Treap
{
  public:
    Treap( )
    {
        nullNode = new TreapNode;
        nullNode->left = nullNode->right = nullNode;
        nullNode->priority = INT_MAX;
        root = nullNode;
    }

    Treap( const Treap & rhs )
    {
        nullNode = new TreapNode;
        nullNode->left = nullNode->right = nullNode;
        nullNode->priority = INT_MAX;
        root = clone( rhs.root );
    }
~Treap( )
    {
        makeEmpty( );
        delete nullNode;
    }
    

    Treap( Treap && rhs ) : root{ rhs.root }, nullNode{ rhs.nullNode }
    {
        rhs.root = nullptr;
        rhs.nullNode = nullptr;
    }

    
    /**
     * Deep copy.
     */
    Treap & operator=( const Treap & rhs )
    {
        Treap copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
        
    /**
     * Move.
     */
    Treap & operator=( Treap && rhs )
    {
        std::swap( root, rhs.root );
        std::swap( nullNode, rhs.nullNode );
        
        return *this;
    }
const Comparable & findMin( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };

        TreapNode *ptr = root;
        while( ptr->left != nullNode )
            ptr = ptr->left;

        return ptr->element;
    }

    const Comparable & findMax( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };

        TreapNode *ptr = root;
        while( ptr->right != nullNode )
            ptr = ptr->right;

        return ptr->element;
    }

    bool contains( const Comparable & x ) const
    {
        TreapNode *current = root;
        nullNode->element = x;

        for( ; ; )
        {
            if( x < current->element )
                current = current->left;
            else if( current->element < x )
                current = current->right;
            else
                return current != nullNode;
        }
    }
