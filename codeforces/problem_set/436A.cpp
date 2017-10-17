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
  int n, x;
  scanf("%d %d", &n, &x);
  vector<pair<int, int>> caramels;
  vector<pair<int, int>> fruits;
  bool caramels_seen[2005];
  bool fruits_seen[2005];
  memset(caramels_seen, 0, sizeof(caramels_seen));
  memset(fruits_seen, 0, sizeof(fruits_seen));
  for (int i = 0; i < n; i++) {
    int t, h, m;
    scanf("%d %d %d", &t, &h, &m);
    if (t == 0) {
      caramels.push_back(make_pair(h, m));
    } else {
      fruits.push_back(make_pair(h, m));
    }
  }
  sort(caramels.begin(), caramels.end());
  sort(fruits.begin(), fruits.end());
  bool found_caramel = false;
  bool found_fruit = false;
  int best;
  int best_i;
  int count = 0;
  int other_count = 0;
  do {
    if (found_caramel && !found_fruit) {
      found_caramel = false;
    } else {
      best = 0;
      best_i = 0;
      found_caramel = false;
      for (int i = 0; i < caramels.size(); i++) {
        if (caramels[i].first > x) {
          break;
        }
        if (!caramels_seen[i] && caramels[i].second > best) {
          best = caramels[i].second;
          best_i = i;
          found_caramel = true;
        }
      }
      if (found_caramel) {
        x += best;
        caramels_seen[best_i] = true;
        count++;
      }
    }
    if (found_fruit && !found_caramel) {
      found_fruit = false;
    } else {

      found_fruit = false;
      best = 0;
      best_i = 0;
      for (int i = 0; i < fruits.size(); i++) {
        if (fruits[i].first > x) {
          break;
        }
        if (!fruits_seen[i] && fruits[i].second > best) {
          best = fruits[i].second;
          best_i = i;
          found_fruit = true;
        }
      }
      if (found_fruit) {
        x += best;
        fruits_seen[best_i] = true;
        count++;
      }
    }
  } while (found_caramel || found_fruit);
  do {
    if (found_fruit && !found_caramel) {
      found_fruit = false;
    } else {
      found_fruit = false;
      best = 0;
      best_i = 0;
      for (int i = 0; i < fruits.size(); i++) {
        if (fruits[i].first > x) {
          break;
        }
        if (!fruits_seen[i] && fruits[i].second > best) {
          best = fruits[i].second;
          best_i = i;
          found_fruit = true;
        }
      }
      if (found_fruit) {
        x += best;
        fruits_seen[best_i] = true;
        other_count++;
      }
    }
    if (found_caramel && !found_fruit) {
      found_caramel = false;
    } else {
      best = 0;
      best_i = 0;
      found_caramel = false;
      for (int i = 0; i < caramels.size(); i++) {
        if (caramels[i].first > x) {
          break;
        }
        if (!caramels_seen[i] && caramels[i].second > best) {
          best = caramels[i].second;
          best_i = i;
          found_caramel = true;
        }
      }
      if (found_caramel) {
        x += best;
        caramels_seen[best_i] = true;
        other_count++;
      }
    }
  } while (found_caramel || found_fruit);
  printf("%d", max(count, other_count));
}
