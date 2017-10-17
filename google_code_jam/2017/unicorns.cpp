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

string FILENAME = "B-large-practice";

struct color {
  int total;
  char c;

  color(int total, char c) {
    this->total = total;
    this->c = c;
  }

  bool operator<(color other) const {
    return this->total < other.total;
  }
};

color& get_opposite(color& mixed, vector<color>& pure) {
  char c;
  if (mixed.c == 'O') {
    c = 'B';
  } else if (mixed.c == 'G') {
    c = 'R';
  } else {
    c = 'Y';
  }
  for (int i = 0; i < pure.size(); i++) {
    if (pure[i].c == c) {
      return pure[i];
    }
  }
  return pure[0];
}

bool good_color(char f, char me) {
  if (f == 'R') {
    return me == 'R';
  } else if (f == 'Y') {
    return me == 'Y';
  } else if (f == 'B') {
    return me == 'B';
  } else if (f == 'O') {
    return me == 'B';
  } else if (f == 'G') {
    return me == 'R';
  } else {
    return me == 'Y';
  }
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  freopen((FILENAME + ".in").c_str(), "r", stdin);
  freopen((FILENAME + ".out").c_str(), "w", stdout);
  int testcases;
  scanf("%d", &testcases);
  for (int case_id = 1; case_id <= testcases; case_id++) {
    int n;
    printf("Case #%d: ", case_id);
    string colors = "ROYGBV";
    scanf("%d", &n);
    vector<color> mixed;
    vector<color> pure;
    for (int i = 0; i < colors.size(); i++) {
      int a;
      scanf("%d", &a);
      color c = color(a, colors[i]);
      if (i % 2 == 0) {
        pure.push_back(c);
      } else {
        mixed.push_back(c);
      }
    }
    bool set_first = false;
    char f = ' ';
    sort(mixed.rbegin(), mixed.rend());
    vector<char> output(n);
    int index = 0;
    bool baddie = false;
    for (int i = 0; i < mixed.size(); i++) {
      if (mixed[i].total > 0) {
        color& opposite = get_opposite(mixed[i], pure);
        if (i > 0) {
          index++;
        }
        bool start = true;
        while (mixed[i].total > 0) {
          output[index] = mixed[i].c;
          if (!set_first) {
            set_first = true;
            f = mixed[i].c;
          }
          // left
          if (start) {
            if (index == 0) {
              output[output.size() - 1] = opposite.c;
            } else {
              output[index - 1] = opposite.c;
            }
            start = false;
            opposite.total--;
          }

          // right
          if (index + 1 >= output.size()) {
            baddie = true;
            break;
          } else {
            if (output[index + 1] == opposite.c) { // wrap
              break;
            } else if (index + 1 == n) {
              baddie = true;
              break;
            }
            output[index + 1] = opposite.c;
            opposite.total--;
          }
          index += 2;
          mixed[i].total--;
        }
        if (opposite.total < 0) {
          baddie = true;
          break;
        }
      }
      if (baddie) {
        break;
      }
    }
    if (baddie) {
      printf("IMPOSSIBLE\n");
      continue;
    }
    char previous = ' ';
    if (index > 0) {
      previous = output[index - 1];
    }
    while (pure[0].total > 0 || pure[1].total > 0 || pure[2].total > 0) {
      int highest = -1;
      int best_index = -1;
      for (int i = 0; i < 3; i++) {
        if (pure[i].c != previous && pure[i].total > 0 &&
           (pure[i].total > highest || (good_color(f, pure[i].c) && pure[i].total >= highest)) &&
           !(index == n - 1 && pure[i].c == output[0])) {
          highest = pure[i].total;
          best_index = i;
        }
      }
      if (best_index == -1) {
        baddie = true;
        break;
      }
      previous = pure[best_index].c;
      output[index++] = pure[best_index].c;
      pure[best_index].total--;
      if (!set_first) {
        f = pure[best_index].c;
        set_first = true;
      }
    }
    if (baddie) {
      printf("IMPOSSIBLE\n");
      continue;
    }
    for (int i = 0; i < output.size(); i++) {
      printf("%c", output[i]);
    }

    printf("\n");

  }
  fflush(stdout);
}
