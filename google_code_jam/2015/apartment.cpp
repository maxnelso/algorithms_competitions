#include <vector>
#include <list>
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

string FILENAME = "test";

vector<int> read(string s){
  vector<int> ret;
  int n;
  istringstream sin(s);
  while(sin>>n)
    ret.push_back(n);
  return ret;
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  freopen((FILENAME + ".in").c_str(), "r", stdin);
  freopen((FILENAME + ".out").c_str(), "w", stdout);
  int testcases;
  scanf("%d", &testcases);
  for (int case_id = 1; case_id <= testcases; case_id++) {
    printf("Case #%d: ", case_id);
    int r, c, n;
    scanf("%d %d %d", &r, &c, &n);
    vector<vector<bool>> grid;
    for (int i = 0; i < r; i++) {
      vector<bool> row(c);
      grid.push_back(row);
    }
    int out = 0;
    for (int x = 0; x < n; x++) {
      int best = 1000;
      int best_i = 0;
      int best_j = 0;
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
          if (!grid[i][j]) {
            int count = 0;
            if (j + 1 < c && grid[i][j+1]) {
              count++;
            }
            if (j - 1 >= 0 && grid[i][j-1]) {
              count++;
            }
            if (i + 1 < r && grid[i+1][j]) {
              count++;
            }
            if (i - 1 >= 0 && grid[i-1][j]) {
              count++;
            }
            if (count < best) {
              best = count;
              best_i = i;
              best_j = j;
            }
            if (best == 0) {
              break;
            }
          }
        }
        if (best == 0) {
          break;
        }
      }
      grid[best_i][best_j] = true;
      print_container(grid);
      out += best;
    }
    printf("%d\n", out);
  }
  fflush(stdout);
}
