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

class SuffixArrayDiv2 {
  public: string smallerOne(string s);
};

string SuffixArrayDiv2::smallerOne(string s) {
  return "";
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { "abca" }, {"Exists"} },
    { { "bbbb" }, {"Exists"} },
    { { "aaaa" }, {"Does not exist"} },
    { { "examplesareveryweakthinktwicebeforesubmit" }, {"Exists"} },
    // Your custom test goes here:
    //{ { }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        string p0;

        string run(SuffixArrayDiv2* x) {
            return x->smallerOne(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<SuffixArrayDiv2>(
            getTestCases<input, Tester::output<string>>(), disabledTest, 
            1000, 1408731137, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
