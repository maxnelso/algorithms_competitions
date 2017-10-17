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

struct piece {
  char type;
  int x;
  int y;

  piece(char t, int x, int y) {
    this->type = t;
    this->x = x;
    this->y = y;
  }
};

int dist(int x, int y, int a, int b) {
  return abs(a - x) + abs(y - b);
}

int main () {
  int n;
  scanf("%d\n", &n);
  int x, y;
  scanf("%d %d\n", &x, &y);
  piece up('Z', -1, -1);
  piece up_right('Z', -1, -1);
  piece right('Z', -1, -1);
  piece down_right('Z', -1, -1);
  piece down('Z', -1, -1);
  piece down_left('Z', -1, -1);
  piece left('Z', -1, -1);
  piece up_left('Z', -1, -1);
  for (int i = 0; i < n; i++) {
    char c;
    int a, b;
    scanf("%c %d %d\n", &c, &a, &b);
    int d = dist(x, y, a, b);
    if (a == x) {
      if (b < y) {
        if (down.type == 'Z' || d < dist(x, y, down.x, down.y)) {
          down.type = c;
          down.x = a;
          down.y = b;
        }
      } else {
        if (up.type == 'Z' || d < dist(x, y, up.x, up.y)) {
          up.type = c;
          up.x = a;
          up.y = b;
        }
      }
    } else if (b == y) {
      if (a < y) {
        if (left.type == 'Z' || d < dist(x, y, left.x, left.y)) {
          left.type = c;
          left.x = a;
          left.y = b;
        }
      } else {
        if (right.type == 'Z' || d < dist(x, y, right.x, right.y)) {
          right.type = c;
          right.x = a;
          right.y = b;
        }
      }
    } else if (a - x == b - y && a - x > 0) {
      if (up_right.type == 'Z' || d < dist(x, y, up_right.x, up_right.y)) {
        up_right.type = c;
        up_right.x = a;
        up_right.y = b;
      }
    } else if (a - x == abs(b - y)) {
      if (down_right.type == 'Z' || d < dist(x, y, down_right.x, down_right.y)) {
        down_right.type = c;
        down_right.x = a;
        down_right.y = b;
      }
    } else if (b - y == abs(a - x)) {
      if (up_left.type == 'Z' || d < dist(x, y, up_left.x, up_left.y)) {
        up_left.type = c;
        up_left.x = a;
        up_left.y = b;
      }
    } else if (b - y == a - x && a - x < 0) {
      if (down_left.type == 'Z' || d < dist(x, y, down_left.x, down_left.y)) {
        down_left.type = c;
        down_left.x = a;
        down_left.y = b;
      }
    }
  }

  if (up.type == 'R' || up.type == 'Q') {
    printf("YES");
  } else if (right.type == 'R' || right.type == 'Q') {
    printf("YES");
  } else if (down.type == 'R' || down.type == 'Q') {
    printf("YES");
  } else if (left.type == 'R' || left.type == 'Q') {
    printf("YES");
  } else if (up_left.type == 'B' || up_left.type == 'Q') {
    printf("YES");
  } else if (up_right.type == 'B' || up_right.type == 'Q') {
    printf("YES");
  } else if (down_right.type == 'B' || down_right.type == 'Q') {
    printf("YES");
  } else if (down_left.type == 'B' || down_left.type == 'Q') {
    printf("YES");
  } else {
    printf("NO");
  }
}
