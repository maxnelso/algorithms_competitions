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
  vector<set<int>> known_languages;
  bool all_zeroes = true;
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    if (k != 0) {
      all_zeroes = false;
    }
    set<int> languages;
    for (int j = 0; j < k; j++) {
      int a;
      scanf("%d", &a);
      languages.insert(a);
    }
    known_languages.push_back(languages);
  }

  if (all_zeroes) {
    printf("%d", n);
    return 0;
  }

  set<int> seen;
  vector<vector<int>> connected_components;
  for (int i = 0; i < n; i++) {
    if (seen.find(i) != seen.end()) {
      continue;
    }
    vector<int> connected_component;
    queue<int> q;
    q.push(i);
    seen.insert(i);
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      connected_component.push_back(node);
      for (int j = 0; j < n; j++) {
        if (seen.find(j) != seen.end()) {
          continue;
        }

        for (auto& language : known_languages[j]) {
          if (known_languages[node].find(language) != known_languages[node].end()) {
            seen.insert(j);
            q.push(j);
            break;
          }
        }
      }
    }
    connected_components.push_back(connected_component);
  }
  printf("%d", connected_components.size() - 1);
}
