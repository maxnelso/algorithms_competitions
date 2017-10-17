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

class Family {
  public: string isFamily(vector<int> parent1, vector<int> parent2);
};


pair<int, int> make_p(int a, int b) {
  return make_pair(min(a, b), max(a, b));
}

string Family::isFamily(vector<int> parent1, vector<int> parent2) {
  vector<pair<int, int> > diffs;
  vector<pair<int, int> > sames;
  for (int i = 0; i < parent1.size(); ++i) {
    int first_parent = parent1[i];
    int second_parent = parent2[i];
    if (first_parent != -1) {
      pair<int, int> p = make_p(first_parent, second_parent);
      if (find(sames.begin(), sames.end(), p) != sames.end()) {
        return "Impossible";
      }
      for (int j = 0; j < diffs.size(); j++) {
        if (diffs[j].first == first_parent) {
          sames.push_back(make_p(second_parent, diffs[j].second));
        } else if (diffs[j].first == second_parent) {
          sames.push_back(make_p(first_parent, diffs[j].second));
        } else if (diffs[j].second == first_parent) {
          sames.push_back(make_p(second_parent, diffs[j].first));
        } else if (diffs[j].second == second_parent) {
          sames.push_back(make_p(first_parent, diffs[j].first));
        }
      }
      diffs.push_back(p);
    }
  }
  return "Possible";
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x <0 ;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { {-1,-1,0}, {-1,-1,1} }, {"Possible"} },
    { { {-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1} }, {"Possible"} },
    { { {-1,-1,0,0,1}, {-1,-1,1,2,2} }, {"Impossible"} },
    { { {-1,-1,-1,-1,1,-1,0,5,6,-1,0,3,8,6}, {-1,-1,-1,-1,3,-1,4,6,5,-1,5,4,6,1} }, {"Possible"} },
    { { {-1,-1,-1,2,2,-1,5,6,4,6,2,1,8,0,2,4,6,9,-1,16,-1,11}, {-1,-1,-1,1,0,-1,1,4,2,0,4,8,2,3,0,5,14,14,-1,7,-1,13} }, {"Impossible"} },
    // Your custom test goes here:
    //{ { {}, {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        vector<int> p0;vector<int> p1;

        string run(Family* x) {
            return x->isFamily(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<Family>(
            getTestCases<input, Tester::output<string>>(), disabledTest, 
            250, 1398387606, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
