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
#define print_vector(a) cout << "{"; for (int i = 0; i < a.size(); i++) { if (i == a.size() - 1) {cout << a[i];} else { cout << a[i] << ",";}} cout << "}n";
using namespace std;

class RedPaint {
  public: double expectedCells(int N);
};

double RedPaint::expectedCells(int N) {
  double probs[N][N][N]; // starting at cell i, going to cell j, with moves k
  memset(probs, 0, sizeof(probs[0][0][0]) * N * N *N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i != j) {
        for (int k = 0; k < N; ++k) {
          if (k == 0) {
            probs[i][j][k] = 0;
          } else if (k == 1) {
            if (abs(i - j) == 1) {
              probs[i][j][k] = .5;
            } else {
              probs[i][j][k] = 0;
            }
          } else {
            if (i > 0) {
              probs[i][j][k] += probs[i-1][j][k-1]*.5;
            }
            if (j < N - 1) {
              probs[i][j][k] += probs[i][j+1][k-1]*.5;
            }
          }
        }
      }
    }
  }
  double out;
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
    { { 0 }, {1.0} },
    { { 1 }, {2.0} },
    { { 2 }, {2.5} },
    { { 4 }, {3.375} },
    // Your custom test goes here:
    //{ { }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        int p0;

        double run(RedPaint* x) {
            return x->expectedCells(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<RedPaint>(
            getTestCases<input, Tester::output<double>>(), disabledTest, 
            950, 1398529459, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
