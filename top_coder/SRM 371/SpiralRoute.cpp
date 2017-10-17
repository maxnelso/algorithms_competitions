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

class SpiralRoute {
  public: vector<int> thronePosition(int width, int length);
};

vector<int> SpiralRoute::thronePosition(int width, int length) {
  return vector<int>();
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { 6, 4 }, { {1,2} } },
    { { 6, 5 }, { {3,2} } },
    { { 1, 11 }, { {0,10} } },
    { { 12, 50 }, { {5,6} } },
    { { 5000, 5000 }, { {2499,2500} } },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        int p0;int p1;

        vector<int> run(SpiralRoute* x) {
            return x->thronePosition(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<SpiralRoute>(
            getTestCases<input, Tester::output<vector<int>>>(), disabledTest, 
            250, 1400291065, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
