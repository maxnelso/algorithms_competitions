#include <bitset>
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

int grid[1000][1000];

int count(int m, int k) {
  int out = 0;
  while (m > 0 and m % k == 0) {
    out++;
    m /= k;
  }
  return out;
}

std::pair<int, string> dp(int a, int n) {
  int dp[1000][1000];
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      dp[i][0] = count(grid[i][0], a);
      dp[0][i] = count(grid[0][i], a);
    } else {
      dp[i][0] = dp[i-1][0] + count(grid[i][0], a);
      dp[0][i] = dp[0][i-1] + count(grid[0][i], a);
    }
    //printf("%d %d %d\n", 0, i, dp[0][i]);
    //printf("%d %d %d\n", i, 0, dp[i][0]);
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + count(grid[i][j], a);
      //printf("%d %d %d\n", i, j, dp[i][j]);
    }
  }
  string answer;
  int i = n - 1;
  int j = n - 1;
  while (i + j > 0) {
    //printf("i: %d j: %d\n", i, j);
    if (j > 0) {
    //  printf("Value at %d %d: %d\n", i, j - 1, dp[i][j-1]);
    }
    if (i > 0) {
    //  printf("Value at %d %d: %d\n", i - 1, j, dp[i - 1][j]);
    }
    if (i == 0 || (i * j && dp[i][j-1] < dp[i-1][j])) {
      j--;
      answer += 'R';
    } else {
      i--;
      answer += 'D';
    }
    //printf("current answer %s\n", answer.c_str());
  }
  reverse(answer.begin(), answer.end());
  return make_pair(dp[n-1][n-1], answer);
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);

  bool has_zero = false;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a;
      scanf("%d", &a);
      grid[i][j] = a;
    }
  }
  pair<int, string> twos = dp(2, n);
  pair<int, string> fives = dp(5, n);
  int o = min(twos.first, fives.first);
  //printf("mins %d %d\n", twos.first, fives.first);
  //printf("answers %s %s\n", twos.second.c_str(), fives.second.c_str());
  string s;
  if (o == twos.first) {
    s = twos.second;
  } else {
    s = fives.second;
  }

  if (o > 1) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) {
          o = 1;
          s = "";
          for (int k = 0; k < j; k++) s += 'R';
          for (int k = 0; k < n - 1; k++) s += 'D';
          for (int k = 0; k < (n - 1 - j); k++) s += 'R';
          printf("1\n%s", s.c_str());
          return 0;
        }
      }
    }
  }
  printf("%d\n%s", o, s.c_str());
}
