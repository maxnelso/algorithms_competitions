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

class FactoVisors {
  public: int getNum(vector<int> divisors, vector<int> multiples);
};

int FactoVisors::getNum(vector<int> divisors, vector<int> multiples) {
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
    { { {1}, {100} }, {9} },
    { { {6,9}, {18} }, {1} },
    { { {6,9}, {96,180} }, {0} },
    { { {2,4}, {256} }, {7} },
    { { {1000,10000,100000}, {1000000000} }, {25} },
    // Your custom test goes here:
    //{ { {}, {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        vector<int> p0;vector<int> p1;

        int run(FactoVisors* x) {
            return x->getNum(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<FactoVisors>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1408298446, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
