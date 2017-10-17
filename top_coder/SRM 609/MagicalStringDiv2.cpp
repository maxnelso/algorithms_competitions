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

class MagicalStringDiv2 {
  public: int minimalMoves(string S);
};

int MagicalStringDiv2::minimalMoves(string S) {
  int count = 0;
  for (int i = 0; i < S.size(); i++) {
    if (i < S.size() / 2 && S[i] == '<') {
      count++;
    } else if (i >= S.size() / 2 && S[i] == '>') {
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
    { { ">><<><" }, {2} },
    { { ">>>><<<<" }, {0} },
    { { "<<>>" }, {4} },
    { { "<><<<>>>>><<>>>>><>><<<>><><><><<><<<<<><<>>><><><" }, {20} },
    // Your custom test goes here:
    //{ { }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        string p0;

        int run(MagicalStringDiv2* x) {
            return x->minimalMoves(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<MagicalStringDiv2>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            250, 1474439567, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
