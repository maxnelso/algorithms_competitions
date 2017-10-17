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
#endif

using namespace std;

class DoubleWeights {
  public: int minimalCost(vector<string> weight1, vector<string> weight2);
};

int DoubleWeights::minimalCost(vector<string> weight1, vector<string> weight2) {
  for (int i = 0; i <= weight1.size(); i++) {
    vector<int> bitmask(weight1.size());
    for (int j = 0; j < i; j++) {
      bitmask[weight1.size() - j - 1] = 1;
    }

    do {
      for (int j = 0; j < bitmask.size(); j++) {
        printf("%d ", bitmask[j]);
      }
        printf("\n");
    } while (next_permutation(bitmask.begin(), bitmask.end()));
  }
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x) {
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { {"..14","..94","19..","44.."}, {"..94","..14","91..","44.."} }, {64} },
    //{ { {"..14","..14","11..","44.."}, {"..94","..94","99..","44.."} }, {36} },
    //{ { {"..",".."}, {"..",".."} }, {-1} },
    //{ { {".....9","..9...",".9.9..","..9.9.","...9.9","9...9."}, {".....9","..9...",".9.9..","..9.9.","...9.9","9...9."} }, {2025} },
    //{ { {".4...1","4.1...",".1.1..","..1.1.","...1.1","1...1."}, {".4...1","4.1...",".1.1..","..1.1.","...1.1","1...1."} }, {16} },
    // Your custom test goes here:
    //{ { {}, {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<string> p0;vector<string> p1;

        int run(DoubleWeights* x) {
            return x->minimalCost(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<DoubleWeights>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1472409101, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
