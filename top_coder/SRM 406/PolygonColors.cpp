#include <vector>
#include <list>
#include <fstream>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <iterator>

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

class PolygonColors {
  public: int getWays(int N, vector<int> colors);
};

int PolygonColors::getWays(int N, vector<int> colors) {
  return 0;
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { 3, {1,2,0} }, {1} },
    { { 4, {1,2,3,0} }, {3} },
    { { 5, {0,1,1,1,1} }, {0} },
    { { 16, {0,1,2,6,4,5,6,7,1,9,10,11,12,13,14,10} }, {96791474} },
    // Your custom test goes here:
    //{ { , {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        int p0;vector<int> p1;

        int run(PolygonColors* x) {
            return x->getWays(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<PolygonColors>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            1000, 1408301017, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
