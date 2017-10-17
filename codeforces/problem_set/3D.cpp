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

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  char c[(int) (5*10e4+100)];
  scanf("%s", c);
  string s(c);
  int depth = 0;
  unsigned long long total = 0;
  priority_queue<pair<int, int>> pq;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      depth++;
    } else if (s[i] == ')') {
      depth--;
    } else {
      int a, b;
      scanf("%d %d", &a, &b);
      depth--;
      s[i] = ')';
      total += b;
      pq.push(make_pair(b - a, i));
    }
    if (depth < 0) {
      if (pq.empty()) {
        printf("-1");
        return 0;
      }
      pair<int, int> p = pq.top();
      pq.pop();
      s[p.second] = '(';
      total -= p.first;
      depth += 2;
    }
  }
  if (depth != 0) {
    printf("-1");
    return 0;
  }
  cout << total << endl;
  printf("%s", s.c_str());
}
