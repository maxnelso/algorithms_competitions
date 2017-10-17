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

class YetAnotherORProblem2 {
  public: int countSequences(int N, int R);
};

int YetAnotherORProblem2::countSequences(int N, int R) {
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
    { { 2, 2 }, {7} },
    { { 2, 3 }, {9} },
    { { 3, 3 }, {16} },
    { { 7, 1023 }, {73741815} },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        int p0;int p1;

        int run(YetAnotherORProblem2* x) {
            return x->countSequences(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<YetAnotherORProblem2>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            1000, 1406401105, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
