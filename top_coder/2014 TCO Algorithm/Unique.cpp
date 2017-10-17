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

class Unique {
  public: string removeDuplicates(string S);
};

string Unique::removeDuplicates(string S) {
  map<char, bool> seen;
  string out = "";
  for (int i = 0; i < S.size(); ++i) {
    if (seen.find( S[i]) != seen.end()) {
      continue;
    } else {
      out = out + S[i];
      seen[S[i]] = true;
    }
  }
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
    { { "banana" }, {"ban"} },
    { { "aardvark" }, {"ardvk"} },
    { { "xxxxx" }, {"x"} },
    { { "topcoder" }, {"topcder"} },
    // Your custom test goes here:
    //{ { }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        string p0;

        string run(Unique* x) {
            return x->removeDuplicates(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<Unique>(
            getTestCases<input, Tester::output<string>>(), disabledTest, 
            250, 1398528015, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
