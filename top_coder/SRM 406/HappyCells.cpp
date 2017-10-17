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

class HappyCells {
  public: vector<int> getHappy(vector<string> grid);
};

bool in_bounds(int x, int y, vector<string> grid) {
  return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
}

vector<int> HappyCells::getHappy(vector<string> grid) {
  vector<int> out(3);
  vector<pair<int, int>> diags = { {1, 1}, {-1, -1}, {-1, 1}, {1, -1} };
  vector<pair<int, int>> orthogs = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[0].size(); ++j) {
      bool diag = true;
      for (int k = 0; k < diags.size(); ++k) {
        if (in_bounds(i + diags[k].first, j + diags[k].second, grid)) {
          if (grid[i + diags[k].first][j + diags[k].second] == '.') {
            //printf("Failing on %d %d %c\n", i + diags[k].first, j + diags[k].second, grid[i + diags[k].first][j + diags[k].second]);
            diag = false;
            break;
          }
        }
      }
      if (grid[i][j] != '.') {
        diag = false;
      }
      bool orthog = true;
      for (int k = 0; k < orthogs.size(); ++k) {
        if (in_bounds(i + orthogs[k].first, j + orthogs[k].second, grid)) {
          if (grid[i + orthogs[k].first][j + orthogs[k].second] == '.') {
            orthog = false;
            break;
          }
        }
      }
      if (grid[i][j] != '.') {
        orthog = false;
      }
      printf("For %d %d: we get %d %d\n", i, j, diag, orthog);
      if (orthog && diag) {
        out[0]++;
      } else if (orthog) {
        out[1]++;
      } else if (diag) {
        out[2]++;
      }
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
    { { {"XXX","X.X","XXX"} }, { {1,0,0} } },
    { { {"."} }, { {1,0,0} } },
    { { {"XXXXXX","X.XXXX","XXX.XX","X..XXX","XXXXXX"} }, { {1,1,1} } },
    { { {"..."} }, { {0,0,3} } },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        vector<string> p0;

        vector<int> run(HappyCells* x) {
            return x->getHappy(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<HappyCells>(
            getTestCases<input, Tester::output<vector<int>>>(), disabledTest, 
            250, 1408296825, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
