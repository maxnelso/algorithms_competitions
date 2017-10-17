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

class CandyShop {
  public: int countProbablePlaces(vector<int> X, vector<int> Y, vector<int> R);
};

int CandyShop::countProbablePlaces(vector<int> X, vector<int> Y, vector<int> R) {
  bool available[201][201];
  memset(available, true, sizeof(available[0][0]) * 201 * 201);
  int n = X.size();
  for (int i = 0; i < n; ++i) {
    for (int j = -100; j <= 100; j++) {
      for (int k = -100; k <= 100; k++) {
        if (abs(j - X[i]) + abs(k - Y[i]) > R[i]) {
          available[j+100][k+100] = false;
        }
      }
    }
  }
  int count = 0;
  for (int j = 0; j < 201; j++) {
    for (int k = 0; k < 201; k++) {
      if (available[j][k]) {
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
    { { {0}, {0}, {1} }, {5} },
    { { {0}, {0}, {2} }, {13} },
    { { {2,3}, {1,-1}, {2,2} }, {4} },
    { { {2,3,5}, {1,-1,0}, {2,2,3} }, {3} },
    { { {-100,-100,-100,0,0,0,100,100,100}, {-100,0,100,-100,0,100,-100,0,100}, {1,1,1,1,1,1,1,1,1} }, {0} },
    { { {-3,3,5,5}, {4,5,-2,0}, {10,11,8,6} }, {33} },
    { { {91}, {-64}, {33} }, {2245} },
    // Your custom test goes here:
    //{ { {}, {}, {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        vector<int> p0;vector<int> p1;vector<int> p2;

        int run(CandyShop* x) {
            return x->countProbablePlaces(p0,p1,p2);
        }
        void print() { Tester::printArgs(p0,p1,p2); }
    };
    
    int main() {
        return Tester::runTests<CandyShop>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            250, 1406397855, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
