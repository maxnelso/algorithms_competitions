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

class GameOfLifeDivTwo {
  public: string theSimulation(string init, int T);
};

string GameOfLifeDivTwo::theSimulation(string init, int T) {
  string temp = "";
  for (int i = 0; i < T; i++) {
    for (int j = 0; j < init.size(); j++) {
      int a_index = j - 1;
      if (a_index < 0) {
        a_index = init.size() - 1;
      }
      int c_index = j + 1;
      if (c_index == init.size()) {
        c_index = 0;
      }
      char a = init[a_index];
      char b = init[j];
      char c = init[c_index];
      int out = a - '0' + b - '0' + c - '0';
      if (out >= 2) {
        temp += '1';
      } else {
        temp += '0';
      }
    }
    init = temp;
    temp = "";
  }
  return init;
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { "01010", 2 }, {"00000"} },
    { { "010101", 5 }, {"101010"} },
    { { "111010", 58 }, {"111111"} },
    { { "111111111", 511 }, {"111111111"} },
    { { "110010000010111110010100001001", 1000 }, {"110000000001111110000000000001"} },
    { { "00101110011", 0 }, {"00101110011"} },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        string p0;int p1;

        string run(GameOfLifeDivTwo* x) {
            return x->theSimulation(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<GameOfLifeDivTwo>(
            getTestCases<input, Tester::output<string>>(), disabledTest, 
            250, 1403902476, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
