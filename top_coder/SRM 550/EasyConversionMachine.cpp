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

class EasyConversionMachine {
  public: string isItPossible(string originalWord, string finalWord, int k);
};

string EasyConversionMachine::isItPossible(string originalWord, string finalWord, int k) {
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
    { { "aababba", "bbbbbbb", 2 }, {"IMPOSSIBLE"} },
    { { "aabb", "aabb", 1 }, {"IMPOSSIBLE"} },
    { { "aaaaabaa", "bbbbbabb", 8 }, {"POSSIBLE"} },
    { { "aaa", "bab", 4 }, {"POSSIBLE"} },
    { { "aababbabaa", "abbbbaabab", 9 }, {"IMPOSSIBLE"} },
    // Your custom test goes here:
    //{ { , , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        string p0;string p1;int p2;

        string run(EasyConversionMachine* x) {
            return x->isItPossible(p0,p1,p2);
        }
        void print() { Tester::printArgs(p0,p1,p2); }
    };
    
    int main() {
        return Tester::runTests<EasyConversionMachine>(
            getTestCases<input, Tester::output<string>>(), disabledTest, 
            250, 1424221905, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
