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

class DivideAndShift {
  public: int getLeast(int N, int M);
};

vector<int> primes_to(int n) {
  vector<int> primes;
  for (int i = 2; i <= n; ++i) {
    bool not_prime = false;
    for (int j = 2; j * j <= i; ++j) {
      if (i % j == 0) {
        not_prime = true;
        break;
      }
    }
    if (!not_prime) {
      primes.push_back(i);
    }
  }
  return primes;
}


vector<int> dividing_primes(int n, vector<int>& primes) {
  vector<int> divisors;
  for (int i = 0; i < primes.size(); i++) {
    if (primes[i] > n) {
      break;
    }
    if (n % primes[i] == 0) {
      divisors.push_back(primes[i]);
    }
  }
  return divisors;
}

int getLeastHelper(int N, int M, vector<int>& primes, int level) {
  if (M == 1) {
    printf("Returning at %d %d %d\n", N, M, level);
    return level;
  }
  if (M == 2 || M == N) {
    printf("Returning at %d %d %d\n", N, M, level);
    return level + 1;
  }
  vector<int> divisors = dividing_primes(N, primes);
  int best = min(M, N - M + 1) + level; // shifting
  for (int i = 0; i < divisors.size(); ++i) {
    best = min(best, getLeastHelper(N / divisors[i], ((M - 1) % (N / divisors[i])) + 1, primes, level + 1));
  }
  return best;
}

int DivideAndShift::getLeast(int N, int M) {
  vector<int> primes = primes_to(1000000);
  return getLeastHelper(N, M, primes, 0);
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { 56, 14 }, {3} },
    { { 49, 5 }, {2} },
    { { 256, 7 }, {6} },
    { { 6, 1 }, {0} },
    { { 77777, 11111 }, {2} },
    { { 123456, 12347}, {7} },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        int p0;int p1;

        int run(DivideAndShift* x) {
            return x->getLeast(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<DivideAndShift>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1406398784, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
