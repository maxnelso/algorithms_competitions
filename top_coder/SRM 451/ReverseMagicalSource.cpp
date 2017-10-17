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

class ReverseMagicalSource {
  public: int find(int source, int A);
};

int ReverseMagicalSource::find(int source, int A) {
  int i = 1;
  int total = source;
  while (total <= A) {
    source = source * pow(10, i);
    total += source;
  }
  return total;
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { 19, 200 }, {209} },
    { { 19, 18 }, {19} },
    { { 333, 36963 }, {369963} },
    { { 1234, 1000000 }, {1370974} },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        int p0;int p1;

        int run(ReverseMagicalSource* x) {
            return x->find(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<ReverseMagicalSource>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            250, 1403664676, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
