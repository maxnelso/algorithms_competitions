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

bool seen[20];

using namespace std;

class Xscoregame {
  public: int getscore(vector<int> A);
};

int Xscoregame::getscore(vector<int> A) {
  int x = 0;
  for (int i = 0; i < A.size(); i++) {
    int biggest_index = -1;
    for (int j = 0; j < A.size(); j++) {
      if ((biggest_index == -1 || (x ^ A[j]) > (x ^ A[biggest_index])) && !seen[j]) {
        biggest_index = j;
      }
    }
    seen[biggest_index] = true;
    x = x + (x ^ A[biggest_index]);
  }
  return x;
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { {1,2,3} }, {12} },
    { { {10,0,0,0} }, {80} },
    { { {1,1,1,1,1,1} }, {1} },
    { { {1,0,1,0,1,0,1,0} }, {170} },
    { { {50,0,1,0,1,0,1,0,1,0,1,0,1,0,1} }, {830122} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<int> p0;

        int run(Xscoregame* x) {
            return x->getscore(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<Xscoregame>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            250, 1487693154, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
