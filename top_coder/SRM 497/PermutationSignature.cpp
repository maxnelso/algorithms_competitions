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

class PermutationSignature {
  public: vector<int> reconstruct(string signature);
};

vector<int> PermutationSignature::reconstruct(string signature) {
  vector<int> d_counts;
  int d_count = 0;
  for (int i = 0; i < signature.size(); i++) {
    if (signature[i] == 'I') {
      d_counts.push_back(d_count);
      d_count = 0;
    } else {
      d_count++;
    }
  }
  d_counts.push_back(d_count);
  vector<bool> seen(signature.size() + 1);
  fill(seen.begin(), seen.end(), false);
  vector<int> out;
  for (int i = 0; i < d_counts.size(); i++) {
    int smallest = 0;
    while (seen[smallest]) {
      smallest++;
    }
    seen[smallest] = true;
    for (int j = 0; j < d_counts[i]; j++) {
      out.push_back(smallest + (d_counts[i] - j) + 1);
      seen[smallest + (d_counts[i] - j)] = true;
    }
    out.push_back(smallest + 1);
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
    { { "IIIII" }, { {1,2,3,4,5,6} } },
    { { "DI" }, { {2,1,3} } },
    { { "IIIID" }, { {1,2,3,4,6,5} } },
    { { "DIIDID" }, { {2,1,3,5,4,7,6} } },
    // Your custom test goes here:
    //{ { }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        string p0;

        vector<int> run(PermutationSignature* x) {
            return x->reconstruct(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<PermutationSignature>(
            getTestCases<input, Tester::output<vector<int>>>(), disabledTest, 
            250, 1399694285, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
