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


class RandomSort {
  public: double getExpected(vector<int> permutation);
};

string vtos(vector<int> s) {
  string out = "";
  for (int i = 0; i < s.size(); ++i) {
    out += to_string(s[i]);
  }
  return out;
}

bool is_sorted(vector<int> permutation) {
  vector<int> copy(permutation);
  sort(copy.begin(), copy.end());
  return equal(copy.begin(), copy.end(), permutation.begin());
}

double helper(vector<int> permutation, int swaps, double p, map<string, double>& memo) {
  if (is_sorted(permutation)) {
    return swaps * p;
  }
  if (memo.find(vtos(permutation)) != memo.end()) {
    return memo[vtos(permutation)] + (swaps * p);
  }
  vector<pair<int, int>> pairs;
  for (int i = 0; i < permutation.size(); ++i) {
    for (int j = i + 1; j < permutation.size(); ++j) {
      if (permutation[i] > permutation[j])  {
        pairs.push_back(make_pair(i, j));
      }
    }
  }
  double out = 0;
  for (int i = 0; i < pairs.size(); ++i) {
    vector<int> copy(permutation);
    swap(copy[pairs[i].first], copy[pairs[i].second]);
    double swaps_out = helper(copy, swaps + 1, p * (1.0d / pairs.size()), memo);
    memo[vtos(permutation)] = swaps_out;
    out += swaps_out;
  }
  return out;
}

double RandomSort::getExpected(vector<int> permutation) {
  map<string, double> memo;
  vector<int> copy(permutation);
  sort(copy.begin(), copy.end());
  memo[vtos(copy)] = 0;
  return helper(permutation, 0, 1, memo);
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { {1,3,2} }, {1.0} },
    { { {4,3,2,1} }, {4.066666666666666} },
    { { {1} }, {0.0} },
    { { {2,5,1,6,3,4} }, {5.666666666666666} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        vector<int> p0;

        double run(RandomSort* x) {
            return x->getExpected(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<RandomSort>(
            getTestCases<input, Tester::output<double>>(), disabledTest, 
            1000, 1406604507, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
