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

class PowerSupply {
  public: int maxProfit(vector<int> x, vector<int> y, int D);
};

int PowerSupply::maxProfit(vector<int> x, vector<int> y, int D) {
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
    { { {0,3,0,0,0}, {1,2,6,-4,1}, 1 }, {4} },
    { { {-1000000,13,1000000}, {0,0,0}, 0 }, {3} },
    { { {-5,-2,2,8,-1}, {1,2,1,2,8}, 1 }, {4} },
    { { {-5,-5,-2,-2,3}, {-2,-3,4,6,9}, 2 }, {4} },
    { { {511590,-60297,337900,-322958,-806739,358447,685932,663609,276080,-213586}, {-500859,-840607,-792296,-379621,-890856,362559,-98535,617148,-128203,802475}, 31194 }, {4} },
    // Your custom test goes here:
    //{ { {}, {}, }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        vector<int> p0;vector<int> p1;int p2;

        int run(PowerSupply* x) {
            return x->maxProfit(p0,p1,p2);
        }
        void print() { Tester::printArgs(p0,p1,p2); }
    };
    
    int main() {
        return Tester::runTests<PowerSupply>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            300, 1401912143, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
