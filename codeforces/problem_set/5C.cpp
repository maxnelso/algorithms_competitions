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
#include <unordered_map>

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

int d[1000050];
int c[1000050];

int main () {
  char ch[1000050];
  scanf("%s", ch);
  string s(ch);
  map<int, int> m;
  stack<int> st;
  memset(c, -1, sizeof(c));
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      st.push(i);
    } else {
      if (st.empty()) {
        c[i] = -1;
        d[i] = -1;
      } else {
        int top = st.top();
        st.pop();
        d[i] = top;
        int pos = d[i] - 1;
        if (s[pos] == ')' && c[pos] != -1) {
          c[i] = c[pos];
        } else {
          c[i] = d[i];
        }
      }
    }
  }
  int max_count = 0;
  int max_length = 0;
  for (int i = 0; i < 1000050; i++) {
    if (c[i] == -1) {
      continue;
    }
    int length = i - c[i] + 1;
    if (length > max_length) {
      max_count = 1;
      max_length = length;
    } else if (length == max_length) {
      max_count++;
    }
  }
  if (max_length == 0) {
    printf("0 1");
    return 0;
  }
  printf("%d %d\n", max_length, max_count);
}
