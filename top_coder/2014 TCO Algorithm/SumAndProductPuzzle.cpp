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

class SumAndProductPuzzle {
  public: long long getSum(int A, int B);
};

long long SumAndProductPuzzle::getSum(int A, int B) {
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
    { { 30, 33 }, {33LL} },
    { { 8, 11 }, {19LL} },
    { { 40, 43 }, {0LL} },
    { { 47, 74 }, {168LL} },
    { { 1, 2 }, {0LL} },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        int p0;int p1;

        long long run(SumAndProductPuzzle* x) {
            return x->getSum(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<SumAndProductPuzzle>(
            getTestCases<input, Tester::output<long long>>(), disabledTest, 
            500, 1402158448, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
