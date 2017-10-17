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

class SumAndProduct {
  public: int smallestSet(int S, int P);
};

int SumAndProduct::smallestSet(int S, int P) {
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
    { { 10, 10 }, {1} },
    { { 5, 6 }, {2} },
    { { 5, 100 }, {-1} },
    { { 100, 1000000000 }, {9} },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        int p0;int p1;

        int run(SumAndProduct* x) {
            return x->smallestSet(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<SumAndProduct>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            1000, 1403589104, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
