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

void solve_2(string& s) {
  int out = 0;
  string a_start = "";
  for (int i = 0; i < s.size(); i++) {
    a_start += 'A' + i % 2;
  }
  string b_start = "";
  for (int i = 0; i < s.size(); i++) {
    b_start += 'A' + (i + 1) % 2;
  }

  int a_out = 0;
  for (int i = 0; i < s.size(); i++) {
    a_out += s[i] != a_start[i];
  }

  int b_out = 0;
  for (int i = 0; i < s.size(); i++) {
    b_out += s[i] != b_start[i];
  }

  if (a_out < b_out) {
    printf("%d\n", a_out);
    printf("%s", a_start.c_str());
  } else {
    printf("%d\n", b_out);
    printf("%s", b_start.c_str());
  }
}

char get_any_different_character(char c, int k) {
  for (int i = 0; i < k; i++) {
    if ('A' + i != c) {
      return 'A' + i;
    }
  }
}

char get_any_different_character(char c1, char c2, int k) {
  for (int i = 0; i < k; i++) {
    if ('A' + i != c1 && 'A' + i != c2) {
      return 'A' + i;
    }
  }
}


int main () {
  int n, k;
  scanf("%d %d", &n, &k);
  string s;
  cin >> s;
  if (k == 2) {
    solve_2(s);
    return 0;
  }

  int out = 0;
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] == s[i + 1]) {
      out++;
      if (i + 1 == s.size() - 1) {
        char c = get_any_different_character(s[i + 1], k);
        s[i + 1] = c;
      } else {
        char c = get_any_different_character(s[i + 1], s[i + 2], k);
        s[i + 1] = c;
      }
    }
  }
  printf("%d\n", out);
  printf("%s", s.c_str());
}
