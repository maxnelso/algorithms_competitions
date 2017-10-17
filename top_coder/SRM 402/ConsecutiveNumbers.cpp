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

class ConsecutiveNumbers {
  public: vector<int> missingNumber(vector<int> numbers);
};

vector<int> ConsecutiveNumbers::missingNumber(vector<int> numbers) {
  sort(numbers.begin(), numbers.end());
  bool seen = false;
  vector<int> out;
  for (int i = 0; i < numbers.size() - 1; ++i) {
    if (numbers[i] != numbers[i+1] - 1) {
      if (numbers[i] == numbers[i+1]) {
        return vector<int>();
      }
      if (seen) {
        return vector<int>();
      }
      if (numbers[i+1] - numbers[i] > 2) {
        return vector<int>();
      }
      out.push_back(numbers[i] + 1);
      seen = true;
    }
  }
  if (out.size() == 1) {
    return out;
  }
  if (numbers[0] - 1 > 0) {
    out.push_back(numbers[0] - 1);
  }
  out.push_back(numbers[numbers.size() - 1] + 1);
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
    { { {10,7,12,8,11} }, { {9} } },
    { { {3,6} }, { {} } },
    { { {5,6,7,8} }, { {4,9} } },
    { { {1000000000} }, { {999999999,1000000001} } },
    { { {1,6,9,3,8,12,7,4,11,5,10} }, { {2} } },
    { { {1} }, { {2} } },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        vector<int> p0;

        vector<int> run(ConsecutiveNumbers* x) {
            return x->missingNumber(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<ConsecutiveNumbers>(
            getTestCases<input, Tester::output<vector<int>>>(), disabledTest, 
            500, 1406603842, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
