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

class BlockTower {
  public: int getTallest(vector<int> blockHeights);
};

int BlockTower::getTallest(vector<int> blockHeights) {
  vector<int> even_indices;
  for (int i = 0; i < blockHeights.size(); i++) {
    if (blockHeights[i] % 2 == 0) {
      even_indices.push_back(i);
    }
  }
  int just_odds = 0;
  int with_evens = 0;
  for (int i = 0; i < blockHeights.size(); ++i) {
    if (blockHeights[i] % 2 == 1) {
      just_odds += blockHeights[i];
    }
  }
  for (int i = 0; i < even_indices.size(); ++i) {
    int count = 0;
    for (int j = 0; j <= i; j++) {
      count += blockHeights[even_indices[j]];
    }
    for (int j = even_indices[i] + 1; j < blockHeights.size(); ++j) {
      if (blockHeights[j] % 2 == 1) {
        count += blockHeights[j];
      }
    }
    with_evens = max(with_evens, count);
  }
  return max(just_odds, with_evens);
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { {4,7} }, {11} },
    { { {7,4} }, {7} },
    { { {7} }, {7} },
    { { {4} }, {4} },
    { { {48,1,50,1,50,1,48} }, {196} },
    { { {49,2,49,2,49} }, {147} },
    { { {44,3,44,3,44,47,2,47,2,47,2} }, {273} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        vector<int> p0;

        int run(BlockTower* x) {
            return x->getTallest(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<BlockTower>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            250, 1403752319, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
