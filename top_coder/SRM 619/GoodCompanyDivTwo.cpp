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

class GoodCompanyDivTwo {
  public: int countGood(vector<int> superior, vector<int> workType);
};

int GoodCompanyDivTwo::countGood(vector<int> superior, vector<int> workType) {
  set<set<int>> divisions;
  set<int> boss;
  boss.insert(0);
  divisions.insert(boss);
  for (int i = 1; i < superior.size(); i++) {
    int boss = superior[i];
    for (auto& division : divisions) {
      for (auto superior : division) {
        if (superior == boss) {
          division.insert(i);
          break;
        }
      }
    }
  }
  return 0;

}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { {-1,0}, {1,2} }, {2} },
    { { {-1,0}, {1,1} }, {1} },
    { { {-1,0,1,1}, {1,4,3,2} }, {4} },
    { { {-1,0,1,0,0}, {3,3,5,2,2} }, {4} },
    { { {-1,0,1,1,1,0,2,5}, {1,1,2,3,4,5,3,3} }, {7} },
    { { {-1,0,0,1,1,3,0,2,0,5,2,5,5,6,1,2,11,12,10,4,7,16,10,9,12,18,15,23,20,7,4}, {4,6,4,7,7,1,2,8,1,7,2,4,2,9,11,1,10,11,4,6,11,7,2,8,9,9,10,10,9,8,8} }, {27} },
    // Your custom test goes here:
    //{ { {}, {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<int> p0;vector<int> p1;

        int run(GoodCompanyDivTwo* x) {
            return x->countGood(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<GoodCompanyDivTwo>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            250, 1474409779, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
