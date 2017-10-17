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

class RandomGraph {
  public: double probability(int n, int p);
};

double RandomGraph::probability(int n, int p) {
  return 0.0;
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { 7, 0 }, {0.0} },
    { { 3, 620 }, {0.0} },
    { { 4, 500 }, {0.59375} },
    { { 8, 100 }, {0.33566851611343496} },
    { { 15, 50 }, {0.5686761670525845} },
    { { 50, 10 }, {0.7494276522159893} },
    { { 50, 1000 }, {1.0} },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        int p0;int p1;

        double run(RandomGraph* x) {
            return x->probability(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<RandomGraph>(
            getTestCases<input, Tester::output<double>>(), disabledTest, 
            1000, 1400285604, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
