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

class RunningLetters {
  public: int newsLength(vector<string> running);
};

int RunningLetters::newsLength(vector<string> running) {
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
    { { {"3 abc 1 ab"} }, {3} },
    { { {"1 babaaba"} }, {5} },
    { { {"1 ba 1 c 1 bacba 3 cba"} }, {3} },
    { { {"42 runningletters 42 runningletters 1 running"} }, {14} },
    { { {"1 b ","1 a ","1 b ","1 a"," 1 b"} }, {2} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        vector<string> p0;

        int run(RunningLetters* x) {
            return x->newsLength(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<RunningLetters>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            1000, 1406000370, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
