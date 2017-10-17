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

map<tuple<int, int, int>, int> memo;

class CheeseSlicing {
  public: int totalArea(int A, int B, int C, int S);
};

tuple<int, int, int> to_tuple(int A, int B, int C) {
  vector<int> blah = {A, B, C};
  sort(blah.begin(), blah.end());
  tuple<int, int, int> out = make_tuple(blah[0], blah[1], blah[2]);
  return out;
}

int score(int A, int B, int C, int S) {
  tuple<int, int, int> sorted_slices = to_tuple(A, B, C);
  if (get<0>(sorted_slices) < S) {
    return 0;
  }
  return get<1>(sorted_slices) * get<2>(sorted_slices);
}

int solve(int A, int B, int C, int S) {
  tuple<int, int, int> sorted_slices = to_tuple(A, B, C);
  if (memo.find(sorted_slices) != memo.end()) {
    return memo[sorted_slices];
  }
  int out = score(A, B, C, S);
  for (int i = S; i < A; i++) {
    out = max(out, solve(A - i, B, C, S) + solve(i, B, C, S));
  }
  for (int i = S; i < B; i++) {
    out = max(out, solve(A, B - i, C, S) + solve(A, i, C, S));
  }
  for (int i = S; i < C; i++) {
    out = max(out, solve(A, B, C - i, S) + solve(A, B, i, S));
  }

  memo[sorted_slices] = out;
  return out;
}

int CheeseSlicing::totalArea(int A, int B, int C, int S) {
  return solve(A, B, C, S);
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { 1, 3, 3, 2 }, {0} },
    { { 5, 3, 5, 3 }, {25} },
    { { 5, 5, 5, 2 }, {58} },
    { { 49, 92, 20, 3 }, {30045} },
    // Your custom test goes here:
    //{ { , , , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;int p1;int p2;int p3;

        int run(CheeseSlicing* x) {
            return x->totalArea(p0,p1,p2,p3);
        }
        void print() { Tester::printArgs(p0,p1,p2,p3); }
    };
    
    int main() {
        return Tester::runTests<CheeseSlicing>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1491063832, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
