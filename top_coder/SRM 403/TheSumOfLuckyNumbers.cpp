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

class TheSumOfLuckyNumbers {
  public: vector<int> sum(int n);
};

vector<int> TheSumOfLuckyNumbers::sum(int n) {
  vector<int> luckys;
  queue<pair<int, vector<int>>> q;
  bool seen[1000005];
  for (int i = 1; i < 7; i++) {
    for(int k = 0; k <= i; k++) {
      vector<bool> selectors(i);
      fill(selectors.end() - k, selectors.end(), true);
      do {
        string s = "";
        for (int j = 0; j < i; ++j) {
          if (selectors[j]) {
            s += "7";
          } else {
            s += "4";
          }
        }
        luckys.push_back(stoi(s));
        vector<int> sum = {stoi(s)};
        q.push(make_pair(stoi(s), sum));
        seen[stoi(s)] = true;
      } while (next_permutation(selectors.begin(), selectors.end()));
    }
  }
  while (!q.empty()) {
    pair<int, vector<int>> p = q.front();
    q.pop();
    if (p.first == n) {
      vector<int> out = p.second;
      return out;
    }
    for (int i = 0; i < luckys.size(); ++i) {
      int sum = p.first + luckys[i];
      if (sum == n) {
        vector<int> out = p.second;
        out.push_back(luckys[i]);
        return out;
      }
      if (sum <= 1000000 && !seen[sum]) {
        seen[sum] = true;
        vector<int> sums = p.second;
        sums.push_back(luckys[i]);
        q.push(make_pair(sum, sums));
      }
    }
  }
  return vector<int>();
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
  {  { 11 }, { {4,7} } },
    { { 12 }, { {4,4,4} } },
    { { 13 }, { {} } },
    { { 950000 }, { {} } },
    { { 100 }, { {4,4,4,44,44} } },
    // Your custom test goes here:
    //{ { }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        int p0;

        vector<int> run(TheSumOfLuckyNumbers* x) {
            return x->sum(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<TheSumOfLuckyNumbers>(
            getTestCases<input, Tester::output<vector<int>>>(), disabledTest, 
            1000, 1407004035, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
