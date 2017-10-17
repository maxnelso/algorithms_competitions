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

class SwitchingGame {
  public: int timeToWin(vector<string> states);
};

int SwitchingGame::timeToWin(vector<string> states) {
  string current;
  int time = states.size();
  for (int i = 0; i < states[0].size(); ++i) {
    current += '-';
  }
  for (int i = 0; i < states.size(); ++i) {
    printf("%s\n", states[i].c_str());
    int swappedOns = 0;
    int swappedOffs = 0;
    for (int j = 0; j < states[i].size(); ++j) {
      if (states[i][j] != '?') {
        if (states[i][j] == '-' && current[j] == '+') {
          swappedOns = 1;
        }
        if (states[i][j] == '+' && current[j] == '-') {
          swappedOffs = 1;
        }
        current[j] = states[i][j];
      }
    }
    for (int j = 0; j < states[i].size(); ++j) {
      if (states[i][j] == '?') {
        for (int k = i; k < states.size(); k++) {
          if (states[k][j] == '+' && swappedOffs != 0) {
            current[j] = states[k][j];
            break;
          }
          if (states[k][j] == '-' && swappedOns != 0) {
            current[j] = states[k][j];
            break;
          }
        }
      }
    }
    time = time + swappedOns + swappedOffs;
  }
  return time;
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { {"++--","--++"} }, {5} },
    { { {"+-++","+-++"} }, {3} },
    { { {"?-","?+","?-","++"} }, {5} },
    { { {"+","?","?","?","-"} }, {7} },
    { { {"+??+++","++??+-","?++??+","?-+-??","??+?++","++-?+?","?++?-+","?--+++","-??-?+"} }, {20} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        vector<string> p0;

        int run(SwitchingGame* x) {
            return x->timeToWin(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<SwitchingGame>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            350, 1402156815, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
