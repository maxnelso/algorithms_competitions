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

class EasyHomework {
  public: string determineSign(vector<int> A);
};

string EasyHomework::determineSign(vector<int> A) {
  if (A[0] == 0) {
    return "ZERO";
  }
  bool positive = A[0] > 0;
  for (int i = 1; i < A.size(); ++i) {
    if (A[i] == 0) {
      return "ZERO";
    }
    if (A[i] < 0) {
      positive = !positive;
    }
  }
  if (positive) {
    return "POSITIVE";
  }
  return "NEGATIVE";
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { {5,7,2} }, {"POSITIVE"} },
    { { {-5,7,2} }, {"NEGATIVE"} },
    { { {5,7,2,0} }, {"ZERO"} },
    { { {3,-14,159,-26} }, {"POSITIVE"} },
    { { {-1000000000} }, {"NEGATIVE"} },
    { { {123,-456,789,-101112,131415,161718,192021,222324,252627,282930,313233,343536,373839,404142,434445,464748,495051,525354,555657} }, {"POSITIVE"} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        vector<int> p0;

        string run(EasyHomework* x) {
            return x->determineSign(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<EasyHomework>(
            getTestCases<input, Tester::output<string>>(), disabledTest, 
            250, 1405095642, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
