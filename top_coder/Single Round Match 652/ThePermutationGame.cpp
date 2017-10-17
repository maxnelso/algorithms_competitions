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

class ThePermutationGame {
  public: int findMin(int N);
};

long long gcd (unsigned long long a, unsigned long long b) {
  unsigned long long c;
  while (a != 0) {
    c = a;
    a = b % a;
    b = c;
  }
  return b;
}

unsigned long long lcm(unsigned long long a, unsigned long long b) {
  return a * b / gcd(a, b);
}

int ThePermutationGame::findMin(int N) {
  unsigned long long out = 2;
  for (unsigned long long i = 2; i <= N; i++) {
    out = lcm(out, i);
  }
  return out % 1000000007;
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
  return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
  { { 2 }, {2} },
    { { 3 }, {6} },
    { { 11 }, {27720} },
    { { 102 }, {53580071} },
    { { 9999 }, {927702802} },
    // Your custom test goes here:
    //{ { }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "tester.cpp"
struct input {
  int p0;

  int run(ThePermutationGame* x) {
    return x->findMin(p0);
  }
  void print() { Tester::printArgs(p0); }
};

int main() {
  return Tester::runTests<ThePermutationGame>(
      getTestCases<input, Tester::output<int>>(), disabledTest, 
      250, 1425915571, CASE_TIME_OUT, Tester::COMPACT_REPORT
      );
}
// CUT end
