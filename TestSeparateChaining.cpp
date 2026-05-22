#include <iostream>
#include "SeparateChaining.h"
using namespace std;

    // Simple main
int main( )
{
    HashTable<int> h1;
    HashTable<int> h2;

    const int NUMS = 400000;
    const int GAP  =   37;
    int i;

    cout << "Checking... (no more output means success)" << endl;
