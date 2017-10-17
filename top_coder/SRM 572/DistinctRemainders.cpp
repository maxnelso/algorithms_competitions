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

class DistinctRemainders {
  public: int howMany(long long N, int M);
};

int DistinctRemainders::howMany(long long N, int M) {

}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { 3, 2 }, {5} },
    { { 3, 3 }, {9} },
    { { 58, 1 }, {1} },
    { { 572, 7 }, {922572833} },
    { { 1000000000000000000, 20 }, {240297629} },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        long long p0;int p1;

        int run(DistinctRemainders* x) {
            return x->howMany(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<DistinctRemainders>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            1000, 1405097889, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
