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

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  char c[100000];
  scanf("%s", c);
  string s(c);
  int k;
  scanf("%d", &k);
  map<char, int> values;
  int best = 0;
  for (int i = 0; i < 26; i++) {
    char c = 'a' + i;
    int a;
    scanf("%d", &a);
    values[c] = a;
    if (a > best) {
      best = a;
    }
  }
  int score = 0;
  for (int i = 0; i < s.size(); i++) {
    score += values[s[i]] * (i + 1);
  }
  for (int i = s.size(); i < s.size() + k; i++) {
    score += best * (i + 1);
  }
  printf("%d", score);
}
