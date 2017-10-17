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

class LightedPanels {
  public: int minTouch(vector<string> board);
};

int LightedPanels::minTouch(vector<string> board) {
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
    { { {"*****","*...*","*...*","*...*","*****"} }, {1} },
    { { {".*"} }, {-1} },
    { { {"**.","**.","..."} }, {2} },
    { { {"*...","**..","..**","...*"} }, {10} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        vector<string> p0;

        int run(LightedPanels* x) {
            return x->minTouch(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<LightedPanels>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            1000, 1405880270, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
