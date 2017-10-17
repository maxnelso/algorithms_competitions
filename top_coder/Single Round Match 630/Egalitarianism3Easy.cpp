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

  template <typename Iterator>
inline bool next_combination(const Iterator first, Iterator k, const Iterator last)
{
  /* Credits: Thomas Draper */
  if ((first == last) || (first == k) || (last == k))
    return false;
  Iterator itr1 = first;
  Iterator itr2 = last;
  ++itr1;
  if (last == itr1)
    return false;
  itr1 = last;
  --itr1;
  itr1 = k;
  --itr2;
  while (first != itr1)
  {
    if (*--itr1 < *itr2)
    {
      Iterator j = k;
      while (!(*itr1 < *j)) ++j;
      std::iter_swap(itr1,j);
      ++itr1;
      ++j;
      itr2 = k;
      std::rotate(itr1,j,last);
      while (last != j)
      {
        ++j;
        ++itr2;
      }
      std::rotate(k,itr2,last);
      return true;
    }
  }
  std::rotate(first,k,last);
  return false;
}

class Egalitarianism3Easy {
  public: int maxCities(int n, vector<int> a, vector<int> b, vector<int> len);
};

bool is_done(vector<int> a, int my_index) {
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] == 0 && i != my_index) {
      return false;
    }
  }
  return true;
}

int Egalitarianism3Easy::maxCities(int n, vector<int> a, vector<int> b, vector<int> len) {
  map<int, vector<int>> distances;
  for (int i = 0; i < n; ++i) {
    vector<int> tmp(n);
    distances[i] = tmp;
  }
  for (int i = 0; i < b.size(); ++i) {
    distances[b[i] - 1][a[i] - 1] = len[i];
    distances[a[i] - 1][b[i] - 1] = len[i];
  }
  for (int i = 0; i < n; ++i) {
    while (!is_done(distances[i], i)) {
      for (int j = 0; j < n; ++j) {
        if (j != i) {
          for (int k = 0; k < n; ++k) {
            if (k != i && k != j) {
              if (distances[i][j] == 0) {
                distances[i][j] = distances[i][k] + distances[k][j];
                distances[j][i] = distances[i][k] + distances[k][j];

              } else {
                distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
                distances[j][i] = min(distances[i][j], distances[i][k] + distances[k][j]);
              }
              break;
            }
          }
        }
      }
    }
  }
  print_container(distances);
  for (int i = n; i >= 2; i--) {
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
      nums.push_back(i);
    }
    do {
      int dist = distances[nums[0]][nums[1]];
      bool bad = false;
      for (int j = 0; j < i; ++j) {
        for (int k = j + 1; k < i; ++k) {
     //     printf("Looking at %d %d %d with %d\n", nums[j], nums[k], distances[nums[j]][nums[k]], i);
          if (distances[nums[j]][nums[k]] != dist) {
            bad = true;
          }
        }
      }
      if (bad) {
        continue;
      }
      return i;
    } while(next_combination(nums.begin(), nums.begin() + i, nums.end()));
  }
  return 1;
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
  return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
  { { 4, {1,1,1}, {2,3,4}, {1,1,1} }, {3} },
    { { 6, {1,2,3,2,3}, {2,3,4,5,6}, {2,1,3,2,3} }, {3} },
    { {9, {2, 7, 7, 3, 9, 7, 6, 3}, {4, 9, 6, 5, 3, 2, 8, 1}, {857, 857, 857, 857, 857, 857, 857, 857}}, {3} },
    //{ { 10, {1,1,1,1,1,1,1,1,1}, {2,3,4,5,6,7,8,9,10}, {1000,1000,1000,1000,1000,1000,1000,1000,1000} }, {9} },
    //{ { 2, {1}, {2}, {3} }, {2} },
   // { { 1, {}, {}, {} }, {1} },
    // Your custom test goes here:
    //{ { , {}, {}, {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "../tester.cpp"
struct input {
  int p0;vector<int> p1;vector<int> p2;vector<int> p3;

  int run(Egalitarianism3Easy* x) {
    return x->maxCities(p0,p1,p2,p3);
  }
  void print() { Tester::printArgs(p0,p1,p2,p3); }
};

int main() {
  return Tester::runTests<Egalitarianism3Easy>(
      getTestCases<input, Tester::output<int>>(), disabledTest, 
      500, 1408669555, CASE_TIME_OUT, Tester::COMPACT_REPORT
      );
}
// CUT end
