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

class TheLuckyNumbers {
  public: int count(int a, int b);
};

int TheLuckyNumbers::count(int a, int b) {
  int count = 0;
  for (int i = 1; i < 11; i++) {
    for(int k = 0; k <= i; k++) {
      vector<bool> selectors(i);
      fill(selectors.end() - k, selectors.end(), true);
      do {
        string s = "";
        for (int j = 0; j < i; ++j) {
          if (selectors[j]) {
            s += "7";
          } else {
            s += "4";
          }
        }
        if (stol(s) >= a && stol(s) <= b) {
          count++;
        }
      } while (next_permutation(selectors.begin(), selectors.end()));
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
    { { 1, 10 }, {2} },
    { { 11, 20 }, {0} },
    { { 74, 77 }, {2} },
    { { 1000000, 5000000 }, {64} },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        int p0;int p1;

        int run(TheLuckyNumbers* x) {
            return x->count(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<TheLuckyNumbers>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1407002790, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
