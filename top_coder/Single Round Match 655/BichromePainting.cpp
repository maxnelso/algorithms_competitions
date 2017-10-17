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

class BichromePainting {
  public: string isThatPossible(vector<string> board, int k);
};

string BichromePainting::isThatPossible(vector<string> board, int k) {
  vector<string> current;
  for (int i = 0; i < board.size(); i++) {
    string s;
    for (int j = 0; j < board[0].size(); j++) {
      s += 'W';
    }
    current.push_back(s);
  }
  for (int i = 0; i <= board.size() - k; i++) {
    for (int j = 0; j <= board[0].size() - k; j++) {
      if (board[i][j] != current[i][j]) {
        for (int x = 0; x < k; x++) {
          for (int y = 0; y < k; y++) {
            current[i + x][j + y] = board[i][j];
          }
        }
      }
      if (i == board.size() - k) {
        bool change = false;
        for (int x = 0; x < k; x++) {
          if (board[i + x][j] == 'B' && current[i + x][j] == 'W') {
            change = true;
            break;
          }
        }
        if (change) {
          for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
              current[i + x][j + y] = board[i][j];
            }
          }
        }
      }
      if (j == board[0].size() - k) {
        bool change = false;
        for (int y = 0; y < k; y++) {
          if (board[i][j + y] == 'B' && current[i][j + y] == 'W') {
            change = true;
            break;
          }
        }
        if (change) {
          for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
              current[i + x][j + y] = board[i][j];
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      if (board[i][j] != current[i][j]) {
        return "Impossible";
      }
    }
  }
  return "Possible";
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { {"BBBW","BWWW","BWWW","WWWW"}, 3 }, {"Possible"} },
    { { {"BBW","BBW","WWB"}, 2 }, {"Impossible"} },
    { { {"BW","WB"}, 2 }, {"Impossible"} },
    { { {"BW","WB"}, 1 }, {"Possible"} },
    { { {"WW","WW"}, 2 }, {"Possible"} },
    { { {"BWBWBB","WBWBBB","BWBWBB","WBWBBB","BBBBBB","BBBBBB"}, 2 }, {"Possible"} },
    { { {"BWBWBB","WBWBWB","BWBWBB","WBWBWB","BWBWBB","BBBBBB"}, 2 }, {"Impossible"} },
    { { {"BWBWBB","WBWBWB","BWBWBB","WBWBWB","BWBWBB","BBBBBB"}, 1 }, {"Possible"} },
    { { {"BB","BB"}, 2 }, {"Possible"} },
    // Your custom test goes here:
    //{ { {}, }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<string> p0;int p1;

        string run(BichromePainting* x) {
            return x->isThatPossible(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<BichromePainting>(
            getTestCases<input, Tester::output<string>>(), disabledTest, 
            250, 1428591754, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
