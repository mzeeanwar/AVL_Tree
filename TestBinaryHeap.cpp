#include <iostream>
#include <sstream>
#include <string>
#include "BinaryHeap.h"
using namespace std;

    // Test program
int main( )
{
    int minItem = 10000;  // same number of digits
    int maxItem = 99999;
    BinaryHeap<string> h;
    string str = "hello";
    int i = 37;
    string x;

    cout << "Begin test... " << endl;
