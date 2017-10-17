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
  string start = "BGRY";
  char c[1000];
  scanf("%s", c);
  string s(c);
  do {
    bool works = true;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '!') {
        continue;
      } else if (s[i] != start[i % 4]) {
        works = false;
        break;
      }
    }
    if (works) {
      break;
    }
  } while (next_permutation(start.begin(), start.end()));

  map<char, int> counts;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '!') {
      char c = start[i % 4];
      counts[c]++;
    }
  }
  for (auto c : {'R', 'B', 'Y', 'G'}) {
    printf("%d ", counts[c]);
  }
}
