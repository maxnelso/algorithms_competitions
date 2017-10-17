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

class DoubleLetter {
  public: string ableToSolve(string S);
};

string DoubleLetter::ableToSolve(string S) {
  bool found = true;
  while (found) {
    found = false;
    string tmp = "";
    for (int i = 0; i < S.size(); ++i) {
      if (i < S.size() && S[i] == S[i+1] && !found) {
        found = true;
        i++;
      } else {
        tmp += S[i];
      }
    }
    S = tmp;
  }
  return S.size() == 0 ? "Possible" : "Impossible";
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { "aabccb" }, {"Possible"} },
    { { "a" }, {"Impossible"} },
    { { "aabccbb" }, {"Impossible"} },
    { { "abcddcba" }, {"Possible"} },
    { { "abab" }, {"Impossible"} },
    { { "aaaaaaaaaa" }, {"Possible"} },
    { { "aababbabbaba" }, {"Impossible"} },
    { { "zzxzxxzxxzzx" }, {"Possible"} },
    // Your custom test goes here:
    //{ { }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        string p0;

        string run(DoubleLetter* x) {
            return x->ableToSolve(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<DoubleLetter>(
            getTestCases<input, Tester::output<string>>(), disabledTest, 
            250, 1408669204, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
