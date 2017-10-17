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

class CatAndRat {
  public: double getTime(int R, int T, int Vrat, int Vcat);
};

double CatAndRat::getTime(int R, int T, int Vrat, int Vcat) {
  if (Vrat >= Vcat) {
    return -1.0;
  }
  double pi = atan(1)*4;
  // not half way
  if (Vrat * T < pi * R) {
    cout << "mouse goes " << (Vrat * T) << endl;
    return ((double) (Vrat * T)) / (((double) (Vcat - Vrat)));
  } else {
    return (double) (pi * R) / ((double) (Vcat - Vrat));
  }

}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { 10, 1, 1, 1 }, {-1.0} },
    { { 10, 1, 1, 2 }, {1.0} },
    { { 10, 1, 2, 1 }, {-1.0} },
    { { 1000, 1000, 1, 1000 }, {1.001001001001001} },
    { { 1, 1000, 1, 2 }, {3.141592653589793} },
    // Your custom test goes here:
    //{ { , , , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        int p0;int p1;int p2;int p3;

        double run(CatAndRat* x) {
            return x->getTime(p0,p1,p2,p3);
        }
        void print() { Tester::printArgs(p0,p1,p2,p3); }
    };
    
    int main() {
        return Tester::runTests<CatAndRat>(
            getTestCases<input, Tester::output<double>>(), disabledTest, 
            450, 1401930675, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
