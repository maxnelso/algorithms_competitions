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

int A[2100];
int D[2100][2100];

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  char c[2100];
  scanf("%s", c);
  string s(c);

  char d[600];
  scanf("%s", d);
  string p(d);

  for (int i = 0; i < s.size(); i++) {
    int ps = i;
    int pp;
    for (pp = 0; pp < p.size(); pp++) {
      while (ps < s.size() && p[pp] != s[ps]) {
        ps++;
      }
      if (ps == s.size()) {
        break;
      } else {
        ps++;
      }
    }
    if (pp == p.size()) {
      A[i] = ps - i;
    } else {
      A[i] = -1;
    }
  }

  for (int i = 0; i < s.size(); i++) {
    for (int r = 0; r <= i; r++) {
      D[i + 1][r] = max(D[i + 1][r], D[i][r]);
      D[i + 1][r + 1] = max(D[i + 1][r + 1], D[i][r]);
      if (A[i] >= 0) {
        D[i + A[i]][r + A[i] - p.size()] = max(D[i + A[i]][r + A[i] - p.size()], D[i][r] + 1);
      }
    }
  }
  printf("%d", D[s.size()][0]);
  for (int i = 1; i <= s.size(); i++) {
    printf(" %d", D[s.size()][i]);
  }
  printf("\n");
}
