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

class StrongPrimePower {
  public: vector<int> baseAndExponent(string n);
};

bool is_prime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

vector<int> StrongPrimePower::baseAndExponent(string n) {
  vector<int> out;
  long long in = stoll(n);
  for (int i = 2; i <= 60; i++) {
    int root = (int)round(pow((double) in, (double) 1.0 / i));
    if (is_prime(root)) {
      printf("%d %d\n", root, i);
      long long tmp = 1;
      for (int j = 0; j < i; j++) {
        tmp *= root;
      }
      if (tmp == in) {
        out.push_back(root);
        out.push_back(i);
        break;
      }
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
    { { "27" }, { {3,3} } },
    { { "10" }, { {} } },
    { { "7" }, { {} } },
    { { "1296" }, { {} } },
    { { "576460752303423488" }, { {2,59} } },
    { { "999999874000003969" }, { {999999937,2} } },
    // Your custom test goes here:
    //{ { }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        string p0;

        vector<int> run(StrongPrimePower* x) {
            return x->baseAndExponent(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<StrongPrimePower>(
            getTestCases<input, Tester::output<vector<int>>>(), disabledTest, 
            500, 1405878279, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
