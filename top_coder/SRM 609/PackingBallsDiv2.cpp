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

class PackingBallsDiv2 {
  public: int minPacks(int R, int G, int B);
};

int PackingBallsDiv2::minPacks(int R, int G, int B) {
  int rmod = R % 3;
  int gmod = G % 3;
  int bmod = B % 3;
  int count = (R + G + B) / 3;
  if (rmod != gmod || rmod != bmod || gmod != bmod) {
    count++;
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
    { { 4, 2, 4 }, {4} },
    { { 1, 7, 1 }, {3} },
    { { 2, 3, 5 }, {4} },
    { { 78, 53, 64 }, {66} },
    { { 100, 100, 100 }, {100} },
    // Your custom test goes here:
    //{ { , , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        int p0;int p1;int p2;

        int run(PackingBallsDiv2* x) {
            return x->minPacks(p0,p1,p2);
        }
        void print() { Tester::printArgs(p0,p1,p2); }
    };
    
    int main() {
        return Tester::runTests<PackingBallsDiv2>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1474439900, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
