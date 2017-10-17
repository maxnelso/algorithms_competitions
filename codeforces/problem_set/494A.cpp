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
  char c[1000000];
  scanf("%s", c);
  string s(c);
  int count = 0;
  vector<int> out;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      count++;
    } else if (s[i] == ')') {
      count--;
    } else {
      count--;
      if (count < 0) {
        printf("-1");
        return 0;
      }
      out.push_back(1);
    }
  }
  if (count < 0) {
    printf("-1");
    return 0;
  }
  out[out.size() - 1] = count + 1;

  count = 0;
  int index = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      count++;
    } else if (s[i] == ')') {
      count--;
    } else {
      count -= out[index++];
    }
    if (count < 0) {
      printf("-1");
      return 0;
    }
  }
  for (int i = 0; i < out.size(); i++) {
    printf("%d\n", out[i]);
  }
  setvbuf(stdout, NULL, _IONBF, 0);
}
