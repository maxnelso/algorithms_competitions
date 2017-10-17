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

class AlwaysDefined {
  public: long long countIntegers(long long L, long long R, int W);
};

long long AlwaysDefined::countIntegers(long long L, long long R, int W) {
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
    { { 10, 10, 4 }, {1LL} },
    { { 1, 99, 2 }, {50LL} },
    { { 1282, 1410, 10 }, {42LL} },
    { { 29195807, 273209804877, 42 }, {31415926535LL} },
    // Your custom test goes here:
    //{ { , , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        long long p0;long long p1;int p2;

        long long run(AlwaysDefined* x) {
            return x->countIntegers(p0,p1,p2);
        }
        void print() { Tester::printArgs(p0,p1,p2); }
    };
    
    int main() {
        return Tester::runTests<AlwaysDefined>(
            getTestCases<input, Tester::output<long long>>(), disabledTest, 
            900, 1402159249, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
