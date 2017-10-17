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

class Zoo {
  public: long long theCount(vector<int> answers);
};

long long factorial(int n) {
  int f = 1;
  for (int i = 1; i <= n; i++) {
    f *= i;
  }
  return f;
}

long long Zoo::theCount(vector<int> answers) {
  sort(answers.begin(), answers.end());
  bool one_left = false;
  int num = 0;
  for (int i = 0; i < answers.size(); i++) {
    if (i + 1 < answers.size()) {
      if (answers[i]

    }
  }
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { {0,1,2,3,4} }, {2LL} },
    { { {5,8} }, {0LL} },
    { { {0,0,0,0,0,0} }, {0LL} },
    { { {1,0,2,0,1} }, {8LL} },
    { { {1,0,1} }, {0LL} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        vector<int> p0;

        long long run(Zoo* x) {
            return x->theCount(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<Zoo>(
            getTestCases<input, Tester::output<long long>>(), disabledTest, 
            500, 1403907268, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
