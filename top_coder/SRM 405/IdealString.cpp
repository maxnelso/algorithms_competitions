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

class IdealString {
  public: string construct(int length);
};

string IdealString::construct(int length) {
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
    { { 1 }, {"A"} },
    { { 3 }, {"ABB"} },
    { { 2 }, {""} },
    { { 6 }, {"ABCBCC"} },
    { { 7 }, {"ABBCCCC"} },
    { { 5 }, {""} },
    // Your custom test goes here:
    //{ { }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        int p0;

        string run(IdealString* x) {
            return x->construct(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<IdealString>(
            getTestCases<input, Tester::output<string>>(), disabledTest, 
            1000, 1407088273, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
