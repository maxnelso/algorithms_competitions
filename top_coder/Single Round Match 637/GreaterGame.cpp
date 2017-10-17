#include <bitset>
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

class GreaterGame {
  public: double calc(vector<int> hand, vector<int> sothe);
};

double GreaterGame::calc(vector<int> hand, vector<int> sothe) {
  return 0.0;
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { {4,2}, {-1,-1} }, {1.5} },
    { { {4,2}, {1,3} }, {2.0} },
    { { {2}, {-1} }, {1.0} },
    { { {1,3,5,7}, {8,-1,4,-1} }, {2.5} },
    { { {6,12,17,14,20,8,16,7,2,15}, {-1,-1,4,-1,11,3,13,-1,-1,18} }, {8.0} },
    // Your custom test goes here:
    //{ { {}, {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<int> p0;vector<int> p1;

        double run(GreaterGame* x) {
            return x->calc(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<GreaterGame>(
            getTestCases<input, Tester::output<double>>(), disabledTest, 
            250, 1414076407, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
