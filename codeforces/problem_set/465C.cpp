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

int get_index(s) {
  for (int i = 0; i < count; ++i) {
    /* code */
  }
}

bool tolerable(string s) {
  for (int i = 2; i <= 3 ; ++i) {
    for (int j = 0; j <= s.size() - i; ++j) {
      if ((int) s.size() - i < 0) {
        break;
      }
      int begin = j;
      int end = j + i - 1;
      bool bad = true;
      while (end > begin) {
        if (s[end] != s[begin]) {
          bad = false;
          break;
        }
        begin++;
        end--;
      }
      if (bad) {
        return false;
      }
    }
  }
  return true;
}

string get_next(string now, string original, int p) {
  for (int i = now.size() - 1; i >= 0; --i) {
    if (now[i] - 'a' + 1 < p) {
      now[i] = now[i] + 1;
      return now;
    } else {
      now[i] = 'a';
    }
  }
  return "";
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n, p;
  scanf("%d %d", &n, &p);
  char c[1010];
  scanf("%s", c);
  string s(c);
  string next = get_next(s, s, p);
  bool good = true;
  while (next.size() > 0) {
    if (tolerable(next)) {
      printf("%s", next.c_str());
      good = false;
      break;
    }
    next = get_next(next, s, p);
  }
  if (good) {
    printf("NO");

  }

}
