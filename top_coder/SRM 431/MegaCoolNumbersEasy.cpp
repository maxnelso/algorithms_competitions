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

class MegaCoolNumbersEasy {
  public: int count(int N);
};

bool is_cool(int n) {
  string s = to_string(n);
  if (s.size() == 1) {
    return true;
  }
  int diff = s[1] - '0' - s[0] - '0';
  for (int i = 1; i < s.size(); i++) {
    if (s[i] - '0' - s[i-1] - '0' != diff) {
      return false;
    }
  }
  return true;
}

int MegaCoolNumbersEasy::count(int N) {
  int count = 0;
  for (int i = 1; i <= N; i++) {
    if (is_cool(i)) {
      count++;
    }
  }
  return count;
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { 1 }, {1} },
    { { 110 }, {99} },
    { { 500 }, {119} },
    // Your custom test goes here:
    //{ { }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        int p0;

        int run(MegaCoolNumbersEasy* x) {
            return x->count(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<MegaCoolNumbersEasy>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            250, 1403579395, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
