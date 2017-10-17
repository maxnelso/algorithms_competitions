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

class DreamingAboutCarrots {
  public: int carrotsBetweenCarrots(int x1, int y1, int x2, int y2);
};

int DreamingAboutCarrots::carrotsBetweenCarrots(int x1, int y1, int x2, int y2) {
  double slope = (y2 - y1) / ((double) x2 - x1);
  int count = 0;
  double b = y1 - slope * x1;
  printf("%f %f\n", slope, b);
  for (int i = min(x1,x2) + 1; i < max(x1,x2); ++i) {
    for (int j = min(y1,y2) + 1; j < max(y1,y2); ++j) {
      if (j == slope * i + b) {
        count++;
      }
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
    { { 1, 1, 5, 5 }, {3} },
    { { 0, 0, 1, 1 }, {0} },
    { { 50, 48, 0, 0 }, {1} },
    { { 0, 0, 42, 36 }, {5} },
    // Your custom test goes here:
    //{ { , , , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        int p0;int p1;int p2;int p3;

        int run(DreamingAboutCarrots* x) {
            return x->carrotsBetweenCarrots(p0,p1,p2,p3);
        }
        void print() { Tester::printArgs(p0,p1,p2,p3); }
    };
    
    int main() {
        return Tester::runTests<DreamingAboutCarrots>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            250, 1405997632, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
