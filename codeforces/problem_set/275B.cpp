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
  int n, m;
  scanf("%d %d", &n, &m);
  vector<string> grid;
  vector<pair<int, int>> blacks;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    grid.push_back(s);
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == 'B') {
        blacks.push_back(make_pair(i, j));
      }
    }
  }

  for (auto& black1 : blacks) {
    for (auto& black2 : blacks) {
      if (black1 == black2) {
        continue;
      }

      pair<int, int> diff = {0, 0};
      if (black2.first > black1.first) {
        diff.first = 1;
      } else if (black2.first < black1.first) {
        diff.first = -1;
      }
      if (black2.second > black1.second) {
        diff.second = 1;
      } else if (black2.second < black1.second) {
        diff.second = -1;
      }

      pair<int, int> copy_black1 = black1;
      bool found = false;
      // One way
      if (diff.first != 0) {
        found = true;
        while (copy_black1.first != black2.first) {
          if (grid[copy_black1.first][copy_black1.second] != 'B') {
            break;
          }
          copy_black1.first += diff.first;
        }
        if (copy_black1.first != black2.first) {
          found = false;
        }
        while (copy_black1.second != black2.second) {
          if (grid[copy_black1.first][copy_black1.second] != 'B') {
            break;
          }
          copy_black1.second += diff.second;
        }
        if (copy_black1.second != black2.second) {
          found = false;
        }
      }

      if (found) {
        continue;
      }

      copy_black1 = black1;
      // Other way
      if (diff.second != 0) {
        found = true;
        while (copy_black1.second != black2.second) {
          if (grid[copy_black1.first][copy_black1.second] != 'B') {
            break;
          }
          copy_black1.second += diff.second;
        }

        if (copy_black1.second != black2.second) {
          found = false;
        }

        while (copy_black1.first != black2.first) {
          if (grid[copy_black1.first][copy_black1.second] != 'B') {
            break;
          }
          copy_black1.first += diff.first;
        }

        if (copy_black1.first != black2.first) {
          found = false;
        }

      }

      if (!found) {
        printf("NO");
        return 0;
      }
    }
  }

  printf("YES");
}
