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
#define print_container(c) cout << c << endl;
#endif

using namespace std;

class ParenthesesDiv2Hard {
  public: int minSwaps(string s, vector<int> L, vector<int> R);
};

int ParenthesesDiv2Hard::minSwaps(string s, vector<int> L, vector<int> R) {
  vector<int> swappies;
  sort(L.begin(), L.end());
  sort(R.begin(), R.end());
  bool in_slice = false;
  int depth = 0;
  int extra_lefts = 0;
  int extra_rights = 0;
  int index = 0;
  for (int i = 0; i < s.size(); i++) {
    if (!in_slice && i == L[index]) {
      printf("sup");
      in_slice = true;
      depth = 0;
    }


    if (in_slice) {
      if (s[i] == '(') {
        depth++;
      } else {
        depth--;
      }
    } else {
      if (s[i] == '(') {
        extra_lefts++;
      } else {
        extra_rights++;
      }
    }


    if (in_slice && i == R[index]) {
      printf("aaa");
      in_slice = false;
      index++;
      swappies.push_back(depth);
    }
  }

  sort(swappies.begin(), swappies.end());

  printf("\n");
  for (int i = 0; i < swappies.size(); i++) {
    printf("%d", swappies[i]);
  }

  printf("\n");
  int out = 0;
  for (int i = 0; i < swappies.size(); i++) {
    int current = swappies[i];

    if (current > 0) {
      break;
    }

    while (current != 0) {
      bool found = false;
      for (int j = swappies.size() - 1; j > i; j--) {
        if (swappies[j] > 0) {
          swappies[i]++;
          current = swappies[i];
          swappies[j]--;
          out++;
          found = true;
          break;
        }
      }
      if (!found) {
        break;
      }
    }
  }

  for (int i = 0; i < swappies.size(); i++) {
    printf("%d", swappies[i]);
  }

  for (int i = 0; i < swappies.size(); i++) {
    if (swappies[i] > 0) {
        if (extra_lefts - swappies[i] < 0) {
          return -1;
        } else {
          extra_lefts -= swappies[i];
          out += swappies[i];
        }
    } else {
        if (extra_rights - swappies[i] < 0) {
          return -1;
        } else {
          extra_rights -= swappies[i];
          out += swappies[i];
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
    { { ")(", {0}, {1} }, {1} },
    { { "(())", {0,2}, {1,3} }, {1} },
    { { "(((())", {0,2}, {1,3} }, {2} },
    { { "(((((((((", {0,2}, {1,3} }, {-1} },
    { { "))()())((()()()()()())))((((((", {1,6,13,17,23,25}, {4,7,16,20,24,28} }, {5} },
    { { "(", {0}, {0} }, {-1} },
    // Your custom test goes here:
    //{ { , {}, {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        string p0;vector<int> p1;vector<int> p2;

        int run(ParenthesesDiv2Hard* x) {
            return x->minSwaps(p0,p1,p2);
        }
        void print() { Tester::printArgs(p0,p1,p2); }
    };
    
    int main() {
        return Tester::runTests<ParenthesesDiv2Hard>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            1000, 1472113764, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
