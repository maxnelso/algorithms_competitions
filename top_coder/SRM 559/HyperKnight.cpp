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

class HyperKnight {
  public: long long countCells(int a, int b, int numRows, int numColumns, int k);
};

long long HyperKnight::countCells(int a, int b, int numRows, int numColumns, int k) {
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
    { { 2, 1, 8, 8, 4 }, {20LL} },
    { { 3, 2, 8, 8, 2 }, {16LL} },
    { { 1, 3, 7, 11, 0 }, {0LL} },
    { { 3, 2, 10, 20, 8 }, {56LL} },
    { { 1, 4, 100, 10, 6 }, {564LL} },
    { { 2, 3, 1000000000, 1000000000, 8 }, {999999988000000036LL} },
    // Your custom test goes here:
    //{ { , , , , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        int p0;int p1;int p2;int p3;int p4;

        long long run(HyperKnight* x) {
            return x->countCells(p0,p1,p2,p3,p4);
        }
        void print() { Tester::printArgs(p0,p1,p2,p3,p4); }
    };
    
    int main() {
        return Tester::runTests<HyperKnight>(
            getTestCases<input, Tester::output<long long>>(), disabledTest, 
            500, 1403753409, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
