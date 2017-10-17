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

class FallingFactorialPower {
  public: double compute(int n, int k);
};

double FallingFactorialPower::compute(int n, int k) {
  double out;
  if (k == 0) {
    return 1;
  }
  if (k < 0) {
    out = 1;
    for (int i = 1; i <= abs(k); ++i) {
      out /= (double) n + i;
    }
  } else {
    out = n;
    for (int i = 1; i < k; ++i) {
      out *= n - i;
    }
  }
  return out;
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { 7, 3 }, {210.0} },
    { { 10, 1 }, {10.0} },
    { { 5, 0 }, {1.0} },
    { { 3, -1 }, {0.25} },
    { { 2, -3 }, {0.016666666666666666} },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        int p0;int p1;

        double run(FallingFactorialPower* x) {
            return x->compute(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<FallingFactorialPower>(
            getTestCases<input, Tester::output<double>>(), disabledTest, 
            250, 1407086350, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
