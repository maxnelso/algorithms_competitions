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

class CatchTheBeatEasy {
  public: string ableToCatchAll(vector<int> x, vector<int> y);
};

string CatchTheBeatEasy::ableToCatchAll(vector<int> x, vector<int> y) {
  vector<pair <int, int> > pairs;
  for (int i = 0; i < x.size(); i++) {
    pairs.push_back(make_pair(y[i], x[i]));
  }
  sort(pairs.begin(), pairs.end());
  int currentTime = 0;
  int currentX = 0;
  for (int i = 0; i < x.size(); i++) {
    int timeLeft = abs(pairs[i].first - currentTime);
    currentTime = pairs[i].first;
    int dist = abs(pairs[i].second - currentX);
    currentX = pairs[i].second;
    if (dist > timeLeft) {
      return "Not able to catch";
    }
  }
  return "Able to catch";
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { {-1,1,0}, {1,3,4} }, {"Able to catch"} },
    { { {-3}, {2} }, {"Not able to catch"} },
    { { {-1,1,0}, {1,2,4} }, {"Not able to catch"} },
    { { {0,-1,1}, {9,1,3} }, {"Able to catch"} },
    { { {70,-108,52,-70,84,-29,66,-33}, {141,299,402,280,28,363,427,232} }, {"Not able to catch"} },
    { { {-175,-28,-207,-29,-43,-183,-175,-112,-183,-31,-25,-66,-114,-116,-66}, {320,107,379,72,126,445,318,255,445,62,52,184,247,245,185} }, {"Able to catch"} },
    { { {0,0,0,0}, {0,0,0,0} }, {"Able to catch"} },
    // Your custom test goes here:
    //{ { {}, {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        vector<int> p0;vector<int> p1;

        string run(CatchTheBeatEasy* x) {
            return x->ableToCatchAll(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<CatchTheBeatEasy>(
            getTestCases<input, Tester::output<string>>(), disabledTest, 
            250, 1401930003, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
