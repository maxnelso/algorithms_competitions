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

int a[26][26];
char s[200001];
char t[200001];

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n, out = 0;
  scanf("%d", &n);
  scanf("%s", s);
  scanf("%s", t);
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      out++;
    }
    a[s[i] - 'a'][t[i] - 'a'] = i + 1;
  }

  for (int i = 0; i < 26; i++) {
    for (int j = 0;j < 26; j++) {
      if (i == j) {
        continue;
      }
      if (a[i][j] > 0 && a[j][i] > 0) {
        printf("%d\n", out - 2);
        printf("%d %d", a[i][j], a[j][i]);
        return 0;
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      if (i == j) {
        continue;
      }
      for (int k = 0; k < 26; k++) {
        if (k == j) {
          continue;
        }
        if (a[i][j] > 0 && a[j][k] > 0) {
          printf("%d\n", out - 1);
          printf("%d %d", a[i][j], a[j][k]);
          return 0;
        }
      }
    }
  }
  printf("%d\n", out);
  printf("-1 -1");
}
