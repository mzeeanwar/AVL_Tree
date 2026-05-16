#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <iterator>
#include <stdexcept>
using std::cout;
using std::vector;
using std::string;
using std::endl;
using std::invalid_argument;
using std::sort;
  
void makeLCPArray( vector<int> & s, const vector<int> & sa, vector<int> & LCP );
void createSuffixArray( const string & str, vector<int> & sa, vector<int> & LCP );
void makeSuffixArray( const vector<int> & s, vector<int> & SA, int n, int K );
int assignNames( const vector<int> & s, vector<int> & s12, vector<int> & SA12,
                                int n0, int n12, int K );
void radixPass( const vector<int> & in, vector<int> & out,
                const vector<int> & s, int offset, int n, int K );
void radixPass( const vector<int> & in, vector<int> & out,
                const vector<int> & s, int n, int K );
void computeS12( vector<int> & s12, vector<int> & SA12, int n12, int K12 );
void computeS0( const vector<int> & s, vector<int> & s0,
                vector<int> & SA0, const vector<int> & SA12,
                            int n0, int n12, int K );
void merge( const vector<int> & s, const vector<int> & s12,
            vector<int> & SA, const vector<int> & SA0, const vector<int> & SA12,
                            int n, int n0, int n12, int t );
int getIndexIntoS( const vector<int> & SA12, int t, int n0 );
