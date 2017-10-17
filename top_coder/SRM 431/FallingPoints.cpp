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

class FallingPoints {
  public: vector<double> getHeights(vector<int> X, int R);
};

double get_y(int x1, int x2, double y1, int R) {
  if (abs(x1 - x2) > R) {
    return 0.0;
  }
  return sqrt(pow(R, 2) - pow((x2 - x1), 2)) + y1;
}

vector<double> FallingPoints::getHeights(vector<int> X, int R) {
  vector<double> out;
  out.push_back(0.0);
  for (int i = 1; i < X.size(); i++) {
    double best = 0.0;
    best = max(best, get_y(X[i-1], X[i], out[i-1], R));
    out.push_back(best);
  }
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
    { { {0}, 10 }, { {0.0} } },
    { { {1,100}, 10 }, { {0.0,0.0} } },
    { { {0,9}, 10 }, { {0.0,4.358898943540674} } },
    { { {0,9,19}, 10 }, { {0.0,4.358898943540674,4.358898943540674} } },
    { { {13, 6, 0, 42, 51, 23, 33}, 10}, { {0.0, 7.14142842854285, 15.14142842854285, 0.0, 4.358898943540674, 0.0, 0.0} } },
    // Your custom test goes here:
    //{ { {}, }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        vector<int> p0;int p1;

        vector<double> run(FallingPoints* x) {
            return x->getHeights(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<FallingPoints>(
            getTestCases<input, Tester::output<vector<double>>>(), disabledTest, 
            500, 1403579828, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
