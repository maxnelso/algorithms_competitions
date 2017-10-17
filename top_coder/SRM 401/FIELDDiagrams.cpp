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

class FIELDDiagrams {
  public: long long countDiagrams(int fieldOrder);
};

long long FIELDDiagrams::countDiagrams(int fieldOrder) {
  long long dp[30 + 1][30 + 1];
  for (int i = 0; i <= fieldOrder; ++i) {
    dp[fieldOrder][i] = 1;
  }
  for (int i = fieldOrder - 1; i >= 0; --i) {
    for (int j = 0; j <= fieldOrder; ++j) {
      dp[i][j] = 0;
      for (int k = 0; k <= min(j, fieldOrder - i); ++k) {
        dp[i][j] += dp[i+1][k];
      }
    }
  }
  return dp[0][fieldOrder] - 1;
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { 2 }, {4LL} },
    { { 3 }, {13LL} },
    { { 5 }, {131LL} },
    // Your custom test goes here:
    //{ { }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        int p0;

        long long run(FIELDDiagrams* x) {
            return x->countDiagrams(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<FIELDDiagrams>(
            getTestCases<input, Tester::output<long long>>(), disabledTest, 
            500, 1405998123, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
