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

class NextOrPrev {
  public: int getMinimum(int nextCost, int prevCost, string start, string goal);
};

int NextOrPrev::getMinimum(int nextCost, int prevCost, string start, string goal) {
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
    { { 5, 8, "ae", "bc" }, {21} },
    { { 5, 8, "ae", "cb" }, {-1} },
    { { 1, 1, "srm", "srm" }, {0} },
    { { 10, 1, "acb", "bdc" }, {30} },
    { { 10, 1, "zyxw", "vuts" }, {16} },
    { { 563, 440, "ptrbgcnlaizo", "rtscedkiahul" }, {10295} },
    { { 126, 311, "yovlkwpjgsna", "zpwnkytjisob" }, {-1} },
    // Your custom test goes here:
    //{ { , , , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        int p0;int p1;string p2;string p3;

        int run(NextOrPrev* x) {
            return x->getMinimum(p0,p1,p2,p3);
        }
        void print() { Tester::printArgs(p0,p1,p2,p3); }
    };
    
    int main() {
        return Tester::runTests<NextOrPrev>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1405095880, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
