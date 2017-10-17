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

int count_vowels(string s) {
  int out = 0;
  for (int i = 0; i < s.size(); i++) {
    out += s[i] >= 'A' && s[i] <= 'Z';
  }
  return out;
}

int main () {
  int n;
  scanf("%d\n", &n);
  string current;
  int best = 0;
  for (int i = 0; i < n; i++) {
    char c;
    scanf("%c", &c);
    if (c == ' ') {
      best = max(best, count_vowels(current));
      current = "";
    } else {
      current += c;
    }
  }
  best = max(best, count_vowels(current));
  printf("%d", best);
}
