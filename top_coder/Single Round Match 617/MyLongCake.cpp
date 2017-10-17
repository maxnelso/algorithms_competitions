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

class MyLongCake {
  public: int cut(int n);
};

vector<int> get_divisors(int n) {
  vector<int> divisors;
  for (int i = n - 1; i >= 2; --i) {
    if (n % i == 0) {
      divisors.push_back(i);
    }
  }
  return divisors;
}

int MyLongCake::cut(int n) {
  vector<int> divisors = get_divisors(n);
  vector<int> lengths;
  int index = 0;
  int n_old = n;
  while (n > 0) {
    int div = divisors[index];
    index = (index + 1) % divisors.size();
    int length = n_old / div;
    if (lengths.size() == 0) {
      int length = n_old / div;
      n -= length;
      lengths.push_back(length);
    } else {
      int new_length = length - lengths[lengths.size() - 1];
      while (new_length > divisors[0]) {
        
      }
      n -= new_length;
      lengths.push_back(new_length);
    }
  }
  print_vector(lengths);
  return lengths.size();
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { 6 }, {4} },
    { { 3 }, {1} },
    { { 15 }, {7} },
    { { 100000 }, {60000} },
    // Your custom test goes here:
    //{ { }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        int p0;

        int run(MyLongCake* x) {
            return x->cut(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<MyLongCake>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            250, 1398081600, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
