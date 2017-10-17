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

class SquareScores {
  public: double calcexpectation(vector<int> p, string s);
};

double SquareScores::calcexpectation(vector<int> p, string s) {
  while (p.size() != 26) {
    p.push_back(0);
  }
  double out = 0.0f;
  for (int i = 1; i <= s.size(); i++) {
    for (int j = 0; j < 26; j++) {
      char c = 'a' + j;
      for (int k = 0; k < s.size() - i + 1; k++) { // start index
        double probability = 1.0;
        for (int l = 0; l < i; l++) {
          int index = k + l;
          if (s[index] != c && s[index] != '?') {
            probability = 0;
            break;
          } else if (s[index] == c) {
            probability = probability;
          } else if (s[index] == '?') {
            probability = probability * (p[j] / 100.0);
          }
        }
        out += probability;
      }
    }
  }
  return out;
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { {1,99}, "aaaba" }, {8.0} },
    { { {10,20,70}, "aa?bbbb" }, {15.0} },
    { { {100}, "?" }, {1.0} },
    { { {100}, "??" }, {3.0} },
    { { {10,20,30,40}, "a??c?dc?b" }, {11.117} },
    { { {25,25,21,2,2,25}, "a??b???????ff??e" }, {21.68512690712425} },
    { { {4,4,4,3,4,4,4,4,4,4,3,4,4,4,3,4,4,4,4,4,4,4,3,4,4,4}, "??????????????????????????????" }, {31.16931963781721} },
    { { {4,3,4,3,8,2,4,3,4,4,3,2,4,4,3,4,2,4,7,6,4,4,3,4,4,3}, "makigotapresentfromniko" }, {23.0} },
    // Your custom test goes here:
    //{ { {}, }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<int> p0;string p1;

        double run(SquareScores* x) {
            return x->calcexpectation(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<SquareScores>(
            getTestCases<input, Tester::output<double>>(), disabledTest, 
            250, 1427332540, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
