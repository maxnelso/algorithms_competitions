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
#include <climits>
#include <iterator>
#include <unordered_map>

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

int main () {
  int n, p;
  scanf("%d %d", &n, &p);
  p--;
  string s;
  cin >> s;
  if (p >= s.size() / 2) {
    reverse(s.begin(), s.end());
    p = s.size() - p - 1;
  }

  int left = -1;
  int right = -1;
  int total_changes = 0;
  for (int i = 0; i < s.size() / 2; i++) {
    char a = s[i];
    char b = s[s.size() - i - 1];
    if (a > b) {
      swap(a, b);
    }
    int going_up = b - a;
    int going_down = a - 'a' + 'z' - b + 1;
    int best = min(going_up, going_down);
    if (best > 0 && left == -1) {
      left = i;
    }
    if (best > 0) {
      right = i;
    }

    total_changes += best;
  }

  if (left == -1) {
    printf("0");
    return 0;
  }

  int out;
  if (p >= right) {
    out = total_changes + (p - left);
  } else if (p <= left) {
    out = total_changes + (right - p);
  } else {
    int left_then_right = total_changes + (p - left) + (p - left) + (right - p);
    int right_then_left = total_changes + (right - p) + (p - left) + (right - p);
    out = min(left_then_right, right_then_left);
  }
  printf("%d", out);
}
