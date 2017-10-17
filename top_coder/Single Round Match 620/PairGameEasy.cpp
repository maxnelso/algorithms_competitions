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

class PairGameEasy {
  public: string able(int a, int b, int c, int d);
};

string PairGameEasy::able(int a, int b, int c, int d) {
  queue<pair<int, int> > q;
  q.push(make_pair(a, b));
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    if (p.first == c && p.second == d) {
      return "Able to generate";
    }
    if (p.first > c || p.second > d) {
      continue;
    }
    q.push(make_pair(p.first + p.second, p.second));
    q.push(make_pair(p.first, p.second + p.first));
  }
  return "Not able to generate";
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { 1, 2, 3, 5 }, {"Able to generate"} },
    { { 1, 2, 2, 1 }, {"Not able to generate"} },
    { { 2, 2, 2, 999 }, {"Not able to generate"} },
    { { 2, 2, 2, 1000 }, {"Able to generate"} },
    { { 47, 58, 384, 221 }, {"Able to generate"} },
    { { 1000, 1000, 1000, 1000 }, {"Able to generate"} },
    // Your custom test goes here:
    //{ { , , , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        int p0;int p1;int p2;int p3;

        string run(PairGameEasy* x) {
            return x->able(p0,p1,p2,p3);
        }
        void print() { Tester::printArgs(p0,p1,p2,p3); }
    };
    
    int main() {
        return Tester::runTests<PairGameEasy>(
            getTestCases<input, Tester::output<string>>(), disabledTest, 
            500, 1399738797, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
