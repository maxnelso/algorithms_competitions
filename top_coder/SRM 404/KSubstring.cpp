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

class KSubstring {
  public: vector<int> maxSubstring(int A0, int X, int Y, int M, int n);
};

vector<int> KSubstring::maxSubstring(int A0, int X, int Y, int M, int n) {
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
    { { 5, 3, 4, 25, 5 }, { {2,1} } },
    { { 8, 19, 17, 2093, 12 }, { {5,161} } },
    { { 53, 13, 9, 65535, 500 }, { {244,0} } },
    { { 12, 34, 55, 7890, 123 }, { {35,4} } },
    // Your custom test goes here:
    //{ { , , , , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        int p0;int p1;int p2;int p3;int p4;

        vector<int> run(KSubstring* x) {
            return x->maxSubstring(p0,p1,p2,p3,p4);
        }
        void print() { Tester::printArgs(p0,p1,p2,p3,p4); }
    };
    
    int main() {
        return Tester::runTests<KSubstring>(
            getTestCases<input, Tester::output<vector<int>>>(), disabledTest, 
            500, 1400294589, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
