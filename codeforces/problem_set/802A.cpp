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

int main () {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> books(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &books[i]);
  }
  set<int> current;
  int out = 0;
  for (int i = 0; i < n; i++) {
    int book = books[i];
    if (current.find(book) != current.end()) {
      continue;
    }
    out++;
    if (current.size() == k) {
      int min_count = 100;
      int min_book = -1;
      for (auto& b : current) {
        int c = 0;
        for (int j = i + 1; j < n; j++) {
          if (books[j] == b) {
            c++;
          }
        }
        if (c < min_count) {
          min_book = b;
          min_count = c;
        }
      }
      current.erase(min_book);
    }
    current.insert(book);
  }
  printf("%d", out);
}
