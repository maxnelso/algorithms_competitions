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

using namespace std;

class DivFreed2 {
  public: int count(int n, int k);
};

const int MOD = 1000000007;

int DivFreed2::count(int n, int k) {
  vector<vector<int>> divisors(k + 1);

  for (int i = 1; i <= k; i++) {
    for (int j = 2*i; j <= k; j += i) {
      divisors[j].push_back(i);
    }
  }

  vector<vector<long> > f(n + 1, vector<long>(k+1) );

  for (int i = 1; i <= k; i++) {
      f[1][i] = 1;
  }

  for (int t = 2; t <= n; t++) {
    long sum = 0;
    for (int i = 1; i <= k; i++) {
      sum += f[t-1][i];
    }
    sum = sum % MOD;

    for (int i = 1; i <= k; i++) {
      f[t][i] = sum;
      for (int d: divisors[i]) {
        f[t][i] = (f[t][i] + MOD - f[t-1][d]) % MOD;
      }
    }

  }
  long sum = 0;
  for (int i = 1; i <= k; i++) {
    sum += f[n][i];
  }
  return sum % MOD;

}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { 2, 2 }, {3} },
    { { 9, 1 }, {1} },
    { { 3, 3 }, {15} },
    { { 1, 107 }, {107} },
    { { 2, 10 }, {83} },
    { { 2, 1234 }, {1515011} },
    { { 3, 8 }, {326} },
    { { 10, 100000 }, {526882214} },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;int p1;

        int run(DivFreed2* x) {
            return x->count(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<DivFreed2>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            600, 1473145197, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
