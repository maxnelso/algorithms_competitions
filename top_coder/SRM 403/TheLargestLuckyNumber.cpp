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

class TheLargestLuckyNumber {
  public: int find(int n);
};

bool is_lucky(int n) {
  string s = to_string(n);
  bool good = true;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != '7' && s[i] != '4') {
      good = false;
      break;
    }
  }
  return good;
}

int TheLargestLuckyNumber::find(int n) {
  for (int i = n; i >= 4; --i) {
    if (is_lucky(i)) {
      return i;
    }
  }
  return -1;
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { 100 }, {77} },
    { { 75 }, {74} },
    { { 5 }, {4} },
    { { 474747 }, {474747} },
    // Your custom test goes here:
    //{ { }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        int p0;

        int run(TheLargestLuckyNumber* x) {
            return x->find(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<TheLargestLuckyNumber>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            250, 1407002536, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
