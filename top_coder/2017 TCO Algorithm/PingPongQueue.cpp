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

class PingPongQueue {
  public: vector<int> whoPlaysNext(vector<int> skills, int N, int K);
};

vector<int> PingPongQueue::whoPlaysNext(vector<int> skills, int N, int K) {
  map<int, int> in_a_row;
  deque<int> q;
  for (int i = 0; i < skills.size(); i++) {
    q.push_back(i);
  }
  int c = 0;
  int a;
  int b;
  while (c < K - 1) {
    a = q.front();
    q.pop_front();
    b = q.front();
    q.pop_front();
    int a_skill = skills[a];
    int b_skill = skills[b];
    c++;
    if (a_skill > b_skill) {
      in_a_row[a]++;
      in_a_row[b] = 0;
      q.push_back(b);
      if (in_a_row[a] == N) {
        in_a_row[a] = 0;
        q.push_back(a);
      } else {
        q.push_front(a);
      }
      swap(a, b);
    } else {
      in_a_row[b]++;
      in_a_row[a] = 0;
      q.push_back(a);
      if (in_a_row[b] == N) {
        in_a_row[b] = 0;
        q.push_back(b);
      } else {
        q.push_front(b);
      }
    }
  }
  a = q.front();
  q.pop_front();
  b = q.front();
  q.pop_front();
  return {min(skills[a], skills[b]), max(skills[a], skills[b])};
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
  return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
  { { {1,2,3}, 2, 2 }, { {2,3} } },
    { { {1,2,3}, 2, 4 }, { {1,2} } },
    { { {49,24,26,12,5,33,25,30,35,41,46,23,21,3,38,43,11,19,34,29,20,32,39,7,50}, 10, 399 }, { {12,50} } },
    { { {30,12}, 34, 80 }, { {12,30} } },
    // Your custom test goes here:
    //{ { {}, , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<int> p0;int p1;int p2;

        vector<int> run(PingPongQueue* x) {
            return x->whoPlaysNext(p0,p1,p2);
        }
        void print() { Tester::printArgs(p0,p1,p2); }
    };
    
    int main() {
        return Tester::runTests<PingPongQueue>(
            getTestCases<input, Tester::output<vector<int>>>(), disabledTest, 
            250, 1491062515, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
