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

class GrabbingTaxi {
  public: int minTime(vector<int> tXs, vector<int> tYs, int gX, int gY, int walkTime, int taxiTime);
};

int GrabbingTaxi::minTime(vector<int> tXs, vector<int> tYs, int gX, int gY, int walkTime, int taxiTime) {
  int best = (abs(gX) + abs(gY)) * walkTime;
  for (int i = 0; i < tXs.size(); ++i) {
    best = min(best, ((abs(tXs[i]) + abs(tYs[i])) * walkTime) +
                    ((abs(gX - tXs[i]) + abs(gY - tYs[i])) * taxiTime));
  }
  return best;
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { {}, {}, 3, 2, 10, 2 }, {50} },
    { { {-2,-2}, {0,-2}, -4, -2, 15, 3 }, {42} },
    { { {3}, {0}, 5, 0, 10, 20 }, {50} },
    { { {34,-12,1,0,21,-43,-98,11,86,-31}, {11,5,-68,69,-78,-49,-36,-2,1,70}, -97, -39, 47, 13 }, {2476} },
    { { {82,-60,57,98,30,-67,84,-42,-100,62}, {-7,90,53,-56,-15,-87,22,-3,-61,-30}, 21, 15, 53, 2 }, {1908} },
    // Your custom test goes here:
    //{ { {}, {}, , , , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        vector<int> p0;vector<int> p1;int p2;int p3;int p4;int p5;

        int run(GrabbingTaxi* x) {
            return x->minTime(p0,p1,p2,p3,p4,p5);
        }
        void print() { Tester::printArgs(p0,p1,p2,p3,p4,p5); }
    };
    
    int main() {
        return Tester::runTests<GrabbingTaxi>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            250, 1405877744, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
