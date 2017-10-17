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
  string s;
  cin >> s;
  set<char> good_letters;
  for (int i = 0; i < s.size(); i++) {
    good_letters.insert(s[i]);
  }
  string pattern;
  cin >> pattern;
  int n;
  scanf("%d", &n);
  bool no_star = pattern.find('*') == string::npos;
  for (int i = 0; i < n; i++) {
    string test;
    cin >> test;
    bool flag = true;
    int z = 0;
    if (test.size() != pattern.size() && no_star) {
      flag = false;
    }
    for (int j = 0; j < pattern.size(); j++) {
      if (pattern[j] != '?' && pattern[j] != '*') { // Regular letter
        if (test[z] != pattern[j]) {
          flag = false;
          break;
        }
      } else if (pattern[j] == '?') {
        if (good_letters.find(test[z]) == good_letters.end()) {
          flag = false;
          break;
        }
      } else if (pattern[j] == '*') {
        int diff = (int) test.size() - (int) pattern.size();
        if (diff < -1) { // Too big diff
          flag = false;
          break;
        } else if (diff == -1) { // Empty char
          z--;
          // Do nothing
        } else {
          for (int k = j; k < j + diff + 1; k++) {
            if (good_letters.find(test[k]) != good_letters.end()) {
              flag = false;
              break;
            }
          }
          if (!flag) {
            break;
          }
          z += diff;
        }
      }
      z++;
    }
    if (!flag) {
     printf("NO\n");
    } else {
     printf("YES\n");
    }
  }
}
