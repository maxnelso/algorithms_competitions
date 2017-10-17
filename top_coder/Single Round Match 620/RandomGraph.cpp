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
#define print_vector_2d(a) for (int i = 0; i < a.size(); i++) {for (int j = 0; j < a[i].size(); j++) { if (j == a[0].size() - 1) {cout << a[i][j];} else { cout << a[i][j] << " ";}} cout << endl; }
using namespace std;

class RandomGraph {
  public: double probability(int n, int p);
};

unsigned nChoosek( unsigned n, unsigned k )
{
  if (k > n) return 0;
  if (k * 2 > n) k = n-k;
  if (k == 0) return 1;

  int result = n;
  for( int i = 2; i <= k; ++i ) {
    result *= (n-i+1);
    result /= i;
  }
  return result;
}

double RandomGraph::probability(int n, int p) {
  if (n < 3) {
    return 0;
  }
  double p_edge = p / 1000.0;
  double out = 0;
  //degree 2
  double two_degree = 0;
  //degree 1 :(
  //degree 0
  out += probability(n - 1, p);
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
  return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
  { { 7, 0 }, {0.0} },
    { { 3, 620 }, {0.0} },
    { { 4, 500 }, {0.59375} },
    { { 8, 100 }, {0.33566851611343496} },
    { { 15, 50 }, {0.5686761670525845} },
    { { 50, 10 }, {0.7494276522159893} },
    { { 50, 1000 }, {1.0} },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
//#define DISABLE_THREADS
#include "../tester.cpp"
struct input {
  int p0;int p1;

  double run(RandomGraph* x) {
    return x->probability(p0,p1);
  }
  void print() { Tester::printArgs(p0,p1); }
};

int main() {
  return Tester::runTests<RandomGraph>(
      getTestCases<input, Tester::output<double>>(), disabledTest, 
      1000, 1399739599, CASE_TIME_OUT, Tester::COMPACT_REPORT
      );
}
// CUT end
