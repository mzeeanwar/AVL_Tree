#include <algorithm>
#include <ctime>
using namespace std;

/*
DISTRIBUTION OF DICTIONARY:
Read the words...88984
1       1
2       48
3       601
4       2409
5       4882
6       8205
7       11989
8       13672
9       13014
10      11297
11      8617
12      6003
13      3814
14      2173
15      1169
16      600
17      302
18      107
19      53
20      28
Elapsed time FAST: 2.01  (unordered_map 1.47)
Elapsed time MEDIUM: 18.44
Elapsed time SLOW: 97.15
**/

vector<string> readWords( istream & in )
{
    string oneLine;
    vector<string> v;

    while( in >> oneLine )
        v.push_back( oneLine );
    
    return v;
}
